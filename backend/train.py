from preprocessor import Preprocessor
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
from sklearn.linear_model import LinearRegression, SGDRegressor, Ridge
from sklearn.metrics import mean_squared_error
from sklearn.svm import SVR
import math
import os
import joblib
import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
import pandas as pd
from torchvision.datasets import MNIST
from torch.utils.data import DataLoader
from torchvision import transforms
from torch_model import trainModel

WEIGHTS_FILE = "../data/weights.apt"

# Training class
# Allows for two methods - RandomForest and LinearRegression
# Generates comparision graphs between multiple methods
# Generates predicted - ground truth graph

class MLP(nn.Module):
  '''
    Multilayer Perceptron.
  '''
  def __init__(self):
    super().__init__()
    self.layers = nn.Sequential(
      nn.Flatten(),
      nn.Linear(32 * 32 * 3, 64),
      nn.ReLU(),
      nn.Linear(64, 32),
      nn.ReLU(),
      nn.Linear(32, 10)
    )


  def forward(self, x):
    '''Forward pass'''
    return self.layers(x)

class RegressionModel(nn.Module):
    def __init__(self, in_feat=1, out_feat=1):
        super().__init__()
        self.fc = nn.Linear(in_feat, out_feat) # Definesc o retea neuronala cu un singur strat Fully Connected

    def forward(self, x):
        print(x)
        out = self.fc(x)
        return out

class Train:
    def __init__(self, check=False):

        if check is True:
            self.regressor = RandomForestRegressor()
        else:
            self.regressor = LinearRegression()

        # TODO(@apostolescus)
        self.x, self.y, self.test_data, _ = Preprocessor().get_dataset()

    # False to get test data, True to get train data
    def _get_test_train_data(self, train, all=False):

        if all is True:
            return self.x, self.y

        x_train, x_test, y_train, y_test = train_test_split(self.x,
                                                            self.y,
                                                            test_size=0.2)

        if train is True:
            return x_train, y_train
        else:
            return x_test, y_test

    def train(self):

        x_train, y_train = self._get_test_train_data(True, True)
        self.regressor.fit(x_train, y_train)

        joblib.dump(self.regressor, WEIGHTS_FILE)

    # test method - plots the difference btw prediction and ground truth
    def test(self, model_name=WEIGHTS_FILE):

        self.regressor = joblib.load(model_name)

        x_test, y_test = self._get_test_train_data(False)

        y_predicted = self.regressor.predict(x_test)

        plt.plot(y_test - y_predicted, marker='o', linestyle='')
        plt.axhline(y=0, color="r", linestyle="-")
        plt.title("Diferenta nota reala-prezisa Linear Regression")
        plt.ylabel("Eroarea de predictie")
        plt.xlabel("Id date test")
        # plt.show()
        plt.savefig("graph.png")

    # compares multiple prediction methods
    # generates graphic representation of RMSE
    def test_multiple_methods(self):

        x_train, y_train = self._get_test_train_data(True)
        x_test, y_test = self._get_test_train_data(False)

        linear_regressor = LinearRegression()
        svr_regressor = SVR()
        random_forest_regressor = RandomForestRegressor()
        ridge_regressor = Ridge()

        linear_regressor.fit(x_train, y_train)
        svr_regressor.fit(x_train, y_train)
        random_forest_regressor.fit(x_train, y_train)
        ridge_regressor.fit(x_train, y_train)

        svr_predict = svr_regressor.predict(x_test)
        linear_predict = linear_regressor.predict(x_test)
        random_forest_predict = random_forest_regressor.predict(x_test)
        ridge_predict = ridge_regressor.predict(x_test)

        # print("Linear Predict :", linear_predict)
        # print("True notes: ", y_test)

        rmse_SVR = self._calculate_rmse(y_test, svr_predict)
        print("RMSE SVR: ", rmse_SVR)

        rmse_Linear = self._calculate_rmse(y_test, linear_predict)
        print("RMSE Linear Regression: ", rmse_Linear)

        rmse_Forest = self._calculate_rmse(y_test, random_forest_predict)
        print("RMSE Random Forest: ", rmse_Forest)

        rmse_Ridge = self._calculate_rmse(y_test, ridge_predict)
        print("RMSE Ridge: ", rmse_Ridge)

        x = ['Linear Reg.', 'Rand. Forest', 'Ridge', 'SVR']
        y = [rmse_Linear, rmse_Forest, rmse_Ridge, rmse_SVR]

        counter = 0

        for i in y:
            if round(i, 4) == 0:
                x[counter] = x[counter] + "\n" + str(round(i, 15))
            else:
                x[counter] = x[counter] + "\n" + str(round(i, 4))
            counter += 1

        plt.bar(x, y)
        plt.ylabel("Valoare RMSE")
        plt.xlabel("Algoritm")
        plt.title("Comparație RMSE")
        plt.savefig("model_comparision.png")
        plt.show()

    def _calculate_rmse(self, y_test, y_predicted):

        mse = mean_squared_error(y_test, y_predicted)
        rmse = np.sqrt(mse)

        return rmse

    def calculate_test(self, model_name=WEIGHTS_FILE):
        self.regressor = joblib.load(model_name)

        y_predicted = self.regressor.predict(self.test_data)

        f = open("../others/results.txt", "w")

        for i in y_predicted:
            f.write(str(round(i, 2)) + "\n")

        return y_predicted

    def _load_true_notes(self):

        array = np.loadtxt("true_notes")
        print("True notes:", array)

        return array


class Predictor:
    def __init__(self, model_name=WEIGHTS_FILE):
        self.model = joblib.load(model_name)

            
    # returns <class 'numpy.ndarray'>
    def predict(self, features):
        
        prediction = self.model.predict(features)


        

        return prediction


class Predictor2:
    def __init__(self, model_name=WEIGHTS_FILE):
        self.model=RegressionModel(20, 1)
        self.model.load_state_dict(torch.load(model_name))
        self.model.eval()
        print(self.model.state_dict())
        self.test_set = trainModel()

            
    # returns <class 'numpy.ndarray'>
    def predict(self, features):
        test_loader = torch.utils.data.DataLoader(self.test_set, batch_size=32, shuffle=False)
        eval_outputs = []
        true_labels = []
        x = []

        with torch.no_grad():
            for batch in test_loader:
                inputs, labels = batch['features'], batch['labels']
                # calculate outputs by running images through the network
                outputs = self.model(inputs)
                eval_outputs += outputs.squeeze(dim=1).tolist()
                true_labels += labels.squeeze(dim=1).tolist()
                x += inputs.squeeze(dim=1).tolist()

        # print(true_labels)
        # print(eval_outputs)
        # print(x)

        tmp = 0
        count = 0
        for i in true_labels:
            tmp += i
            count += 1

        tmp /= count

        print(tmp)

        return tmp


# How to run

train = Train(True)
train.train()
train.calculate_test()

# true_notes = train._load_true_notes()
# prd = Predictor()
# # x_test, y_test = train._get_test_train_data(False)
# y_true = prd.predict(train.test_data)
# print(y_true)
# # y_prd = prd.predict(x_test)

# # print(y_true)
# print("RMSE: ", train._calculate_rmse(y_true, true_notes))
