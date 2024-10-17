
#include "functions_fifo.h"


void stampa_sequenza()
{
	Coda *p = codaVuota();
	int numero;
	do {
		scanf("%d", &numero);
		inCoda(p, numero);
	} while (numero >= 0);

	puts("");
	while (!estCodaVuota(p)) {
		printf("%d\n", outCoda(p));
	}
}

int elemento_iesimo(Coda* c, int pos)
{
		while (pos >= 0 && !estCodaVuota(c))
		{
			if (pos == 0)
				return primoCoda(c);
			outCoda(c);
			--pos;
		}
		return -1;
}

void avoid_stampa(Coda* c, int elem)
{
	Coda *c2 = codaVuota();
	while (!estCodaVuota(c))
	{
		int out = outCoda(c);
		if (out != elem)
			printf("%d ", out);
		inCoda(c2, out);
	}

	while (!estCodaVuota(c2))
	{
		inCoda(c, outCoda(c2));
	}
	free(c2);
}

Coda* coda_circolare(Coda* c, int n)
{
    if(n<=0) 
        return codaVuota();

    if(estCodaVuota(c))
        return codaVuota();

    Coda* risultato = codaVuota();

    int i = 0;
    while(i<n)
    {
        int elem = outCoda(c);
        inCoda(risultato, elem);
        inCoda(c, elem);
        i++;
    }
    return risultato;
}

Coda* elementi_pari(Coda* c)
{

    Coda* nuovaCoda = codaVuota();

    int i=0;
    while(!estCodaVuota(c))
    {
        if(i%2==0)
        {
            inCoda(nuovaCoda, primoCoda(c));
        }
        outCoda(c);
        i++;
    }
    return nuovaCoda;
}
