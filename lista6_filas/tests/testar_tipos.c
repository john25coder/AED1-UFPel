#include "../fila_clientes.h"
#include "../exercicio09/fila_circular.h"
#include "../exercicio10/fila_documentos.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    FilaClientes *clientes = clientes_cria();
    assert(clientes != NULL);
    Cliente c;
    assert(sizeCliente(clientes) == 0);
    assert(!dequeueCliente(clientes, &c));
    enqueueCliente(clientes, (Cliente){101, "Ana Silva"});
    enqueueCliente(clientes, (Cliente){102, "Joao Souza"});
    assert(sizeCliente(clientes) == 2);
    assert(frontCliente(clientes, &c) && c.numero == 101);
    assert(dequeueCliente(clientes, &c) && strcmp(c.nome, "Ana Silva") == 0);
    assert(dequeueCliente(clientes, &c) && c.numero == 102);
    assert(!frontCliente(clientes, &c));
    enqueueCliente(clientes, (Cliente){103, "Carlos Lima"});
    assert(dequeueCliente(clientes, &c) && c.numero == 103);
    clientes_libera(clientes);

    FilaCircular circular;
    circular_inicializa(&circular);
    assert(circular_vazia(&circular));
    assert(circular_quantidade(&circular) == 0);
    for (int i = 1; i <= CAPACIDADE_UTIL; i++) {
        Cliente novo = {i, "Cliente"};
        assert(circular_enqueue(&circular, novo));
    }
    assert(circular_cheia(&circular));
    assert(!circular_enqueue(&circular, (Cliente){999, "Excesso"}));
    assert(circular_quantidade(&circular) == CAPACIDADE_UTIL);
    assert(circular_dequeue(&circular, &c) && c.numero == 1);
    assert(circular_dequeue(&circular, &c) && c.numero == 2);
    assert(circular_enqueue(&circular, (Cliente){6, "Sexto"}));
    assert(circular_enqueue(&circular, (Cliente){7, "Setimo"}));
    assert(circular_cheia(&circular));
    assert(circular_front(&circular, &c) && c.numero == 3);
    for (int i = 3; i <= 7; i++) assert(circular_dequeue(&circular, &c) && c.numero == i);
    assert(circular_vazia(&circular));
    assert(!circular_dequeue(&circular, &c));
    assert(circular_enqueue(&circular, (Cliente){8, "Oitavo"}));
    assert(circular_dequeue(&circular, &c) && c.numero == 8);

    FilaDocumentos *docs = documentos_cria();
    assert(docs != NULL);
    Documento doc;
    assert(sizeDocumento(docs) == 0);
    assert(!dequeueDocumento(docs, &doc));
    enqueueDocumento(docs, (Documento){1, "Relatorio.pdf", 5});
    enqueueDocumento(docs, (Documento){2, "Resumo.pdf", 2});
    enqueueDocumento(docs, (Documento){3, "O Hobbit.pdf", 328});
    assert(frontDocumento(docs, &doc) && doc.id == 1);
    assert(sizeDocumento(docs) == 3);
    assert(dequeueDocumento(docs, &doc) && doc.paginas == 5);
    assert(dequeueDocumento(docs, &doc) && strcmp(doc.nome, "Resumo.pdf") == 0);
    assert(dequeueDocumento(docs, &doc) && doc.id == 3);
    assert(!frontDocumento(docs, &doc));
    documentos_libera(docs);

    puts("Lista 6: clientes, fila circular e documentos aprovados.");
    return 0;
}
