#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Sort(int arr[], int n) {
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
}
void fillMatrix(int **arr2, int N, int M, int arr[], int row, int col, int k) {
    if (N <= 0 || M <= 0) return;
    
    // Fill the top row
    for (int i = col; i < col + M; i++) {
        arr2[row][i] = arr[k];
        k++;
    } 
    // Fill the right column
    for (int i = row + 1; i < row + N; i++) {
        arr2[i][col + M - 1] = arr[k];
        k++;
    } 
    // Fill the bottom row
    if (N > 1) {
        for (int i = col + M - 2; i >= col; i--) {
            arr2[row + N - 1][i] = arr[k];
            k++;
        }
    } 
    // Fill the left column
    if (M > 1) {
        for (int i = row + N - 2; i > row; i--) {
            arr2[i][col] = arr[k];
            k++;
        }
    }
    // Recursively fill the inner matrix
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
        arr[i] = (rand() % 100);
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
    Sort(arr, k);
    k = 0;
    fillMatrix(arr2, N, M, arr, 0, 0, k);
    printf("Final bidimensional array sorted (in the center the highest value and towards the edges the lowest value):\n");
    printMatrix(arr2, N, M);
    return 0;
}
