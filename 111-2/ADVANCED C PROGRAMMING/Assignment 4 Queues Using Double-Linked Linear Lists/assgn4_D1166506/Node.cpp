#include <cstdlib>
#include "Node.h"

Node::Node ()
{
    elem = 0 ;
    prev = NULL ;
    next = NULL ;
}

Node::Node (int e)
{
    elem = e ;
    prev = NULL ;
    next = NULL ;
}

