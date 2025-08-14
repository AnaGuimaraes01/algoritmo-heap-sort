// Implementação do Heap Sort
#include <stdio.h>
#include "heapsort.h"

// Função para trocar dois elementos
static void swap(int *a, int *b) {
    int temp = *a; // Recebe o valor apontado por a (valor do primeiro elemento).
    *a = *b; //Coloca no lugar de a o valor que estava em b.
    *b = temp;  //Troca completa
}

// Função para "afundar" o elemento e manter a propriedade de max-heap
static void heapify(int arr[], int n, int i) { // HEAPIFY recebe o vetor arr, o tamanho do heap n e o índice i do nó que queremos ajustar.
    int largest = i; // maior entre pai e filhos
    int left = 2 * i + 1; //Índice do filho esquerdo
    int right = 2 * i + 2; // Índice do filho direito

    // Ela verifica se o pai é menor que algum dos filhos. Primeiro compara com o filho esquerdo; se ele for maior, atualiza o índice largest. Depois compara com o direito e faz o mesmo. Se o maior não for o próprio pai, troca pai e filho e chama heapify novamente na posição do filho, para continuar ajustando até a árvore ficar correta.

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Função para construir um max-heap
static void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) { // Começamos pelo último nó que tem filhos. Percorre todos os nós não-folha de baixo para cima.
        heapify(arr, n, i); //Aplica HEAPIFY em cada nó para garantir a propriedade de max-heap.
    }
}

// Função principal do Heap Sort
void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n); //transforma o vetor em um max-heap.
    // Loop que pega o maior elemento (raiz) e o coloca no fim do vetor. A cada iteração, reduzimos o tamanho do heap (i).
    for (int i = n - 1; i > 0; i--) { 

    //SWAP Troca a raiz (maior) com o elemento na posição i (coloca o maior no final).
        swap(&arr[0], &arr[i]); 

        // Depois, aplicamos HEAPIFY na raiz para restaurar a propriedade de max-heap no restante do vetor.
heapify(arr, i, 0);
        heapify(arr, i, 0);
    }
}

// Imprimir um vetor
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
}
