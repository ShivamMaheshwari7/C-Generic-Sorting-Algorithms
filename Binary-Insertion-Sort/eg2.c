/* finding position for num so that after insertion of num at that position, array is sorted */
#include<stdio.h>
int main()
{
int x[]={120,135,140,152,170,210,335,337,375,410,250};
int si,ei,mid,num,size,y;
size=11;
si=0;
ei=size-2;

num=x[size-1];  /* Last element of array */

while(si<=ei)
{
mid=si+(ei-si)/2;
if(x[mid]==num)
{
si=mid;
break;
}
if(x[mid]>num) ei=mid-1;
else si=mid+1;
}

/* si has that position */

for(y=size-2;y>=si;y--) x[y+1]=x[y];
x[si]=num;

for(y=0;y<size;y++) printf("%d\n",x[y]);
return 0;
}