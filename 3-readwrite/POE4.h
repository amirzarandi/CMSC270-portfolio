#ifndef RECURSIVEBINARYSEARCH_H_ 
#define RECURSIVEBINARYSEARCH_H_ 

int recursiveBinarySearch(int arr[], int x, int low, int high) {
    if(low > high) {
        return -1;
    } else {
        int mid = (low + high) / 2;
        if (x == arr[mid]) {
            return mid;
        } else if (x > arr[mid]) {
            return recursiveBinarySearch(arr, x, mid+1, high);
        } else if (x < arr[mid]) {
            return recursiveBinarySearch(arr, x, low, mid-1);
        }
    }
}

#endif /*RECURSIVEBINARYSEARCH_H_*/