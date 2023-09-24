#include <stdbool.h>
#include <stdio.h> 
#include <time.h>
void swap(int* xp, int* yp)//subprogram that changes 2 variables with place
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)//start bubble sort subprogram 
{
    int i, j;
    
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}                                  //end bubble sort subprogram
void selectionSort(int arr[], int n)  //start selection sort subprogram
{
    int i, j, min, k;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        k = arr[i];
        arr[i] = arr[min];
        arr[min] = k;
    }
}                                   //end selection sort subprogram 
void insertionSort(int arr[], int n) //start insertion sort subprogram
{
    int i, k, j;
    for (i = 1; i < n; i++)
    {
        k = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
} //end insertion sort subprogram 
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high) //start quickSort subprogram
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
} //end QuickSort subprogram
void printArray(int arr[], int size)//printing subprogram 
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
void scanArray(int arr[],int n)//subprogram for introducing array from console 
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%i",&arr[i]);
}
int main()
{
    int n,i;
    double a;
    scanf("%i \n",&n);
    int arr1[n], arr2[n];
    scanArray(arr1,n);
    for (i=0;i<n;i++)
    {
    arr2[i]= arr1[i];
    }
    clock_t start, stop;
    start= clock();
    bubbleSort(arr1, n);
    stop = clock();
    a = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("\n");
    printf("bubble sort : \n");
    printArray(arr1, n);
    printf("\n");
    printf("%.6lf\n",a);
    for (i=0;i<n;i++)
    {
    arr1[i]= arr2[i];
    }
    start= clock();
    selectionSort(arr1, n);
    stop = clock();
    a = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("\n");
    printf("selection sort : \n");
    printArray(arr1, n);
    printf("\n");
    printf("%.6lf\n",a);
    for (i=0;i<n;i++)
    {
    arr1[i]= arr2[i];
    }
    start= clock();
    insertionSort(arr1, n);
    stop = clock();
    a = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("\n");
    printf("insertion sort : \n");
    printArray(arr1, n);
    printf("\n");
    printf("%.6lf\n",a);
    for (i=0;i<n;i++)
    {
    arr1[i]= arr2[i];
    }
    start= clock();
    quickSort(arr1, 0,n-1);
    stop = clock();
    a = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("\n");
    printf("quickSort sort : \n");
    printArray(arr1, n);
    printf("\n");
    printf("%.6lf\n",a);
    return 0;
}