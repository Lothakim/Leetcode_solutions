#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *longestPalindrome(char *s);
int is_Palindrome(char *s, int start, int end);

int main(){
    char *s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char *result = longestPalindrome(s);
    puts(result);

}

char *longestPalindrome(char *s)
{
    int len = strlen(s);
    int start = 0;
    int end = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if (is_Palindrome(s, i ,j))
            {
                if (j-i > end-start)
                {
                    start = i;
                    end = j;
                }
            }
        }
    }

    char *re = (char *)malloc(sizeof(char)*(end-start+2));
    char *p = re;
    for (int i = start; i <= end; i++)
    {
        *p++ = s[i];
    }
    *p = '\0';

    return re;
}

int is_Palindrome(char *s, int i, int j)
{
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            return 0;
        }   
    }
    return 1;
}