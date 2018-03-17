#include <stdio.h>
#include <stdlib.h>
int flag = 0;//遍历时用来判断
int indexs = 0;//遍
int n;
int zui[1100] = {0};

int puanduan(int shu[], int fir, int ends)
{
    int flagin = 0;
    int tepshu = fir;
    int i = fir;
    if(flag != 1 && fir <= ends)
    {
        if(fir == ends)
        {
            zui[indexs++] = shu[fir];
            return 0;
        }

        for(; i <= ends-1; i++)
        {
            if(shu[i+1] >= shu[fir])
            {
                tepshu = i;
                flagin = 1;
                break;
            }
        }

        for(i = tepshu+1; i <= ends && flagin != 0; i++)
        {
            if(shu[i] < shu[fir])
            {
                flag = 1;
                break;
            }
        }

        if(flag != 1)
        {
            if(flagin != 0)
                puanduan(shu, fir+1, tepshu);
            else
                puanduan(shu, fir+1, ends);
        }
        if(flag != 1 && flagin != 0)
        {
            puanduan(shu, tepshu+1, ends);
        }

        zui[indexs++] = shu[fir];

    }

    return 0;
}

int puanduan2(int shu[], int fir, int ends)
{
    int flagin = 0;
    int tepshu = fir;
    int i = fir;
    if(flag != 1 && fir <= ends)
    {
        if(fir == ends)
        {
            zui[indexs++] = shu[fir];
            return 0;
        }

        for(; i <= ends-1; i++)
        {
            if(shu[i+1] < shu[fir])
            {
                tepshu = i;
                flagin = 1;
                break;
            }
        }

        for(i = tepshu+1; i <= ends && flagin != 0; i++)
        {
            if(shu[i] >= shu[fir])
            {
                flag = 1;
                break;
            }
        }

        if(flag != 1)
        {
            if(flagin != 0)
                puanduan2(shu, fir+1, tepshu);
            else
                puanduan2(shu, fir+1, ends);
        }
        if(flag != 1 && flagin != 0)
        {
            puanduan2(shu, tepshu+1, ends);
        }

        zui[indexs++] = shu[fir];

    }

    return 0;
}

int main()
{
    int shu[1100] = {0};
    int i, k;
    int jinpan = 0;
    int jinpan2 = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &shu[i]);
        if(i == 0)
            jinpan = i;
        else
        {
            if(shu[i] < shu[0] && jinpan2 == 0)
            {
                jinpan = i;
                jinpan2 = 1;
            }
        }
    }

    if(n == 1)
    {
        printf("YES\n%d", shu[0]);
        return 0;
    }


    if(jinpan - 0 > 1)
        puanduan2(shu, 0, n-1);
    else
        puanduan(shu, 0, n-1);

    if(flag == 1)
        printf("NO");
    else
    {
        printf("YES\n%d", zui[0]);
        for(k = 1; k < n; k++)
        {
            printf(" %d", zui[k]);
        }
    }

    return 0;
}
