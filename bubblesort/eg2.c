#include<stdio.h>
void bubbleSort(int *r,int size)
{
int m,e,f,g;
m=size-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
if(r[f]<r[e])
{
g=r[e];
r[e]=r[f];
r[f]=g;
}
e++;
f++;
}
m--;
}
}
int main()
{
int x[5];
int y;
for(y=0;y<=4;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
bubbleSort(x,5);
for(y=0;y<=4;y++)
{
printf("%d\n",x[y]);
}
return 0;
}