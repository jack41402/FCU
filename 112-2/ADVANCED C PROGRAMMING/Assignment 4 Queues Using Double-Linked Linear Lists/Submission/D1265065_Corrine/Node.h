//
//  Node.h
//  Assignment_4_D1265065
//
//  Created by Corrine  on 2024/4/29.
//

#ifndef Node_h
#define Node_h

#include <iostream>
#include <string>
using namespace std;

class Node {
    friend class IQueue; // Class IStack can access the private data elements.
    
    private:
        int elem; // Data of a node.
        Node *prev; // Link of the previous node.
        Node *next; // Link of the next node node.
        
    public:
        Node(); // Default constructor. Set elem to 0 and prev and next to NULL.
        
        Node(int); // Constructor with data element. Set elem to the parameter value and prev and next to NULL.
};

#endif /* Node_hpp */
