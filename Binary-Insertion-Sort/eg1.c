/* Binary Search Implementation */
#include<stdio.h>
int main()
{
int x[]={120,135,140,152,170,210,335,337,375,410,520};
int si,ei,mid,num;
si=0;
ei=10;

printf("Enter a number to search : ");
scanf("%d",&num);

while(si<=ei)
{
mid=si+(ei-si)/2;
if(x[mid]==num) break;
if(x[mid]>num) ei=mid-1;
else si=mid+1;
}

if(si>ei)
{
printf("%d not found\n",num);
}
else
{
printf("%d found at index %d\n",num,mid);
}
return 0;
}