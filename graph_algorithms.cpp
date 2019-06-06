#include "graph.h"
#include <iostream>
#include <map>

using namespace std;

int get_diameter(Graph graph) { // TODO
    return 0;
}

float get_clustering_coefficient(Graph graph) { // TODO
    return 0.0;
}

std::map<int, int> get_degree_distribution(Graph graph) {
    map<int, int> result;
    int num_nodes = graph.get_num_nodes();

    for (int i = 1; i <= num_nodes; ++i) {
        Node n(i);
        int degree = graph.get_neighbors(n).size();
        result[degree] = result[degree] + 1;
    }
    return result;
}