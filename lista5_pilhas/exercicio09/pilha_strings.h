#ifndef PILHA_STRINGS_H
#define PILHA_STRINGS_H

typedef struct pilha_strings PilhaStrings;
PilhaStrings *pilhaStrings_cria(void);
void pilhaStrings_libera(PilhaStrings *pilha);
int pilhaStrings_vazia(const PilhaStrings *pilha);
int pushString(PilhaStrings *pilha, const char *pagina);
int popString(PilhaStrings *pilha);
const char *topString(const PilhaStrings *pilha);
void printStrings(const PilhaStrings *pilha);

#endif
