#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int puanduansushu(int n)
{
    int j = 2;
    int flag = 1;
    for(; j < n; j++)
        if(n % j == 0)
            flag = 0;

    return flag;
}

int in(int j,int rear, int qu[])
{
    int flag = 1;
    int i = 0;
    for(i = 0; i < rear; i++)
    {
        if(j == qu[i])
            flag = 0;
    }

    return flag;
}
int main()
{
    int n;
    int j, k;

    int qu[MAX] = {0};
    int rear = 0;

    scanf("%d", &n);
    qu[rear++] = 1;

    for(j = 1; j <= n; j++)
        qu[j] = 1;
    while(rear > 0)
    {
        int flag = 0;
        for(j = qu[rear]+1; j <= n; j++)
        {
            if(puanduansushu(j + qu[rear-1]))
            {
                if(in(j, rear, qu))
                {
                    qu[rear] = j;
                    flag = 1;
                    if(rear == n-1)
                    {
                        flag = 0;
                        if(puanduansushu(j + qu[0]))
                        {
                            flag = 1;
                        }
                    }
                }
            }

            if(flag == 1)
                break;
        }

        if(flag == 0)
        {
            qu[rear] = 1;
            rear--;
        }
        else if(flag == 1)
        {
            rear++;
            if(rear >= n)
            {
                for(k = 0; k < n; k++)
                {
                    printf("%d ", qu[k]);
                }
                printf("\n");
                qu[rear] = 1;
                rear--;
            }
        }
    }

    return 0;
}
