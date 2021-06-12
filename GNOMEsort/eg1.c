#include<stdio.h>
int main()
{
int x[10],y,size,j,g;
size=10;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}

j=0;
while(j<size)
{
if(j==0) j++;
if(x[j]<x[j-1])
{
g=x[j];
x[j]=x[j-1];
x[j-1]=g;
j--;
}
else j++;
}

for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}