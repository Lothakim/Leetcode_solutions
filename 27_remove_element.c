#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int removeElement(int* nums, int numsSize, int val);

int main(void)
{

}

int removeElement(int* nums, int numsSize, int val)
{
    int len = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[len] = nums[i];
            len++;
        }
    }
    return len;
}