#include "project3.h"
#include "random_generation_sample.cpp"
#include "graph.h"
#include <set>
#include <iostream>

using namespace std;

Graph create_barabasi_albert_graph(int n, int d) { // implement in barabasi_albert.cpp only if your student ID is EVEN
    // TODO
    Graph result = make_graph(n, vector<int>{}, vector<int>{});
    int size = 2 * n * d;
    int M[size];
    set<pair<int, int>> edges;
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
        if (uid != vid && edges.find(edge) == edges.end()) {
            // cout << uid << " " << vid << endl;
            result.add_edges(uid, vid);
            edges.insert(edge);
            edges.insert(redge);
        }
    }
    return result;
}