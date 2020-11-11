#include <stdio.h>

int BS(int * arr,int finding,int length){
	int start = 0;
	int end = length-1;
	int mid;
	while(start <= end){
		mid = (start+end)/2;
		if(finding == arr[mid])return mid;
		
		if(finding > arr[mid]) start = mid + 1;
		else end = mid - 1;
	}
	return -1;
}

int main(void){
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int length = sizeof(arr)/sizeof(int);
	printf("%d \n",BS(arr,3,length));
	printf("%d \n",BS(arr,9,length));
	printf("%d \n",BS(arr,13,length));
	return 0;
}
