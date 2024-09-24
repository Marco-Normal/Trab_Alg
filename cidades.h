#ifndef CIDADES_H_
#define CIDADES_H_

typedef struct _cidade cidade;
/* Cria uma cidade. Parâmetro é o identificador único da cidade */
cidade *criar_cidade(int);
/* Conecta duas cidades, com parâmetro da distância entre elas */
int conectar_cidades(cidade *, cidade *, int);
/* Apaga a cidade */
int apagar_cidade(cidade **a);
#endif // CIDADES_H_
