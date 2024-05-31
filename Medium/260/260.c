#include <stdio.h>

int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int *out = (int *)malloc(2 * sizeof(int));
    int k = 0;
    int i = 0;
    int j;

    while (i < numsSize)
    {
        int flag = 0;
        j = 0;
        while (j < numsSize)
        {
            if (nums[i] == nums[j] && i != j)
            {
                flag = 1;
                break;
            }
            j++;
        }
        if (!flag)
            out[k++] = nums[i];
        i++;
    }
    *returnSize = 2;
    return out;
}

int main()
{
		int nums[] = {1, 2, 1, 3, 2, 5};
		int returnSize;
		int *out = singleNumber(nums, 6, &returnSize);
		printf("%d %d\n", out[0], out[1]);
		return 0;
}