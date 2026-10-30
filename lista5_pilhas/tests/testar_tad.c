#include "../pilha.h"
#include <assert.h>
#include <stddef.h>

int main(void) {
    Pilha *p = pilha_cria();
    assert(p != NULL);
    assert(empty(p) && size(p) == 0);
    push(p, (Elem){'A'});
    push(p, (Elem){'B'});
    assert(!empty(p) && size(p) == 2);
    assert(pop(p).carac == 'B');
    assert(pop(p).carac == 'A');
    assert(empty(p) && size(p) == 0);
    for (int i = 0; i < 100; ++i) push(p, (Elem){(char)('a' + i % 26)});
    assert(size(p) == 100);
    reset(p);
    assert(empty(p) && size(p) == 0);
    push(p, (Elem){'Z'});
    clear(p);
    assert(empty(p));
    pilha_libera(p);
    pilha_libera(NULL);
    return 0;
}
