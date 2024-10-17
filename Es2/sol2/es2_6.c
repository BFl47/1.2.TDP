#include <stdio.h>

const int MAX_PRINTS = 10;
const int PRIMO_CARATTERE_ALFANUMERICO_ASCII = 48;

int main()
{

    int i;
    printf("Inserisci un numero intero:\n");
    scanf("%d", &i);

    int j = 0;
    while(j==0)
    {
        printf("Inserisci un altro numero intero (non nullo):\n");
        scanf("%d", &j);
    }

    double k = (double) i / j;
    //NOTA: in questo caso basta convertire uno solo dei due operandi a float
    //affinché il risultato sia float (il cast è automatico quando la 
    //conversione non comporta una perdita di informazione!). 
    
    //Se non avessimo usato il cast esplicito a float, il risultato sarebbe 
    //stato inizialmente calcolato come int (perciò la parte decimale sarebbe 
    //stata troncata!) e dunque convertito a float (tipo della variabile a sinistra 
    //dell'assegnazione)

    double temp = k - (int) k; //Otteniamo la parte decimale sottraendo la parte intera
                              //NOTA: (int) k troncherà la parte decimale dell'intero k
                              //restituendone solo la parte intera
    
    int p = 0;
    while(temp > 0 && p<MAX_PRINTS){

        //"Spostiamo" la prima cifra decimale a sinistra della virgola
        temp *= 10;

        //Otteniamo tale cifra tramite troncamento della parte decimale
        int cifra = (int) temp;

        //Salviamo in temp la restante parte decimale
        temp = temp - (int) temp;

        //printf("%d\n", cifra);

        char carattere_alfanumerico_cifra = (char) (cifra + PRIMO_CARATTERE_ALFANUMERICO_ASCII + p);
        printf("%c\n", carattere_alfanumerico_cifra);

        p++;
    }
    return 0;
}
