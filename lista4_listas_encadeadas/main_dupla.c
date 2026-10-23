#include "lista_dupla.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    ListaDupla *l = duplaCriar();
    assert(duplaVazia(l));
    assert(!duplaRemoverInicio(l));
    assert(!duplaRemoverFinal(l));
    duplaInserirFinal(l, 20);
    duplaInserirInicio(l, 10);
    duplaInserirFinal(l, 30);
    int encontrado = 0;
    assert(duplaBuscar(l, 20, &encontrado) && encontrado == 20);
    assert(!duplaBuscar(l, 99, NULL));
    assert(duplaRemoverInicio(l));
    assert(!duplaBuscar(l, 10, NULL));
    assert(duplaRemoverFinal(l));
    assert(!duplaBuscar(l, 30, NULL));
    assert(duplaBuscar(l, 20, NULL));
    assert(duplaPalindromo(l));
    assert(duplaRemoverFinal(l));
    assert(duplaVazia(l));
    duplaInserirInicio(l, 42);
    assert(duplaRemoverInicio(l));
    assert(duplaVazia(l));
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
