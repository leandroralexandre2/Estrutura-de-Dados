#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


typedef struct _no {
    int chave;
    struct _no *esq, *dir;
} no_t;

typedef struct _abb {
    no_t *raiz;
} abb_t;

no_t* cria_no(int valor) {
    no_t *novo;
    novo = new no_t;
    novo->chave = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void inicializa_abb(abb_t &arvore) {
    arvore.raiz = NULL;
}
// INSERCAO
void abb_insere(no_t *&no, int valor) {
    if (no == NULL) {
        no = cria_no(valor);
    } else if (valor < no->chave) {
        abb_insere(no->esq, valor);
    } else if (valor > no->chave) {
        abb_insere(no->dir, valor);
    }
}

void abb_insere(abb_t &arvore, int valor) {
    abb_insere(arvore.raiz, valor);
}

// BUSCA
no_t* busca(no_t *no, int valor) {
    if (no == NULL || no->chave == valor) {
        return no;
    } else if (valor < no->chave) {
        return busca(no->esq, valor);
    } else {
        return busca(no->dir, valor);
    }
}

no_t* abb_busca(abb_t &arvore, int valor) {
    return busca(arvore.raiz, valor);
}

no_t* busca_minimo(no_t *no) {
    while (no->esq != NULL) {
        no = no->esq;
    }
    return no;
}

// PRE ORDEM: Percorre a �rvore em prE-ordem visitando o n�, o filho esquerdo e o filho direito.

void abb_pre_ordem(no_t *no) {
    if (no != NULL) {
        printf("%d ", no->chave);
        abb_pre_ordem(no->esq);
        abb_pre_ordem(no->dir);
    }
    
}

void abb_pre_ordem(abb_t &arvore) {
    abb_pre_ordem(arvore.raiz);
}

//  EM IN-ORDEM: Percorre a Arvore em in-ordem, visitando o filho esquerdo, o n� e o filho direito.
void abb_in_ordem(no_t *no) {
    if (no != NULL) {
        abb_in_ordem(no->esq);
        printf("%d ", no->chave);
        abb_in_ordem(no->dir);
    }
 
}

void abb_in_ordem(abb_t &arvore) {
    abb_in_ordem(arvore.raiz);
}


//  EM POS-ORDEM
void abb_pos_ordem(no_t *no) {
    if (no != NULL) {
        abb_pos_ordem(no->esq);
        abb_pos_ordem(no->dir);
        printf("%d ", no->chave);
    }
 
}

void abb_pos_ordem(abb_t &arvore) {
    abb_pos_ordem(arvore.raiz);
}

// REMOCAO
no_t* abb_remove(no_t *&no, int valor) {
    if (no == NULL) {
        return NULL;
    }
    if (valor < no->chave) {
        no->esq = abb_remove(no->esq, valor);
    } else if (valor > no->chave) {
        no->dir = abb_remove(no->dir, valor);
    } else {
        
        if (no->esq == NULL) {
            no_t *temp = no;
            no = no->dir;
            delete temp;
        } else if (no->dir == NULL) {
            no_t *temp = no;
            no = no->esq;
            delete temp;
        }
        else {
            no_t *temp = busca_minimo(no->dir);
            no->chave = temp->chave;
            no->dir = abb_remove(no->dir, temp->chave);
        }
    }
    return no;
}

void abb_remove(abb_t &arvore, int valor) {
    abb_remove(arvore.raiz, valor);
}


int main() {
    abb_t arvore;
    inicializa_abb(arvore);
    int item, valor;
    do {
        printf("\nEscolha um item para acao: \n");
        printf("\n------------------\n");
        printf("0- Insercao\n");
        printf("1- Busca\n");
        printf("2- Remocao\n");
        printf("3- Pre-ordem\n");
        printf("4- In-ordem\n");
        printf("5- Pos-ordem\n");
        printf("6- Sair\n");
        printf("Escolha: ");
        printf("\n------------------\n");


        scanf("%d", &item);
        
          switch (item) {
            case 0:
                printf("Informe o numero para ser inserido: ");
                scanf("%d", &valor);
                abb_insere(arvore, valor);
                break;
                
                
            case 1:
                printf("Informe o valor para ser buscado: ");
                scanf("%d", &valor);
                if (abb_busca(arvore, valor) != NULL) {
                    printf("O numero foi achado.\n");
                } else {
                    printf("Numero nao achado.\n");
                }
                break;
                
                
            case 2:
                printf("Informe o valor para ser removido: ");
                scanf("%d", &valor);
                
                abb_remove(arvore, valor);
                break;
            
            case 3:
            printf("Percurso em pre-ordem: ");
            abb_pre_ordem(arvore);
            printf("\n");
            break;


            case 4:
            printf("Percurso em in-ordem: ");
            abb_in_ordem(arvore);
            printf("\n");
            break;


            case 5:
            printf("Percurso em pos-ordem: ");
            abb_pos_ordem(arvore);
            printf("\n");
            break;
                
                
            case 6:
                printf("Fim da operacao\n");
                break;
                
            default:
              printf("Escolha errada.\n");
        }
        
}while (item != 3);
    return 0;
}

