
//ejercicio 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplicarMatrices(int A[30][30], int B[30][30], int resultado[30][30]) {
    int i, j, k;

    for (i = 0; i < 30; i++) {
        for (j = 0; j < 30; j++) {
            resultado[i][j] = 0;
            for (k = 0; k < 30; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int i, j;
    int A[30][30], B[30][30], resultado[30][30];
    clock_t inicio, fin;

    
    srand(time(NULL));
    for (i = 0; i < 30; i++) {
        for (j = 0; j < 30; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }
  
    printf("Matriz A:\n");
    for (i = 0; i < 30; i++) {
        for (j = 0; j < 30; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    
    printf("\nMatriz B:\n");
    for (i = 0; i < 30; i++) {
        for (j = 0; j < 30; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

  
    inicio = clock();

  
    multiplicarMatrices(A, B, resultado);

    
    fin = clock();

   
    printf("\nResultado:\n");
    for (i = 0; i < 30; i++) {
        for (j = 0; j < 30; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

     
    double tiempoEjecucion = ((double)(fin - inicio)) / CLOCKS_PER_SEC * 1000000;
    printf("\nTiempo de ejecucion: %.4f milisegundos\n", tiempoEjecucion);

    return 0;
}

/*

// ejercicio 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; 
    }
}

int main() {
    const int arraySize = 10000;
    int arr[arraySize];
    int tempArr[arraySize];
    clock_t start, end;
    double elapsedTime;

    srand(time(NULL));

 
    generateRandomArray(arr, arraySize);

    
    double insertionSortTimes[100];
    for (int i = 0; i < 100; i++) {
        
        for (int j = 0; j < arraySize; j++) {
            tempArr[j] = arr[j];
        }

        start = clock();
        insertionSort(tempArr, arraySize);
        end = clock();

        elapsedTime = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        insertionSortTimes[i] = elapsedTime;
    }

    
    double quickSortTimes[100];
    for (int i = 0; i < 100; i++) {
        
        for (int j = 0; j < arraySize; j++) {
            tempArr[j] = arr[j];
        }

        start = clock();
        quickSort(tempArr, 0, arraySize - 1);
        end = clock();

        elapsedTime = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        quickSortTimes[i] = elapsedTime;
    }

   
    double bubbleSortTimes[100];
    for (int i = 0; i < 100; i++) {
        
        for (int j = 0; j < arraySize; j++) {
            tempArr[j] = arr[j];
        }

        start = clock();
        bubbleSort(tempArr, arraySize);
        end = clock();

        elapsedTime = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        bubbleSortTimes[i] = elapsedTime;
    }

 
    double insertionSortAvg = 0, quickSortAvg = 0, bubbleSortAvg = 0;
    double insertionSortMin = insertionSortTimes[0], quickSortMin = quickSortTimes[0], bubbleSortMin = bubbleSortTimes[0];
    double insertionSortMax = insertionSortTimes[0], quickSortMax = quickSortTimes[0], bubbleSortMax = bubbleSortTimes[0];

    for (int i = 0; i < 100; i++) {
        insertionSortAvg += insertionSortTimes[i];
        quickSortAvg += quickSortTimes[i];
        bubbleSortAvg += bubbleSortTimes[i];

        
        if (insertionSortTimes[i] < insertionSortMin) {
            insertionSortMin = insertionSortTimes[i];
        }
        if (insertionSortTimes[i] > insertionSortMax) {
            insertionSortMax = insertionSortTimes[i];
        }

        if (quickSortTimes[i] < quickSortMin) {
            quickSortMin = quickSortTimes[i];
        }
        if (quickSortTimes[i] > quickSortMax) {
            quickSortMax = quickSortTimes[i];
        }

        if (bubbleSortTimes[i] < bubbleSortMin) {
            bubbleSortMin = bubbleSortTimes[i];
        }
        if (bubbleSortTimes[i] > bubbleSortMax) {
            bubbleSortMax = bubbleSortTimes[i];
        }
    }

    insertionSortAvg /= 100;
    quickSortAvg /= 100;
    bubbleSortAvg /= 100;

  
    printf("Insertion Sort:\n");
    printf("Tiempo promedio: %.2f ms\n", insertionSortAvg);
    printf("Tiempo minimo: %.2f ms\n", insertionSortMin);
    printf("Tiempo maximo: %.2f ms\n\n", insertionSortMax);

    printf("Quick Sort:\n");
    printf("Tiempo promedio: %.2f ms\n", quickSortAvg);
    printf("Tiempo minimo: %.2f ms\n", quickSortMin);
    printf("Tiempo maximo: %.2f ms\n\n", quickSortMax);

    printf("Bubble Sort:\n");
    printf("Tiempo promedio: %.2f ms\n", bubbleSortAvg);
    printf("Tiempo minimo: %.2f ms\n", bubbleSortMin);
    printf("Tiempo maximo: %.2f ms\n", bubbleSortMax);

    return 0;
}


/*
//ejercicio 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busquedaSecuencial(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int busquedaBinaria(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void generarArregloOrdenado(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

double calcularPromedio(double times[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += times[i];
    }
    return sum / size;
}

double calcularMinimo(double times[], int size) {
    double min = times[0];
    for (int i = 1; i < size; i++) {
        if (times[i] < min) {
            min = times[i];
        }
    }
    return min;
}

double calcularMaximo(double times[], int size) {
    double max = times[0];
    for (int i = 1; i < size; i++) {
        if (times[i] > max) {
            max = times[i];
        }
    }
    return max;
}

int main() {
    const int arraySize = 50000;
    int arr[arraySize];

    srand((unsigned)time(NULL));
    generarArregloOrdenado(arr, arraySize);

    double secuencialTimes[100];
    double binariaTimes[100];

    for (int i = 0; i < 100; i++) {
        int randomNumber = rand() % arraySize;

        clock_t start = clock();
        busquedaSecuencial(arr, arraySize, randomNumber);
        clock_t end = clock();
        double elapsed = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
        secuencialTimes[i] = elapsed;

        start = clock();
        busquedaBinaria(arr, 0, arraySize - 1, randomNumber);
        end = clock();
        elapsed = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
        binariaTimes[i] = elapsed;
    }

    double secuencialPromedio = calcularPromedio(secuencialTimes, 100);
    double secuencialMinimo = calcularMinimo(secuencialTimes, 100);
    double secuencialMaximo = calcularMaximo(secuencialTimes, 100);

    double binariaPromedio = calcularPromedio(binariaTimes, 100);
    double binariaMinimo = calcularMinimo(binariaTimes, 100);
    double binariaMaximo = calcularMaximo(binariaTimes, 100);

    printf("Busqueda Secuencial:\n");
    printf("Tiempo promedio: %.2f ms\n", secuencialPromedio);
    printf("Tiempo minimo: %.2f ms\n", secuencialMinimo);
    printf("Tiempo maximo: %.2f ms\n\n", secuencialMaximo);

    printf("Busqueda Binaria:\n");
    printf("Tiempo promedio: %.2f ms\n", binariaPromedio);
    printf("Tiempo minimo: %.2f ms\n", binariaMinimo);
    printf("Tiempo maximo: %.2f ms\n", binariaMaximo);

    return 0;
}
|*/






























