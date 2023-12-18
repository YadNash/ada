#include<bits/stdc++.h>
using namespace std;

void insert(int arr[], int n){
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

int main(){
    int arr[] = {6,5,4,3,2,1};
    int n =6;
    clock_t start, end;
    start = clock();
    insert(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\ntime spent: " << time_spent << endl;
    
}