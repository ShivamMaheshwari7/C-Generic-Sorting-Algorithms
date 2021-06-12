#include<stdio.h>
#include<stdlib.h>
int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<=x[lb])
{
e++;
}
while(x[f]>x[lb])
{
f--;
}
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
}
}
return f;
}
void quickSort(int *x,int lb,int ub)
{
int pp;
if(ub<=lb) return;
pp=findPartitionPoint(x,lb,ub);
quickSort(x,lb,pp-1);
quickSort(x,pp+1,ub);
}
int main()
{
long int position;
int numbers,y,num1,num2,i,num[10],smallest,j,z;
FILE *f,*file,*files[10];
int *x;
char fileName[10];

f=fopen("data.d","rb");
fseek(f,0,SEEK_END);
position=ftell(f);
printf("Length of file in bytes : %d\n",position);
numbers=position/sizeof(int);
printf("Total numbers in file : %d\n",numbers);
num1=numbers/10;
num2=num1+(numbers%10);
fseek(f,0,SEEK_SET);
for(y=0;y<=9;y++)
{
if(y==0)
{
x=(int *)malloc(sizeof(int)*num2);
for(i=0;i<num2;i++)
{
fread((x+i),sizeof(int),1,f);
}
quickSort(x,0,num2-1);
sprintf(fileName,"file%d.d",y+1);
file=fopen(fileName,"wb");
for(i=0;i<num2;i++)
{
fwrite((x+i),sizeof(int),1,file);
}
}
else
{
x=(int *)malloc(sizeof(int)*num1);
for(i=0;i<num1;i++)
{
fread((x+i),sizeof(int),1,f);
}
quickSort(x,0,num1-1);
sprintf(fileName,"file%d.d",y+1);
file=fopen(fileName,"wb");
for(i=0;i<num1;i++)
{
fwrite((x+i),sizeof(int),1,file);
}
}
free(x);
fclose(file);
}
fclose(f);

file=fopen("datasort.d","wb");
for(y=0;y<=9;y++)
{
sprintf(fileName,"file%d.d",y+1);
files[y]=fopen(fileName,"rb");
}

/* logic to merge all 10 sorted files */
for(y=0;y<=9;y++)
{
fread(&num[y],sizeof(int),1,files[y]);
}

z=0;
while(1)
{
for(y=0;y<=9;y++)
{
if(files[y]!=NULL)
{
smallest=num[y];
break;
}
}
if(y==10) break;

i=y;
for(j=y+1;j<=9;j++)
{
if(num[j]<smallest && files[j]!=NULL)
{
smallest=num[j];
i=j;
}
}

if(feof(files[i]))
{
fclose(files[i]);
files[i]=NULL;
z++;
}
if(z==10) break;

if(files[i]!=NULL)
{
fwrite(&smallest,sizeof(int),1,file);
fread(&num[i],sizeof(int),1,files[i]);
}
}

fclose(file);
return 0;
}