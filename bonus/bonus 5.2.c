
void crescente_aux(TipoAlbero a, int* array, int lv) {
  if (estVuoto(a))
    return;
  array[lv] += radice(a);
  crescente_aux(sinistro(a), array, lv + 1);
  crescente_aux(destro(a), array, lv + 1);
}

int crescente(TipoAlbero a) {
  if (estVuoto(a))
  	return -1;
  int* array = (int*) calloc(10, sizeof(int));
  crescente_aux(a, array, 0);
  bool crescente = true;
  int pos;
  for (int i = 0; i<9; i++) {
    if (array[i] <= array[i+1]) 
      crescente = true;
    else if (array[i] > array[i+1] && array[i+1] != 0) {
      crescente = false;
      pos = i+1;
      break;
    }
  }
  if (crescente) 
    return -1;
  else 
    return pos;
    	
}
