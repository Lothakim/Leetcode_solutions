#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int removeDuplicates(int* nums, int numsSize);

int main(void)
{

}

int removeDuplicates(int* nums, int numsSize){
    if(!numsSize)
        return 0;
    int len = 0;
    for (int  i = 1; i <numsSize; i++)
    {
        if (nums[i] != nums[len])
        {
            len++;
            nums[len] = nums[i];
        }
    }
    return len+1;
}