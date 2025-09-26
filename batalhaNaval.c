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

/*/ Desafio Batalha Naval - MateCheck
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
}*/
    /* batalha_naval_habilidades.c
   Batalha Naval (10x10) - visualização de áreas de efeito de habilidades:
   Cone, Cruz e Octaedro (losango) - matrizes construídas dinamicamente.

   Convenções de valores no tabuleiro:
     0 = água
     3 = navio
     5 = área afetada por habilidade

   Simplificações:
   - Posições dos navios e das habilidades definidas diretamente no código.
   - O programa apenas exibe a área de efeito (não aplica dano).
   - Matrizes de habilidade têm tamanho ímpar (5x5) para ter um centro bem definido.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM_TAB 10       /* tamanho do tabuleiro (10x10) */
#define VAL_AGUA 0
#define VAL_NAVIO 3
#define VAL_AFETADO 5

#define TAM_HAB 5        /* tamanho da matriz de habilidade (ímpar) */

/* Protótipos das funções (nomes em português) */
void inicializar_tabuleiro(int tab[TAM_TAB][TAM_TAB]);
void posicionar_navios_exemplo(int tab[TAM_TAB][TAM_TAB]);
void imprimir_tabuleiro_numerico(int tab[TAM_TAB][TAM_TAB]);
void construir_cone(int mat[TAM_HAB][TAM_HAB]);
void construir_cruz(int mat[TAM_HAB][TAM_HAB]);
void construir_octaedro(int mat[TAM_HAB][TAM_HAB]);
void sobrepor_habilidade(int tab[TAM_TAB][TAM_TAB], int mat[TAM_HAB][TAM_HAB], int origem_linha, int origem_coluna);

/* Função principal */
int main(void) {
    int tabuleiro[TAM_TAB][TAM_TAB];
    int mat_cone[TAM_HAB][TAM_HAB];
    int mat_cruz[TAM_HAB][TAM_HAB];
    int mat_octa[TAM_HAB][TAM_HAB];

    /* 1) Inicializa tabuleiro com água */
    inicializar_tabuleiro(tabuleiro);

    /* 2) Coloca alguns navios de exemplo (valor 3) */
    posicionar_navios_exemplo(tabuleiro);

    /* 3) Constroi dinamicamente as matrizes de habilidade (valores 0/1) */
    construir_cone(mat_cone);
    construir_cruz(mat_cruz);
    construir_octaedro(mat_octa);

    /* 4) Define origens das habilidades no tabuleiro (coordenadas 0-indexadas) */
    /* Observação: coordenadas fixas conforme simplificação do enunciado */
    int origem_cone_l = 1, origem_cone_c = 2;   /* cone com ponto no topo (apontando para baixo) */
    int origem_cruz_l = 6, origem_cruz_c = 6;   /* cruz centrada */
    int origem_octa_l = 4, origem_octa_c = 4;   /* octaedro (losango) centrado */

    /* 5) Sobrepõe as habilidades no tabuleiro (marca com VAL_AFETADO) */
    sobrepor_habilidade(tabuleiro, mat_cone, origem_cone_l, origem_cone_c);
    sobrepor_habilidade(tabuleiro, mat_cruz, origem_cruz_l, origem_cruz_c);
    sobrepor_habilidade(tabuleiro, mat_octa, origem_octa_l, origem_octa_c);

    /* 6) Exibe resultado */
    printf("Legenda: 0=agua, 3=navio, 5=area afetada\n\n");
    imprimir_tabuleiro_numerico(tabuleiro);

    return 0;
}

/* Inicializa todo o tabuleiro com água (valor 0) */
void inicializar_tabuleiro(int tab[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; ++i) {
        for (int j = 0; j < TAM_TAB; ++j) {
            tab[i][j] = VAL_AGUA;
        }
    }
}

/* Posiciona alguns navios de exemplo para demonstrar sobreposição */
void posicionar_navios_exemplo(int tab[TAM_TAB][TAM_TAB]) {
    /* Navio horizontal de tamanho 5 na linha 0, colunas 2..6 */
    for (int c = 2; c <= 6; ++c) tab[0][c] = VAL_NAVIO;

    /* Navio vertical de tamanho 4 na coluna 1, linhas 3..6 */
    for (int l = 3; l <= 6; ++l) tab[l][1] = VAL_NAVIO;

    /* Pequena formação extra (apenas para exemplo) */
    tab[8][7] = VAL_NAVIO;
    tab[7][7] = VAL_NAVIO;
    tab[7][8] = VAL_NAVIO;
}

