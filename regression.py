import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl
import pandas as pd
import math
import random
from scipy import stats

def log_array(arr):
    return np.array([math.log(e, 2) for e in arr])

def get_lin_log_regression_coefficients(x, y):
    return np.polyfit(log_array(x), y, 1)

def linear_regression():
    def plot_diameter_regression(fname): 
        data = pd.read_csv(fname, sep=',')
        n = data['n'].values
        diameter = data['diameter'].values

        m, b = get_lin_log_regression_coefficients(n, diameter)       
        plt.plot(x, m*x + b, label=f'{fname.rstrip(".csv")}: y ~ {round(m, 2)}x + {round(b, 2)}')

    def plot_coefficient_regression(fname): 
        data = pd.read_csv(fname, sep=',')
        n = data['n'].values
        coefficient = data['clustering-coefficient'].values

        m, b = get_lin_log_regression_coefficients(n, coefficient)       
        plt.plot(x, m*x + b, label=f'{fname.rstrip(".csv")}: y ~ {round(m, 2)}x + {round(b, 2)}')

    
    x = np.array(range(2, 20))

    # diameter
    plot_diameter_regression("diameter.csv")
    plt.legend()
    plt.grid(which='both')
    plt.xticks(x)
    plt.yticks(np.arange(12))

    plt.savefig('diameter-regression.png', dpi = 100)
    plt.show()

    # clustering coefficient
    plot_coefficient_regression("clustering-coefficient.csv")
    plt.legend()
    plt.grid(which='both')
    plt.xticks(x)
    plt.yticks(np.arange(12))

    plt.savefig('coefficient-regression.png', dpi = 100)
    plt.show()


    plt.close()

linear_regression()
