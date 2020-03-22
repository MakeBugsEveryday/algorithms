//
// Created by 梁宪松 on 2018-12-19.
//

/*
 *  希尔排序：基于插入排序的快速排序算法，交换不相邻的元素
 *  核心思想：使数组任意间隔h的元素都有序
 *  1/2(3^k - 1) ，从 N/3 递减至 1
 *
 *  数组越大，优势越大
 *  希尔排序时间复杂度的下界是n*log2n，上界 n^(3/2)
 *  */
void shellSort(int arr[], int arrCount) {

    printf("arr count : %d\n", arrCount);

    int offset = 1;
    // 确立递增数列： 1， 4， 13， 40， 121
    while (offset < arrCount/3) { offset = (3 * offset + 1);}
    printf("offset: %d\n", offset);

    while (offset > 1) {

        // 插入排序
        for (int i = offset; i < arrCount; i++) {
            for (int j = i; j >= offset; j-=offset) {

                // 交换 j 和 j - offset
                if (arr[j] < arr[j-offset]) {
                    int temp = arr[j - offset];
                    arr[j - offset] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        offset = offset / 3;
    }
}

void demo() {

    int arr[] = {10,5,7,2,7,3,6, 8, 6,4,3,7,2,14, 17};
    int arrCount = sizeof(arr) / sizeof(arr[0]);
    shellSort(arr, arrCount);
    for (int i = 0; i < arrCount; i++) {
        printf("%d ", arr[i]);
    }
}
