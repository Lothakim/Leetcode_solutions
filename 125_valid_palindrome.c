#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(char * s){
    char *p = s, *q = s;
    while(*q != '\0'){
        q++;
    }
    q--;
    while (p<q)
    {
        while (!(('0'<=*p&&*p<='9') || ('a'<=*p&&*p<='z') || ('A'<=*p&&*p<='Z')))
        {
            p++;
        }
        while (!(('0'<=*q&&*q<='9') || ('a'<=*q&&*q<='z') || ('A'<=*q&&*q<='Z')))
        {
            q--;
        }
        if (*p == *q || *p-32 == *q || *p+32 == *q)
        {
            p++;
            q--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    char *s = "A man, a plan, a canal: Panama";
    if (isPalindrome(s))
    {
        printf("isPalindrome");
    }
    else
    {
        printf("isnotPalindrome");
    }
}