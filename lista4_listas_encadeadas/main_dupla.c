#include "lista_dupla.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    ListaDupla *l = duplaCriar();
    assert(duplaPalindromo(l));
    assert(!duplaRemoverPrimeiraOcorrencia(l, 99));
    int v[] = {10,20,30,20,10};
    for (int i = 0; i < 5; i++) duplaInserirFinal(l, v[i]);
    assert(duplaPalindromo(l));
    assert(duplaRemoverPrimeiraOcorrencia(l, 30));
    assert(duplaPalindromo(l)); /* par e palindromo */
    assert(duplaRemoverPrimeiraOcorrencia(l, 10)); /* cabeca */
    assert(!duplaPalindromo(l));
    assert(duplaRemoverPrimeiraOcorrencia(l, 10)); /* cauda */
    assert(duplaPalindromo(l));
    assert(duplaRemoverPrimeiraOcorrencia(l, 20));
    assert(duplaPalindromo(l));
    assert(duplaRemoverPrimeiraOcorrencia(l, 20));
    assert(duplaPalindromo(l));
    assert(!duplaRemoverPrimeiraOcorrencia(l, 20));
    duplaInserirFinal(l, 11);
    duplaInserirFinal(l, 22);
    duplaInserirFinal(l, 33);
    assert(!duplaPalindromo(l));
    printf("Testes de lista duplamente encadeada passaram.\n");
    duplaImprimir(l);
    duplaLiberar(l);
    return 0;
}
