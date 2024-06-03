#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Node.h"
#include "IQueue.h"
using namespace std;

int main(void) {
    
    srand(time(NULL)); // Initialize the random number generator with the current time
    
    int n = rand()%10+1; //n represents trial count;
    
    cout<<"Trial count: "<<n<<endl;
    IQueue que; // Create a queue object
    
    
    // Loop for each trial
    for(int i=0;i<n;i++){
        
        cout<<endl<<">>>> Trial "<<i+1<<": enqueue and dequeue operations"<<endl;
        
        int enq; // Variable to store the number of elements to enqueue
        enq=rand()%99+1; // Generate a random number of elements to enqueue
        
        for(int j=0;j<enq;j++){ // Loop to enqueue elements
            que.enqueue(rand() % 99 + 1); // Enqueue random elements
        }
        
        cout<<"Enqueue "<<enq<<" elements to the quene."<<endl;
        que.printHeadToTail();
        
        int deq;
        do{
            deq=rand()%99+1;
        }while(deq >= que.getSize()); // Ensure the number of elements to dequeue does not exceed the size of the queue
        
        for(int j=0;j<deq;j++){
            que.dequeue(); // Dequeue random number of elements from the queue
        }
        cout<<endl<<endl<<"Dequeue "<<deq<<" elements to the quene."<<endl;
        que.printHeadToTail();
        cout<<"-------------------------------------------------------------------"<<endl;
    }
    return 0;
}
