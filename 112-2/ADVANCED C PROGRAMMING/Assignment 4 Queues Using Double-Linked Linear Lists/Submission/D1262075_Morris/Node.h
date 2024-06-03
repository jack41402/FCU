class Node {
	friend class IQueue; // Class IStack can access the private data elements.
	
	private:
		int elem; // Data of a node.
		Node *prev; // Link of the previous node. 
		Node *next; // Link of the next node node.
		
	public:
		Node(); // Default constructor.
		
		Node(int); // Constructor with data element. 
}; 
