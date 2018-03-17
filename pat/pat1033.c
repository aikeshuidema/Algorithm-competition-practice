#include <stdio.h>
#include <stdlib.h>

int panduangeshu(int n)
{
    int ar[100] = {0};
    int tep = 0;
    int i = 0;

    for(i = 0; i < 4; i++)
    {
        if(ar[n % 10] == 0)
        {
            tep++;
            ar[n % 10] = 1;
        }
        n = n / 10;
    }

    return tep;
}
int main()
{
    int year = 0;
    int year2 = 0;
    int flag = 0;
    int n;

    scanf("%d %d", &year, &n);
    year2 = year;
    flag = panduangeshu(year);
    while(flag != n)
    {
        year++;
        flag = panduangeshu(year);
    }

    printf("%d %04d", year - year2, year);

    return 0;
}
