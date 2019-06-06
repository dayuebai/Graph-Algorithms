#include "graph.h"
#include <iostream>

using namespace std;



// construct a graph using num_nodes nodes and edges (ui, vi) for all i
// u and v will be the same length
// (ui, vi) are pairs of integers which can be mapped uniquely to (ui', vi'), pairs of Nodes
Graph make_graph(int num_nodes, std::vector<int> u, std::vector<int> v);