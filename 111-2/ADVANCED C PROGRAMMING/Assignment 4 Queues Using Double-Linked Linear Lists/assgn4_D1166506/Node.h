class Node
{
    friend class IQueue ; // Class IQueue can access the private data elements.

private :
    int elem ; // Data of a node.
    Node *prev ; // Previous of a node.
    Node *next ; // Next of a node.

public :
    Node() ; // Default constructor.
    Node(int) ; // Constructor with data element.
} ;
