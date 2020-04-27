#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int strStr(char * haystack, char * needle);

int main(void)
{

}

int strStr(char * haystack, char * needle)
{
    int index = 0;
    char *p = haystack;
    while (*p != '\0')
    {
        char *q = p;
        char *t = needle;
        while (*t != '\0')
        {
            if (*t != *q)
            {
                break;
            }
            q++;
            t++;
        }
        if (*t == '\0')
        {
            return index;
        }
        p++;
        index++;
    }
    return -1;
}