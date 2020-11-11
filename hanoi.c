#include <stdio.h>

void hanoi(int n,char start,char mid,char end){
	if( n ==1 ){
		printf("%d : %c => %c \n",n,start,end);
		return;
	}
	hanoi(n-1,start,end,mid);
	printf("%d : %c => %c \n",n,start,end);
	hanoi(n-1,mid,start,end);
}

int main(void){
	hanoi(3,'A','B','C');
	return 0;
}
