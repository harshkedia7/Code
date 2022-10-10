#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	for(int j=1;j<n;j++)
	printf("i= %d j=%d ",i,j);
	return 0;
}
