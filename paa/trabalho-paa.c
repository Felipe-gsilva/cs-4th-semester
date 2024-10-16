#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define m 9999

#define ALEATORIO 0
#define ORDENADO 1
#define INVERSAMENTE_ORDENADO 2

// Função: get_array
// Descrição: Preenche o array A com valores conforme o tipo especificado:
//            - ALEATORIO: valores aleatórios de 0 a m-1.
//            - ORDENADO: valores em ordem crescente de 0 a tamanho-1.
//            - INVERSAMENTE_ORDENADO: valores em ordem decrescente de tamanho-1 a 0.
// Parâmetros:
//    - int* A: Ponteiro para o array a ser preenchido.
//    - int tamanho: Tamanho do array.
//    - int tipo: Tipo de preenchimento do array.
// Retorno: Nenhum.
void get_array(int* A, int tamanho, int tipo) {
    switch (tipo) {
        case ALEATORIO:
            for (int i = 0; i < tamanho; i++) {
                A[i] = rand() % m;
            }
            break;
        case ORDENADO:
            for (int i = 0; i < tamanho; i++) {
                A[i] = i; 
            }
            break;
        case INVERSAMENTE_ORDENADO:
            for (int i = 0; i < tamanho; i++) {
                A[i] = tamanho - i - 1; 
            }
            break;
        default:
            printf("Tipo de A inválido!\n");
            break;
    }
}

// Função: get_positive_array
// Descrição: Preenche o array A com valores positivos conforme o tipo especificado:
//            - ALEATORIO: valores aleatórios de 1 a m.
//            - ORDENADO: valores em ordem crescente de 1 a tamanho.
//            - INVERSAMENTE_ORDENADO: valores em ordem decrescente de tamanho a 1.
// Parâmetros:
//    - int* A: Ponteiro para o array a ser preenchido.
//    - int tamanho: Tamanho do array.
//    - int tipo: Tipo de preenchimento do array.
// Retorno: Nenhum.
void get_positive_array(int* A, int tamanho, int tipo) {
    switch (tipo) {
        case ALEATORIO:
            for (int i = 0; i < tamanho; i++) {
                A[i] = (rand() % m) + 1;  
            }
            break;
        case ORDENADO:
            for (int i = 0; i < tamanho; i++) {
                A[i] = i + 1;  
            }
            break;
        case INVERSAMENTE_ORDENADO:
            for (int i = 0; i < tamanho; i++) {
                A[i] = tamanho - i;  
            }
            break;
        default:
            printf("Invalid array type!\n");
            break;
    }
}

// Função: get_time
// Descrição: Calcula o tempo de execução de uma função de ordenação sobre um array de tamanho n.
// Parâmetros:
//    - void (*funcao)(int*, int): Ponteiro para a função de ordenação a ser executada.
//    - int* A: Ponteiro para o array a ser ordenado.
//    - int n: Tamanho do array.
//    - const char* name: Nome da função de ordenação.
//    - int tipo: Tipo de preenchimento do array.
// Retorno: Nenhum.
void get_time(void (*funcao)(int*, int), int* A, int n, const char* name, int tipo) {
    get_array(A, n, tipo);
    clock_t start, end;
    double total;
    start = clock();
    funcao(A, n);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%s: %f segundos\n", name, total);
}

// Função: get_counting_time
// Descrição: Similar à função get_time, mas utiliza arrays com valores positivos para o Counting Sort.
// Parâmetros: Mesmos parâmetros da função get_time.
// Retorno: Nenhum.
void get_counting_time(void (*funcao)(int*, int), int* A, int n, const char* name, int tipo) {
    get_positive_array(A, n, tipo);
    clock_t start, end;
    double total;
    start = clock();
    funcao(A, n);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%s: %f segundos\n", name, total);
}


// Função: get_three_var_time
// Descrição: Calcula o tempo de execução de uma função de ordenação que usa três variáveis (índice inicial e final).
// Parâmetros:
//    - void (*funcao)(int*, int, int): Ponteiro para a função de ordenação.
//    - int* A: Ponteiro para o array a ser ordenado.
//    - int l: Índice inicial do array.
//    - int r: Índice final do array.
//    - const char* name: Nome da função de ordenação.
//    - int tipo: Tipo de preenchimento do array.
// Retorno: Nenhum.
void get_three_var_time(void (*funcao)(int*, int, int), int* A, int l, int r,const char* name, int tipo) {
    get_array(A, r, tipo);
    clock_t start, end;
    double total;
    start = clock();
    funcao(A, l, r);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%s: %f segundos\n", name, total);
}


