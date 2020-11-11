#include <stdio.h>

int BSearchRecur(int * arr,int start,int end,int find){
	if(start>end) return -1;
	int mid = (start+end)/2;
	
	if(find == arr[mid]) return mid;
	if(find > arr[mid]) return BSearchRecur(arr,mid+1,end,find);
	else return BSearchRecur(arr,start,mid-1,find);
}

int main(void){
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int length = sizeof(arr)/sizeof(int);
	printf("%d \n",BSearchRecur(arr,0,length-1,0));
	return 0;
}
