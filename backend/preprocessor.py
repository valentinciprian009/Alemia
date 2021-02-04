from sklearn.impute import KNNImputer
from sklearn.feature_selection import SelectKBest, f_regression
import numpy as np
import pandas
import os
import typing

FEATURES_DATASET = "../data/features.csv"
GRADES_DATASET = "../data/grades.csv"
HISTOGRAMS_DUMP_FOLDER = "../data/histograms"
NEIGHBORS_CONSIDERED = 3
K_BEST_FEATURES_SELECTED = 15
DROPPED_COLUMNS = ["label", "nr_struct"]


class Preprocessor:
    _dataframe: pandas.DataFrame = None
    _dropped_columns_indexes: list = []
    _features: np.ndarray = None
    _grades: np.ndarray = None

    def __init__(self, generate_histograms=False):
        # Read the required dataframes, merge them and get the indexes for
        # dropped columns
        features_df = pandas.read_csv(FEATURES_DATASET, index_col="nr_crt")
        grades_df = pandas.read_csv(GRADES_DATASET)
        full_df = pandas.merge(features_df, grades_df)
        full_df = full_df.loc[:, ~full_df.columns.str.match("Unnamed")]

        # Save the processed dataframe
        self._dataframe = full_df

        # Do miscellaneous operations
        self._drop_columns()
        self._fill_empty_columns()
        if (generate_histograms):
            self._plot_histograms()

        # Get the grades
        self._grades = self._dataframe.pop("grade")

        # Select only the relevant columns
        self._selector = SelectKBest(f_regression, k=K_BEST_FEATURES_SELECTED)
        self._features = self._selector.fit_transform(self._dataframe,
                                                      self._grades)

        # Log the selected columns
        print("[+] Successfully selecting {} columns of dataset: ".format(
            K_BEST_FEATURES_SELECTED))
        selected_columns = self._dataframe.columns[self._selector.get_support(
            indices=True)].tolist()
        for column in selected_columns:
            print("\t- \"{}\"".format(column))

    def _fill_empty_columns(self) -> None:
        # Get column with empty entries
        na_count = self._dataframe.isna().sum(min_count=1)
        na_count = na_count[na_count > 0]
        print("[+] Column that needs to be filled are:")
        for index, value in na_count.items():
            print("\t- \"{}\", having {} missing values".format(index, value))

        # Fill the missing values via kNN imputation
        imputer = KNNImputer(n_neighbors=3, weights="uniform")
        self._dataframe = pandas.DataFrame(
            imputer.fit_transform(self._dataframe),
            columns=self._dataframe.columns).round(2)

        # For each column that contained missing values, round the result
        for index, _ in na_count.items():
            self._dataframe[index] = self._dataframe[index].round(2)

    def _plot_histograms(self) -> None:
        # Drop the columns that doesn't contains numeric values
        plotted_dataframe = self._dataframe.copy()

        # Dump each histogram to file
        for column in plotted_dataframe.columns:
            histogram = plotted_dataframe[column].hist(
                orientation="horizontal")
            figure = histogram.get_figure()
            figure_full_path = os.path.join(HISTOGRAMS_DUMP_FOLDER,
                                            column.lower() + ".png")
            figure.savefig(figure_full_path, format="png")
            figure.clear()

        # Log success
        print("[+] Successfully created and dumped {} histograms".format(
            len(plotted_dataframe.columns)))

    def _drop_columns(self) -> None:
        print("[+] Successfully dropped {} columns".format(
            len(DROPPED_COLUMNS)))
        for column in DROPPED_COLUMNS:
            del self._dataframe[column]
            print("\t- \"{}\"".format(column))

    def get_dataset(self) -> typing.Tuple[pandas.DataFrame, pandas.DataFrame]:
        return (self._features, self._grades)

    def transform_entry(self, entry: list) -> list:
        # Drop the useless columns
        features_df = pandas.read_csv(FEATURES_DATASET, index_col="nr_crt")
        dropped_columns = DROPPED_COLUMNS.copy()
        for column in dropped_columns:
            index = list(features_df.columns).index(column)
            entry.pop(index)

        # Try to convert each column
        entry = [int(item) for item in entry]

        # Select the relevant columns
        entry = (self._selector.transform([entry]))[0]

        return entry