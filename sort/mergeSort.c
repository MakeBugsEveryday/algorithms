//
// Created by 梁宪松 on 2018-12-19.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN(a,b) ((a)<(b)?(a):(b))
/*
 * 原地归并
 *
 * 将 [lo..mid] 和 [mid..hi] 进行归并成一个有序数组
 * */
// 辅助数组
int supportArr[] = {};
void merge(int arr[], int lo, int mid, int hi) {

    printf("merge :lo: %d, mid: %d, hi: %d \n", lo, mid, hi);

    int i = lo;
    int j = mid + 1;
    // 复制到辅助数组
    for (int k = lo; k <= hi; k++) {
        supportArr[k] = arr[k];
    }

    // 归并， 回写原数组
    for (int k = lo; k <= hi; k++) {


        if (i > mid) {
            // 左取尽
            arr[k] = supportArr[j++];
        } else if(j > hi) {
            // 右取尽
            arr[k] = supportArr[i++];
        } else if(supportArr[j] < supportArr[i]) {
            // 判断 arr[j] 和 arr[i] 大小， 如果 arr[j] 更小，
            arr[k] = supportArr[j++];
        } else {
            arr[k] = supportArr[i++];
        }
    }
}

/*
 * 自顶向下归并排序， 复杂度 NlogN，等价于后序遍历依赖树
 * */
void mergeSort_top2Bottom(int arr[], int lo, int hi) {


    if (hi <= lo) { return;}
    int mid = lo + (hi - lo)/2;
    printf("sort :lo: %d, mid: %d, hi: %d \n", lo, mid, hi);

    mergeSort_top2Bottom(arr, lo, mid);         // 将左半边排序
    mergeSort_top2Bottom(arr, mid + 1, hi);     // 将右半边排序
    merge(arr, lo, mid, hi);                    // 归并结果
}

/*
 * 至底向上归并排序
 * */
void mergeSort_bottom2Top(int arr[], int arrCount) {

    // 确立数组大小, 1, 2, 4, 8, 16,
    for (int i = 1; i < arrCount; i=2*i) {
        for (int lo = 0; lo < arrCount - i; lo+=2*i) {
            // 注意这里要处理边界情况
            merge(arr, lo, lo+i-1, MIN(arrCount-1, lo+i+i-1));
        }
    }
}

void demo() {

    int arr[] = {10,5,7,2,7,3,6, 8, 6,4,3,7,2,14, 17, 23};
    int arrCount = sizeof(arr) / sizeof(arr[0]);
    printf("arrCount: %d \n", arrCount);
    // 进行归并排序
//    mergeSort_top2Bottom(arr, 0, arrCount-1);
    mergeSort_bottom2Top(arr, arrCount);
    for (int i = 0; i < arrCount; i++) {
        printf("%d ", arr[i]);
    }
}
