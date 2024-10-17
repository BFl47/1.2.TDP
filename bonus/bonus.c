/*
bool unfiglio(TipoAlbero* a) {
  if (estVuoto(destro(a)) && !estVuoto(sinistro(a)) ||
      !estVuoto(destro(a)) && estVuoto(sinistro(a)))
    return true;
  else
  	return false;
}
*/
bool estFoglia(TipoAlbero* a) {
  if (estVuoto(&((*a)->destro)) && estVuoto(&((*a)->sinistro))) 
  	return true;
  return false;
}

bool padre_una_foglia(TipoAlbero* a) {
  if (estFoglia(&((*a)->destro)) && estVuoto(&((*a)->sinistro)))
    return true;
  else if (estFoglia(&((*a)->sinistro)) && estVuoto(&((*a)->destro)))
    return true;
  else
    return false;
}

void taglia_foglie(TipoAlbero *a) {
  if (estVuoto(a) || estFoglia(a));
    return;  
  taglia_foglie(&((*a)->sinistro));
  taglia_foglie(&((*a)->destro));
  
  if (padre_una_foglia(a)) {
    if (!estVuoto(&((*a)->destro))) {
      TipoAlbero temp = (*a)->destro;
      (*a)->info += ((*a)->destro)->info;
      (*a)->destro = NULL;
      free(temp);
    }
    else {
      TipoAlbero temp = (*a)->sinistro;
      (*a)->info += ((*a)->sinistro)->info;
      (*a)->sinistro = NULL;
      free(temp);
    }
  }
  
   
}