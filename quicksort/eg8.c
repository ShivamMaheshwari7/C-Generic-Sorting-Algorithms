#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct __stack_node
{
void *data;
struct __stack_node *next;
}StackNode;

typedef struct __stack
{
int elementSize;
StackNode *top;
int size;
}Stack;

void initStack(Stack *stack,int elementSize)
{
stack->top=NULL;
stack->size=0;
stack->elementSize=elementSize;
}

int isEmpty(Stack *stack)
{
return stack->size==0;
}

void push(Stack *stack,const void *data)
{
StackNode *t;
t=(StackNode *)malloc(sizeof(StackNode));
t->data=(void *)malloc(stack->elementSize);
memcpy(t->data,data,stack->elementSize);
t->next=stack->top;
stack->top=t;
stack->size++;
}

void pop(Stack *stack,void *data)
{
StackNode *t;
t=stack->top;
stack->top=stack->top->next;
stack->size--;
memcpy(data,(const void *)t->data,stack->elementSize);
free(t->data);
free(t);
}

int findPartitionPoint(void *x,int lb,int ub,int es,int (*p2f)(void *,void *))
{
int e,f;
void *g;
g=(void *)malloc(es);
e=lb;
f=ub;
while(e<f)
{
while(e<ub && p2f(x+(e*es),x+(lb*es))<=0) e++;
while(p2f(x+(f*es),x+(lb*es))>0) f--;
if(e<f)
{
memcpy(g,(const void *)(x+(e*es)),es);
memcpy(x+(e*es),(const void *)(x+(f*es)),es);
memcpy(x+(f*es),(const void *)g,es);
}
else
{
memcpy(g,(const void *)(x+(lb*es)),es);
memcpy(x+(lb*es),(const void *)(x+(f*es)),es);
memcpy(x+(f*es),(const void *)g,es);
}
}
free(g);
return f;
}

void quickSort(void *x,int lowerBound,int upperBound,int es,int (*p2f)(void *,void *))
{
struct LBUB
{
int lb,ub;
};
struct LBUB lbub;
Stack stk;
int lb,ub,pp;
initStack(&stk,sizeof(struct LBUB));
lbub.lb=lowerBound;
lbub.ub=upperBound;
push(&stk,&lbub);
while(!isEmpty(&stk))
{
pop(&stk,&lbub);
lb=lbub.lb;
ub=lbub.ub;
pp=findPartitionPoint(x,lb,ub,es,p2f);
if(pp+1<ub)
{
lbub.lb=pp+1;
lbub.ub=ub;
push(&stk,&lbub);
}
if(lb<pp-1)
{
lbub.lb=lb;
lbub.ub=pp-1;
push(&stk,&lbub);
}
}
}

int intComparator(void *left,void *right)
{
return (*((int *)left))-(*((int *)right));
}

int main()
{
int *x,req,y;
printf("Enter requirement : ");
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
quickSort((void *)x,0,req-1,sizeof(int),intComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}