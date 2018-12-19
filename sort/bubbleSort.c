//
// Created by 梁宪松 on 2018-12-18.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 冒泡排序
void bubbleSort(int arr[], int arrCount) {

    printf("arr count : %d\n", arrCount);
    for(int i = 0; i < arrCount-1; i++) {

        for (int j = 0; j < arrCount-i-1; j++) {
            // 每次和相邻的进行交换
            if (arr[j] > arr[j+1]) {
                // 交换 i 和 j
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


void demo() {

    int arr[] = {0,5,7,2,7,3,6};
    int arrCount = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, arrCount);
    for (int i = 0; i < arrCount; i++) {
        printf("%d ", arr[i]);
    }
}

