#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAX 10
// initilazing queue
int cqueue[MAX];
int rear = 0;
int front = 0;
// Function to check if the cqueue is empty
bool isEmpty() {
    return front==rear ;
}

// Function to check if the cqueue is full
bool isFull() {
    return (rear+1)%MAX == front;
}

void enqueue() // enqueue
{
int item;
if (isFull())
  printf("Queue Overflow \n");
else
 {
 printf("\nInset the element in queue : ");
 scanf("%d", &item);
 rear = (rear + 1)%MAX;
 cqueue[rear] = item;
 }
} /*End of insert()*/
void dequeue() //dequeue
{
     if(isEmpty())
     {
       printf("\nQueue Underflow \n");
       return ;
     }
    else
    {
    front = (front + 1) %MAX;
    printf("\nElement deleted from queue is : %d\n", cqueue[front]);
    }
} /*End of delete() */
void display()// print queue
{
int i;
    if (isEmpty() )
        printf("\nQueue is empty \n");
     else
    {  printf("\nQueue is : ");
        
        for (i = (front+1)%MAX; i != (rear+1)%MAX; i=(i+1)%MAX)
            printf("%d ", cqueue[i]);
        
        printf("\n");
        
    }
}
// Function to peek at the front item
int peek() {
    if (isEmpty()) {
        printf("Queue is empty. Nothing to peek.\n");
        return -1; // Error value
    } else {
        return cqueue[front+1];
    }
}

int main()
{
int choice;
while (1)
{
printf("\n1.Insert element to queue \n");
printf("2.Delete element from queue \n");
printf("3.Display all elements of queue \n");
printf("4.Peek \n");
printf("5.Quit \n");
printf("\nEnter your choice : ");
scanf("%d", &choice);
switch (choice)
{
case 1:
    enqueue();
    break;
case 2:
    dequeue();
    break;
case 3:
    display();
    break;
case 4:
    int x=peek();
    if(x!=-1) printf("\nfront element is=%d\n",x);
    break;
case 5:
    exit(1);

default:

printf("\nWrong choice \n");

} /*End of switch*/

} /*End of while*/
return 0;
} /*End of main()*/