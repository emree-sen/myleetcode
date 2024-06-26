#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct pair {
    int num;
    int cnt;
};

int cmp(const void* a, const void* b) {
    return *(const int*) a - *(const int*) b;
}

bool isNStraightHand(int* nums, int numsSize, int k) {
    if(numsSize % k != 0) return false;
    if(k == 1) return true;

    qsort(nums, numsSize, sizeof(int), cmp);
    struct pair* arr = (struct pair*) calloc(numsSize, sizeof(struct pair));
    arr[0].num = nums[0];
    arr[0].cnt = 1;
    int idx = 0;
    for(int i = 1; i < numsSize; i++) {
        if(nums[i] != arr[idx].num) idx++;
        arr[idx].num = nums[i];
        arr[idx].cnt++;
    }
    int pos = 0;
    for(int i = 0; i < numsSize; i++) {
        while(pos < idx && arr[pos].cnt == 0) {
            pos++;
        }
        if(arr[pos].num == nums[i] && arr[pos].cnt > 0) {
            for(int j = 0; j < k; j++) {
                int tar = nums[i] + j;
                if(arr[pos+j].cnt > 0 && arr[pos+j].num == tar) {
                    arr[pos+j].cnt--;
                } else {
                    free(arr);
                    return false;
                }
            }
        }
    }
    free(arr);
    return true;
}

int main() {
		int nums[] = {1, 2, 3, 6, 2, 3, 4, 7, 8};
		int numsSize = 9;
		int k = 3;
		printf("%d\n", isNStraightHand(nums, numsSize, k));
		return 0;
}