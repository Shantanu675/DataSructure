//Bubble Sorting
#include<stdio.h>
void main(){

int arr[10],n,i,j,temp;

printf("Enter number of array : ");
scanf("%d",&n);

printf("Enter Array Elements :\n");
for(i=0; i<n; i++){
	scanf("%d",&arr[i]);
}

for(i=0; i<n-1; i++){
	for(j=0; j<n-1-i; j++){
		if(arr[j]>arr[j+1]){
		temp = arr[j];
		arr[j] = arr[j+1];
		arr[j+1] = temp;
		}
	
	}
}

printf("Sorted Elements : \n");
for(i=0; i<n; i++){
	printf("%d\n",arr[i]);
}

}
