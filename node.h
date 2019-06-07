#ifndef NODE_H
#define NODE_H

#include "project3.h"
#include <iostream>

using namespace std;

class Node {
    public:
        int id;

        Node () {
            id = 1;
        }

        Node (int ID) {
            id = ID;
        }

        Node (const Node& anode) {
            id = anode.id;
        }

        bool operator == (const Node& other) const { // const at the end of a function signature means that the function should assume 
            return id == other.id;                   // the object of which it is a member is const . 
        } 
};

#endif // NODE_H