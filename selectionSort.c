// Selection Sorting 
#include<stdio.h>
void main(){

int arr[10],n,i,j,temp,pos;

printf("Enter number of array : ");
scanf("%d",&n);

printf("Enter Array Elements :\n");
for(i=0; i<n; i++){
	scanf("%d",&arr[i]);
}

for(i=0; i<n-1; i++){
	pos =i;
	for(j=i+1; j<n; j++){
		if(arr[pos]>arr[j]){
		pos = j;
		}
	}
	temp = arr[i];
	arr[i] = arr[pos];
	arr[pos] = temp;
	}
	
printf("Sorted Elements : \n");
for(i=0; i<n; i++){
	printf("%d\n",arr[i]);
}

}
