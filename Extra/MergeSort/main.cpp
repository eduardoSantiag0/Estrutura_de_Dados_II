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

    cout << 
    "\n\t=====================================================================\n"
    "\t Uau! Um brilho dourado ilumina a sala escura...\n"
    "\t Voce encontrou uma tiara rosa reluzente! \n"
    "\t Dizem que pertence a uma princesa encantada que habita o topo da masmorra.\n"
    "\t Sera que voce conseguira leva-la ate ela? A jornada sera perigosa...\n"
    "\t=====================================================================\n";

    cout << 
        "                   ,_  .--.\n"
        "             , ,   _)\\/    ;--.\n"
        "     . ' .    \\_\\-'   |  .'    \\\n"
        "    -= * =-   (.-,   /  /       |\n"
        "     ' .\\'    ).  ))/ .'   _/\\ /\n"
        "         \\_   \\_  /( /     \\ /(\n"
        "         /_\\ .--'   `-.    //  \\\n"
        "         ||\\/        , '._//    |\n"
        "         ||/ /`(_ (_,;`-._/     /\n"
        "         \\_.'   )   /`\\       .'\n"
        "              .' .  |  ;.   /`\n"
        "             /      |\\(  `.(\n"
        "            |   |/  | `    `\n"
        "            |   |  /\n"
        "            |   |.'\n"
        "         __/'  /\n"
        "     _ .'  _.-`\n"
        "  _.` `.-;`/\n"
        " /_.-'` / /\n"
        "       | /\n"
        "      ( /\n"
        "     /_/\n";


    cout << 
    "\n\t=====================================================================\n"
    "\t As montanhas deram lugar a cerejeiras floridas... \n"
    "\t Voce chegou ao  Japao Feudal!\n"
    "\t A lenda fala de uma peca magica de Go escondida no castelo do Shogun.\n"
    "\t Apenas os mais bravos poderao encontra-la e desvendar o caminho de volta.\n"
    "\t=====================================================================\n";


    cout << 
        "                )\\         O_._._._A_._._._O         /( \n"
        "                \\`--.___,'=================`.___,--'/ \n"
        "                 \\`--._.__                 __._,--'/ \n"
        "                   \\  ,. l`~~~~~~~~~~~~~~~'l ,.  / \n"
        "       __            \\||(_)!_!_!_.-._!_!_!(_)||/            __ \n"
        "       \\\\`-.__        ||_|____!!_|;|_!!____|_||        __,-'// \n"
        "        \\\\    `==---='-----------'='-----------`=---=='    // \n"
        "        | `--.                                         ,--' | \n"
        "         \\  ,.`~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~',.  / \n"
        "           \\||  ____,-------._,-------._,-------.____  ||/ \n"
        "            ||\\|___!`=======\"!`=======\"!`=======\"!___|/|| \n"
        "            || |---||--------||-| | |-!!--------||---| || \n"
        "  __O_____O_ll_lO_____O_____O|| |'|'| ||O_____O_____Ol_ll_O_____O__ \n"
        "  o H o o H o o H o o H o o |-----------| o o H o o H o o H o o H o \n"
        " ___H_____H_____H_____H____O =========== O____H_____H_____H_____H___ \n"
        "                          /|=============|\\ \n"
        "()______()______()______() '==== +-+ ====' ()______()______()______() \n"
        "||{_}{_}||{_}{_}||{_}{_}/| ===== |_| ===== |\\{_}{_}||{_}{_}||{_}{_}|| \n"
        "||      ||      ||     / |==== s(   )s ====| \\     ||      ||      || \n"
        "======================()  =================  ()====================== \n"
        "----------------------/| ------------------- |\\---------------------- \n"
        "                     / |---------------------| \\ \n"
        "-'--'--'           ()  '---------------------'  () \n"
        "                   /| ------------------------- |\\    --'--'--' \n"
        "       --'--'     / |---------------------------| \\    '--' \n"
        "                ()  |___________________________|  ()           '--'- \n"
        "  --'-          /| _______________________________  |\\ \n"
        " --'           / |__________________________________| \\ \n";

}