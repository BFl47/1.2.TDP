#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  int d;
  printf("Inserire il raggio del cerchio (intero): ");
  scanf("%d", &d);

  if(d < 1) {
    printf("Il raggio deve essere un intero strettamente positivo!\n");
    return -1;
  }

  int dd = d * d; 
  //Itera sulle "righe" del quadrato in cui disegneremo il cerchio
  for(int r = -d; r <= d; ++r) {
    int rr = r * r;
    //Itera sulle "colonne" del quadrato in cui disegneremo il cerchio
    for(int c = -d; c <= d; ++c) {
      int cc = c * c;
      //Calcola la distanza della "cella" (r,c) dal centro del quadrato (il cerchio è centrato in (d,d))
      int interno = rr + cc <= dd; //Verifica sulla distanza (ma al quadrato)
      //NOTA: L'operatore "<=" rende l'espressione a destra dell'uguale un'espressione logica (booleana):
      //a seconda della verità o falsità di tale espressione, essa restituirà 1 (vero) o 0 (falso)
      
      printf((interno)? "*": "-");
    }
    printf("\n");
  }

  return 0;
} 
