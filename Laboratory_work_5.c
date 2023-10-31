#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dynamic_memory_alloc(int ***arr, int n, int m) {
    *arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        (*arr)[i] = (int *)malloc(m * sizeof(int));
    }
}

void free_memory_alloc(int ***arr, int n) {
    for (int i = 0; i < n; i++) {
        free((*arr)[i]);
    }
    free(*arr);
}

void enter_values(int **arr, int n, int m) {
    printf("Enter the elements for bidimensional array:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void fill_arr_with_random_values(int **arr, int n, int m) {
    srand(time(NULL));
    printf("Filing the array with random values:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % 100;
        }
    }
}

void selection_sort_for_odd_column(int **arr, int n, int m) {  //base task from Kulev_PC_SDA varianta 17
    for (int j = 0; j < m; j += 2) {
        for (int i = 0; i < n - 1; i++) {
            int maxIndex = i;
            for (int k = i + 1; k < n; k++) {
                if (arr[k][j] > arr[maxIndex][j]) {
                    maxIndex = k;
                }
            }
            if (maxIndex != i) {
                int temp = arr[i][j];
                arr[i][j] = arr[maxIndex][j];
                arr[maxIndex][j] = temp;
            }
        }
    }
}

void show_the_array(int **arr, int n, int m) {
    printf("The array:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int return_Index(const int *array, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (*array == target) {
            return i;  
        }
        array++;  
    }
    
    return -1;  
}

void find_index(){
    int num;
    int target;
    int index;
    int *arr = malloc(num * sizeof(int));
    printf("The length of 1D array\n");
    scanf("%d",&num);
    printf("Enter the elements of array\n");
    for (int i = 0; i < num; i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element you want to find index\n");
    scanf("%i",&target);
    index = return_Index(arr,num,target);
    if (index != -1){
        printf("the index first occurence of %d is %d",target, index);
    }
    else{
        printf("the %d isn't in the array");
    }
}

void revers_array(){
    int num;
    int index;
    int *arr = malloc(num * sizeof(int));
    int *inv = malloc(num * sizeof(int));
    printf("The length of 1D array\n");
    scanf("%d",&num);
    printf("Enter the elements of array\n");
    for (int i = 0; i < num; i++){
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < num; i++){
        inv[(num-1)-i] = arr[i];
    }
    printf("The reverse array\n");
    for (int i = 0; i < num;i++){
        printf("%d ", inv[i]);
    }
}

int main() {
    int n, m, choice;
    int **arr = NULL;

    printf("Enter the number of lines (n): ");
    scanf("%d", &n);
    printf("Enter the number of columns (m): ");
    scanf("%d", &m);

    while (1) {
        printf("\nOptions Menu:\n");
        printf("1. Dynamic memory allocation for arrays\n");
        printf("2. Entering elements for array from the keyboard\n");
        printf("3. Completing the array with random values\n");
        printf("4. To sort the odd columns of the array into descending order\n");
        printf("5. Show array on the screen\n");
        printf("6. Freeing the memory allocated for the table\n");
        printf("7. Find the index of the first occurence of a specific value\n");
        printf("8. Find the revers of a 1D array\n");
        printf("0. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            
            case 1:
                dynamic_memory_alloc(&arr, n, m);
                break;
            case 2:
                enter_values(arr, n, m);
                break;
            case 3:
                fill_arr_with_random_values(arr, n, m);
                break;
            case 4:
                selection_sort_for_odd_column(arr, n, m);
                break;
            case 5:
                show_the_array(arr, n, m);
                break;
            case 6:
                free_memory_alloc(&arr, n);
                break;
            case 7:
                find_index();
                break;
            case 8:
                revers_array();
                break;
            case 0:
                free_memory_alloc(&arr, n);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
