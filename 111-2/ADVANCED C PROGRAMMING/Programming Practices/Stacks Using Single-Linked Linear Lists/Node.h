class Node {
    friend class IStack; // Class IStack can access the private data elements.

private:
    int elem; // Data of a node.
    Node *next; // Link of a node.

public:
    Node(); // Default constructor.

    Node(int); // Constructor with data element.
}; 
