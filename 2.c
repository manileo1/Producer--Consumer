#include<stdio.h>
#include<stdlib.h>

int m=1,full=0,empty=3,n=0;

int main()
{

    void prod();
    void cons();
    int wait(int);
    int signal(int);
    printf("1-Producer\n 2-Consumer\n 3-Quit\n");
    int ch;
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:    if((m==1)&&(empty!=0))
                        prod();
                    else
                        printf("Full- Can't Write\n");
                    break;
            case 2:    if((m==1)&&(full!=0))
                        cons();
                    else
                        printf("Empty- Can't Read\n");
                    break;
            case 3:
                    exit(0);
                    break;
        }
    }

    return 0;
}

int wait(int sig)
{
    sig=sig-1;
    return (sig);
}

int signal(int sig)
{
    sig=sig+1;
    return(sig);
}

void prod()
{
    m =wait(m); //set mutex
    full=signal(full);
    empty=wait(empty);
    n++;
    printf("\nWritten by Producer :%d \n",n);
    m=signal(m); // unset mutex
}

void cons()
{
    m=wait(m);
    full=wait(full);
    empty=signal(empty);
    printf("\nRead by Consumer :%d \n",n);
    n--;
    m=signal(m);
}
