#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Node.h"
#include "IQueue.h"
using namespace std;

int main(void) {
    IQueue que;
    int count, i, j, enq_c, deq_c;//"count" represents trial count;
    
    srand(time(NULL));
    count=rand()%10+1;
    cout<<"Trial count: "<<count<<endl;
    IQueue();
    for(i=0;i<count;i++){
        cout<<endl<<">>>> Trial "<<i+1<<": enqueue and dequeue operations"<<endl;
        enq_c=rand()%99+1;
        for(j=0;j<enq_c;j++){
            que.enqueue(rand() % 99 + 1);
        }
        cout<<"Enqueue "<<enq_c<<" elements to the quene."<<endl;
        que.printHeadToTail();
        do{
            deq_c=rand()%99+1;
        }while(deq_c>=que.getSize());
        for(j=0;j<deq_c;j++){
            que.dequeue();
        }
        cout<<endl<<endl<<"Dequeue "<<deq_c<<" elements to the quene."<<endl;
        que.printHeadToTail();
        cout<<"-------------------------------------------------------------------"<<endl;
    }
    return 0;
}

