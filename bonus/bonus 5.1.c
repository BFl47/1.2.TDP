void max_alb_aux(TipoAlbero a, int* array, int lv) {
  if (estVuoto(a))
    return;
  array[lv] += 1;
  max_alb_aux(sinistro(a), array, lv+1);
  max_alb_aux(destro(a), array, lv+1);    
}

int max_albero(TipoAlbero a) {
  if (estVuoto(a))
    return -1;
  int* array = (int*) calloc(10, sizeof(int));
  max_alb_aux(a, array, 0);
  int massimo = 0;
  int pos = 0;
  for (int i = 0; i<10; i++) {
    if (array[i] > massimo) {
      massimo = array[i];
      pos = i;
  	}
  }
  free(array);
  return pos;	
}
