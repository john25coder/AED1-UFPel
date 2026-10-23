#include "../lista3_tad_personagem/personagem.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    char nome[] = "Teste";
    Personagem *alvo = personagem_cria(nome);
    Personagem *atacante = personagem_cria("Atacante");
    assert(alvo && atacante && personagem_vivo(alvo));
    nome[0] = 'X';
    personagem_curar(alvo);
    personagem_status(alvo); /* nome copiado, vida inicial e limite de 100 */
    for (int i = 0; i < 6; i++) personagem_atacar(atacante, alvo);
    assert(!personagem_vivo(alvo));
    personagem_status(alvo); /* a vida nao fica negativa */
    personagem_curar(alvo);
    assert(personagem_vivo(alvo)); /* o enunciado nao proibe curar vida zero */
    personagem_status(alvo);
    for (int i = 0; i < 10; i++) personagem_curar(alvo);
    personagem_status(alvo);
    for (int i = 0; i < 5; i++) personagem_atacar(alvo, atacante);
    assert(!personagem_vivo(atacante));
    personagem_atacar(atacante, alvo);
    personagem_status(alvo); /* sem restricao adicional nao pedida no enunciado */
    personagem_curar(NULL);
    personagem_libera(alvo);
    personagem_libera(atacante);
    puts("TESTES_PERSONAGEM_OK");
    return 0;
}
