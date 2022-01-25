#!/usr/bin/env python3

from cgitb import text
from flask import Flask, request, jsonify
from flask_cors import CORS
from Crypto.Hash import MD5
from threading import Thread
import pandas
import zipfile
import os
import time
import warnings
import feature_extraction
import torch_model
from preprocessor import Preprocessor
from train import Predictor2, Train, Predictor
from torch_model import trainModel

DOWNLOAD_DIRECTORY = "uploads"
EXTRACTION_DIRECTORY = "../data/raw/train"
GRADES_CSV_FILENAME = "../data/grades.csv"
FEATURES_CSV_FILENAME = "../data/features.csv"
RETRAINED_PROJECT_CSV = "../data/my_data.csv"
INIT_DATASET = False
TRAIN_MODEL = True

last_student_scanned = None
preprocessor = None
predictor = None
preprocessor2 = None
predictor2 = None

# Create the Flask web app
app = Flask(__name__)
CORS(app)


# Default route
@app.route("/")
def default_route():
    return "Alemia API\n"


# Prediction route
@app.route("/predict", methods=["POST"])
def predict_route():

    global last_student_scanned, preprocessor, predictor, preprocessor2, predictor2

    # Get arguments
    uploaded_file = request.files["file"]

    # Generate a filename and save the file locally
    unique_filename = uploaded_file.filename + str(time.time())
    unique_filename = MD5.new(unique_filename.encode("utf-8")).hexdigest()
    last_student_scanned = unique_filename
    full_path = os.path.join(DOWNLOAD_DIRECTORY, unique_filename + ".zip")
    uploaded_file.save(full_path)

    # Extract the uploaded archive
    extraction_full_path = os.path.join(EXTRACTION_DIRECTORY, unique_filename)
    os.makedirs(extraction_full_path)
    with zipfile.ZipFile(full_path, "r") as zip_file:
        zip_file.extractall(extraction_full_path)

    output = open("../data/my_data.csv", "w")
    output.write("nr_crt,label,nr_clase,nr_errors,nr_inheritance,nr_virtual,nr_static,nr_global,nr_public,nr_private,nr_protected,nr_define,nr_template,nr_stl,nr_namespace,nr_enum,nr_struct,nr_cpp,nr_comments,nr_function,headers_size,sources_size,\n")
    output.close()

    aux = extraction_full_path
    print(len(next(os.walk(extraction_full_path+"/"))[1]))
    if(len(next(os.walk(extraction_full_path+"/"))[1]) == 1):
        # Get features
        features = feature_extraction.retrain_data_one(
            extraction_full_path + "/")
        print(extraction_full_path)
        features = preprocessor.transform_entry(features)

        # Predict the grade
        grade = predictor.predict([features])[0]
        grade = round(grade, 2)

        grade2 = predictor2.predict([features])
        print(grade2)
        grade2 = round(grade2, 2)
        print(grade2)

        # Dump the grade into the specific CSV file
        grades_df = pandas.read_csv(GRADES_CSV_FILENAME)
        grades_df.loc[len(grades_df.index)] = [last_student_scanned, grade]
        grades_df = grades_df[["label", "grade"]]
        grades_df.to_csv(GRADES_CSV_FILENAME, index=False)
        arr = []
        arr.append(grade)
        arr_names = []
        arr_names.append(uploaded_file.filename)
        arr_gradesPy=[]
        arr_gradesPy.append(grade2)
        hashes=[]
        hashes.append(last_student_scanned)
        # Return a result
        result = {"predicted_grade": arr,
        "predicted_grade2":arr_gradesPy,
        "projects_names": arr_names,"hashes" : hashes}
        return jsonify(result)

    else:
        aux_2 = ""
        arr_names = []
        arr_grades = []
        arr_gradesPy=[]
        hashes = []
        for filename in os.listdir(extraction_full_path+"/"):
            grade = 0
            extraction_full_path = aux+"/"+filename
            print(extraction_full_path+"/")
            features = feature_extraction.retrain_data_one(
                extraction_full_path+"/")
            features = preprocessor.transform_entry(features)

            # Predict the grade
            grade = predictor.predict([features])[0]
            grade = round(grade, 2)

            grade2 = predictor2.predict([features])
            print(grade2)
            grade2 = round(grade2, 2)
            print(grade2)

            aux_aux = last_student_scanned + str(time.time())
            aux_hash = MD5.new(aux_aux.encode("utf-8")).hexdigest()
            hashes.append(aux_hash)
            # Dump the grade into the specific CSV file
            grades_df = pandas.read_csv(GRADES_CSV_FILENAME)
            grades_df.loc[len(grades_df.index)] = [aux_hash, grade]
            grades_df = grades_df[["label", "grade"]]
            grades_df.to_csv(GRADES_CSV_FILENAME, index=False)
            arr_names.append(filename)
            arr_grades.append(grade)
            aux_2 += "  "+str(grade)
            arr_gradesPy.append(grade2) 
            # print(aux_2)

        #     # Return a result
        result = {"predicted_grade": arr_grades, "predicted_grade2": arr_gradesPy, "projects_names": arr_names, "hashes" : hashes}
        return jsonify(result)


