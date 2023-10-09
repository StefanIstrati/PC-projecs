#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

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
void Sort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        Sort(arr, low, pi - 1);
        Sort(arr, pi + 1, high);
    }
}
void fillMatrix(int **arr2, int N, int M, int arr[], int row, int col, int k) {
    if (N <= 0 || M <= 0) return;

    for (int i = row ; i < row + N; i++) {
        arr2[i][col + M - 1] = arr[k];
        k++;
    }
        for (int i = col + M - 2; i >= col; i--) {
            arr2[row + N - 1][i] = arr[k];
            k++;
        }
        for (int i = row + N - 2; i >= row; i--) {
            arr2[i][col] = arr[k];
            k++;
        }
    for (int i = col+1; i < col + M-1; i++) {
        arr2[row][i] = arr[k];
        k++;
    }
    fillMatrix(arr2, N - 2, M - 2, arr, row + 1, col + 1, k);
}
void printMatrix(int **matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%i\t", matrix[i][j]);
        }
        printf("\n");
        printf("\n");
    }
}
int main() {
    int N, M;
    printf("Enter the number of rows (N) and columns (M) of the matrix: ");
    scanf("%d %d", &N, &M);
    int **arr2 = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        arr2[i] = (int *)malloc(M * sizeof(int));
    }
    int arr[N * M];
    int k;
    k = N * M;
    srand(time(NULL));
    for (int i = 0; i < k; i++) {
        arr[i] = (rand() % 1000);
    }
    k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr2[i][j] = arr[k];
            k++;
        }
    }
    printf("Initial bidimensional array:\n");
    printMatrix(arr2, N, M);
    Sort(arr,0, k-1);
    k = 0;
    fillMatrix(arr2, N, M, arr, 0, 0, k);
    printf("Final bidimensional array sorted in the center the highest value and towards the edges the lowest value:\n");
    printMatrix(arr2, N, M);
    return 0;
}
