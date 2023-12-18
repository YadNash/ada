#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e, int pivot){
    int index = s;
   
    for (int i = s; i <= e; i++)
    {
        if(arr[i]<= pivot){
            swap(arr[index], arr[i]);
            index++;
        }
    } index--;
    return index;
    
}

void quick(int arr[], int start, int end){
    if(start < end ) {
        int pivot = arr[end];
    int p = partition(arr, start, end, pivot);
    quick(arr, start, p-1);
    quick(arr, p+1, end);
    }
}

int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int n = 9 ;
    clock_t start, end;
    start = clock();
    quick(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\ntime spent: " << time_spent << endl;
}