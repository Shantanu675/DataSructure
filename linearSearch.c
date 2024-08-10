// Linear Search
#include<stdio.h>
void main(){

int arr[10], n, i, item, pos, found=0;

printf("Enter number of elements you want in an Array : ");
scanf("%d",&n);
printf("Enter Elements in Array\n");

for(i=0; i<n; i++){
	scanf("%d",&arr[i]);
}

printf("Enter item which you wanna to find in given array : ");
scanf("%d",&item);

for(i=0; i<n; i++){
	if(item == arr[i]){
	pos = i;
	printf("%d item find at %d position\n",item,pos+1);
	found++;
	}
}

if(found == 0){
printf("%d item absent in given array\n",item);
}
}
