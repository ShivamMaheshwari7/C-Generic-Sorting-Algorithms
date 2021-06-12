#include<stdio.h>
void selectionSort(int *data,int size);
int main()
{
int x[5],y;
for(y=0;y<=4;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
selectionSort(x,5);
for(y=0;y<=4;y++)
{
printf("%d\n",x[y]);
}
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