/* Imprime o tabuleiro como números (formato legível) */
void imprimir_tabuleiro_numerico(int tab[TAM_TAB][TAM_TAB]) {
    /* Cabeçalho de colunas (1..10) */
    printf("   ");
    for (int c = 0; c < TAM_TAB; ++c) printf("%2d", c+1);
    printf("\n");

    /* Linhas com índice e valores */
    for (int l = 0; l < TAM_TAB; ++l) {
        printf("%2d ", l+1);
        for (int c = 0; c < TAM_TAB; ++c) {
            printf("%2d", tab[l][c]);
        }
        printf("\n");
    }
}

/* -----------------------------
   Construção dinâmica das matrizes
   Cada função deve usar loops aninhados e condicionais
   para preencher a matriz com 0 (não afetado) ou 1 (afetado)
   ----------------------------- */

/* CONE (apontando para baixo)
   Estratégia:
   - Centro da matriz: TAM_HAB/2
   - A "ponta" do cone fica na linha 0, na coluna central.
   - Para cada linha i de 0..centro, preenchermos uma largura crescente:
       metade_largura = i  -> colunas center - i .. center + i
   - Linhas abaixo do centro (se houver) permanecem 0.
*/
void construir_cone(int mat[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;

    /* Inicializa com zeros usando loops aninhados */
    for (int i = 0; i < TAM_HAB; ++i) {
        for (int j = 0; j < TAM_HAB; ++j) {
            mat[i][j] = 0;
        }
    }

    /* Preenche o cone da linha 0 até a linha 'centro' */
    for (int i = 0; i <= centro; ++i) {
        int metade_largura = i; /* cresce conforme descemos */
        int inicio = centro - metade_largura;
        int fim = centro + metade_largura;
        /* valida e preenche usando condicionais dentro do loop */
        for (int j = inicio; j <= fim; ++j) {
            if (j >= 0 && j < TAM_HAB) {
                mat[i][j] = 1;
            }
        }
    }
}

/* CRUZ
   Estratégia:
   - Centro da matriz: TAM_HAB/2
   - Marca 1 em toda linha 'centro' e em toda coluna 'centro'
*/
void construir_cruz(int mat[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; ++i) {
        for (int j = 0; j < TAM_HAB; ++j) {
            if (i == centro || j == centro) mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }
}

/* OCTAEDRO (vista frontal) -> losango / diamante
   Estratégia:
   - Usamos a condição de distância de Manhattan:
       abs(i-centro) + abs(j-centro) <= centro  => dentro do losango
*/
void construir_octaedro(int mat[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; ++i) {
        for (int j = 0; j < TAM_HAB; ++j) {
            int manhattan = abs(i - centro) + abs(j - centro);
            if (manhattan <= centro) mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }
}

/* Sobrepõe a matriz de habilidade no tabuleiro centralizando-a na origem
   - origem_linha / origem_coluna são coordenadas 0-indexadas do tabuleiro
   - Para cada célula da matriz==1, calcula a célula alvo no tabuleiro:
       alvo_l = origem_linha + (i - centro_da_matriz)
       alvo_c = origem_coluna + (j - centro_da_matriz)
   - Valida limites do tabuleiro com condicionais antes de escrever VAL_AFETADO
   - Observação: aqui sobrescrevemos o que havia no tabuleiro com VAL_AFETADO
*/
void sobrepor_habilidade(int tab[TAM_TAB][TAM_TAB], int mat[TAM_HAB][TAM_HAB], int origem_linha, int origem_coluna) {
    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; ++i) {
        for (int j = 0; j < TAM_HAB; ++j) {
            if (mat[i][j] == 1) { /* só processa células que fazem parte da área */
                int alvo_l = origem_linha + (i - centro);
                int alvo_c = origem_coluna + (j - centro);

                /* Verifica se a célula alvo está dentro do tabuleiro */
                if (alvo_l >= 0 && alvo_l < TAM_TAB && alvo_c >= 0 && alvo_c < TAM_TAB) {
                    /* Marca como área afetada (valor 5) */
                    tab[alvo_l][alvo_c] = VAL_AFETADO;
                }
            }
        }
    }
}
   