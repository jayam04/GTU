#include <stdio.h>
#include <stdbool.h>



struct Queue {
	int first;
	int last;
	int array[5];
};

int enqueue(struct Queue *q, int insertElement) {
	if((q->last + 1) % 5 == q->first && q->last != -1){
		return 1;
	}

	q->array[((q->last) + 1) % 5] = insertElement;
	(q->last) = (q->last + 1) % 5;
	
	return 0;
}

int dequeue(struct Queue *q, int *removedElement) {
    if(q->last == -1) {
        return 1;
    }
	*removedElement = q->array[q->first];
	q->array[q->first] = '\0';

    if(q->first == q->last){
        q->last = -1;
        q->first = 0;
        return 0;
    }

	(q->first)++;
	return 0;

}

int display(struct Queue *q) {
    if(q->last == -1) {
        printf("empty!!\n");
        return 1;
    }

    if (q->last >= q->first) {
        for(int i = q->first; i <= (q->last); i++) {
            printf("%d ", q->array[i]);
        }
        printf("\n");
        return 0;
    }

    else {
        for(int i = q->first; i <= (q->last) + 5; i++) {
            printf("%d ", q->array[i % 5]);
        }
        printf("\n");
        return 0;
    }
    
}


int main(){
	// initiate queue
	struct Queue queue;
	queue.last = -1;
    queue.first = 0;
	for (int i = 0; i < 5; i++) {
		queue.array[i] = '\0';
	}

	printf("empty queue created!\n\n");
    
    printf("tasks I can do: \n");
    printf("1  insert\n");
    printf("2  delete\n");
    printf("3  display\n");
    printf("0  exit\n");

	int input;
	while(true) {
		printf("\n");
		printf("what would you like to do? ");
        scanf("%d", &input);
        switch(input) {
			case 0:
			return 0;
			
			case 1:
			printf("enter character to insert: ");
			int insertElement;
			scanf("%d", &insertElement);
			int insertStatus = enqueue(&queue, insertElement);
			if(!insertStatus) {
				printf("%d inserted sucessfilly\n", insertElement);
			}
			else if(insertStatus == 1){
				printf("queue full element not inserted!!\n");
			}
			break;

			case 2:
			printf("deleting element!!\n");
			int removedElement;
			int deleteStatus = dequeue(&queue, &removedElement);
			if (deleteStatus == 1) {
				printf("queue is empty!!\n");
				break;
			}
			printf("%d removed from queue!!\n", removedElement);
			break;

			case 3:
			display(&queue);
			break;
			
		}
	}
	return(0);
}