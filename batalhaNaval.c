/*#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código será para o desenvolvimento do sistema de Batalha Naval.

    // Nível Novato - Posicionamento dos Navios
 
 Constantes do jogo
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
    posicionarNavioDiagonal(tabuleiro, 0, 3);

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    
       return 0;
}*/

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    #include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Intermediário - Tabuleiro Completo e Navios Diagonais

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

// Função auxiliar para verificar se uma posição está livre
int posicaoValida(int tabuleiro[10][10], int linha, int coluna) {
    return (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM && tabuleiro[linha][coluna] == AGUA);
}

// Função para posicionar navio horizontal
int posicionarNavioHorizontal(int tabuleiro[10][10], int linha, int coluna) {
    if (coluna + TAM_NAVIO > TAM) return 0; // valida limite
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (!posicaoValida(tabuleiro, linha, coluna + i)) return 0; // sobreposição
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
    return 1;
}

// Função para posicionar navio vertical
int posicionarNavioVertical(int tabuleiro[10][10], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM) return 0; // valida limite
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (!posicaoValida(tabuleiro, linha + i, coluna)) return 0; // sobreposição
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
    return 1;
}

// Função para posicionar navio diagonal principal (\)
int posicionarNavioDiagonalPrincipal(int tabuleiro[10][10], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM || coluna + TAM_NAVIO > TAM) return 0; // valida limite
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (!posicaoValida(tabuleiro, linha + i, coluna + i)) return 0; // sobreposição
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = NAVIO;
    }
    return 1;
}

// Função para posicionar navio diagonal secundária (/)
int posicionarNavioDiagonalSecundaria(int tabuleiro[10][10], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM || coluna - TAM_NAVIO + 1 < 0) return 0; // valida limite
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (!posicaoValida(tabuleiro, linha + i, coluna - i)) return 0; // sobreposição
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = NAVIO;
    }
    return 1;
}

// Função para exibir o tabuleiro
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

    // Posiciona 4 navios: 2 normais e 2 diagonais
    posicionarNavioHorizontal(tabuleiro, 2, 3); // navio horizontal
    posicionarNavioVertical(tabuleiro, 5, 7);   // navio vertical
    posicionarNavioDiagonalPrincipal(tabuleiro, 0, 0); // diagonal principal
    posicionarNavioDiagonalSecundaria(tabuleiro, 0, 9); // diagonal secundária

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
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

   