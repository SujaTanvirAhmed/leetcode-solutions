#include <stdio.h>

int removeElement(int *nums, int numsSize, int val);
void printArray(int *array, int size);

int main(void)
{
    int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int k;
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("\nBefore operations:\n");
    printArray(nums, size);

    k = removeElement(nums, size, val);
    
    printf("\nAfter operations:\n");
    printf("k = %d\n", k);
    printArray(nums, size);

    return 0;
}

int removeElement(int *nums, int numsSize, int val)
{
    int i, j;
    for (i = 0; i < numsSize; i++)
    {
        if (*(nums + i) == val)
        {
            for (j = i + 1; j < numsSize; j++)
            {
                *(nums + j - 1) = *(nums + j);
            }
            i--;
            numsSize--;
        }
    }
    return numsSize;
}

void printArray(int *array, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d", *(array + i));
        if (i == size - 1)
            printf("\n");
        else
            printf(" ");
    }
}