// Função: bubble_sort
// Descrição: Implementação do algoritmo de ordenação Bubble Sort.
// Parâmetros:
//    - int A[]: Array a ser ordenado.
//    - int n: Tamanho do array.
// Retorno: Nenhum.
void bubble_sort(int A[], int n){
    int i,j,aux;
    for(i = 0; i < n-1 ; i++){
        for(j = 0; j < n-i-1 ;j++){
            if(A[j] > A[j+1]){
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
            }
        }
    }
}

// Função: insertion_sort
// Descrição: Implementação do algoritmo de ordenação Insertion Sort.
// Parâmetros:
//    - int A[]: Array a ser ordenado.
//    - int n: Tamanho do array.
// Retorno: Nenhum.
void insertion_sort(int A[], int n){
    for(int i = 0; i <  n ; i++){    
        int key = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j = j-1; 
        }
        A[j+1] = key;
    }
}

// Função: bucket_sort
// Descrição: Implementação do algoritmo de ordenação Bucket Sort.
// Parâmetros:
//    - int A[]: Array a ser ordenado.
//    - int n: Tamanho do array.
// Retorno: Nenhum.
void bucket_sort(int A[], int n) {
    int num_buckets = (int) sqrt(n); // Or some other heuristic based on `n`
    int** bucket = (int**)malloc(num_buckets * sizeof(int*));
    int* count = (int*)malloc(num_buckets * sizeof(int));

    if (bucket == NULL || count == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < num_buckets; i++) {
        bucket[i] = (int*)malloc(n * sizeof(int));
        count[i] = 0;
    }

    int max_value = m; 
    for (int i = 0; i < n; i++) {
        int bucket_index = (A[i] * num_buckets) / max_value;
        if (bucket_index >= num_buckets) bucket_index = num_buckets - 1; 
        bucket[bucket_index][count[bucket_index]++] = A[i];
    }

    for (int i = 0; i < num_buckets; i++) {
        if (count[i] > 0) {
            insertion_sort(bucket[i], count[i]);
        }
    }

    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < count[i]; j++) {
            A[index++] = bucket[i][j];
        }
    }

    for (int i = 0; i < num_buckets; i++) {
        free(bucket[i]);
    }
    free(bucket);
    free(count);
}

