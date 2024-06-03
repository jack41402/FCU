#ifndef NODE_H
#define NODE_H

class Node {
    friend class IQueue; // IQueue can access private members of Node

private:
    int elem; // Element held by the Node
    Node *prev; // Pointer to previous Node
    Node *next; // Pointer to next Node

public:
    Node(); // Default constructor declaration
    Node(int e); // Constructor with element declaration
};

#endif

