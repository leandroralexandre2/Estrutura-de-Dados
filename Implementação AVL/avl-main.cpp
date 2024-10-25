#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

// tipo para representar cada nó da árvore
typedef struct _no {
    int chave;
    int h;
    struct _no *esq;
    struct _no *dir;
    struct _no *pai;
} no_t;

// tipo representando árvore AVL
typedef struct _avl {
    no_t *raiz;
} avl_t;

// cria um novo nó
no_t* no_cria(int chave, no_t *pai) {
    no_t *novo;
    novo = new no_t;
    novo->chave = chave;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->h = 0;
    novo->pai = pai;
    return novo;
}

// calcula a altura de um nó
int no_altura(no_t *no) {
    if (no == NULL) {
        return -1;
    } else {
        return max(no_altura(no->esq), no_altura(no->dir)) + 1;
    }
}

// percurso em pré-ordem
void no_preordem(no_t *no) {
    if (no == NULL) {
        return;
    }
    printf("Chave: %3d    Altura: %2d\n", no->chave, no->h);
    no_preordem(no->esq);
    no_preordem(no->dir);
}

// busca um elemento a partir de um nó
no_t* no_busca(no_t *raiz, int q) {
    if (raiz == NULL) {
        return NULL;
    }
    if (raiz->chave == q) {
        return raiz;
    } else if (q < raiz->chave) {
        return no_busca(raiz->esq, q);
    } else {
        return no_busca(raiz->dir, q);
    }
}

// insere um elemento
int no_insere(no_t *&raiz, int chave) {
    if (raiz == NULL) {
        no_t *novo = no_cria(chave, NULL);
        raiz = novo;
    	cout<<"valor Inseredo! "<<endl<<endl;
        return -1;   
    }
    no_t *pai, *atual;
    pai = atual = raiz;
    while (atual != NULL) {
        if (atual->chave == chave) {
            return -2;
        }
        pai = atual;
        if (chave < atual->chave) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }
    no_t *novo = no_cria(chave, pai);
    if (chave < pai->chave) {
        pai->esq = novo;
    } else {
        pai->dir = novo;
    }
    // atualiza a altura do pai
    pai->h = no_altura(pai);

    // a partir daqui, deve-se subir na árvore e
    // verificar as novas alturas e se houve desbalanceamento

    return 0;
}


// inicializa uma AVL
void avl_inicializa(avl_t &arv) {
    arv.raiz = NULL;
}

// verifica se AVL é vazia
bool avl_vazia(avl_t &arv) {
    return arv.raiz == NULL;
}

// exibe elementos da AVL
void avl_preordem(avl_t &arv) {
    if (avl_vazia(arv)) {
        cout << "AVL vazia!\n";
    } else {
        no_preordem(arv.raiz);
    }
}

// busca elemento na AVL
no_t* avl_busca(avl_t &arv, int q) {
    if (avl_vazia(arv)) {
        return NULL;
    }
    return no_busca(arv.raiz, q);
}




int main() {
    avl_t arv;
    avl_inicializa(arv);
    int opcao, chave;
	setlocale(LC_ALL, "Portuguese");
    do {
    
        cout << "1 Inserir elemento\n";
        cout << "2 Exibir �rvore\n";
        cout << "3 Buscar elemento\n";
        cout << "Digite a op��o desejada: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Informe a chave inserir: ";
                cin >> chave;
                no_insere(arv.raiz, chave);
                break;
            case 2:
                cout << "Elemento da arvore:";
                avl_preordem(arv);
                break;
            case 3:
                cout << "Informe a chave a buscar: ";
                cin >> chave;
                no_t *no_encontrado = avl_busca(arv, chave);
                if (no_encontrado == NULL) {
                    cout << "Chave n�o localizada.\n";
                } else {
                    cout << "Chave localziada na altura " << no_encontrado->h << ".\n";
                }
                break;
  
        }

    } while (opcao != 0);

    return 0;
}
