#include <iostream>

class No
{
public:
    No *esq;
    No *dir;
    int valor;

    // Construtores para facilitar a inserção de um nó
    No(int valor)
    {
        this->dir = 0;
        this->esq = 0;
        this->valor = valor;
    }

    No(int valor, No *dir)
    {
        this->valor = valor;
        this->dir = dir;
    }

    No(No *esq, int valor)
    {
        this->valor = valor;
        this->esq = esq;
    }

    No(No *esq, int valor, No *dir)
    {
        this->valor = valor;
        this->esq = esq;
        this->dir = dir;
    }

    bool e_folha()
    {
        return !this->dir && !this->esq;
    }
};

class Arvore
{
private:
    // Imprime em pré ordem recursivamente
    void pre_ordem(No *no)
    {
        if (!no)
        {
            return;
        }

        std::cout << no->valor << ' ';
        pre_ordem(no->esq);
        pre_ordem(no->dir);
    }

    // Imprime em ordem recursivamente
    void em_ordem(No *no)
    {
        if (!no)
        {
            return;
        }

        em_ordem(no->esq);
        std::cout << no->valor << ' ';
        em_ordem(no->dir);
    }

    // Imprime em pós ordem recursivamente
    void pos_ordem(No *no)
    {
        if (!no)
        {
            return;
        }

        pos_ordem(no->esq);
        pos_ordem(no->dir);
        std::cout << no->valor << ' ';
    }

    int soma_folhas(No *no)
    {
        if (no->e_folha())
        {
            return no->valor;
        }

        int a, b;

        if (no->esq)
        {
            a = soma_folhas(no->esq);
        }
        if (no->dir)
        {
            b = soma_folhas(no->dir);
        }

        if (no->esq && no->dir)
        {
            return a + b;
        }

        return no->esq ? a : b;
    }

public:
    No *raiz;

    // Construtores para facilitar a criação da árvore
    Arvore(int raiz)
    {
        this->raiz = new No(raiz);
    }
    Arvore(No *raiz)
    {
        this->raiz = raiz;
    }

    Arvore()
    {
        this->raiz = 0;
    }

    // Métodos públicos que passam a raiz da árvore para os métodos privados de impressão recursiva
    void pre_ordem()
    {
        std::cout << "PRE ORDEM: ";
        pre_ordem(this->raiz);
        std::cout << "\n\n";
    }
    void em_ordem()
    {
        std::cout << "EM ORDEM: ";
        em_ordem(this->raiz);
        std::cout << "\n\n";
    }
    void pos_ordem()
    {
        std::cout << "POS ORDEM: ";
        pos_ordem(this->raiz);
        std::cout << "\n\n";
    }

    int soma_folhas()
    {
        return this->soma_folhas(this->raiz);
    }
};