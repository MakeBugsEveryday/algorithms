//
// Created by 梁宪松 on 2018-12-18.
//
#include <stdio.h>
#include <stdlib.h>

// 选择排序， 平均需要比较 n^2 /2 次， 交换 N次
void selectionSort(int arr[], int arrCount) {

    printf("arr count : %d\n", arrCount);

    // 找到最小的与第 1，2，3.. 交换位置
    for (int i = 0; i < arrCount; i++) {
        // 记录最小元素的索引
        int min = i;
        for (int j = i + 1; j < arrCount; j++) {
            if (arr[min] > arr[j]) {
                // 交换 i 和 j
                min = j;
            }
        }

        if (min != i) {
            // 交换 i 与 min
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

void demo() {

    int arr[] = {10,5,7,2,7,3,6};
    int arrCount = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, arrCount);
    for (int i = 0; i < arrCount; i++) {
        printf("%d ", arr[i]);
    }
}
