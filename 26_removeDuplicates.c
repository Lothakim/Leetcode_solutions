#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int removeDuplicates(int* nums, int numsSize);

int main(void)
{

}

int removeDuplicates(int* nums, int numsSize)
{
    int len = 1;
    for (int  i = 1; i <numsSize; i++)
    {
        if (nums[i] != nums[i-1])
        {
            len++;
        }
    }
    return len;
}