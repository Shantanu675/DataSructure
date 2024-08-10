// Binary search (Divide And Conquer)
#include<stdio.h>
void main(){

int arr[10], n, i, item, found, high, low, mid;

printf("Enter number of elements you want in an Array : ");
scanf("%d",&n);
printf("Enter Elements in Array\n");

for(i=0; i<n; i++){
	scanf("%d",&arr[i]);
}

printf("Enter item which you wanna to find in given array : ");
scanf("%d",&item);

low =0;
high =n-1;
mid = (low + high)/2;

for(i=0; i<n; i++){
	if(item == arr[mid]){
	printf("%d item found at %d position\n",item,mid+1);
	found++;
	break;
	}
	
	if(item < arr[mid]){
	high = mid-1;
	}
	
	if(item > arr[mid]){
	low = mid+1;
	}
	
	mid = (high+low)/2;
}

if(found == 0){
printf("%d item absent in given array\n",item);
}
}
