#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main(int argc, char const *argv[]) {
  lista *a = iniciaLista(); // lista *a = NULL

  a = alocaInicio(a, 50);
  a = alocaInicio(a, 30);

  a = alocaMeio(a, 41, 1);
  //a = alocaFim(a, 2);


  imprime(a);

  a = libera(a);

  imprime(a);

  return 0;
}
