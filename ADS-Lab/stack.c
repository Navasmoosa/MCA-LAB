 #include<stdio.h>
 int main()
 {
   int stack[100];
   int i, n,ch,val;
   int top=-1;
   printf("Enter size of queue:");
   scanf("%d",&n);
   if(n<=0)
  {
     printf("Invalid size!\n");
     return 1;
  }
  while(1)
  {
      printf("\nSTACK OPERATIONS\n");
      printf("1.PUSH\n2.POP\n3.DIPLAY\n4.EXIT\n");
      printf("Enter Your Choice:");
      scanf("%d",&ch);
 
      if(ch==1)
      {
          if(top==n-1)
          {
              printf("Stack Overflow\n");
          }
          else
          {
             printf("Enter value: ");
              scanf("%d",&val);
              top++;
              stack[top]=val;
             printf("%d Pushed\n",val);
        }
      }
     else if(ch==2)
     {
          if(top==-1)
         {
              printf("Stack Underflow\n");
          }
         else
         {       
      printf("%d Poped\n",stack[top]);
            top--;46         }
     }
    else if(ch==3)
    {
         if(top==-1)
         {
             printf("Stack is Empty");
         }
         else
         {
              printf("Stack Elments are: \n");
             for(i=top;i>=0;i--)
              {
                  printf("%d",stack[i]);
             }
        }
     }
 else if(ch==4)
      {
        break;
      }
      else
      {
          printf("Invalid Choice");
    }
  }
  return 0;
  }
 
 
 
