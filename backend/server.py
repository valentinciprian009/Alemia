#!/usr/bin/env python3

from flask import Flask, request, jsonify
from flask_cors import CORS
from Crypto.Hash import MD5
import zipfile
import os
import time

app = Flask(__name__)
CORS(app)

DOWNLOAD_DIRECTORY = "uploads"
EXTRACTION_DIRECTORY = "../data/raw/train"


# Default route
@app.route("/")
def default_route():
    return "Alemia API\n"


# Prediction route
@app.route("/predict", methods=["POST"])
def predict_route():

    # Get arguments
    uploaded_file = request.files["file"]

    # Generate a filename and save the file locally
    unique_filename = uploaded_file.filename + str(time.time())
    unique_filename = MD5.new(unique_filename.encode("utf-8")).hexdigest()
    full_path = os.path.join(DOWNLOAD_DIRECTORY, unique_filename + ".zip")
    uploaded_file.save(full_path)

    # Extract the uploaded archive
    extraction_full_path = os.path.join(EXTRACTION_DIRECTORY, unique_filename)
    os.makedirs(extraction_full_path)
    with zipfile.ZipFile(full_path, "r") as zip_file:
        zip_file.extractall(extraction_full_path)

    # Return a result
    result = {"predicted_grade": 10}
    return jsonify(result)


# Grade adjusting route
@app.route("/adjust_grade", methods=["GET"])
def grade_adjustment_route():

    # Get arguments
    adjusted_grade = request.args.get("adjusted_grade", type=float)

    #TODO: Save the adjusted grade into the labels file

    # Return a result
    result = {"status": "ok"}
    return jsonify(result)


# Model retraining route
@app.route("/retrain_model", methods=["GET"])
def model_retraining_route():

    #TODO: Create a thread that retrain the model

    # Return a result
    result = {"status": "ok"}
    return jsonify(result)


def main():
    app.run(host="0.0.0.0", port=3001, debug=True)


if __name__ == "__main__":
    main()