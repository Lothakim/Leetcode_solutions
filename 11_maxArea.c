#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int maxArea(int* height, int heightSize);

int main(void)
{
    int h[] = {1,8,6,2,5,4,8,3,7};
    int max = maxArea(h, 9);
    printf("%d", max);
    return 0;
}

int maxArea(int* height, int heightSize)
{
    int max = 0;
    for (int i = 0; i < heightSize; i++)
    {
        for (int j = i+1; j < heightSize; j++)
        {
            int h = height[i]>height[j]?height[j]:height[i];
            int temp = h*(j-i);
            max = max>temp?max:temp;
        }
    }
    return max;
}