#include <stdio.h>
#include <windows.h>    // Necessário para SetConsoleCP e SetConsoleOutputCP
#include "heapsort.h"

int main(void) {
    // Configura o console do Windows para UTF-8
    SetConsoleCP(65001);       // Entrada
    SetConsoleOutputCP(65001); // Saída

    int n;

    printf("Digite a quantidade de elementos: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Entrada inválida.\n");
        return 1;
    }

    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    printf("Vetor ordenado: ");
    printArray(arr, n);

    return 0;
}
