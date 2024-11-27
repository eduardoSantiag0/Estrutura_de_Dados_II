#include <vector>
#include <iostream>

//* Dividir uma estrutura em subconjuntos 
//* Aplicar a ordenação nos elementos que foram extraídos da estrutura originaria. Divisão: mergeSort
//* Após a ordenação destes subconjuntos, 
//* é feita a mistura destes em um conjunto final ordenado. Recursão: (intercala)

using namespace std;

void intercala (vector<int>& arr, int inicio, int meio, int final) //! Merge
{
    int n1 = meio - inicio + 1; // tamanho dos vetores temporários
    int n2 = final - meio; // tamanho dos vetores temporários

    // Criando vetores temporários L (inicio ao meio) e R (meio ao fim de arr)
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[inicio + i];
    for (int j = 0; j < n2; j++) R[j] = arr[meio + 1 + j];


    // Índices para percorrer os vetores temporários e o vetor original
    int walkL = 0, walkR = 0, k = inicio;

    //  Devolva no vetor original
    while (walkL < n1 && walkR < n2) {
        if (L[walkL] <= R[walkR]) {
            arr[k] = L[walkL];
            walkL++;
        } else {
            arr[k] = R[walkR];
            walkR++;
        }
        k++;
    }

    // Copia os elementos restantes do vetor L 
    while (walkL < n1) {
        arr[k] = L[walkL];
        walkL++;
        k++;
    }

    // Copia os elementos restantes do vetor R 
    while (walkR < n2) {
        arr[k] = R[walkR];
        walkR++;
        k++;
    }
}

void mergeSort (vector<int>& arr, int inicio, int final) //! Divisão
{
    if (inicio < final) { // Dividindo em Subvetores
        int meio = inicio + (final - inicio) / 2;

        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, final);
        intercala(arr, inicio, meio, final);
    }

}

void printVector(vector<int>& arr)
{
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main ()
{
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    cout << "\tOriginal \n";
    printVector(arr);

    mergeSort(arr, 0, n - 1);

    cout << "\tOrdenado com Merge Sort \n";
    printVector(arr);

}