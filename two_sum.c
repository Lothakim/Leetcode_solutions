#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* nums, int numsSize, int target){
    int i, j;
    int *result;
    for (i = 0; i < numsSize; i++){
        for (j = i+1; i < numsSize; j++)
        {
            if (nums[i]+nums[j]==target){
                result = (int *)malloc(2*sizeof(int));
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    return NULL;
}

int main(){
    int a[4] = {2,9,11,7};
    int target = 9;

    int *b = twoSum(a,4,9);

    for (int i = 0; i < 2; i++)
        printf("%d ",b[i]);
            
    return 0;
}