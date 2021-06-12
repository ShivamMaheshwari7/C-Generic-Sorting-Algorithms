#include<stdio.h>
#include<stdlib.h>
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
int *x;
int y,j;
printf("Enter your requirement : ");
scanf("%d",&j);
if(j<=0)
{
printf("Invalid requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*j);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers\n",j);
return 0;
}
for(y=0;y<j;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
bubbleSort(x,j);
for(y=0;y<j;y++)
{
printf("%d\n",x[y]);
}
free(x); // to avoid memory leaks
return 0;
}