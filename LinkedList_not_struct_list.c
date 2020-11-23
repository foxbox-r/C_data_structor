#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int LData;
typedef struct _node{
	LData data;
	struct _node * next;
} Node;

int main(void){
	Node * head = NULL;
	Node * tail = NULL;
	LData data;
	while(1){
		printf("insert your number : ");
		scanf("%d",&data);
		
		if(data < 1)break;
		Node * newNode = (Node *)malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = NULL;
		if(head == NULL) head = newNode;
		else tail->next = newNode;
		tail = newNode;
	}
	
	if(head == NULL) return 0;
	else{
		Node * cur = head;
		printf("%d ",cur->data);
		while(cur->next != NULL){
			printf("%d ",cur->next->data);
			cur = cur->next;
		}
	}
	puts("");
	
	if(head == NULL) return 0;
	else{
		Node * delNode = head;
		Node * delNextNode = delNode->next;
		printf("remove %d \n",delNode->data);
		free(delNode);
		while(delNextNode != NULL){
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			printf("remove %d \n",delNode->data);
			free(delNode);
		}
	}
	
	
	return 0;
}
