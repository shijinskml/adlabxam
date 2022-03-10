#include<stdio.h>
#include<conio.h>
void main()
{
int a[20];
int top=0,n,ch,item,i;
clrscr();
printf("enter the size of the array\n");
scanf("%d",&n);
do
{
 printf("\nchoice");
 printf("\n1.push\n2.pop\n3.exit\n");
 printf("enter the choice\n");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:if(top>=n)
  printf("stack overflow");
  else
  {
  printf("enter the element:");
  scanf("%d",&item);
  top=top+1;
  a[top]=item;
  }
  break;
  case 2:if(top<0)
  printf("stack underflow");
  else
  {
  a[top]='\0';
  top=top-1;
  }
  break;
  case 3:exit(0);
  break;
  default:printf("wrong choice");
  }
  if(top<0)
  printf("\nstack is empty");
  else
  {
  printf("\n stack is\n");
  for(i=top;i>0;i--)
  printf("%d\t",a[i]);
  }}
  while(ch!=3);
  getch();
  }
