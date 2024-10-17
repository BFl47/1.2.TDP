#include <stdio.h>

int main()
{

  printf("Digita il tuo nome e ti diro' chi sei:\n");

  char c;

  //Leggi il primo carattere
  //NOTA: usando la stringa di formato '%c' NON vengono consumati eventuali
  //caratteri "blank" (' ' o caratteri speciali come '\n' o '\t')
  scanf("%c", &c);

  int somma = 0;

  //Se il carattere letto è un simbolo di 'newline' (che corrisponde alla pressione del tasto ENTER), 
  //termina il ciclo di lettura 
  while (c != '\n')
  {
    //Trasforma caratteri upper-case in lower-case
    if (c >= 'A' && c <= 'Z')
    {
      c = c + ('a' - 'A');
    }
    somma += c;
    scanf("%c", &c);
  }

  //Finché la somma delle cifre non è compresa tra 1 e 9 oppure uguale ad 11 o a 22...
  while (somma > 9 && somma != 11 && somma != 22)
  {
    int s1 = somma;
    somma = 0;
    //... ottieni una nuova somma, sommando le single cifre della somma precedente
    while (s1 > 0)
    {
      somma += s1 % 10;
      s1 /= 10;
    }
  }
  printf("il tuo numero e': %d\n", somma);

  switch (somma)
  {
  case 1:
    printf(" Dotato di spirito di iniziativa, intraprendente, capace di comandare, indipendente, determinato, individualista.\n");
    break;
  case 2:
    printf(" Collaborativo, versatile, rispettoso, capace lavorare in team, buon mediatore.\n");
    break;
  case 3:
    printf(" Auto-espressione, comunicatività, socializzazione, vena artistica, entusiasmo verso la vita.\n");
    break;
  case 4:
    printf(" Valori forti, ordine, dedizione, ribellione, in costante evoluzione.\n");
    break;
  case 5:
    printf(" Espansivo, visionario, avventuroso, uso costruttivo della liberta'�.\n");
    break;
  case 6:
    printf(" Responsabile, protettivo, premuroso, di supporto, disponibile verso la comunita'�, equilibrato, compassionevole.\n");
    break;
  case 7:
    printf(" Spirito analitico, comprensivo, preparato, consapevole, studioso, riflessivo.\n");
    break;
  case 8:
    printf(" Ambizioso, che punta al prestigio e al potere, materialista.\n");
    break;
  case 9:
    printf(" Filantropo, generoso, altruista, creativo, forte senso del dovere.\n");
    break;
  case 11:
    printf(" Spirituale, intuitivo, ascetico, idealista, sognatore.\n");
    break;
  case 22:
    printf(" (in numerologia il numero 22 e' considerato il piu' potente di tutti, per questo viene definito spesso \"Master builder\"): Temerario, forte, abile nel comandare.\n");
    break;
  }
}
