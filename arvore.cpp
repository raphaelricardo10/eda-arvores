#include "arvore.hpp"

int main()
{
    // Nível 1
    No *raiz = new No(10);

    // Nível 2
    raiz->esq = new No(20);
    raiz->dir = new No(15);

    // Nível 3
    raiz->esq->esq = new No(12);
    raiz->esq->dir = new No(8);
    raiz->dir->esq = new No(5);
    raiz->dir->dir = new No(7);

    // Nível 4
    raiz->esq->esq->esq = new No(1);
    raiz->esq->esq->dir = new No(2);

    // Insere os nós na árvore
    Arvore arvore(raiz);

    // Realiza as impressões
    arvore.pre_ordem();
    arvore.em_ordem();
    arvore.pos_ordem();

    std::cout << arvore.soma_folhas();

    return 0;
}