#include <stdio.h>

struct Node{
	int data;
	struct Node *next;
};
struct Node *top = NULL;
void push(){
	int value;
	struct Node *newNode;
	newNode = (struct Node *)malloc(sizeof(struct Node));
	if (newNode == NULL){
		printf("Stack Overflow!\n");
		return;
	}
	printf("Enter value to push: ");
	scanf("%d", &value);
	newNode->data = value;
	newNode->next = top;
	top = newNode;
	printf("%d pushed onto the stack.\n", value);
}
void pop(){
	struct Node *temp;
	if (top == NULL){
		printf("Stack Underflow!\n");
		return;
	}
	temp = top;
	printf("%d poped from the stack.\n", top->data);
	top = top->next;
	free(temp);
}
void peek(){
	if (top == NULL){
		printf("Stack is empty.\n");
		return;
	}
	printf("Top element is: %d\n", top->data);
}
void display(){
	struct Node *temp;
	if (top == NULL){
		printf("Stack is empty.\n");
		return;
	}
	temp = top;
	printf("Stack elements are:\n");
	
	while (temp != NULL){
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}
int main(){
	int choice;
	do{
		printf("\n------STACK MENU------\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				printf("Program terminated\n");
				break;
			default:
				printf("Invalid choice!.\n");
		}
	}while (choice != 5);
	return 0;
}