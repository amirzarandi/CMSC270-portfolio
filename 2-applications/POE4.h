#ifndef BINARYSEARCH_H_ 
#define BINARYSEARCH_H_ 

int binarySearch(int arr[], int size, int x) {
    int low = 0;
    int high = size - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == x) {
            return mid;
        }

        if(x < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

#endif /*BINARYSEARCH_H_*/