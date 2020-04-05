#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char * longestCommonPrefix(char ** strs, int strsSize);

int main(void)
{
    char *str[] = {"flower","flow","floght"};
    char *s = longestCommonPrefix(str, 3);
    puts(s);
    return 0;
}

char * longestCommonPrefix(char ** strs, int strsSize)
{
    int len = strlen(strs[0]);
    for (int i = 0; i < len; i++)
    {
        char temp = strs[0][i];
        for ( int j = 1; j < strsSize; j++)
        {
            if (temp != strs[j][i])
            {
                char *s = (char *)malloc(i*sizeof(char));
                int k;
                for (k = 0; k < i; k++)
                {
                    s[k] = strs[0][k];
                }
                s[k] = '\0';
                return s;
            }
        }
    }
}