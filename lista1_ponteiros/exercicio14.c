#include <stdio.h>
#include <stdlib.h>
int *intercalar(int *v1, int *v2, int n, int *n3) {
    if (!n3 || n < 0) return NULL;
    *n3 = 2 * n;
    if (n == 0) return NULL;
    int *v3 = malloc((size_t)*n3 * sizeof *v3);
    if (!v3) { *n3 = 0; return NULL; }
    for (int i = 0; i < n; i++) {
        v3[2 * i] = v1[i];
        v3[2 * i + 1] = v2[i];
    }
    return v3;
}
int main(void) {
    int a[] = {10, 20, 30}, b[] = {40, 50, 60}, n3;
    int *v = intercalar(a, b, 3, &n3);
    if (!v) return 1;
    for (int i = 0; i < n3; i++) printf("%d%c", v[i], i == n3 - 1 ? '\n' : ' ');
    free(v);
    return 0;
}
