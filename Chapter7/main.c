#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int main()
{
      int n, flag, flag2, flag3;
      int num;
      int sum = 1;

      scanf("%d", &n);

      flag = -100;
      flag2 = 0;
      flag3 = 0;
      if(n == 1)
      {
          scanf("%d", &sum);
          if(sum == 0)
            printf("%d", sum);
          n--;
      }
      while(n--)
      {
          scanf("%d", &num);
          if(num != 0)
          {
              sum *= num;
              if(num < 0)
              {
                  flag3++;
                  if(num > flag)
                    flag = num;
              }
              else
                flag2++;
          }
      }

      if(sum > 0)
        printf("%d", sum);
      else if(sum < 0)
      {
          if(flag2 == 0 && flag3 == 1)
            printf("0");
          else
            printf("%d", sum / flag);
      }

      return 0;
}
