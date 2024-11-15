// Queue application

#include <stdio.h>
#include <stdlib.h>
#include "queue_array.h"

int main(void) {
  Queue q; // Declare a queue.
  int cmd; // Command integer.
  int e; // Queue element.
  
  initial_queue(&q); // Initial queue q.
  while (1) { // Repeat the command until quit
    // Command list.
    printf("1. Enqueue     2. Dequeue      3. Head element\n");
    printf("4. Empty test  5. Print queue  6. Quit\n");
    printf("**** Enter a command: ");
    scanf("%d", &cmd); // Read a command.
    switch (cmd) {
      case 1: { // 1. Enqueue.
        printf("\nEnqueue operation.\n  Enter an enqueued element: ");
        scanf("%d", &e);
        enqueue(&q, e); // Enqueue.
        break;
      }
      case 2: { // 2. Dequeue.
        printf("\nDequeue operation.\n");
        e = dequeue(&q); // Dequeue.
        if (e!=-9999) printf("\n  Element %d has been dequeued.\n", e);
        break;
      }
      case 3: { // 3. Head element.
        e = head(q); // Get head element.
        if (e!=-9999) printf("\n  The head element is %d.\n", e);
        break;
      }
      case 4: { // 4. Empty test.
        if (is_empty(q)) printf("\n  The queue is empty.\n");
        else printf("\n  The queue is not empty.\n");
        break;
      }
      case 5: { // 5. Print queue.
        print_queue(q);
        break;
      }
      case 6: { // 6. Quit.
        return 0; // Return from the main program.
      }
      default: { // Incorrect command.
	    printf("Incorrect command.\n");
	  }
    };
    printf("\n****************************************************\n\n");
  }
}
