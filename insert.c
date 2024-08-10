// Insertion 
#include<stdio.h>

int main()
{ 
int array [100]; int i, n, x, pos;

printf("Enter the number of elements array :");
scanf("%d", &n);
printf("Enter the elements \n");

for (i = 0; i < n; i++)
{
scanf("%d", &array[i]);
}

printf("Input array elements are: \n"); 

for (i=0; i<n; i++)
{
printf("%d\t", array[i]);
}

int m = array[n-1];

printf("\nEnter the new element to be in array :");
scanf("%d", &x);

printf("Enter the position where element insert :");
scanf("%d", &pos);

//shift all elements 1 position forward //where element needs to be inserted n=n+1;

for(i = n-1; i >= pos; i--)
{
array[i]=array[i-1];
}

array [pos-1]=x; //Insert the element

//print the new array
for (i = 0; i < n; i++)
{
printf("%d\t", array[i]);
}
printf("%d\t", m);
return 0;
}
