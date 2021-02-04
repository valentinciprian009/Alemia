import feature_extraction
from train import Train, Predictor
from preprocessor import Preprocessor
import sys
import os
import zipfile




def main():
    cwd = os.getcwd()
    prep = Preprocessor()
    pred = Predictor()

    archive_full_path = os.path.join(cwd, sys.argv[1])
    extraction_full_path = os.path.join(cwd, "/archive")

    with zipfile.ZipFile(archive_full_path, "r") as zip_file:
        zip_file.extractall(extraction_full_path)

    features = feature_extraction.retrain_data_one(extraction_full_path + "/")
    features = prep.transform_entry(features)

    grade = pred.predict([features])[0]
    grade = round(grade, 2)

    print("Grade is: ", grade)

if __name__ == "__main__":
    main()