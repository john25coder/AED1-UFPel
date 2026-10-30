#ifndef FILA_CLIENTES_H
#define FILA_CLIENTES_H

#include "cliente.h"

typedef struct fila_clientes FilaClientes;
FilaClientes *clientes_cria(void);
void clientes_libera(FilaClientes *fila);
void enqueueCliente(FilaClientes *fila, Cliente cliente);
int dequeueCliente(FilaClientes *fila, Cliente *resultado);
int frontCliente(const FilaClientes *fila, Cliente *resultado);
int sizeCliente(const FilaClientes *fila);
void printClientes(const FilaClientes *fila);

#endif
