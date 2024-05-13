// Specify the class nodes of single-linked linear list, Node.
class Node
{
	friend class CStack  ;
	public :
		char getNode() ;
	private :
		Node() ;
		Node *next ;
		char data ;
};
