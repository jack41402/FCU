#include"Node.h"
#include<cstdlib>

Node::Node(){
	elem=0;
	prev=NULL;//Initialize "prev" of the node to NULL
	next=NULL;//Initialize "next" of the node to NULL
}

Node::Node(int e){
	elem=e;
	prev=NULL;//Initialize "prev" of the node to NULL
	next=NULL;//Initialize "next" of the node to NULL
}


