#include "node.h"
#include "graph.h"
#include <iostream>

using namespace std;

Graph::Graph(): node_number(0), edge_number(0) {}

Graph::Graph(int num_nodes): node_number(num_nodes), edge_number(0) {
    for (int i = 0; i < node_number; ++i) { // Initialize adajcent list
        int nid = i + 1;
        Node n(nid);
        vector<Node> node_neighbor_list;

        id_to_node_map[nid] = n;
        adjacent_list.push_back(node_neighbor_list);
    }
}

Graph::Graph(const Graph& agraph): node_number(agraph.node_number), edge_number(agraph.edge_number), id_to_node_map(agraph.id_to_node_map), adjacent_list(agraph.adjacent_list) {}

int Graph::get_num_nodes() {
    return node_number;
}

int Graph::get_num_edges() {
    return edge_number;
}

bool Graph::is_neighbor(Node u, Node v) {
    vector<Node> u_neighbor_list = adjacent_list.at(u.id - 1);

    for (int i = 0; i < u_neighbor_list.size(); ++i) {
        if (u_neighbor_list.at(i).id == v.id)
            return true;
    }
    return false;
}

vector<Node> Graph::get_neighbors(Node u) { 
    int node_id = u.id;
    return adjacent_list.at(node_id - 1);
}

map<int, Node> Graph::get_id_to_node_map() { 
    return id_to_node_map;
}

void Graph::add_edges(int uid, int vid) {
    ++edge_number;
    Node u(uid), v(vid);
    adjacent_list.at(uid - 1).push_back(v);
    adjacent_list.at(vid - 1).push_back(u);
}

Graph::~Graph() {}

// Construct a graph using num_nodes nodes and edges (ui, vi) for all i
// u and v will be the same length
// (ui, vi) are pairs of integers which can be mapped uniquely to (ui', vi'), pairs of Nodes
Graph make_graph(int num_nodes, std::vector<int> u, std::vector<int> v) {
    Graph result = Graph(num_nodes);
    int edge_number = u.size();

    for (int i = 0; i < edge_number; ++i) {
        result.add_edges(u.at(i), v.at(i));
    }
    return result;
}