#include <stdio.h>
#include <stdlib.h>

#include "pila.h"
#include "coda.h"

#include "functions_fifo.h"
#include "functions_lifo.h"

#include "utils.h"

int main()
{
    printf("Esercizio 10.1: \n");
    printf("\nSequenza inversa: ");
    stampa_sequenza_inversa();

    printf("Esercizio 10.2: \n");
    int arr_input_pila[6] = {6, 5, 4, 3, 2, 1};
    Coda* pila1 = initPila(arr_input_pila, 6);
    printf("Input pila: ");
    printPila(pila1);

    int arr_da_rimuovere[3] = {1, 2, 3};
    printf("\nArray da rimuovere: ");
    printIntArray(arr_da_rimuovere, 3);
    printf("Esecuzione rimuovi alcuni...\n");
    rimuovi_alcuni(pila1, arr_da_rimuovere, 3);
    printf("Output pila: ");
    printPila(pila1);

    printf("\n\nEsercizio 10.3/10.4: \n");
    const char* string = "aa";
    printf("Input: %s, ", string);
    printf("Palindromo (iterativo): %s, ", (check_palindrome(string) ? "true" : "false"));
    printf("Palindromo (ricorsivo): %s\n", (check_palindrome_r(string) ? "true" : "false"));

    string = "a";
    printf("Input: %s, ", string);
    printf("Palindromo (iterativo): %s, ", (check_palindrome(string) ? "true" : "false"));
    printf("Palindromo (ricorsivo): %s\n", (check_palindrome_r(string) ? "true" : "false"));

    string = "";
    printf("Input: %s, ", string);
    printf("Palindromo (iterativo): %s, ", (check_palindrome(string) ? "true" : "false"));
    printf("Palindromo (ricorsivo): %s\n", (check_palindrome_r(string) ? "true" : "false"));

    string = "abba";
    printf("Input: %s, ", string);
    printf("Palindromo (iterativo): %s, ", (check_palindrome(string) ? "true" : "false"));
    printf("Palindromo (ricorsivo): %s\n", (check_palindrome_r(string) ? "true" : "false"));

    string = "abb";
    printf("Input: %s, ", string);
    printf("Palindromo (iterativo): %s, ", (check_palindrome(string) ? "true" : "false"));
    printf("Palindromo (ricorsivo): %s\n", (check_palindrome_r(string) ? "true" : "false"));

    string = "145541";
    printf("Input: %s, ", string);
    printf("Palindromo (iterativo): %s, ", (check_palindrome(string) ? "true" : "false"));
    printf("Palindromo (ricorsivo): %s\n", (check_palindrome_r(string) ? "true" : "false"));



    printf("\n\nEsercizio 10.5: \n");
    int arr3[7] = {1, 3, 4, 2, 4, 2, 3};
    printf("Input array: ");
    printIntArray(arr3, 7);
    int* result3 = rimuoviMinori(arr3, 7);
    printf("Output array: ");
    printIntArray(result3, 4);



    printf("\n\nEsercizio 10.6: \n");
    stampa_sequenza();



    printf("\n\nEsercizio 10.7: \n");
    int arr5[4] = {1, 2, 3, 4};
    Coda* coda5 = initCoda(arr5, 4);
    printf("Input coda: ");
    printCoda(coda5);

    int pos = -2;
    printf("\n\nPosizione: %d, ", pos);
    printf("Elemento (dovrebbe essere -1): %d", elemento_iesimo(copiaCoda(coda5), pos));

    pos = 0;
    printf("\n\nPosizione: %d, ", pos);
    printf("Elemento (dovrebbe essere 1): %d", elemento_iesimo(copiaCoda(coda5), pos));

    pos = 2;
    printf("\n\nPosizione: %d, ", pos);
    printf("Elemento (dovrebbe essere 3): %d", elemento_iesimo(copiaCoda(coda5), pos));

    pos = 5;
    printf("\n\nPosizione: %d, ", pos);
    printf("Elemento (dovrebbe essere -1): %d", elemento_iesimo(copiaCoda(coda5), pos));



    printf("\n\nEsercizio 10.8: \n");
    int arr6[8] = {1, 2, -1, 4, -1, -1, 5, -1};
    Coda* coda6 = initCoda(arr6, 8);
    printf("Input coda: ");
    printCoda(coda6);

    printf("\nCoda senza elementi uguali a -1: ");
    avoid_stampa(coda6, -1);
    printf("\nInput coda dopo l'esecuzione: ");
    printCoda(coda6);



    printf("\n\nEsercizio 10.9: \n");
    int arr7[4] = {0, 1, 2, 3};
    Coda* coda7 = initCoda(arr7, 4);
    printf("Input coda: ");
    printCoda(coda7);

    printf("\nCoda circolare con 2 stampe: ");
    Coda* coda_circolare_1 = coda_circolare(copiaCoda(coda7), 2);
    printCoda(coda_circolare_1);

    printf("\nCoda circolare con 4 stampe: ");
    Coda* coda_circolare_2 = coda_circolare(copiaCoda(coda7), 4);
    printCoda(coda_circolare_2);

    printf("\nCoda circolare con 6 stampe: ");
    Coda* coda_circolare_3 = coda_circolare(copiaCoda(coda7), 6);
    printCoda(coda_circolare_3);

    printf("\nCoda circolare con 10 stampe: ");
    Coda* coda_circolare_4 = coda_circolare(copiaCoda(coda7), 10);
    printCoda(coda_circolare_4);

    printf("\n\nEsercizio 10.10: \n");
    int arr9[8] = {1, -1, 2, -1, 3, -1, 4, -1};
    Coda* coda9 = initCoda(arr9, 8);
    printf("Input coda: ");
    printCoda(coda9);

    printf("\nCoda senza elementi in posizione dispari: ");
    Coda* result2 = elementi_pari(coda9);
    printCoda(result2);
    printf("\n");

}
