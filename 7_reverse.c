#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int reverse(int x);

int main(void)
{
    int num = -1082802800;
    int num_reversed = reverse(num);
    printf("%d", num_reversed);
    return 0;
}

int reverse(int x)
{
    int signal = x>0?1:-1;
    x = x>0?x:-x;
    
    int num[10] = {0};
    int i = 0, result = 0;
    while (x > 0)
    {
        num[i] = x%10;
        x /= 10;
        i++;
    }
    
    for (int k = i-1, m = 0; k >= 0; k--, m++)
    {
        int temp = 1;
        for (int l = k; l > 0; l--)
        {
            temp *= 10;
        }
        result += num[m]*temp;
    }
    return result*signal;
}