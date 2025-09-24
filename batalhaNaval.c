#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código será para o desenvolvimento do sistema de Batalha Naval.

    // Nível Novato - Posicionamento dos Navios
    #include <stdio.h>

// Constantes do jogo
const int TAM = 10;       // tamanho do tabuleiro (10x10)
const int NAVIO = 3;      // valor que representa navio na matriz
const int AGUA = 0;       // valor que representa água na matriz
const int TAM_NAVIO = 3;  // tamanho fixo dos navios

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para posicionar navio horizontal
void posicionarNavioHorizontal(int tabuleiro[10][10], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
}

// Função para posicionar navio vertical
void posicionarNavioVertical(int tabuleiro[10][10], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
}

// Função para exibir o tabuleiro com cabeçalho (A–J) e laterais (1–10)
void exibirTabuleiro(int tabuleiro[10][10]) {
    char letras[10] = {'A','B','C','D','E','F','G','H','I','J'};

    printf("TABULEIRO BATALHA NAVAL\n   ");
    for (int j = 0; j < TAM; j++) {
        printf("%c ", letras[j]); // cabeçalho A–J
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i+1); // lateral numerada (1–10)
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[10][10];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Define posições iniciais dos navios (fixas no código)
    posicionarNavioHorizontal(tabuleiro, 2, 3); // navio horizontal
    posicionarNavioVertical(tabuleiro, 5, 7);   // navio vertical

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    
       return 0;
}

    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

       return 0;
}

