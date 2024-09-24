#include "algoritmo.h"
#include "cidades.h"
#include <stdio.h>
#include <stdlib.h>
struct _caminho {
  cidade *lista;
  int custo;
  int tamanho;
};

caminho *criar_caminho(void) {
  caminho *c = (caminho *)malloc(sizeof(caminho));
  if (c == NULL) {
    fprintf(stderr, "Not enough memory. Couldn't create the path");
    return NULL;
  }
  c->lista = NULL;
  c->custo = 0;
  c->tamanho = 0;
  return c;
}

caminho *forca_bruta(cidade *lista) {
  if (lista == NULL) {
    fprintf(stderr, "The city list is invalid. Please try again");
    return NULL;
  }
}
