#include "project3.h"
#include "graph.h"
#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void message(string s)
{
    cout << s << "\n";
}

void newline()
{
    cout << "\n";
}

bool vectors_have_same_nodes(vector<Node> nodes1, vector<Node> nodes2)
{
    sort(nodes1.begin(), nodes1.end(), [](const Node& u, const Node& v){return u.id < v.id;});
    sort(nodes2.begin(), nodes2.end(), [](const Node& u, const Node& v){return u.id < v.id;});
    return nodes1 == nodes2;
}

void run_tests()
{
    message(string("*******************************************")
            + string("\ntest start\n")
            + string("*******************************************"));
    
    message("0 nodes, 0 edges");
    message("Testing graph = Graph()");
    Graph graph;
    map<int, Node> id_to_node;
    message("Testing graph returns get_num_nodes() == 0");
    assert (graph.get_num_nodes() == 0);
    message("Testing graph returns get_num_edges() == 0");
    assert (graph.get_num_edges() == 0);

    newline();
    message("For each of the following graphs, we will use the shorthand (n, {(u1, v1), ... , (um, vm)}) to denote make_graph(n, vector<int>{u1, ... , um}, vector<int>{v1, ... , vm})");
    message("(n, {}) denotes make_graph(n, vector<int>{}, vector<int>{}), meaning the vectors are empty");
    message("Any vector<Node> will be shown sorted by node id");

    newline();
    message("0 nodes, 0 edges");
    message("Testing graph = (0, {})");
    graph = make_graph(0, vector<int>{}, vector<int>{});
    message("Testing graph returns get_num_nodes() == 0");
    assert (graph.get_num_nodes() == 0);
    message("Testing graph returns get_num_edges() == 0");
    assert (graph.get_num_edges() == 0);
    map<int, int> distribution_map = get_degree_distribution(graph);
    print_map(distribution_map);
    int diameter = get_diameter(graph);

    newline();
    message("1 node, 0 edges");
    message("Testing graph = (1, {})");
    graph = make_graph(1, vector<int>{}, vector<int>{});
    message("Testing graph returns get_num_nodes() == 1");
    assert (graph.get_num_nodes() == 1);
    message("Testing graph returns get_num_edges() == 0");
    assert (graph.get_num_edges() == 0);
    // distribution_map = get_degree_distribution(graph);
    // print_map(distribution_map)
    // diameter = get_diameter(graph);

    newline();
    message("2 nodes, 0 edges");
    message("Testing graph = (2, {})");
    graph = make_graph(2, vector<int>{}, vector<int>{});
    message("Testing graph returns get_num_nodes() == 2");
    assert (graph.get_num_nodes() == 2); 
    message("Testing graph returns get_num_edges() == 0");
    assert (graph.get_num_edges() == 0);
    id_to_node = graph.get_id_to_node_map(); 
    message("Testing graph returns is_neighbor(id_to_node[1], id_to_node[2]) == false");
    assert (graph.is_neighbor(id_to_node[1], id_to_node[2]) == false);
    message("Testing graph returns is_neighbor(id_to_node[2], id_to_node[1]) == false");
    assert (graph.is_neighbor(id_to_node[2], id_to_node[1]) == false);
    message("Testing graph returns get_neighbors(id_to_node[1]) == vector<Node>{}");
    assert (vectors_have_same_nodes(graph.get_neighbors(id_to_node[1]), vector<Node>{}));
    message("Testing graph returns get_neighbors(id_to_node[2]) == vector<Node>{}");
    assert (vectors_have_same_nodes(graph.get_neighbors(id_to_node[2]), vector<Node>{}));
    // distribution_map = get_degree_distribution(graph);
    // print_map(distribution_map)
    // diameter = get_diameter(graph);

    newline();
    message("2 nodes, 1 edge");
    message("Testing graph = (2, {(1, 2)})");
    graph = make_graph(2, vector<int>{1}, vector<int>{2});
    message("Testing graph returns get_num_nodes() == 2");
    assert (graph.get_num_nodes() == 2); 
    message("Testing graph returns get_num_edges() == 1");
    assert (graph.get_num_edges() == 1);
    id_to_node = graph.get_id_to_node_map(); 
    message("Testing graph returns is_neighbor(id_to_node[1], id_to_node[2]) == true");
    assert (graph.is_neighbor(id_to_node[1], id_to_node[2]) == true);
    message("Testing graph returns is_neighbor(id_to_node[2], id_to_node[1]) == true");
    assert (graph.is_neighbor(id_to_node[2], id_to_node[1]) == true);
    message("Testing graph returns get_neighbors(id_to_node[1]) == vector<Node>{id_to_node[2]}");
    assert (vectors_have_same_nodes(graph.get_neighbors(id_to_node[1]), vector<Node>{id_to_node[2]}));
    message("Testing graph returns get_neighbors(id_to_node[2]) == vector<Node>{id_to_node[1]}");
    assert (vectors_have_same_nodes(graph.get_neighbors(id_to_node[2]), vector<Node>{id_to_node[1]}));
    // distribution_map = get_degree_distribution(graph);
    // print_map(distribution_map)
    // diameter = get_diameter(graph);
    
    newline();
    message("3 nodes, 0 edges");
    message("Testing graph = (3, {})");
    graph = make_graph(3, vector<int>{}, vector<int>{});
    message("Testing graph returns get_num_nodes() == 3");
    assert (graph.get_num_nodes() == 3); 
    message("Testing graph returns get_num_edges() == 0");
    assert (graph.get_num_edges() == 0);
    id_to_node = graph.get_id_to_node_map(); 
    message("Testing graph returns is_neighbor(id_to_node[1], id_to_node[2]) == false");
    assert (graph.is_neighbor(id_to_node[1], id_to_node[2]) == false);
    message("Testing graph returns is_neighbor(id_to_node[1], id_to_node[3]) == false");
    assert (graph.is_neighbor(id_to_node[1], id_to_node[3]) == false);
    message("Testing graph returns is_neighbor(id_to_node[2], id_to_node[1]) == false");
    assert (graph.is_neighbor(id_to_node[2], id_to_node[1]) == false);
    message("Testing graph returns is_neighbor(id_to_node[2], id_to_node[3]) == false");
    assert (graph.is_neighbor(id_to_node[2], id_to_node[3]) == false);
    message("Testing graph returns is_neighbor(id_to_node[3], id_to_node[1]) == false");
    assert (graph.is_neighbor(id_to_node[3], id_to_node[1]) == false);
    message("Testing graph returns is_neighbor(id_to_node[3], id_to_node[2]) == false");
    assert (graph.is_neighbor(id_to_node[3], id_to_node[2]) == false);
    message("Testing graph returns get_neighbors(id_to_node[1]) == vector<Node>{}");
    assert (vectors_have_same_nodes(graph.get_neighbors(id_to_node[1]), vector<Node>{}));
    message("Testing graph returns get_neighbors(id_to_node[2]) == vector<Node>{}");
    assert (vectors_have_same_nodes(graph.get_neighbors(id_to_node[2]), vector<Node>{}));
    message("Testing graph returns get_neighbors(id_to_node[3]) == vector<Node>{}");
    assert (vectors_have_same_nodes(graph.get_neighbors(id_to_node[3]), vector<Node>{}));
    // distribution_map = get_degree_distribution(graph);
    // print_map(distribution_map)
    diameter = get_diameter(graph);
    // cout << "Diameter: " << diameter << endl;

    newline();
    message("3 nodes, 1 edge");
    message("Testing graph = (3, {(2, 3)})");
    graph = make_graph(3, vector<int>{2}, vector<int>{3});
    message("Testing graph returns get_num_nodes() == 3");
    assert (graph.get_num_nodes() == 3); 
    message("Testing graph returns get_num_edges() == 1");
    assert (graph.get_num_edges() == 1);
    id_to_node = graph.get_id_to_node_map(); 
    message("Testing graph returns is_neighbor(id_to_node[1], id_to_node[2]) == false");
    assert (graph.is_neighbor(id_to_node[1], id_to_node[2]) == false);
    message("Testing graph returns is_neighbor(id_to_node[1], id_to_node[3]) == false");
    assert (graph.is_neighbor(id_to_node[1], id_to_node[3]) == false);
    message("Testing graph returns is_neighbor(id_to_node[2], id_to_node[1]) == false");
    assert (graph.is_neighbor(id_to_node[2], id_to_node[1]) == false);
    message("Testing graph returns is_neighbor(id_to_node[2], id_to_node[3]) == true");
    assert (graph.is_neighbor(id_to_node[2], id_to_node[3]) == true);
    message("Testing graph returns is_neighbor(id_to_node[3], id_to_node[1]) == false");
    assert (graph.is_neighbor(id_to_node[3], id_to_node[1]) == false);
    message("Testing graph returns is_neighbor(id_to_node[3], id_to_node[2]) == true");
    assert (graph.is_neighbor(id_to_node[3], id_to_node[2]) == true);
    message("Testing graph returns get_neighbors(id_to_node[1]) == vector<Node>{}");
    assert (vectors_have_same_nodes(graph.get_neighbors(id_to_node[1]), vector<Node>{}));
    message("Testing graph returns get_neighbors(id_to_node[2]) == vector<Node>{id_to_node[3]}");
    assert (vectors_have_same_nodes(graph.get_neighbors(id_to_node[2]), vector<Node>{id_to_node[3]}));
    message("Testing graph returns get_neighbors(id_to_node[3]) == vector<Node>{id_to_node[2]}");
    assert (vectors_have_same_nodes(graph.get_neighbors(id_to_node[3]), vector<Node>{id_to_node[2]}));
    // distribution_map = get_degree_distribution(graph);
    // print_map(distribution_map)
    diameter = get_diameter(graph);
    // cout << "Diameter: " << diameter << endl;
    
    newline();
    message("3 nodes, 2 edges");
    message("Testing graph = (3, {(1, 2), (2, 3)})");
    graph = make_graph(3, vector<int>{1, 2}, vector<int>{2, 3});
    message("Testing graph returns get_num_nodes() == 3");
    assert (graph.get_num_nodes() == 3); 
    message("Testing graph returns get_num_edges() == 2");
    assert (graph.get_num_edges() == 2);
    id_to_node = graph.get_id_to_node_map(); 
    message("Testing graph returns is_neighbor(id_to_node[1], id_to_node[2]) == true");
    assert (graph.is_neighbor(id_to_node[1], id_to_node[2]) == true);
    message("Testing graph returns is_neighbor(id_to_node[1], id_to_node[3]) == false");
    assert (graph.is_neighbor(id_to_node[1], id_to_node[3]) == false);
    message("Testing graph returns is_neighbor(id_to_node[2], id_to_node[1]) == true");
    assert (graph.is_neighbor(id_to_node[2], id_to_node[1]) == true);
    message("Testing graph returns is_neighbor(id_to_node[2], id_to_node[3]) == true");
    assert (graph.is_neighbor(id_to_node[2], id_to_node[3]) == true);
    message("Testing graph returns is_neighbor(id_to_node[3], id_to_node[1]) == false");
    assert (graph.is_neighbor(id_to_node[3], id_to_node[1]) == false);
    message("Testing graph returns is_neighbor(id_to_node[3], id_to_node[2]) == true");
    assert (graph.is_neighbor(id_to_node[3], id_to_node[2]) == true);
    message("Testing graph returns get_neighbors(id_to_node[1]) == vector<Node>{id_to_node[2]}");
    assert (vectors_have_same_nodes(graph.get_neighbors(id_to_node[1]), vector<Node>{id_to_node[2]}));
    message("Testing graph returns get_neighbors(id_to_node[2]) == vector<Node>{id_to_node[1], id_to_node[3]}");
    assert (vectors_have_same_nodes(graph.get_neighbors(id_to_node[2]), vector<Node>{id_to_node[1], id_to_node[3]}));
    message("Testing graph returns get_neighbors(id_to_node[3]) == vector<Node>{id_to_node[2]}");
    assert (vectors_have_same_nodes(graph.get_neighbors(id_to_node[3]), vector<Node>{id_to_node[2]}));
    // distribution_map = get_degree_distribution(graph);
    // print_map(distribution_map)
    diameter = get_diameter(graph);
    // cout << "Diameter: " << diameter << endl;

    newline();
    message("3 nodes, 3 edges");
    message("Testing graph = (3, {(1, 2), (2, 3), (1, 3)})");
    graph = make_graph(3, vector<int>{1, 2, 1}, vector<int>{2, 3, 3});
    message("Testing graph returns get_num_nodes() == 3");
    assert (graph.get_num_nodes() == 3); 
    message("Testing graph returns get_num_edges() == 3");
    assert (graph.get_num_edges() == 3);
    id_to_node = graph.get_id_to_node_map(); 
    message("Testing graph returns is_neighbor(id_to_node[1], id_to_node[2]) == true");
    assert (graph.is_neighbor(id_to_node[1], id_to_node[2]) == true);
    message("Testing graph returns is_neighbor(id_to_node[1], id_to_node[3]) == true");
    assert (graph.is_neighbor(id_to_node[1], id_to_node[3]) == true);
    message("Testing graph returns is_neighbor(id_to_node[2], id_to_node[1]) == true");
    assert (graph.is_neighbor(id_to_node[2], id_to_node[1]) == true);
    message("Testing graph returns is_neighbor(id_to_node[2], id_to_node[3]) == true");
    assert (graph.is_neighbor(id_to_node[2], id_to_node[3]) == true);
    message("Testing graph returns is_neighbor(id_to_node[3], id_to_node[1]) == true");
    assert (graph.is_neighbor(id_to_node[3], id_to_node[1]) == true);
    message("Testing graph returns is_neighbor(id_to_node[3], id_to_node[2]) == true");
    assert (graph.is_neighbor(id_to_node[3], id_to_node[2]) == true);
    message("Testing graph returns get_neighbors(id_to_node[1]) == vector<Node>{id_to_node[2], id_to_node[3]}");
    assert (vectors_have_same_nodes(graph.get_neighbors(id_to_node[1]), vector<Node>{id_to_node[2], id_to_node[3]}));
    message("Testing graph returns get_neighbors(id_to_node[2]) == vector<Node>{id_to_node[1], id_to_node[3]}");
    assert (vectors_have_same_nodes(graph.get_neighbors(id_to_node[2]), vector<Node>{id_to_node[1], id_to_node[3]}));
    message("Testing graph returns get_neighbors(id_to_node[3]) == vector<Node>{id_to_node[1], id_to_node[2]}");
    assert (vectors_have_same_nodes(graph.get_neighbors(id_to_node[3]), vector<Node>{id_to_node[1], id_to_node[2]}));
    // distribution_map = get_degree_distribution(graph);
    // print_map(distribution_map);
    float C = get_clustering_coefficient(graph);
    cout << "Clusering coefficient: " << C << endl;

    newline();
    message("12 nodes, 13 edges");
    message("Testing graph = (12, {(1, 5), (2, 3), (3, 5), (4, 5), (4, 7), (4, 8), (5, 8), (6, 8), (7, 8), (7, 10), (7, 11), (8, 9), (11, 12)})");
    graph = make_graph(12, vector<int>{1, 2, 3, 4, 4, 4, 5, 6, 7, 7, 7, 8, 11}, vector<int>{5, 3, 5, 5, 7, 8, 8, 8, 8, 10, 11, 9, 12});
    distribution_map = get_degree_distribution(graph);
    print_map(distribution_map);
    diameter = get_diameter(graph);
    cout << "Diameter: " << diameter << endl;

    newline();
    message("5 nodes, 5 edges");
    message("Testing graph = (5, {(1, 2), (1, 3), (2, 3), (3, 4), (3, 5)})");
    graph = make_graph(5, vector<int>{1, 1, 2, 3, 3}, vector<int>{2, 3, 3, 4, 5});
    C = get_clustering_coefficient(graph);
    cout << "Clusering coefficient: " << C << endl;

    newline();
    message("6 nodes, 10 edges");
    message("Testing graph = (6, {(1, 2), (1, 3), (2, 3), (2, 4), (3, 4), (4, 5), (4, 6), (5, 6), (2, 5), (3, 6)})");
    graph = make_graph(6, vector<int>{1, 1, 2, 2, 3, 4, 4, 5, 2, 3}, vector<int>{2, 3, 3, 4, 4, 5, 6, 6, 5, 6});
    C = get_clustering_coefficient(graph);
    cout << "Clusering coefficient: " << C << endl;
    diameter = get_diameter(graph);
    cout << "Diameter: " << diameter << endl;

    Graph ab_graph = create_barabasi_albert_graph(10, 5);
    cout << "Number of edges: " << ab_graph.get_num_edges() << endl;
    distribution_map = get_degree_distribution(ab_graph);
    print_map(distribution_map);

    newline();
    message(string("+++++++++++++++++++++++++++++++++++++++++++")
            + string("\nall tests passed!\n")
            + string("+++++++++++++++++++++++++++++++++++++++++++"));
}
