#include "node.h"
#include "graph.h"
#include "random_generation_sample.cpp"
#include <map>
#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;

pair<Node, int> bfs(Graph graph, Node start_node) { // Helper function
    int num_nodes = graph.get_num_nodes();
    queue<int> Q;
    bool* reached = new bool[num_nodes];
    int* dist= new int[num_nodes];
    int furthest_distance = 0;
    Node furthest_node(start_node);

    for (int i = 0; i < num_nodes; ++i) {
        reached[i] = false;
        dist[i] = 0;
    }
    reached[start_node.id - 1] = true;
    Q.push(start_node.id);

    while (!Q.empty()) {
        Node n(Q.front());
        Q.pop();
        vector<Node> neighbor_list = graph.get_neighbors(n);

        for (Node neighbor : neighbor_list) {
            if (!reached[neighbor.id - 1]) {
                Q.push(neighbor.id);
                reached[neighbor.id - 1] = true;
                dist[neighbor.id - 1] = dist[n.id - 1] + 1;
            }
        }
    }
    
    for (int i = 0; i < num_nodes; ++i) { // Find the furthest node and its distance to start
        if (dist[i] > furthest_distance) {
            furthest_distance = dist[i];
            furthest_node = Node(i + 1);
        }
    }
    pair<Node, int> result_pair = make_pair(furthest_node, furthest_distance);
    return result_pair;
}

int get_diameter(Graph graph) { // Using heuristic idea 2
    int diameter = 0; 
    int num_nodes = graph.get_num_nodes();

    if (num_nodes > 1) {
        int farthest_distance = 0;
        
        mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();
        int random_start_index = randint(mt, 1, num_nodes);
        Node start_node(random_start_index);
        
        pair<Node, int> farthest = make_pair(start_node, farthest_distance);

        do {
            diameter = farthest.second;
            farthest = bfs(graph, farthest.first);
        } while (farthest.second > diameter);
    }
    return diameter;
}

float get_clustering_coefficient(Graph graph) { // TODO
    return 0.0;
}

map<int, int> get_degree_distribution(Graph graph) {
    map<int, int> result;
    int num_nodes = graph.get_num_nodes();

    for (int i = 1; i <= num_nodes; ++i) {
        Node n(i);
        int degree = graph.get_neighbors(n).size();
        result[degree] = result[degree] + 1;
    }
    return result;
}