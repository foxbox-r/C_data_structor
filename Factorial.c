#include <stdio.h>

int Factorial(int n){
	if(n == 0) return 1;
	return n*Factorial(n-1);
}

int shortFactorial(int n){
	return n == 0?1:n*shortFactorial(n-1);
}

int main(void){
	printf("%d \n",Factorial(9));
	printf("%d \n",shortFactorial(9));
	return 0;
}
