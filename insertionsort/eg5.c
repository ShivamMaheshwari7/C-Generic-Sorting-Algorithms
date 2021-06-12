#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertionSort(void *ptr,int cs,int es,int (*p2f)(void *,void *))
{
int y,z,ep;
void *block;
ep=cs-1;
block=(void *)malloc(es);
y=1;
while(y<=ep)
{
memcpy(block,(const void *)(ptr+(y*es)),es);
z=y-1;
while(z>=0 && p2f(ptr+(z*es),block)>0)
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
int *x,y,req;
printf("Enter your requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
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
insertionSort(x,req,sizeof(int),intComparator);
y=0;
while(y<req)
{
printf("%d\n",x[y]);
y++;
}
free(x);
return 0;
}