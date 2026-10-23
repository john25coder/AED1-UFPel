# Lista 3 — TAD Personagem

`personagem.h` publica **apenas** a interface; a estrutura `struct personagem` aparece apenas em `personagem.c`.

```sh
make
./programa
make clean
```

O enunciado define os limites da cura, mas não a quantidade restaurada; foi adotado **+20 pontos**, inclusive quando a vida é zero, sem ultrapassar 100. O ataque reduz a vida do alvo em 20, com limite inferior zero, sem impor uma condição adicional de vida ao atacante.
