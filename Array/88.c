#include <stdio.h>

// 你的 merge 函式 skeleton
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int len = m+n-1; //位置
    //printf("len1: %d\n", len1);
    int ptr1 = m-1;
    int ptr2 = n-1;

    if(n == 0){
        return;
    }

    while(ptr1>=0 && ptr2>=0){
        //有值再比
        if(nums1[ptr1] > nums2[ptr2]){
            nums1[len--]  = nums1[ptr1--];
        }else{
            nums1[len--] = nums2[ptr2--];
        }
    }
    /*
    nums1 的剩餘元素本來就在原位，不需要再覆蓋
    while(ptr1>=0){
        nums1[len--] = nums1[ptr1--];
    }
    */
    while(ptr2>=0){
        nums1[len--] = nums2[ptr2--];
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Test 1
    int nums1a[6] = {1, 2, 3, 0, 0, 0};
    int nums2a[3] = {2, 5, 6};
    merge(nums1a, 6, 3, nums2a, 3, 3);
    printf("Test 1 Merged: ");
    printArray(nums1a, 6);
    printf("true answer: 1 2 2 3 5 6\n");

    // Test 2: nums2 為空
    int nums1b[1] = {1};
    int nums2b[1] = {};   // 空陣列
    merge(nums1b, 1, 1, nums2b, 0, 0);
    printf("Test 2 Merged: ");
    printArray(nums1b, 1);
    printf("true answer: 1\n");

    // Test 3: nums1 為空
    int nums1c[1] = {0};  // 為空但有空間
    int nums2c[1] = {1};
    merge(nums1c, 1, 0, nums2c, 1, 1);
    printf("Test 3 Merged: ");
    printArray(nums1c, 1);
    printf("true answer: 1\n");

    return 0;
}
