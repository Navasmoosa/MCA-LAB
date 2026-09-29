 #include<stdio.h>
   int main()
   {
       int i,n,ch,val;
       printf("Enter size of queue: ");
       scanf("%d",&n);
     if(n<=0)
     {
         printf("Invalid Size\n");
         return 1;
     }
      int queue[n];
      int f=-1,r=-1;
     while(1)
      {
         printf("\nMENU\n1.Enqueue\n2.Dequeue\n3.Display4.\nExit");
        printf("Enter Your Choice: ");
          scanf("%d",&ch);
         if(ch==1)
          {
              if(r==n-1)
              {
                  printf("Queue is Full");
             }
              else
              {
                  printf("Enter the element: ");
                  scanf("%d",&val);
                  r=r+1;
                  queue[r]=val;
                  if(f==-1)
                  {
                      f=0;
                  }
              }
          }
         else if(ch==2)
          {
             if(f==-1||f>r)
              {
                  printf("Queue is empty");
             }
             else
              {
                 printf("Deleted %d\n",queue[f]);
                 f=f+1;
             }
          }
          else if(ch==3)
          {
              if(f==-1||f>r)
              {
                 printf("Queue is empty");
              }
              else
             {
                  printf("Queue is:");
                 for(i=f;i<=r;i++)
                  {
                    printf("%d",queue[i]);
                  }
              }
      }
         else if(ch==4)/*Exit*/
          {
              break;
          }
      else
      {
          printf("Invalid Choice!\n");
      }
  }
  return 0;
  }
