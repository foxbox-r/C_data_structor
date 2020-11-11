#include <stdio.h>

int Fibo(int n){
	if(n == 1) return 0;
	if(n == 2) return 1;
	return Fibo(n-1) + Fibo(n-2);
}

int main(void){
	int i;
	for(i=1;i<15;i++)
		printf("%d ,",Fibo(i));
	return 0;
}
