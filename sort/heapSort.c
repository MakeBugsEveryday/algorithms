//
// Created by 梁宪松 on 2018-12-20.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


/*
 * 上浮
 * */
void swim(int arr[], int k) {

    while (k > 1 && k/2 < k) {

        // 交换 k 和 k/2
        k = k/2;

        int temp = arr[k/2];
        arr[k/2] = arr[k];
        arr[k] = temp;
    }
}

/*
 * 下沉
 *
 * 将子节点中较大的与父节点交换（构造大顶堆）
 * */
void sink(int arr[], int arrCount, int k) {

    printf("sink started: k: %d\n", k);
    while (2*k < arrCount) {
        int j = 2*k;
        printf("sinking: k: %d\n", j);
        // 查找合适的 j
        if (j < arrCount && arr[j] < arr[j+1]) {
            j++;
        }

        // 判断子节点是否大于父节点
        if (arr[k] >= arr[j]) {
            break;
        }

        // 交换 j 和 k
        int temp = arr[k];
        arr[k] = arr[j];
        arr[j] = temp;

        k = j;
    }
    printf("sink ended: k: %d\n", k);

}

/*
 * 堆排序
 *
 * 使用长度为 N+1 的数组， 我们不会使用 下标 为 0 的元素
 *
 * */
void heapSort(int arr[], int arrCount) {

    printf("arr count : %d\n", arrCount);

    // 构造堆， 将 父节点 与 较大元素交换
    for (int k = arrCount/2; k >= 1; k--) {
        sink(arr, arrCount, k);
    }

    // 排序过程
    int index = arrCount;
    while (index > 1) {

        // 交换 N 和 1 (即交换 第一个 和 最后一个元素)
        int temp = arr[1];
        arr[1] = arr[index];
        arr[index] = temp;

        index--;

        // 将下标为1元素下沉
        sink(arr, index, 1);
    }
}


void demo() {

    int arr[] = {-1,5,7,2,7,3,6, 8, 6,4,3,7,2,14,17,23};
    int arrCount = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, arrCount-1);
    for (int i = 0; i < arrCount; i++) {
        printf("%d ", arr[i]);
    }
}
