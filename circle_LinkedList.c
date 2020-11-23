#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node{
	LData data;
	struct _node * next;
} Node;

typedef struct _circleLinkedList{
	Node * tail;
	Node * cur;
	Node * before;
	int numOfData;
} CList;

typedef CList List;

void ListInit(List * plist){
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsertFront(List * plist,LData data){
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	
	if(plist->tail == NULL){
		plist->tail = newNode;
		plist->tail->next = newNode;
	} else{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}
	++plist->numOfData;
}

int LFirst(List * plist,LData * pdata){
	if(plist->tail == NULL) return FALSE;
	plist->before = plist->tail;
	plist->cur = plist->before->next;
	
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist,LData * pdata){
	if(plist->tail == NULL) return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist){
	Node * rpos = plist->cur;
	LData rdata = rpos->data;
	
	if(rpos == plist->tail){
		if(plist->tail == plist->tail->next)
			plist->tail = NULL;
		else 
			plist->tail = plist->before;
	}
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	
	free(rpos);
	--(plist->numOfData);
	return rdata;
}

int LCount(List * plist){
	return plist->numOfData;
}

int main(void){
	List list;
	int data,i,nodeNum;
	ListInit(&list);
	
	LInsertFront(&list,1);
	LInsertFront(&list,2);
	LInsertFront(&list,3);
	LInsertFront(&list,4);
	
	if(LFirst(&list,&data)){
		printf("%d ",data);
		for(i=0;i<LCount(&list)*2-1;i++){
			if(LNext(&list,&data))
				printf("%d ",data);
		}
	}
	
	nodeNum = LCount(&list);
	printf("\ncount : %d \n",nodeNum);
	
	puts("");
	
	if(nodeNum != 0){
		LFirst(&list,&data);
		if(data%2 == 0)
			printf("remove %d \n",LRemove(&list));
		for(i=0;i<nodeNum-1;i++){
			LNext(&list,&data);
			if(data %2==0)
				printf("remove %d \n",LRemove(&list));
		}
	}
	
	if(LFirst(&list,&data)){
		printf("%d ",data);
		for(i=0;i<LCount(&list)-1;i++){
			if(LNext(&list,&data))
				printf("%d ",data);
		}
	}
	
	puts("");
	printf("\ncount : %d \n",nodeNum);
	
	if(nodeNum != 0){
		LFirst(&list,&data);
		if(data%2 != 0)
			printf("remove %d \n",LRemove(&list));
		for(i=0;i<nodeNum-1;i++){
			LNext(&list,&data);
			if(data %2!=0)
				printf("remove %d \n",LRemove(&list));
		}
	}
	
	LInsertFront(&list,10);
	
	if(LFirst(&list,&data)){
		printf("%d ",data);
		for(i=0;i<LCount(&list)-1;i++){
			if(LNext(&list,&data))
				printf("%d ",data);
		}
	}
	
	
	return 0;
}
