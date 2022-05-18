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

    // Executa a soma das folhas
    std::cout << arvore.soma_folhas() << std::endl;

    // Testa a altura de diferentes nós
    std::cout << raiz->esq->esq->dir->altura() << std::endl;
    std::cout << raiz->esq->esq->altura() << std::endl;
    std::cout << raiz->esq->altura() << std::endl;
    std::cout << raiz->altura() << std::endl;

    return 0;
}