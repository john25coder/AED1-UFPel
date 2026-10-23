#include "personagem.h"
#include <stdio.h>

int main(void) {
    Personagem *ana = personagem_cria("Ana");
    Personagem *bruno = personagem_cria("Bruno");
    if (!ana || !bruno) {
        fputs("Erro de memoria\n", stderr);
        personagem_libera(ana);
        personagem_libera(bruno);
        return 1;
    }
    personagem_status(ana);
    personagem_status(bruno);
    personagem_atacar(ana, bruno);
    personagem_status(bruno);
    personagem_curar(bruno);
    personagem_status(bruno);
    for (int i = 0; i < 5; i++) personagem_atacar(ana, bruno);
    personagem_status(bruno);
    printf("Bruno esta vivo? %d\n", personagem_vivo(bruno));
    personagem_libera(ana);
    personagem_libera(bruno);
    return 0;
}
