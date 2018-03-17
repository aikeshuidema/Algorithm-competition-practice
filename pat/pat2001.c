#include <stdio.h>
#include <stdlib.h>
#define INF 4000
int finalcount = 0;
int minroadnum = 0;
int count = 0;//城市的数目
int countpeo = 0;//最大消防人数
int minroad = -1;
int citynum = 0;
int roadmark[510] = {0};//判断某个城市是否走过
int citypeople[510] = {0};//每个城市的人数
int indexs[510];//记录走过的城市的下标
int finalcity[510] = {0};
int roadfind(int fir, int ends, int ar[][510], int cp[], int roadnum2)//roadnum是路长
{
    int i, j;
    if(fir == ends)
        return -1;
    for(i = 0; i < citynum; i++)
    {
        if(ar[fir][i] == INF)
        {

        }
        else if(i != fir && i != ends && roadmark[i] != 1)
        {
            int flagcou = count;
            roadmark[i] = 1;
            indexs[count] = i;
            count++;
            roadfind(i, ends, ar, cp, roadnum2+ar[fir][i]);
            count = flagcou;
            roadmark[i] = 0;
        }
        else if(i == ends)
        {
            int peo = 0;
            int roadnum = 0;
            roadnum =roadnum2 + ar[fir][i];
            if(minroad == -1)
            {
                minroad = roadnum;
                minroadnum = 1;
                for(j = 0; j < count; j++)
                {
                    peo += citypeople[indexs[j]];
                    finalcity[j] = indexs[j];
                }
                finalcount = count;
                peo = peo + citypeople[ends];
                countpeo = peo;
            }
            else if(roadnum == minroad)
            {
                minroadnum++;
                for(j = 0; j < count; j++)
                {
                    peo += citypeople[indexs[j]];
                }

                if(peo + citypeople[ends] > countpeo)
                {
                    countpeo = peo+citypeople[ends];
                    finalcount = count;
                    for(j = 0; j < count; j++)
                    {
                        peo += citypeople[indexs[j]];
                        finalcity[j] = indexs[j];
                    }
                }
            }
            else if(roadnum < minroad)
            {
                minroad = roadnum;
                minroadnum = 1;
                for(j = 0; j < count; j++)
                {
                    peo += citypeople[indexs[j]];
                    finalcity[j] = indexs[j];
                }
                finalcount = count;
                peo = peo + citypeople[ends];
                countpeo = peo;
            }
        }
    }

    return 1;
}
int main()
{
    int ar[510][510];//道路长度数组
    int roadnum, first, ends;
    int i, j, k;

    scanf("%d %d %d %d", &citynum, &roadnum, &first, &ends);
    for(i = 0; i < citynum; i++)
    {
        scanf("%d", &citypeople[i]);
    }

    for(i = 0; i < citynum; i++)
        for(j = 0; j < citynum; j++)
            {
                ar[i][j] = INF;
                ar[j][i] = INF;
            }
    for(i = 0; i < roadnum; i++)
    {
        int h, l, num;
        scanf("%d %d %d", &h, &l, &num);
        ar[h][l] = num;
        ar[l][h] = num;
    }
    roadmark[first] = 1;
    roadmark[ends] = 1;
    k = roadfind(first, ends, ar, citypeople, 0);
    if(k == 0)
    {
        printf("1 %d", citypeople[ends]);
        return 0;
    }

    printf("%d %d", minroadnum, countpeo+citypeople[first]);
    printf("\n%d ", first);
    for(i = 0; i < finalcount; i++)
        printf("%d ", finalcity[i]);
    printf("%d", ends);

    return 0;
}
