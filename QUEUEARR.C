#define max 20
#include<stdio.h>
#include<conio.h>
void main()
{
 int queue[max],x,i,item,front=-1,rear=-1;
 char ch;
 clrscr();
 printf("menu\n1.insert\n2.delete\n3.display\n4.exit\n");
 do
 {
  printf("enter choice");
  scanf("%d",&x);
  switch(x)
  {
   case 1:if(front==rear+1||(rear==max-1&&front==0))
   printf("overflow");
   else if(front==1)
   {
    front=0;
    rear=0;
    }
    else if(rear==max-1)
    rear=0;
    else
    rear=rear+1;
    printf("enter element to be inserted");
    scanf("%d",&item);
    queue[rear]=item;
    break;
    case 2:if(front==-1)
    printf("underflow");
    else
    {
     item=queue[front];
     if(front==rear)
     front=rear=-1;
     else if(front==max)
     front=0;
     else
     front=front+1;
     }
     printf("element deleted is %d",&item);
     break;
     case 3:printf("queue is\n");
     for(i=front;i<=rear;i++)
     printf("%d\t",queue[i]);
     break;
     case 4:printf("exit");
     break;
     default:printf("wrong choice");
     }
     printf("do u wnt to cntnu?");
     ch=getch();
     }
     while(ch=='y'||ch=='Y');
     getch();
     }