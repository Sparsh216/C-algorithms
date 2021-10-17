#include<stdio.h>
#include<conio.h>
void main()
{
    int s[20],d,sum=0,n,x[20],top=0,i,tot=0;
    clrscr();
    printf("\nEnter the number of values ");
    scanf("%d",&n);
    printf("\nEnter the values in ascending order ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    printf("\nEnter the sum ");
    scanf("%d",&d);
    x[top]=-1;
    printf("\nThe solution to the subset problem is ");
    while(top>=0)
    {
        x[top]=x[top]+1;
        sum=sum+s[x[top]];
        if(sum==d)
        {
            printf("\n");
            tot=tot+1;
            for(i=0;i<=top;i++)
            {
                printf("%d ",s[x[i]]);
            }
            sum=sum-s[x[top]];
        }
        else if(sum>d||top>=n)
        {
            sum=sum-s[x[top]];
            if(top>=1)
            {
                sum=sum-s[x[top-1]];
            }
            top=top-1;
        }
        else
        {
            top=top+1;
            x[top]=x[top-1];
        }
    }
    if(tot==0)
    {
        printf("not possible ");
    }
    getch();
}

