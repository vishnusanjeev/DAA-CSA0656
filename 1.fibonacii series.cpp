#include<stdio.h>
int fibonacii(int n){
	if(n<=1)
	return n;
	return fibonacii(n-1)+fibonacii(n-2);
}
int main(){
	printf("G.Vishnu Sanjeev-192210101\n");
	int n;
	printf("enter the required integer:\n");
	scanf("%d",&n);
	printf("fibonacii series\n");
	for(int i=0;i<n;i++)
    printf("%d ",fibonacii(i));
	return 0;
}
