#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x);

int main(void)
{
    int x = 1234321;
    if (isPalindrome(x))
    {
        printf("%d is a palindrome", x);
    }
    else
    {
        printf("%d isn't a palindrome", x);
    }
    return 0;
}

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    
    int temp[10];
    int i = 0;
    while (x > 0)
    {
        temp[i] = x%10;
        x /= 10;
        i++;
    }
    int k = i-1, m = 0;
    while (m < k)
    {
        if (temp[k] != temp[m])
        {
            return false;
        }
        k--;
        m++;
    }
    return true;
}