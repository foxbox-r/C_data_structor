#include <stdio.h>

#define LIST_LENTH 100
#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct __ArrayList{
	LData arr[LIST_LENTH];
	int numOfData;
	int curPosition;
} ArrayList;

typedef ArrayList List;

void ListInit(List * plist);
void ListInsert(List * plist,LData data);

int LFirst(List * plist,LData * pdata);
int LNext(List * plist , LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

int main(void){
	List list;
	ListInit(&list);
	
	ListInsert(&list,11);
	ListInsert(&list,22);
	ListInsert(&list,33);	
	ListInsert(&list,44);
	ListInsert(&list,55);
	
	LData d;
	
	printf("now List Length : %d \n",LCount(&list));
	
	LFirst(&list,&d);
	printf("%d \n",d);
	LNext(&list,&d);
	printf("%d \n",d);
	LNext(&list,&d);
	printf("%d \n",d);
	LNext(&list,&d);
	printf("%d \n",d);
	LNext(&list,&d);
	printf("%d \n",d);
	LNext(&list,&d);
	printf("%d \n",d);
	
	if(LFirst(&list,&d)){
		if(d == 33) LRemove(&list);
		while(LNext(&list,&d)){
			if(d == 33) LRemove(&list);	
		}
	}
	
	if(LFirst(&list,&d)){
		printf("%d\n",d);
		while(LNext(&list,&d)){
		printf("%d\n",d);
		}
	}
	return 0;
}


void ListInit(List * plist){
	plist->numOfData = 0;
	plist->curPosition = -1;
}

void ListInsert(List * plist,LData data){
	if(plist->numOfData > LIST_LENTH){
		puts("no more data memory.");
		return;
	}
	plist->arr[plist->numOfData] = data;
	++plist->numOfData;
}

int LFirst(List * plist,LData * pdata){
	if(plist->numOfData == 0){
		puts("no data");
		return FALSE;
	}
	
	plist->curPosition = 0;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

int LNext(List * plist , LData * pdata){
	if(plist->curPosition >= plist->numOfData-1){
		puts("no more data");
		return FALSE;
	}
	
	++plist->curPosition;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List * plist){
	int rpos = plist->curPosition;
	int length = plist->numOfData;
	
	LData rData = plist->arr[rpos];
	int i;
	for(i=rpos;i<length-1;i++){
		plist->arr[i] = plist->arr[i+1];
	}
	
	--plist->numOfData;
	--plist->curPosition;
	
	return rData;
}

int LCount(List * plist){
	return plist->numOfData;
}



