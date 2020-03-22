//
// Created by 梁宪松 on 2018-12-18.
//

#include <stdio.h>
#include <stdlib.h>

/*
 *  插入排序， 能够发现已经有序的部分， 对部分有序十分有效，适合小规模数组
 *  对于随机数据，复杂度为 N^2
 *  */
void insertSort(int arr[], int arrCount) {

    printf("arr count : %d\n", arrCount);

    for (int i = 1; i < arrCount; i++) {
        for (int j = i; j > 0; j--) {
            // 交换 j 与 j -1
            if (arr[j] < arr[j-1]) {
                // 交换 i 和 j
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void demo() {

    int arr[] = {10,5,7,2,7,3,6};
    int arrCount = sizeof(arr) / sizeof(arr[0]);
    insertSort(arr, arrCount);
    for (int i = 0; i < arrCount; i++) {
        printf("%d ", arr[i]);
    }
}

