#include<stdio.h>
#include<stdlib.h>
void selectionSort(int *data,int size);
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
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
selectionSort(x,req);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}
void selectionSort(int *data,int size)
{
int e,f,g,si,oep,iep;
oep=size-2;
iep=size-1;
e=0;
while(e<=oep)
{
si=e;
f=e+1;
while(f<=iep)
{
if(data[f]<data[si])
{
si=f;
}
f++;
}
g=data[si];
data[si]=data[e];
data[e]=g;
e++;
}
}