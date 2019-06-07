import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import math
import scipy.interpolate as ip

def plot_diameter(fname):

    data = pd.read_csv(fname, sep=',')

    n = data['n'].values
    data = data['diameter'].values

    x = n
    y = data
    plt.semilogx(x, y, basex = 2)

    plt.xlabel('N: number of vertices')
    plt.ylabel('Diameter')
    plt.title('Diameter-Vertices Graph')
    
    plt.savefig('diameter.png', dpi = 100)
    plt.show()
    plt.close()

def plot_c(fname):

    data = pd.read_csv(fname, sep=',')

    n = data['n'].values
    data = data['clustering-coefficient'].values

    x = n
    y = data
    plt.semilogx(x, y, basex = 2)

    plt.xlabel('N: number of vertices')
    plt.ylabel('C: clustering coefficient')
    plt.title('Clustering Coefficient-Vertices Graph')
    
    plt.savefig('coefficient.png', dpi = 100)
    plt.show()
    plt.close()

plot_diameter("diameter.csv")
plot_c("clustering-coefficient.csv")