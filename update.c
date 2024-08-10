// Updation
#include<stdio.h>
int main()
{
  int i,t,a[10],n,m,s,j=0,b[10];
  printf("Enter the size of Array : ");
  scanf("%d",&n);
  printf("Enter the Values : ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("Given values are : ");
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
  printf("\nEnter the index to be update : ");
  scanf("%d",&t);
  printf("\nEnter the value to be update : ");
  scanf("%d",&s);
  for(i=0;i<n;i++)
  {
    if(i==t)
    {
       a[i]=s;
    }
  }
  printf("\nUpdated value is:");
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
  return 0;
}
    
