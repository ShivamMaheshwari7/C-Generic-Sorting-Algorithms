#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// bubble sort function is being written by Mahesh in year 2020
/*
 ptr for storing base address
 cs represents collection size
 es represents size of one element
 p2f represents pointer to function for storing address of comparator function
*/
void bubbleSort(void *ptr,int cs,int es,int (*p2f)(void *,void *))
{
int e,f,m,w;
void *a,*b,*c;
c=(void *)malloc(es);
m=cs-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
a=ptr+(f*es);
b=ptr+(e*es);
w=p2f(a,b);
if(w<0)
{
/* for swapping */
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
e++;
f++;
}
m--;
}
free(c);  // to avoid memory leak
}
// following code is being written by Suresh in year 2022
struct Student
{
int rollNumber;
char name[21];
};
int studentComparator(void *left,void *right)
{
struct Student *s1,*s2;
s1=(struct Student *)left;
s2=(struct Student *)right;
return strcmp(s1->name,s2->name);
}
int main()
{
int req;
struct Student *students,*j;
int y;
printf("Enter requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
return 0;
}
students=(struct Student *)malloc(sizeof(struct Student)*req);
if(students==NULL)
{
printf("Unable to allocate memory for %d students\n",req);
return 0;
}
j=students;
for(y=0;y<req;y++)
{
printf("Enter roll number : ");
scanf("%d",&(j->rollNumber));
printf("Enter name : ");
scanf("%s",&(j->name));
j++;
}
bubbleSort(students,req,sizeof(struct Student),studentComparator);
for(y=0;y<req;y++)
{
printf("Roll number : %d, Name : %s\n",students[y].rollNumber,students[y].name);
}
free(students);
return 0;
}