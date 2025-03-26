#include <stdio.h>
#include <stdbool.h>

// Tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Representação dos elementos
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se a posição do navio é válida
bool posicaoValida(int linha, int coluna, int tamanho, bool vertical) {
    if (vertical) {
        // Verifica se o navio vertical cabe no tabuleiro
        return (linha >= 0) && (linha + tamanho - 1 < TAMANHO_TABULEIRO) && 
               (coluna >= 0) && (coluna < TAMANHO_TABULEIRO);
    } else {
        // Verifica se o navio horizontal cabe no tabuleiro
        return (linha >= 0) && (linha < TAMANHO_TABULEIRO) && 
               (coluna >= 0) && (coluna + tamanho - 1 < TAMANHO_TABULEIRO);
    }
}

// Função para verificar sobreposição de navios
bool semSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                    int linha, int coluna, int tamanho, bool vertical) {
    if (vertical) {
        for (int i = linha; i < linha + tamanho; i++) {
            if (tabuleiro[i][coluna] != AGUA) {
                return false;
            }
        }
    } else {
        for (int j = coluna; j < coluna + tamanho; j++) {
            if (tabuleiro[linha][j] != AGUA) {
                return false;
            }
        }
    }
    return true;
}

// Função para posicionar um navio no tabuleiro
bool posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                    int linha, int coluna, int tamanho, bool vertical) {
    // Verifica se a posição é válida e não há sobreposição
    if (!posicaoValida(linha, coluna, tamanho, vertical) || 
        !semSobreposicao(tabuleiro, linha, coluna, tamanho, vertical)) {
        return false;
    }
    
    // Posiciona o navio
    if (vertical) {
        for (int i = linha; i < linha + tamanho; i++) {
            tabuleiro[i][coluna] = NAVIO;
        }
    } else {
        for (int j = coluna; j < coluna + tamanho; j++) {
            tabuleiro[linha][j] = NAVIO;
        }
    }
    
    return true;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro de Batalha Naval:\n");
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j); // Cabeçalho das colunas
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i); // Cabeçalho das linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);
    
    // Define as coordenadas dos navios (poderiam ser lidas do usuário)
    int linhaNavioVertical = 2, colunaNavioVertical = 4;
    int linhaNavioHorizontal = 5, colunaNavioHorizontal = 1;
    
    // Tenta posicionar o navio vertical
    if (!posicionarNavio(tabuleiro, linhaNavioVertical, colunaNavioVertical, 
                        TAMANHO_NAVIO, true)) {
        printf("Erro: Não foi possível posicionar o navio vertical nas coordenadas (%d, %d)\n", 
               linhaNavioVertical, colunaNavioVertical);
        return 1;
    }
    
    // Tenta posicionar o navio horizontal
    if (!posicionarNavio(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal, 
                        TAMANHO_NAVIO, false)) {
        printf("Erro: Não foi possível posicionar o navio horizontal nas coordenadas (%d, %d)\n", 
               linhaNavioHorizontal, colunaNavioHorizontal);
        return 1;
    }
    
    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);
    
    return 0;
}