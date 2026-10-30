#ifndef FILA_DOCUMENTOS_H
#define FILA_DOCUMENTOS_H

typedef struct {
    int id;
    char nome[100];
    int paginas;
} Documento;

typedef struct fila_documentos FilaDocumentos;
FilaDocumentos *documentos_cria(void);
void documentos_libera(FilaDocumentos *fila);
void enqueueDocumento(FilaDocumentos *fila, Documento documento);
int dequeueDocumento(FilaDocumentos *fila, Documento *resultado);
int frontDocumento(const FilaDocumentos *fila, Documento *resultado);
int sizeDocumento(const FilaDocumentos *fila);
void printDocumentos(const FilaDocumentos *fila);

#endif
