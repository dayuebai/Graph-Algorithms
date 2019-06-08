#include "project3.h"
#include "node.h"
#include "graph.h"
#include "graph.cpp"
#include "graph_algorithms.cpp"
#include "barabasi_albert.cpp"
#include <float.h>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

struct measurement {
    int n;
    float data;
};

measurement measure_diameter(int n, int reps, Graph graph) {
    float total_diameter = 0.0;

    for(int i = 0; i < reps; ++i) { // For each input size, do "reps" times runs. 
        total_diameter += get_diameter(graph);
    }

    measurement m;
    m.n = n;
    m.data = (float)total_diameter/reps;
    return m;
}

measurement measure_c(int n, int reps, Graph graph) {
    float total_c = 0.0;

    for(int i = 0; i < reps; ++i) {
        total_c += get_clustering_coefficient(graph);
    }

    measurement m;
    m.n = n;
    m.data = (float)total_c/reps;
    return m;
}

void create_file(string filename, string measurement) {
    ofstream f;
    f.open(filename, ios::trunc);
    f << "n," << measurement << "\n";
    f.close();
}

void add_data_to_file(measurement m, string filename) {
    ofstream f;
    f.open(filename, ios::app);
    f << m.n << "," << m.data << "\n";
    f.close();
}

int main() {
    create_file("diameter.csv", "diameter");
    create_file("clustering-coefficient.csv", "clustering-coefficient");

    // degree distribution
    for (int n = 1000; n <= 100000; n *= 10) {
        Graph graph = create_barabasi_albert_graph(n, 5); // Let d = 5

        map<int, int> distribution = get_degree_distribution(graph);
        ofstream f;
        f.open("degree-distribution" + to_string(n) + ".csv", ios::trunc);
        f << "degree" << "," << "number of vertices" << "\n";
        for(auto p : distribution) {
            f << p.first  << "," << p.second << "\n";
        }
        f.close();
    }

    for (int n = 4; n <= 131072; n *= 2) {
        Graph graph = create_barabasi_albert_graph(n, 5); // Let d = 5

        measurement d = measure_diameter(n, 5, graph);
        add_data_to_file(d, "diameter.csv");

        if (n <= 65536) {
            measurement c = measure_c(n, 5, graph);
            add_data_to_file(c, "clustering-coefficient.csv");
        }
    }
    return 0;
}
