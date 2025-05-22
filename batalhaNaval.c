#include <stdio.h>

// Tamanho fixo do tabuleiro e dos navios
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Função para imprimir o tabuleiro (fora do main!)
void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Declaração do tabuleiro
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicialização com 0 (água)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Representação dos navios
    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;
    int linhaVertical = 5;
    int colunaVertical = 7;

    // Posicionamento horizontal
    if (colunaHorizontal + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro: navio horizontal fora do tabuleiro.\n");
        return 1;
    }

    // Posicionamento vertical
    if (linhaVertical + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] == 0) {
                tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
            } else {
                printf("Erro: sobreposição detectada.\n");
                return 1;
            }
        }
    } else {
        printf("Erro: navio vertical fora do tabuleiro.\n");
        return 1;
    }

    // Exibir tabuleiro
    imprimirTabuleiro(tabuleiro);

    return 0;
}