class Node {
	friend class IQueue; 
	
	private:
		int elem;
		Node *prev; 
		Node *next;
		
	public:
		Node();  
		
		Node(int); 
}; 
