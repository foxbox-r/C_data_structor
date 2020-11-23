#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int LData;
typedef struct _node{
	LData data;
	struct _node * next;
} Node;

typedef struct _linkedList{
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
	int (*comp)(LData d1,LData d2);
} LinkedList;

typedef LinkedList List;

void FInsert(List * plist, LData data){
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = plist->head->next;
	plist->head->next = newNode;
	
	(plist->numOfData);
}
void ListInit(List * plist){
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void SInsert(List * plist,LData data){
	
};

void LInsert(List * plist,LData data){
	if(plist->comp == NULL) FInsert(plist,data);
	else SInsert(plist,data);
} 


int LFirst(List * plist,LData * pdata){
	if(plist->head->next == NULL) return FALSE;
	plist->before = plist->head;
	plist->cur = plist->head->next;
	
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist,LData * pdata){
	if(plist->cur->next == NULL) return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	
	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist){
	Node * rpos = plist->cur;
	LData rdata = rpos->data;
	
	
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	
	free(rpos);
	return rdata;
}

int main(void){
	puts("start");
	List list;
	int data;
	ListInit(&list);
	
	LInsert(&list,1);
	LInsert(&list,2);
	LInsert(&list,3);
	LInsert(&list,4);
	
	if(LFirst(&list,&data)){
		printf("%d ",data);
		while(LNext(&list,&data))
			printf("%d ",data);
	}
	puts("");
	
	if(LFirst(&list,&data)){
		printf("remove %d \n",LRemove(&list));
		while(LNext(&list,&data))
			printf("remove %d \n",LRemove(&list));
	}
	puts("");
	
		if(LFirst(&list,&data)){
		printf("%d ",data);
		while(LNext(&list,&data))
			printf("%d ",data);
	}
	return 0;
}
