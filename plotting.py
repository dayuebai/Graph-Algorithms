import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import math
import scipy.interpolate as ip

def plot_diameter(fname):

    data = pd.read_csv(fname, sep=',')

    n = data['n'].values
    diameter = data['diameter'].values

    x = n
    y = diameter
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
    coefficient = data['clustering-coefficient'].values

    x = n
    y = coefficient
    plt.semilogx(x, y, basex = 2)

    plt.xlabel('N: number of vertices')
    plt.ylabel('C: clustering coefficient')
    plt.title('Clustering Coefficient-Vertices Graph')
    
    plt.savefig('coefficient.png', dpi = 100)
    plt.show()
    plt.close()

def plot_distribution(fname):

    data = pd.read_csv(fname, sep=',')

    degree = data['degree'].values
    n = data['number of vertices'].values

    x = degree
    y = n

    # log-log
    plt.loglog(x=x, y=y, basex=10, basey=10)
    plt.plot(x, y, label=fname.rstrip(".csv"))

    plt.xlabel('Degree')
    plt.ylabel('N: number of vertices')
    plt.title('Degree Distribution Graph (log-log scale)')
    
    plt.savefig(fname.strip("degree-").strip(".csv") + "-loglog.png", dpi = 100)
    plt.show()

    # lin-lin
    plt.plot(x, y, label=fname.rstrip(".csv"))

    plt.xlabel('Degree')
    plt.ylabel('N: number of vertices')
    plt.title('Degree Distribution Graph (lin-lin scale)')
    
    plt.savefig(fname.strip("degree-").strip(".csv") + "-linlin.png", dpi = 100)
    plt.show()

    plt.close()

plot_diameter("diameter.csv")
plot_c("clustering-coefficient.csv")
plot_distribution("degree-distribution1000.csv")
plot_distribution("degree-distribution10000.csv")
plot_distribution("degree-distribution100000.csv")