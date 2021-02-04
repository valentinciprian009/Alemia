from preprocessor import Preprocessor
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
from sklearn.svm import SVR
import joblib

WEIGHTS_FILE = "../data/weights.apt"


class Train:
    def __init__(self, check=False):

        if check is True:
            self.regressor = RandomForestRegressor()
        else:
            self.regressor = LinearRegression()

        self.x, self.y = Preprocessor().get_dataset()

    # False to get test data, True to get train data
    def _get_test_train_data(self, train):

        x_train, x_test, y_train, y_test = train_test_split(self.x,
                                                            self.y,
                                                            test_size=0.2)

        if train is True:
            return x_train, y_train
        else:
            return x_test, y_test

    def train(self):

        x_train, y_train = self._get_test_train_data(True)
        self.regressor.fit(x_train, y_train)

        joblib.dump(self.regressor, WEIGHTS_FILE)

    def test(self, model_name=WEIGHTS_FILE):

        self.regressor = joblib.load(model_name)

        x_test, y_test = self._get_test_train_data(False)

        y_predicted = self.regressor.predict(x_test)

        plt.plot(y_test - y_predicted, marker='o', linestyle='')
        plt.axhline(y=0, color="r", linestyle="-")
        plt.title("Diferenta nota reala-prezisa RFR")
        plt.ylabel("Eroarea de predictie")
        plt.xlabel("Id date test")
        plt.show()
        plt.savefig("graph.png")

    def test_multiple_methods(self):

        x_train, y_train = self._get_test_train_data(True)
        x_test, y_test = self._get_test_train_data(False)

        linear_regressor = LinearRegression()
        svr_regressor = SVR()
        random_forest_regressor = RandomForestRegressor()

        linear_regressor.fit(x_train, y_train)
        svr_regressor.fit(x_train, y_train)
        random_forest_regressor.fit(x_train, y_train)

        svr_predict = svr_regressor.predict(x_test)
        linear_predict = linear_regressor.predict(x_test)
        random_forest_predict = random_forest_regressor.predict(x_test)

        print("Linear Predict :", linear_predict)
        print("True notes: ", y_test)

        print("RMSE SVR: ", self._calculate_rmse(y_test, svr_predict))
        print("RMSE Linear Regression: ",
              self._calculate_rmse(y_test, linear_predict))
        print("RMSE Random Forest: ",
              self._calculate_rmse(y_test, random_forest_predict))

    def _calculate_rmse(self, y_test, y_predicted):

        mse = mean_squared_error(y_test, y_predicted)
        rmse = np.sqrt(mse)

        return rmse


class Predictor:
    def __init__(self, model_name=WEIGHTS_FILE):

        self.model = joblib.load(model_name)

    # returns <class 'numpy.ndarray'>
    def predict(self, features):

        prediction = self.model.predict(features)

        return prediction