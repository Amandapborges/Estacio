#include <stdio.h>

int main() {
    // Movimento da Torre (do desafio anterior)
    printf("Movimento da Torre:\n");
    for(int i = 0; i < 5; i++) {
        printf("Direita\n");
    }
    
    // Movimento do Bispo (do desafio anterior)
    printf("\nMovimento do Bispo:\n");
    int movimentos = 0;
    while(movimentos < 3) {
        printf("Diagonal superior direita\n");
        movimentos++;
    }
    
    // Movimento do Cavalo (novo desafio)
    printf("\nMovimento do Cavalo:\n");
    
    // Definindo constantes para o movimento do cavalo
    const int MOVIMENTOS_BAIXO = 2;
    const int MOVIMENTOS_ESQUERDA = 1;
    
    // Primeira parte do L: 2 movimentos para baixo
    for(int i = 0; i < MOVIMENTOS_BAIXO; i++) {
        printf("Baixo\n");
    }
    
    // Segunda parte do L: 1 movimento para esquerda
    int contador = 0;
    do {
        printf("Esquerda\n");
        contador++;
    } while(contador < MOVIMENTOS_ESQUERDA);
    
    return 0;
}