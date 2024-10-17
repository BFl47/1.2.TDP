#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {

  unsigned char b;
  short s;
  int i;
  long l;
  float f;
  double d;
  char c;

	printf("unsigned char ");
  scanf("%c", &b);

	printf("short ");
  scanf("%hd", &s);

	printf("int ");
  scanf("%d", &i);

	printf("long ");
  scanf("%ld", &l);

	printf("float ");
  scanf("%f", &f);

	printf("double ");
  scanf("%lf", &d);

	printf("char ");
  scanf(" %c", &c);  // Notare lo spazio prima del %c. Questo consuma eventuali
	                   // caratteri bianchi, come '\n', rimasti nell'input buffer

  printf("\n1) %ld\n", b + 10 * l);
  printf("2) %ld\n", (b + i) * l);
  printf("3) %f\n", (b + i) * l + f);
  printf("4) %lf\n", s / f + sin(d));
  printf("5) %d\n", c == 'b');
  printf("6) %f\n", l + 1.5f);
  printf("7) %d\n", i < 10);
  printf("8) %f\n", d * 3.14159);
}
