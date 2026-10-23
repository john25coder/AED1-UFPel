#ifndef PERSONAGEM_H
#define PERSONAGEM_H

typedef struct personagem Personagem;

Personagem *personagem_cria(char *nome);
void personagem_atacar(Personagem *atacante, Personagem *alvo);
void personagem_curar(Personagem *p);
int personagem_vivo(Personagem *p);
void personagem_status(Personagem *p);
void personagem_libera(Personagem *p);

#endif
