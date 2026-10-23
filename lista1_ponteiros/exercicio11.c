#include <stdio.h>
#include <stdlib.h>
int *concatenar(int *v1, int n1, int *v2, int n2, int *n3) {
    if (!n3 || n1 < 0 || n2 < 0) return NULL;
    *n3 = n1 + n2;
    if (*n3 == 0) return NULL;
    int *v3 = malloc((size_t)*n3 * sizeof *v3);
    if (!v3) { *n3 = 0; return NULL; }
    for (int i = 0; i < n1; i++) v3[i] = v1[i];
    for (int i = 0; i < n2; i++) v3[n1 + i] = v2[i];
    return v3;
}
int main(void) {
    int n1 = 3, n2 = 2, n3 = 0;
    int *v1 = malloc((size_t)n1 * sizeof *v1);
    int *v2 = malloc((size_t)n2 * sizeof *v2);
    if (!v1 || !v2) { free(v1); free(v2); return 1; }
    v1[0] = 10; v1[1] = 20; v1[2] = 30;
    v2[0] = 40; v2[1] = 50;
    int *v3 = concatenar(v1, n1, v2, n2, &n3);
    if (!v3) { free(v1); free(v2); return 1; }
    for (int i = 0; i < n3; i++) printf("%d%c", v3[i], i == n3 - 1 ? '\n' : ' ');
    printf("n3 = %d\n", n3);
    free(v1); free(v2); free(v3);
    return 0;
}
