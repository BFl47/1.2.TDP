TipoLista copia(TipoLista list) {
  if (estVuota(list))
    return listaVuota();
  else {
    TipoLista ris = cons(car(list), copia(cdr(list)));
    return ris;
  }
}

TipoLista append(TipoLista list, T elem) {
  if (estVuota(list))
    return cons(elem, listaVuota());
  else {
    TipoLista ris = cons(car(list), append(cdr(list), elem));
  	return ris;
  }
}

TipoLista append_almeno_5(TipoLista list, T elem) {
  if (estVuota(list) && elem < 5)
    return copia(list);
  else if (elem >= 5) {
    TipoLista ris = copia(list);
    ris = append(ris, elem);
    return ris;
  }
  else if (elem < 5)
    return copia(list); 
}

TipoLista inverti_numeri_alti(TipoLista list) {
  TipoLista ris = listaVuota();
  if (estVuota(list))
    return listaVuota();
  else //if (car(list) >= 5) 
    return append_almeno_5(inverti_numeri_alti(cdr(list)), car(list));
   //else     return inverti_numeri_alti(cdr(list));
}