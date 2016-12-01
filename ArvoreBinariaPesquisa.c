#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

#define LIMPA_TELA   system("CLS")
#define LIMPA_BUFFER _flushall()
#define COR_LAYOUT   system("COLOR 1F")

/* ESTRUTURA DA ÁRVORE */
typedef struct Arvore {
    int numero;
    struct Arvore *direita;
    struct Arvore *esquerda;
} Arvore;

/* VARIÁVEIS GLOBAIS */
struct Arvore *atual;
struct Arvore *aux;
struct Arvore *raiz;

/* PROTÓTIPOS DAS FUNÇÕES */
void inserir(int numPesquisa);
void pesquisa(int numPesquisa);
void ordemCentral(Arvore *pAux);
void preOrdem(Arvore *pAux);
void posOrdem(Arvore *pAux);

/**
 * FUNÇÃO MAIN
 */
int main() {

    COR_LAYOUT;
    char resposta;
    int escolha, valor;
    raiz = NULL;
    while (1) {
        LIMPA_TELA;
        LIMPA_BUFFER;
        printf("\tMenu\n\n");
        printf("[1] - Inserir um elemento\n[2] - Percursos\n[3] - Pesquisa\n");
        printf("[4] - Sair do programa\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &escolha);
        // SWITCH 1
        switch (escolha) {
            case 1:
                do {
                    LIMPA_TELA;
                    printf("\tInserir valores\n\n");
                    printf("Digite um numero para inserir na arvore: ");
                    scanf("%d", &valor);
                    inserir(valor);
                    LIMPA_BUFFER;
                    printf("Continuar inserindo numeros ? (S = Sim / N = Nao)\n\n");
                    printf("Opcao: ");
                    resposta = getchar();
                } while (toupper(resposta) == 'S');
            break;
            case 2:
                do {
                    LIMPA_TELA;
                    printf("\tPercurso da arvore binaria\n\n");
                    printf("[1] - Central\n[2] - Pre fixado\n[3] - Pos fixado\n\n");
                    printf("Escolha sua opcao: ");
                    scanf("%d", &escolha);
                    // SWITCH 2
                    switch (escolha) {
                        case 1:
                            LIMPA_TELA;
                            printf("Percurso central\n");
                            ordemCentral(raiz);
                            printf("\n");
                            break;
                        case 2:
                            LIMPA_TELA;
                            printf("Percurso pre ordem\n");
                            preOrdem(raiz);
                            printf("\n");
                            break;
                        case 3:
                            LIMPA_TELA;
                            printf("Percurso pos ordem\n");
                            posOrdem(raiz);
                            printf("\n");
                            break;
                        default:
                            printf("Opcao Invalida !\n");
                    } // SWITCH 2
                    LIMPA_BUFFER;
                    printf("Deseja continuar ? (S = Sim / N = Nao)\n\n");
                    printf("Digite: ");
                    resposta = getchar();
                } while (toupper(resposta) == 'S');
            break;
            case 3:
                do {
                    LIMPA_TELA;
                    printf("\tPesquisar dados na arvore\n\n");
                    printf("Informe um numero a ser pesquisado: ");
                    scanf("%d", &valor);
                    pesquisa(valor);
                    LIMPA_BUFFER;
                    printf("Deseja continuar ? (S = Sim / N = Nao)\n\n");
                    printf("Digite sua opcao: ");
                    resposta = getchar();
                } while (toupper(resposta) == 'S');
            break;
            case 4:
                exit(0);
            default:
                printf("Opcao invalida ! Pressione qualquer tecla p/ continuar");
                getch();
        } // SWITCH 1
    } // WHILE

    return 0;

} // MAIN

/**
 * FUNÇÃO QUE INSERE UM NÚMERO NA ÁRVORE
 *
 * @param numPesquisa - NÚMERO QUE SERÁ PESQUISADO
 */
void inserir(int numPesquisa) {
    aux = (Arvore*) malloc(sizeof(Arvore));
    aux->direita = NULL;
    aux->esquerda = NULL;
    aux->numero = numPesquisa;
    if (raiz == NULL)
        raiz = aux;
    // ELSE
    else {
        atual = raiz;
        while (1) {
            // IF INTERNO 1
            if (aux->numero >= atual->numero) {
                if (atual->direita == NULL) {
                    atual->direita = aux;
                    break;
                } else
                    atual = atual->direita;
            } // IF INTERNO 1
            //IF INTERNO 2
            if (aux->numero < atual->numero) {
                if (atual->esquerda == NULL) {
                    getch();
                    atual->esquerda = aux;
                    break;
                } else
                    atual = atual->esquerda;
            } // IF INTERNO 2
        } // WHILE
    } // ELSE
} // FIM DA FUNÇÃO

/**
 * FUNÇÃO QUE PESQUISA UM DETERMINADO NÚMERO NA ÁRVORE
 *
 * @var numPesquisa - NÚMERO A SER PESQUISADO
 */
void pesquisa(int numPesquisa) {
    atual = raiz;
    LIMPA_TELA;
    printf("AGUARDE |-----------------| 0%%");
    Sleep(1000);
    LIMPA_TELA;
    printf("AGUARDE |||||-------------| 35%%");
    Sleep(800);
    LIMPA_TELA;
    printf("AGUARDE ||||||||||--------| 50%%");
    Sleep(500);
    LIMPA_TELA;
    printf("AGUARDE ||||||||||||------| 60%%");
    Sleep(1300);
    LIMPA_TELA;
    printf("AGUARDE |||||||||||||||---| 90%%");
    Sleep(500);
    LIMPA_TELA;
    printf("AGUARDE ||||||||||||||||||| CONCLUIDO\n");
    Sleep(500);
    printf("\n. . . Caminho: ");
    while(atual != NULL) {
        if (numPesquisa == atual->numero) {
            printf("%d ",atual->numero);
            break;
        // ELSE
        } else {
              if (numPesquisa > atual->numero) {
                  printf("%d ",atual->numero);
                  atual=atual->direita;
              } else {
                    printf("%d ",atual->numero);
                    atual=atual->esquerda;
              }
        } // ELSE
    } // WHILE
    if (atual==NULL)
        printf(". . . Dado %d nao encontrado !\n\n", numPesquisa);
} // FIM DA FUNÇÃO

/**
 * PERCURSO DE ORDEM CENTRAL
 */
void ordemCentral(Arvore *pAux) {
    if (pAux != NULL) {
        ordemCentral(pAux->esquerda); // E
        printf("%d ", pAux->numero); // R
        ordemCentral(pAux->direita); // D
    }
}

/**
 * PERCURSO DE PÓS ORDEM
 */
void posOrdem(Arvore *pAux) {
    if (pAux != NULL) {
        posOrdem(pAux->esquerda); // E
        posOrdem(pAux->direita); // D
        printf("%d ", pAux->numero); // R
    }
}

/**
 * PERCURSO DE PRÉ ORDEM
 */
void preOrdem(Arvore *pAux) {
    if (pAux != NULL) {
        printf("%d ", pAux->numero); // R
        preOrdem(pAux->esquerda); // E
        preOrdem(pAux->direita); // D
    }
}