# Grade adjusting route
@app.route("/adjust_grade", methods=["GET"])
def grade_adjustment_route():

    global last_student_scanned

    # Get arguments
    adjusted_grade = request.args.get("adjusted_grade", type=float)
    get_hash=request.args.get("hash")
    print(get_hash)

    # Save the adjusted grade into the labels file
    grades_df = pandas.read_csv(GRADES_CSV_FILENAME)
    grades_df.loc[grades_df["label"] == get_hash,
                  "grade"] = adjusted_grade
    grades_df = grades_df[["label", "grade"]]
    grades_df.to_csv(GRADES_CSV_FILENAME, index=False)

    # Return a result
    result = {"status": "ok"}
    return jsonify(result)


# Model retraining route
@app.route("/retrain_model", methods=["GET"])
def model_retraining_route():

    # Create a thread that retrain the model
    Thread(target=retrain_model).start()

    # Return a result
    result = {"status": "ok"}
    return jsonify(result)

# Get statistics about homeworks
@app.route("/statistics", methods=["GET"])
def statistics_route():
    fields = ['nr_clase','nr_errors','nr_inheritance','nr_virtual','nr_static','nr_global','nr_public','nr_private','nr_protected','nr_define','nr_template','nr_stl','nr_namespace','nr_enum','nr_struct','nr_cpp','nr_comments','nr_function','headers_size','sources_size']

    features = pandas.read_csv(RETRAINED_PROJECT_CSV, skipinitialspace=True, usecols=fields)

    return features.to_json(orient ='records')

# Function for retraining the machine learning model
def retrain_model():
    global predictor, preprocessor, predictor2, preprocessor2

    Train(check=True).train()
    predictor = Predictor()
    preprocessor = Preprocessor()

    trainModel()
    predictor2 = Predictor2("../data/model.pt")
    preprocessor2 = Preprocessor()

    print("[+] Successfully retrained the model")


def main():
    global preprocessor, predictor, preprocessor2, predictor2

    # Initialize the dataset
    if (INIT_DATASET):
        feature_extraction.init_setup()

    # Train the model
    if (TRAIN_MODEL):
        Train(check=True).train()

    # Initialize some parts of the pipeline
    predictor = Predictor()
    preprocessor = Preprocessor()

    trainModel()
    predictor2 = Predictor2("../data/model.pt")
    preprocessor2 = Preprocessor()

    # Run the web server
    app.run(host="0.0.0.0", port=3001, debug=True)


if __name__ == "__main__":

    # Disable warnings
    warnings.simplefilter(action="ignore", category=RuntimeWarning)

    main()
