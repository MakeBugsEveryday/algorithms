//
// Created by 梁宪松 on 2018-12-19.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*
 * 切分
 * */
int partition(int arr[], int lo, int hi) {

    // 左右扫描指针
    int left = lo;
    int right = hi + 1;
    // 锚点元素
    int v = arr[lo];

    while (true) {
        // 扫描左右，检查扫描是否需要交换元素

        // 从左到右查找大于 v 的元素
        while (arr[++left] < v) {
        }
//        if (left == hi) { break;}

        // 从右到左，查找小于 v 的元素
        while (arr[--right] > v) {
        }
//        if (right == lo) { break;}
        // 左右相遇，退出主循环
        if (left >= right) { break;}

        // 说明需要交换 left 和 right
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }

    // 交换 v 和 j 对应位置
    int temp = arr[right];
    arr[right] = v;
    arr[lo] = temp;

    // 返回切分点
    return right;
}


/*
 * 快速排序
 * 一种分治算法，将一个数组分成两个子数组，将两部分独立地排序，
 * 快排和归并排序是互补的
 * 如果左子数组和右子数组都是有序的，那么由左子数组，切分元素，和右子数组
 * 组成的结果数组也一定是有序的
 * */
void quickSort(int arr[], int lo, int hi) {

    if (hi <= lo) { return;}

    // 获取切分点
    int j = partition(arr, lo, hi); // 切分
    printf("point: %d, lo: %d, hi: %d\n ", j, lo, hi);
    quickSort(arr, lo, j-1); // 左半部分排序
    quickSort(arr, j+1, hi); // 右半部分排序
}

void demo() {

    int arr[] = {10,5,7,2,7,3,6, 8, 6,4,3,7,2,14,17,23};
    int arrCount = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, arrCount-1);
    for (int i = 0; i < arrCount; i++) {
        printf("%d ", arr[i]);
    }
}
