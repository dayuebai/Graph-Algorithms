#include "node.h"
#include "graph.h"
#include "random_generation_sample.cpp"
#include <map>
#include <queue>
#include <stack>
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

float get_clustering_coefficient(Graph graph) {
    int num_of_triangle = 0;
    int num_of_two_edge_path = 0;
    int degeneracy = 0;
    int num_nodes = graph.get_num_nodes();

    for (int i = 1; i <= num_nodes; ++i) { // Calculate number of 2-edge paths
        Node n(i);
        int degree = graph.get_neighbors(n).size();
        num_of_two_edge_path += degree * (degree - 1) / 2;
    }

    // Compute number of triangles in the graph
    stack<int> L;
    unordered_set<int> H;
    map<int, unordered_set<int>> D;
    int deg[num_nodes];
    vector<int> N[num_nodes];

    // Initialize array D, D[i] contains a list of the vertices 
    // v that are not already in L for which d_v = i
    for (int i = 1; i <= num_nodes; ++i) {
        Node n(i);
        int degree = graph.get_neighbors(n).size();
        D[degree].insert(i);
        deg[i - 1] = degree;
    }

    // Compute d-degeneracy ordering of vertices
    for (int j = 0; j < num_nodes; ++j) { // Repeat n(number of vertices) times
        int smallest_degree = -1;
        for (auto itr = D.begin(); itr != D.end(); ++itr) {
            if (!itr->second.empty()) {
                smallest_degree = itr->first;
                break;
            }
        }
        unordered_set<int> nodes = D[smallest_degree];
        degeneracy = max(degeneracy, smallest_degree);
        
        int vid = *nodes.begin();
        L.push(vid);
        H.insert(vid);

        D[smallest_degree].erase(vid);
        vector<Node> neighbors = graph.get_neighbors(Node(vid));
        
        for (int k = 0; k < neighbors.size(); ++k) {
            Node neighbor = neighbors[k];
            int nid = neighbor.id;
            if (H.find(nid) == H.end()) {
                int current_degree = deg[nid - 1]--;
                D[current_degree].erase(nid);
                D[current_degree - 1].insert(nid);
                N[vid - 1].push_back(nid);
            }
        }
    }

    // Triangle Counting algorithm
    while (!L.empty()) {
        int v = L.top();
        vector<int> n_v = N[v - 1];
        int size = n_v.size();
        for (int p = 0; p < size - 1; ++p) {
            for (int q = p + 1; q < size; ++q) {
                if (graph.is_neighbor(Node(n_v[p]), Node(n_v[q])))
                    ++num_of_triangle;
            }
        }
        L.pop();
    }
    cout << "Degeneracy: " << degeneracy << endl;
    cout << "Number of triangles: " << num_of_triangle << endl;
    cout << "Number of 2-edge paths: " << num_of_two_edge_path << endl;
    float clustering_coefficient = 3.0 * num_of_triangle / num_of_two_edge_path;
    return clustering_coefficient;
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