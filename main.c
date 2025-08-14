
#include <stdio.h>
#include "heapsort.h"

int main(void) {
    int n;

    printf("Digite a quantidade de elementos: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Entrada inválida.\n");
        return 1;
    }

    int arr[n];

    printf("Digite os %d elementos: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    printf("Vetor ordenado: ");
    printArray(arr, n);

    return 0;
}
