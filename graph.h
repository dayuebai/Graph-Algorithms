#ifndef GRAPH_H
#define GRAPH_H

#include "project3.h"
#include "node.h"
#include <map>

using namespace std;

class Graph : public AbstractGraph {
    // list all methods to override
    // list any other constructors, members, and member functions you may want to use
    public:
        Graph();

        Graph(int num_nodes);

        Graph (const Graph&);

        int get_num_nodes();

        int get_num_edges();

        bool is_neighbor(Node u, Node v);

        vector<Node> get_neighbors(Node u);

        map<int, Node> get_id_to_node_map();

        void add_edges(int ui, int vi);

        ~Graph();
    
    private:
        int node_number;
        int edge_number;
        vector<vector<Node>> adjacent_list;
        map<int, Node> id_to_node_map;
};

#endif // GRAPH_H