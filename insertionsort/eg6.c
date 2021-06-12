#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertionSort(void *ptr,int lb,int ub,int es,int (*p2f)(void *,void *))
{
int y,z,ep;
void *block;
ep=ub;
block=(void *)malloc(es);
y=lb+1;
while(y<=ep)
{
memcpy(block,(const void *)(ptr+(y*es)),es);
z=y-1;
while(z>=lb && p2f(ptr+(z*es),block)>0)
{
memcpy(ptr+((z+1)*es),(const void *)(ptr+(z*es)),es);
z--;
}
memcpy(ptr+((z+1)*es),(const void *)block,es);
y++;
}
free(block);
}
int intComparator(void *left,void *right)
{
int *a,*b;
a=(int *)left;
b=(int *)right;
return (*a)-(*b);
}
int main()
{
int *x,y,req,start,end;
printf("Enter your requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
return 0;
}
printf("Enter start point : ");
scanf("%d",&start);
if(start<0 || start>=req)
{
printf("Invalid start point %d in case of collection of %d numbers\n",start,req);
return 0;
}
printf("Enter end point : ");
scanf("%d",&end);
if(end<start || end>=req)
{
printf("Invalid end point %d in case of start as %d and collection of %d numbers\n",end,start,req);
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers\n",req);
return 0;
}
y=0;
while(y<req)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
y++;
}
insertionSort(x,start,end,sizeof(int),intComparator);
y=0;
while(y<req)
{
printf("%d\n",x[y]);
y++;
}
free(x);
return 0;
}