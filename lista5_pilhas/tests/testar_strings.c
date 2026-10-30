#include "../exercicio09/pilha_strings.h"
#include <assert.h>
#include <stddef.h>
#include <string.h>

int main(void) {
    PilhaStrings *p = pilhaStrings_cria();
    assert(p != NULL);
    assert(pilhaStrings_vazia(p));
    assert(topString(p) == NULL);
    assert(!popString(p));
    assert(pushString(p, "google.com"));
    assert(pushString(p, "ufpel.edu.br"));
    assert(pushString(p, "wikipedia.org"));
    assert(strcmp(topString(p), "wikipedia.org") == 0);
    assert(popString(p));
    assert(strcmp(topString(p), "ufpel.edu.br") == 0);
    assert(popString(p));
    assert(strcmp(topString(p), "google.com") == 0);
    assert(popString(p));
    assert(pilhaStrings_vazia(p));
    pilhaStrings_libera(p);
    return 0;
}
