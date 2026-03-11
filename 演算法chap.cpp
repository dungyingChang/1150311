#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// ===================== 印出陣列 =====================
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ===================== 複製陣列 =====================
void copyArray(int source[], int target[], int n)
{
    for(int i = 0; i < n; i++)
        target[i] = source[i];
}

// ====================================================
// Bubble Sort
// ====================================================
void bubbleSortProcess(int arr[], int n)
{
    cout << "\nBubble Sort Process:\n";
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        cout << "Step " << i + 1 << ": ";
        printArray(arr, n);
    }
}

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ====================================================
// Insertion Sort
// ====================================================
void insertionSortProcess(int arr[], int n)
{
    cout << "\nInsertion Sort Process:\n";
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        cout << "Step " << i << ": ";
        printArray(arr, n);
    }
}

void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ====================================================
// Merge Sort
// ====================================================
void mergeProcess(int arr[], int left, int mid, int right, int n)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[50], R[50];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];

    printArray(arr, n);
}

void mergeSortProcess(int arr[], int left, int right, int n)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSortProcess(arr, left, mid, n);
        mergeSortProcess(arr, mid + 1, right, n);
        mergeProcess(arr, left, mid, right, n);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[10000], R[10000];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// ====================================================
// Quick Sort
// ====================================================
int partitionProcess(int arr[], int low, int high, int n)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    printArray(arr, n);
    return i + 1;
}

void quickSortProcess(int arr[], int low, int high, int n)
{
    if(low < high)
    {
        int pi = partitionProcess(arr, low, high, n);
        quickSortProcess(arr, low, pi - 1, n);
        quickSortProcess(arr, pi + 1, high, n);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ====================================================
// 主程式
// ====================================================
int main()
{
    // ======== Part 1: 顯示排序過程 ========
    int data[8] = {38, 27, 43, 3, 9, 82, 10, 5};
    int n = 8;

    int a[8], b[8], c[8], d[8];
    copyArray(data, a, n);
    copyArray(data, b, n);
    copyArray(data, c, n);
    copyArray(data, d, n);

    cout << "Original Array:\n";
    printArray(data, n);

    bubbleSortProcess(a, n);
    insertionSortProcess(b, n);

    cout << "\nMerge Sort Process:\n";
    mergeSortProcess(c, 0, n - 1, n);

    cout << "\nQuick Sort Process:\n";
    quickSortProcess(d, 0, n - 1, n);

    // ======== Part 2: 測試時間複雜度 ========
    cout << "\n========================================\n";
    cout << "Time Complexity Experiment\n";
    cout << "========================================\n";

    int size = 5000;
    int arr[5000], temp[5000];

    srand(time(NULL));
    for(int i = 0; i < size; i++)
        arr[i] = rand() % 10000;

    clock_t start, end;

    copyArray(arr, temp, size);
    start = clock();
    quickSort(temp, 0, size - 1);
    end = clock();
    cout << "Quick Sort Time: " << (double)(end - start) / CLOCKS_PER_SEC << " sec" << endl;

    copyArray(arr, temp, size);
    start = clock();
    mergeSort(temp, 0, size - 1);
    end = clock();
    cout << "Merge Sort Time: " << (double)(end - start) / CLOCKS_PER_SEC << " sec" << endl;

    copyArray(arr, temp, size);
    start = clock();
    bubbleSort(temp, size);
    end = clock();
    cout << "Bubble Sort Time: " << (double)(end - start) / CLOCKS_PER_SEC << " sec" << endl;

    copyArray(arr, temp, size);
    start = clock();
    insertionSort(temp, size);
    end = clock();
    cout << "Insertion Sort Time: " << (double)(end - start) / CLOCKS_PER_SEC << " sec" << endl;

    // ======== 理論時間複雜度 ========
    cout << "\n========================================\n";
    cout << "Theoretical Time Complexity\n";
    cout << "========================================\n";
    cout << "Quick Sort    : Best O(n log n), Average O(n log n), Worst O(n^2)\n";
    cout << "Merge Sort    : Best O(n log n), Average O(n log n), Worst O(n log n)\n";
    cout << "Bubble Sort   : Best O(n), Average O(n^2), Worst O(n^2)\n";
    cout << "Insertion Sort: Best O(n), Average O(n^2), Worst O(n^2)\n";

    return 0;
}
