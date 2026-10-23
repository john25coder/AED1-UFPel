#include "personagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct personagem {
    char *nome;
    int vida;
    int ataque;
};

Personagem *personagem_cria(char *nome) {
    if (!nome) return NULL;
    Personagem *p = malloc(sizeof *p);
    if (!p) return NULL;
    p->nome = malloc(strlen(nome) + 1);
    if (!p->nome) { free(p); return NULL; }
    strcpy(p->nome, nome);
    p->vida = 100;
    p->ataque = 20;
    return p;
}

int personagem_vivo(Personagem *p) { return p != NULL && p->vida > 0; }

void personagem_atacar(Personagem *atacante, Personagem *alvo) {
    if (!personagem_vivo(atacante) || !personagem_vivo(alvo)) return;
    alvo->vida -= atacante->ataque;
    if (alvo->vida < 0) alvo->vida = 0;
}

void personagem_curar(Personagem *p) {
    if (!p) return;
    /* O enunciado nao determina o valor da cura: foi adotado +20. */
    p->vida += 20;
    if (p->vida > 100) p->vida = 100;
}

void personagem_status(Personagem *p) {
    if (!p) return;
    printf("%s: vida=%d, ataque=%d, vivo=%s\n",
           p->nome, p->vida, p->ataque, personagem_vivo(p) ? "sim" : "nao");
}

void personagem_libera(Personagem *p) {
    if (p) { free(p->nome); free(p); }
}
