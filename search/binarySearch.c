//
// Created by 梁宪松 on 2018-12-20.
//

/*
 * 递归折半查找，基于有序数组
 *
 * 最多需要 logN + 1 次查找
 * */
int binarySearch(int arr[], int key, int lo, int hi){

    if (hi < lo) { return -1;}
    int mid = lo + (hi - lo)/2;

    if (arr[mid] == key) { return mid;}
    else if (arr[mid] < key) {
        return binarySearch(arr, key, mid+1, hi);
    } else{
        return binarySearch(arr, key, lo, mid-1);
    }
}

/*
 * 非递归形式二分查找
 * */
int binarySearch_v2(int arr[], int arrCount, int key) {

    int lo = 0;
    int hi = arrCount;

    while (lo < hi) {
        int mid = lo + (hi - lo)/2;

        if (arr[mid] == key) { return mid;}
        else if(arr[mid] < key) {
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    return -1;
}


void demo() {
    int arr[] = {-1, 2, 4, 5,7,9, 10, 15, 19, 22, 23, 25, 29, 32};
    int arrCount = sizeof(arr) / sizeof(arr[0]);
    int key = 23;
//    int index = binarySearch(arr, key, 0, arrCount-1);
    int index = binarySearch_v2(arr, arrCount-1, key);

    printf("found key: %d at index: %d\n", key, index);
    for (int i = 0; i < arrCount; i++) {
        printf("%d ", arr[i]);
    }
}