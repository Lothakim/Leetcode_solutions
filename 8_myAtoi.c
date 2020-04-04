#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int myAtoi(char * str);

int main(void)
{
    char *str = "4193 with words";
    int x = myAtoi(str);
    printf("%d", x);
    return 0;
}

int myAtoi(char * str)
{
    int len = strlen(str);
    char *p = str;
    int sign = 1;
    while (*p<'0' || *p>'9')
    {
        if (*p == '-')
        {
            sign = -1;
        }
        else
        {
            sign = 1;
        }
        p++;
    }
    int temp[len];
    int i = 0;
    while (*p!='\0')
    {
        if (('0'<=*p&&*p<='9') || *p==' ')
        {
            if (*p==' '){
            p++;
            }
            else{
            temp[i] = *p - '0';
            i++;
            p++;
            }
        }
        else
            break;
    }
    int result = 0;
    for (int k = i-1, m = 0; k >= 0; k--, m++)
    {
        int x = 1;
        for (int l = k; l > 0; l--)
        {
            x *= 10;
        }
        result += temp[m]*x;
    }
    return result*sign;
}