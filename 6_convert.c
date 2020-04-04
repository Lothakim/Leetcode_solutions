#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * convert(char * s, int numRows);

int main(void)
{
    char *s = "PAYPALISHIRING";
    char *p = convert(s, 4);
    puts(p);

    return 0;
}

char * convert(char * s, int numRows)
{
    int len = strlen(s);
    char r[numRows][len];
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < len; j++)
        {
            r[i][j] = '0';
        }
    }
    
    char *p = s;
    int i = 0, j = 0, count = 1;
    while (*p != '\0')
    {
        int pos = count%(2*numRows-2);
        if (pos < numRows && pos > 0)
        {
            r[i][j] = *p;
            i++;
        }
        else
        {
            r[i][j] = *p;
            i--;
            j++;
        }
        p++;
        count++;
    }

    char *result = (char *)malloc(len*sizeof(char));
    p = result;
    for (int k = 0; k < numRows; k++)
    {
        for (int m = 0; m <= j; m++)
        {
            if (r[k][m] != '0')
            {
                *p++ = r[k][m];
            }
        }
    }
    p = '\0';
    
    return result;
}