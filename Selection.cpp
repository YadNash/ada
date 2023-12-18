#include <bits/stdc++.h>
using namespace std;

void selection(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
            swap(arr[min], arr[i]);
    }
}
int main()
{
    int arr[] = {6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    clock_t start, end;
    start = clock();
    selection(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\ntime spent: " << time_spent << endl;
}