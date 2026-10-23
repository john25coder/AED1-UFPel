#include <stdio.h>
void min_max(int *v, int n, int *min, int *max) {
    if (n <= 0 || v == NULL || min == NULL || max == NULL) return;
    *min = *max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < *min) *min = v[i];
        if (v[i] > *max) *max = v[i];
    }
}
int main(void) {
    int v[] = {9, 2, 12, -4, 7};
    int menor = 0, maior = 0;
    min_max(v, 5, &menor, &maior);
    printf("Menor: %d | Maior: %d\n", menor, maior);
    return 0;
}
