#include "project3.h"
#include "graph.h"
#include <set>
#include <iostream>

using namespace std;

Graph create_barabasi_albert_graph(int n, int d) { // implement in barabasi_albert.cpp only if your student ID is EVEN
    // TODO
    Graph result = make_graph(n, vector<int>{1, 2, 3}, vector<int>{2, 3, 1}); // Assume n >= 3
    int size = 2 * n * d;
    int M[size];
    set<pair<int, int>> edges;
    edges.insert(make_pair(1, 2));
    edges.insert(make_pair(1, 3));
    edges.insert(make_pair(2, 3));
    mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();

    for (int v = 0; v < n; ++v) {
        for (int i = 0; i < d; ++i) {
            M[2 * (v * d + i)] = v;
            int r = get_uniform_int_generator(0, 2 * (v * d + i))(mt);
            M[2 * (v * d + i) + 1] = M[r];
        }
    }

    for (int i = 0; i < n * d; ++i) {
        int uid = M[2 * i] + 1;
        int vid = M[2 * i + 1] + 1;
        pair<int, int> edge = make_pair(uid, vid);
        pair<int, int> redge = make_pair(vid, uid);
        if (uid != vid && edges.find(edge) == edges.end() && edges.find(redge) == edges.end()) {
            result.add_edges(uid, vid);
        }
    }
    return result;
}