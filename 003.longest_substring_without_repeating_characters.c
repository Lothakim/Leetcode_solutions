#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char * s);

int main(void)
{
    char *s = "bbtablud";
    int max = lengthOfLongestSubstring(s);

    printf("%d", max);

    return 0;
}

int lengthOfLongestSubstring(char * s)
{
    int len = strlen(s);
    int start_index = 0;
    int sub_str_len = 1;
    int max = 1;

    if (len == 0){
        return 0;
    }

    if (len == 1){
        return 1;
    }


    for (int i = 1; i < len; i++)
    {
        for (int j = start_index; j < i; j++)
        {
            if (s[i] != s[j])
                sub_str_len++;
            else
                start_index = j+1;
        }

        if (sub_str_len > max)
        {
            max = sub_str_len;
        }
        sub_str_len = 1;
    }
    
    return max;
}


int lengthOfLongestSubstring_failed(char * s)
{
    int len = strlen(s);
    int start_index = 0;
    int sub_str_len = 1;
    int max = 1;

    if(len == 0){
        return 0;
    }

    if (len == 1){
        return 1;
    }
    
    for (int i = 1; i < len; i++)
    {
        for (int j = start_index; j < i; j++)
        {
            if (s[i] == s[j])
            {
                start_index = j + 1;
                sub_str_len = sub_str_len - j;
                break;
            }
            else if (j == i - 1)
            {
                sub_str_len++;
            }             
        }

        if (sub_str_len > max)
        {
            max = sub_str_len;
        }
    }
    
    return max;
}