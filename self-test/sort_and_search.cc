#include<iostream>
#include<random>
using namespace std;

void selection_sort(int arr[], int n);
int binary_search(int arr[], int n, int x);
void output(int arr[], int n);

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 99);

    for(int i = 0; i < n; i++){
        arr[i] = dis(gen);
    }

    cout << "original array : " << endl;
    output(arr, n);

    selection_sort(arr, n);

    cout << "sorted array : " << endl;
    output(arr, n);

    int x;
    cin >> x;
    cout << "the number to be searched : " << x << endl;
    int idx = binary_search(arr, n, x);
    if(idx >= 0) {
        cout << "the number is in arr[" << idx << "]" << endl;
    } else {
        cout << "the number is not in the array!" << endl;
    }

    delete[] arr;

    return 0;
}

void selection_sort(int arr[], int n) {
    int min;
    for(int i = 0; i < n - 1; i++) {// arr[n-1]當作base沒意義，因為已經在arr[n-2]完成了

        min = i; // base for the sub-arr

        /* find the min in sub-arr*/
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }

        /* swap min and base */
        if(min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int binary_search(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2; 
        //(right + left) / 2, 小括號內可能最造成overflow, 所以改用別的計算方法避開overflow 

        if(arr[mid] == x) {
            return mid;
        } else if(arr[mid] > x) {
            right = mid - 1;
        } else { 
            // arr[mid] < x
            left = mid + 1;
        }
    }

    return -1;
}

void output(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}