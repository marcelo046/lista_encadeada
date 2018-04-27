
struct LISTA {
  int num;
  struct LISTA *prox;
};

typedef struct LISTA lista;



// ====================================
int nulo(lista *a) {
  return (a == NULL);
}
// ====================================
lista *alocaInicio(lista *a, int n) {
  lista *aux = (lista *)malloc(sizeof(lista));
  if(nulo(aux)) {
    printf("deu ruim\n");
    return a;
  }

  aux->num = n;

  if(nulo(a)) {
    aux->prox = NULL;
    return aux;
  }

  aux->prox = a;
  return aux;

}

// ====================================
lista *iniciaLista() {
  return NULL;
}

// ====================================
lista *alocaFim(lista *a, int n) {
  lista *novo = (lista *)malloc(sizeof(lista));
  if(nulo(novo)) {
    printf("deu ruim\n");
    return a;
  }
  novo->num = n;
  novo->prox = NULL;

  if(nulo(a))
    return novo;

  lista *aux = a;

  while (!nulo(aux->prox))
    aux = aux->prox;

  aux->prox = novo;

  return a;
}

// ====================================
lista *alocaMeio(lista *a, int n, int pos) {
  lista *novo = (lista *)malloc(sizeof(lista));
  lista *aux = a;
  int i = 0;

  if(pos < 0) {
    printf("nao existe posicao negativa!\n");
    return a;
  }

  if(nulo(novo)) {
    printf("deu ruim\n");
    return a;
  }
  novo->num = n;
  novo->prox = NULL; // aponta para nulo temporariamente

  if(nulo(a)) {
    printf("Lista estah vazia, alocando item no comeco\n");
    return novo;
  }

  if (pos == 0)
    return alocaInicio(a, n);

  while (i < pos-1) {
    if (nulo(aux->prox)) {
      printf("valor dado fora do tamanho da lista!\n");
      printf("inserindo item no fim.\n");
      aux->prox = novo;
      return a;
    }
    aux = aux->prox;
    // verif se chegou no fim
    i++;
  }
  novo->prox = aux->prox;
  aux->prox = novo;

  return a;
}


// ====================================
void imprime(lista *a) {
  lista *aux;
  if (nulo(a)) {
    printf("lista nula!\n");
  } else {
    printf("====  lista ====\n\n");
    for (aux = a; aux != NULL; aux = aux->prox)
      printf("|%5d ", aux->num);
    printf("|\n\n");
  }
}

// ====================================
lista *libera(lista *a) {
  lista *aux;
  if (nulo(a))
    return NULL;
  aux = a;
  a = a->prox;
  free(aux);
  return libera(a);
}
/*lista *libera(lista *a) {
  lista *aux = a;

  while (!nulo(aux)) {
    aux = aux->prox;
    free(a);
    a = aux;
  }
  return NULL;
}*/