// Função: find_max
// Descrição: Encontra o maior valor em um array.
// Parâmetros:
//    - int* A: Array de entrada.
//    - int n: Tamanho do array.
// Retorno: O valor máximo encontrado no array.
int find_max(int *A, int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

// Função: counting_sort
// Descrição: Implementação do algoritmo de ordenação Counting Sort.
// Parâmetros:
//    - int A[]: Array a ser ordenado.
//    - int n: Tamanho do array.
// Retorno: Nenhum.
void counting_sort(int A[], int n) {
    int max = find_max(A, n); 
    if (max < 0) {
        printf("Error: Array contains negative values.\n");
        return;
    }

    int* count = (int*)calloc(max + 1, sizeof(int));
    if (count == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    int* output = (int*)malloc(n * sizeof(int));
    if (output == NULL) {
        printf("Memory allocation failed.\n");
        free(count);
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        count[A[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[A[i]] - 1] = A[i];
        count[A[i]]--;
    }

    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }

    free(count);
    free(output);
}


// Função: counting_sort_for_radix
// Descrição: Função auxiliar para o Radix Sort que realiza o Counting Sort baseado em um dígito específico.
// Parâmetros:
//    - int A[]: Array a ser ordenado.
//    - int n: Tamanho do array.
//    - int exp: Expoente para divisão, definindo o dígito a ser considerado.
// Retorno: Nenhum.
void counting_sort_for_radix(int A[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(A[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(A[i] / exp) % 10] - 1] = A[i];
        count[(A[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }
}

// Função: radix_sort
// Descrição: Implementação do algoritmo de ordenação Radix Sort.
// Parâmetros:
//    - int A[]: Array a ser ordenado.
//    - int n: Tamanho do array.
// Retorno: Nenhum.
void radix_sort(int A[], int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max)
            max = A[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort_for_radix(A, n, exp);
    }
}

// Função: heapify
// Descrição: Realiza o processo de heapify para o algoritmo Heap Sort.
// Parâmetros:
//    - int A[]: Array a ser ordenado.
//    - int n: Tamanho do heap.
//    - int i: Índice do elemento atual.
// Retorno: Nenhum.
void heapify(int A[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] > A[largest])
        largest = left;

    if (right < n && A[right] > A[largest])
        largest = right;

    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        heapify(A, n, largest);
    }
}

// Função: heap_sort
// Descrição: Implementação do algoritmo de ordenação Heap Sort.
// Parâmetros:
//    - int A[]: Array a ser ordenado.
//    - int n: Tamanho do array.
// Retorno: Nenhum.
void heap_sort(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        heapify(A, i, 0);
    }
}

// Função: merge
// Descrição: Função auxiliar para o Merge Sort, que funde duas metades ordenadas de um array.
// Parâmetros:
//    - int* A: Array a ser ordenado.
//    - int l: Índice inicial da primeira metade.
//    - int r: Índice final da segunda metade.
//    - int me: Índice do meio.
// Retorno: Nenhum.
void merge(int* A, int l, int r, int me) {
    int n1 = me - l + 1;
    int n2 = r - me;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        L[i] = A[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[me + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Função: merge_sort
// Descrição: Implementação do algoritmo de ordenação Merge Sort.
// Parâmetros:
//    - int A[]: Array a ser ordenado.
//    - int l: Índice inicial.
//    - int r: Índice final.
// Retorno: Nenhum.
void merge_sort(int A[], int l, int r) {
    if (l < r) {
        int me = l + (r - l) / 2;
        merge_sort(A, l, me);
        merge_sort(A, me + 1, r);
        merge(A, l, r, me);
    }
}

// Função: median_of_three
// Descrição: Função auxiliar para o Quick Sort que calcula a mediana de três elementos.
// Parâmetros:
//    - int A[]: Array de entrada.
//    - int l: Índice inicial.
//    - int r: Índice final.
// Retorno: O valor da mediana.
int median_of_three(int A[], int l, int r) {
    int mid = l + (r - l) / 2;
    if (A[mid] < A[l]) {
        int temp = A[l];
        A[l] = A[mid];
        A[mid] = temp;
    }
    if (A[r] < A[l]) {
        int temp = A[l];
        A[l] = A[r];
        A[r] = temp;
    }
    if (A[r] < A[mid]) {
        int temp = A[mid];
        A[mid] = A[r];
        A[r] = temp;
    }
    int temp = A[mid];
    A[mid] = A[r];
    A[r] = temp;
    return A[r];
}

// Função: qpartition
// Descrição: Particiona o array para o Quick Sort utilizando a mediana de três.
// Parâmetros:
//    - int A[]: Array de entrada.
//    - int l: Índice inicial.
//    - int r: Índice final.
// Retorno: Índice do pivô após a partição.
int qpartition(int A[], int l, int r) {
    int pivot = median_of_three(A, l, r);
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (A[j] < pivot) {
            i++;
            int aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }
    int aux = A[i + 1];
    A[i + 1] = A[r];
    A[r] = aux;
    return i + 1;
}

// Função: quick_sort
// Descrição: Implementação do algoritmo de ordenação Quick Sort.
// Parâmetros:
//    - int A[]: Array a ser ordenado.
//    - int l: Índice inicial.
//    - int h: Índice final.
// Retorno: Nenhum.
void quick_sort(int A[], int l, int h) {
    if (l < h) {
        int pi = qpartition(A, l, h);
        quick_sort(A, l, pi - 1);
        quick_sort(A, pi + 1, h);
    }
}

// Função: selection_sort
// Descrição: Implementação do algoritmo de ordenação Selection Sort.
// Parâmetros:
//    - int A[]: Array a ser ordenado.
//    - int n: Tamanho do array.
// Retorno: Nenhum.
void selection_sort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        if (min != i) {
            int aux = A[i];
            A[i] = A[min];
            A[min] = aux;
        }
    }
}

// Função: shell_sort
// Descrição: Implementação do algoritmo de ordenação Shell Sort.
// Parâmetros:
//    - int A[]: Array a ser ordenado.
//    - int n: Tamanho do array.
// Retorno: Nenhum.
void shell_sort(int A[], int n) {
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }
    
    while (h >= 1) {
        for (int i = h; i < n; i++) {
            int aux = A[i];
            int j = i;
            while (j >= h && A[j - h] > aux) {
                A[j] = A[j - h];
                j -= h;
            }
            A[j] = aux;
        }
        h = h / 3;
    }
}

int main() {
    int tamanho = 0;
    for(int i = 1; i < 7; i++) {
        tamanho = pow(10, i);
        int* A = malloc(tamanho * sizeof(int));
        if (A == NULL) {
            printf("Memory allocation failed for size %d\n", tamanho);
            exit(1);
        }
        printf("Obtendo tempo para array de %d tamanho e aleatórias\n", tamanho);
        get_time(bubble_sort, A, tamanho, "Bubble Sort", ALEATORIO);
        get_time(insertion_sort, A, tamanho, "Insertion Sort", ALEATORIO);
        get_time(selection_sort, A, tamanho, "Selection Sort", ALEATORIO);
        get_time(shell_sort, A, tamanho, "Shell Sort", ALEATORIO);
        get_counting_time(counting_sort, A, tamanho, "Counting Sort", ALEATORIO);
        get_time(radix_sort, A, tamanho, "Radix Sort", ALEATORIO);
        get_time(bucket_sort, A, tamanho, "Bucket Sort", ALEATORIO);
        get_three_var_time(merge_sort, A, 0, tamanho - 1, "Merge Sort", ALEATORIO);
        get_three_var_time(quick_sort, A, 0, tamanho - 1, "Quick Sort", ALEATORIO);
        get_time(heap_sort, A, tamanho, "Heap Sort", ALEATORIO);

        puts("");
        printf("Obtendo tempo para array de %d tamanho e ordenadas\n", tamanho);
        get_time(bubble_sort, A, tamanho, "Bubble Sort", ORDENADO);
        get_time(insertion_sort, A, tamanho, "Insertion Sort", ORDENADO);
        get_time(selection_sort, A, tamanho, "Selection Sort", ORDENADO);
        get_time(shell_sort, A, tamanho, "Shell Sort", ORDENADO);
        get_counting_time(counting_sort, A, tamanho, "Counting Sort", ORDENADO);
        get_time(radix_sort, A, tamanho, "Radix Sort", ORDENADO);
        get_time(bucket_sort, A, tamanho, "Bucket Sort", ORDENADO);
        get_three_var_time(merge_sort, A, 0, tamanho - 1, "Merge Sort", ORDENADO);
        get_three_var_time(quick_sort, A, 0, tamanho - 1, "Quick Sort", ORDENADO);
        get_time(heap_sort, A, tamanho, "Heap Sort", ORDENADO);

        puts("");
        printf("Obtendo tempo para array de %d tamanho e inversamente ordenadas\n", tamanho);
        get_time(bubble_sort, A, tamanho, "Bubble Sort", INVERSAMENTE_ORDENADO);
        get_time(insertion_sort, A, tamanho, "Insertion Sort", INVERSAMENTE_ORDENADO);
        get_time(selection_sort, A, tamanho, "Selection Sort", INVERSAMENTE_ORDENADO);
        get_time(shell_sort, A, tamanho, "Shell Sort", INVERSAMENTE_ORDENADO);
        get_counting_time(counting_sort, A, tamanho, "Counting Sort", INVERSAMENTE_ORDENADO);
        get_time(radix_sort, A, tamanho, "Radix Sort", INVERSAMENTE_ORDENADO);
        get_time(bucket_sort, A, tamanho, "Bucket Sort", INVERSAMENTE_ORDENADO);
        get_three_var_time(merge_sort, A, 0, tamanho - 1, "Merge Sort", INVERSAMENTE_ORDENADO);
        get_three_var_time(quick_sort, A, 0, tamanho - 1, "Quick Sort", INVERSAMENTE_ORDENADO);
        get_time(heap_sort, A, tamanho, "Heap Sort", INVERSAMENTE_ORDENADO);
        free(A);
    }
    return 0;
}
