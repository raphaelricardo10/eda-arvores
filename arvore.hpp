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

    // Calcula a profundidade
    // n é uma variável acumuladora
    int profundidade_relativa(int n)
    {
        // Se for folha, retorna o total acumulado
        if (this->e_folha())
        {
            return n;
        }

        n++;
        int pe = 0;
        int pd = 0;

        // Calcula a profundidade dos seus filhos em relação a sí
        if (this->esq)
        {
            pe = this->esq->profundidade_relativa(n);
        }
        if (this->dir)
        {
            pd = this->dir->profundidade_relativa(n);
        }

        // Retorna a maior profundidade
        return pe > pd ? pe : pd;
    }

    // Calcula a altura de um nó
    // O nó é considerado raiz e é calculada a profundidade relativa dos filhos à ele
    int altura()
    {
        // A altura de uma folha é zero
        if (this->e_folha())
        {
            return 0;
        }

        // Profundidade à esquerda
        int pe = 1;
        // Profundidade à direita
        int pd = 1;

        // A altura de um nó é a profundidade dos filhos em relação a ele
        if (this->esq)
        {
            pe = this->esq->profundidade_relativa(pe);
        }
        if (this->dir)
        {
            pd = this->dir->profundidade_relativa(pd);
        }

        // Retorna a maior profundidade
        return pe > pd ? pe : pd;
    }

    int fator_balanceamento()
    {
        int he = 0;
        int hd = 0;

        // Calcula a altura das subárvores direita e esquerda
        if (this->esq)
        {
            he = this->esq->altura();
        }
        if (this->dir)
        {
            hd = this->dir->altura();
        }

        // O fator de balanceamento é essa diferença de alturas
        return he - hd;
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
        // Se for folha, retorna seu valor
        if (no->e_folha())
        {
            return no->valor;
        }

        int a, b;

        // Visita os filhos esquerdo e direito
        if (no->esq)
        {
            a = soma_folhas(no->esq);
        }
        if (no->dir)
        {
            b = soma_folhas(no->dir);
        }

        // Se visitou os dois filhos, retorna a soma
        if (no->esq && no->dir)
        {
            return a + b;
        }

        // Se visitou um só, retorna a soma dele
        return no->esq ? a : b;
    }

    // Exatamente o algoritmo anterior
    // Apenas mudei o operador
    int produto_folhas(No *no)
    {

        // Se for folha, retorna seu valor
        if (no->e_folha())
        {
            return no->valor;
        }

        int a, b;

        // Visita os filhos esquerdo e direito
        if (no->esq)
        {
            a = produto_folhas(no->esq);
        }
        if (no->dir)
        {
            b = produto_folhas(no->dir);
        }

        // Se visitou os dois filhos, retorna o produto
        if (no->esq && no->dir)
        {
            return a * b;
        }

        // Se visitou um só, retorna o produto dele
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

    int produto_folhas()
    {
        return this->produto_folhas(this->raiz);
    }
};