#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int nums1tmp[nums1Size];
    for (int i = 0; i < m; i++)
    {
        nums1tmp[i] = nums1[i];
    }
    int *p1 = nums1tmp, *p2 = nums2, *p = nums1;
    int *p11 = p1+m;
    int *p22 = p2+n;
    while (p1<p11 || p2<p22)
    {
        if (*p1 < *p2)
        {
            *p++ = *p1++;
        }
        else
        {
            *p++ = *p2++;
        }
    }
}

int main(void)
{
    int nums1[] = {1,2,3,4,0,0,0};
    int nums2[] = {2,5,6};
    merge(nums1, 7, 4, nums2, 3, 3);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", nums1[i]);
    }
    return 0;
}