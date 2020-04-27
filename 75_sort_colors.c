#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void sortColors(int* nums, int numsSize);

int main(void){
    int num[] = {2,0,2,1,1,0};
    sortColors(num, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ",num[i]);
    }
    
}

void sortColors(int* nums, int numsSize)
{
    int count[3] = {0};
    int *p = nums;
    while (p < nums+numsSize)
    {
        count[*p++]++;
    }
    p = nums;
    for (int i = 0; i < 3; i++)
    {
        int temp = 0;
        while (temp++ < count[i])
        {
            *p++ = i;
        }
    }
}