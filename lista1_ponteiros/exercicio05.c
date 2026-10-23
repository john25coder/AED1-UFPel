#include <stdio.h>
void inverter(int *v, int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = temp;
    }
}
int main(void) {
    int v[] = {10, 20, 30, 40, 50};
    inverter(v, 5);
    for (int i = 0; i < 5; i++) printf("%d%c", v[i], i == 4 ? '\n' : ' ');
    return 0;
}
