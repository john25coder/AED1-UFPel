#include "../exercicio06/pilha.h"
#include <assert.h>
#include <stddef.h>

int main(void) {
    Pilha *p = pilha_cria();
    assert(p != NULL);
    remover(p, 2.5f);
    assert(empty(p));
    push(p, 1.0f);
    push(p, 2.5f);
    push(p, 3.0f);
    push(p, 2.5f);
    push(p, 4.0f);
    remover(p, 2.5f);
    assert(size(p) == 3);
    assert(pop(p) == 4.0f);
    assert(pop(p) == 3.0f);
    assert(pop(p) == 1.0f);
    remover(p, 2.5f);
    assert(empty(p));
    push(p, 7.0f);
    push(p, 7.0f);
    remover(p, 7.0f);
    assert(empty(p));
    pilha_libera(p);
    return 0;
}
