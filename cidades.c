#include "cidades.h"
#include <stdio.h>
#include <stdlib.h>

struct _cidade {
  int distancia;
  int identificador;
  cidade *conexao;
};

cidade *criar_cidade(int identificador) {
  /**
   * @brief      Cria uma cidade com um identificador único
   *
   * @details    Realiza a alocação de uma cidade, com um identificador
   *             númerico único. Como ela é uma cidade única, ela não
   *             possui conexão, nem uma distância para a conexão. Portanto
   *             Ela é inicializada no -1 e NULL, respectivamente.
   *
   * @param      int identificador
   *
   * @return     cidade *
   *
   * @notes      A distância é inicializada no -1 para mostrar que é inválida.
   *             será usada para checar.
   */

  cidade *city = (cidade *)malloc(sizeof(cidade));
  if (city == NULL) {
    fprintf(stderr, "Couldn't allocate enough! The city wasn't created");
    return city;
  }
  city->identificador = identificador;
  city->distancia = -1;
  city->conexao = NULL;
  return city;
}

int conectar_cidades(cidade *a, cidade *b, int distancia) {
  /**
   * @brief      Realiza a conexão entre 2 cidades
   *
   * @details    Conecta a cidade a na cidade b, colocando
   *             a distância no campo da cidade a. Realiza a checagem
   *             se os ponteiros são válidos, bem como a distância. Retorna
   *             1 se deu certo, -1 se deu erro
   *
   * @param      cidade *a
   * @param      cidade *b
   * @param      int distancia
   *
   * @return     int
   */

  if (a == NULL || b == NULL) {
    fprintf(stderr, "The cities are invalid. Please check it");
    return -1;
  }
  if (distancia < 0) {
    fprintf(stderr, "The distance is invalid");
    return -1;
  }
  a->conexao = b;
  a->distancia = distancia;
  return 1;
}

int apagar_cidade(cidade **a) {
  free(*a);
  return 1;
}
