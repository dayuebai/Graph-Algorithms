#include "project3.h"
#include "node.h"
#include "graph.h"
#include "graph.cpp"
#include "graph_algorithms.cpp"
#include "barabasi_albert.cpp"
#include "tests.h"
#include <iostream>

int main() {
    message("=======================Start testing=======================");
    run_tests();
    message("=======================Finish testing=======================");
    
    return 0;
}
