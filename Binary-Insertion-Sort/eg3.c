#include<stdio.h>
int main()
{
int x[10],si,ei,mid,num,size,y,lb,ub,j;
size=10;
lb=0;
ub=size-1;
for(y=0;y<size;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}

for(y=1;y<=ub;y++)
{
num=x[y];
si=lb;
ei=y-1;
while(si<=ei)
{
mid=si+(ei-si)/2;
if(num==x[mid])
{
si=mid;
break;
}
if(x[mid]>num) ei=mid-1;
else si=mid+1;
}
/* si has that position */
for(j=y-1;j>=si;j--) x[j+1]=x[j];
x[si]=num;
}

for(y=0;y<size;y++) printf("%d\n",x[y]);
return 0;
}