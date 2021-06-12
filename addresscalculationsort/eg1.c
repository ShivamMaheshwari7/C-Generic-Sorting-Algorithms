#include<stdio.h>
#include<stdlib.h>

typedef struct __linked_list_node
{
int num;
struct __linked_list_node *next;
}LinkedListNode;

typedef struct __linked_list
{
int size;
LinkedListNode *head;
}LinkedList;

void initLinkedList(LinkedList *linkedList)
{
linkedList->head=NULL;
linkedList->size=0;
}

void insertInLinkedList(LinkedList *linkedList,int num,int index)
{
LinkedListNode *node,*nd,*nde;
int j;
if(index>linkedList->size || index<0) return;
node=(LinkedListNode *)malloc(sizeof(LinkedListNode));
node->num=num;
node->next=NULL;
if(index==0)
{
node->next=linkedList->head;
linkedList->head=node;
}
else if(index==linkedList->size)
{
nd=linkedList->head;
for(j=1;j<linkedList->size;j++) nd=nd->next;
nd->next=node;
node->next=NULL;
}
else
{
nd=linkedList->head;
for(j=1;j<index;j++) nd=nd->next;
nde=nd->next;
nd->next=node;
node->next=nde;
}
linkedList->size++;
}

void clearLinkedList(LinkedList *linkedList)
{
LinkedListNode *node,*nd;
node=linkedList->head;
while(node!=NULL)
{
nd=node->next;
free(node);
node=nd;
}
linkedList->head=NULL;
linkedList->size=0;
}

int isLinkedListEmpty(LinkedList *linkedList)
{
return linkedList->size==0;
}

int findIndexToInsert(LinkedList *linkedList,int num)
{
LinkedListNode *node;
int index;
if(linkedList->head==NULL || linkedList->size==0) return 0;
node=linkedList->head;
index=0;
while(node!=NULL)
{
if(node->num>num) break;
node=node->next;
index++;
}
return index;
}

int removeFirstFromLinkedList(LinkedList *linkedList)
{
LinkedListNode *node;
int num;
node=linkedList->head;
linkedList->head=linkedList->head->next;
num=node->num;
free(node);
linkedList->size--;
return num;
}

int hash(int num,int digitNumber)
{
int e,f,y;
e=10;
f=1;
for(y=1;y<digitNumber;y++)
{
e=e*10;
f=f*10;
}
return (num%e)/f;
}

int main()
{
int x[10],y,largest,dc,num,key,index,j;
LinkedList buckets[10];
for(y=0;y<=9;y++) initLinkedList(&buckets[y]);
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
largest=x[0];
for(y=1;y<=9;y++)
{
if(x[y]>largest) largest=x[y];
}
dc=1;
num=largest;
while(num>9)
{
num=num/10;
dc++;
}
for(y=0;y<=9;y++)
{
num=x[y];
key=hash(num,dc);
index=findIndexToInsert(&buckets[key],num);
insertInLinkedList(&buckets[key],num,index);
}

/* retriving data from all linked list and put it into array */
j=0;
for(y=0;y<=9;y++)
{
while(!isLinkedListEmpty(&buckets[y]))
{
num=removeFirstFromLinkedList(&buckets[y]);
x[j]=num;
j++;
}
}

for(y=0;y<=9;y++) clearLinkedList(&buckets[y]);
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}