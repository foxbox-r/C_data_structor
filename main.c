#include <stdio.h>
#inclue "ArrayList.h"

int main(void){
	List list;
	ListInit(&list);
	
	ListInsert(&list,11);
	ListInsert(&list,22);
	ListInsert(&list,33);	
	ListInsert(&list,44);
	ListInsert(&list,55);
	
	LData d;
	
	printf("now List Length : %d",LCount(&list));
	
	return 0;
}
