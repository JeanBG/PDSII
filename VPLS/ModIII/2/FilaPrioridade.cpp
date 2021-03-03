#include "FilaPrioridade.hpp"

FilaPrioridade::FilaPrioridade()
{
    this->cabeca = nullptr;
    this->fim = nullptr;
}

void FilaPrioridade::inserir(int prioriadde, int dado)
{
    No *novo_item = new No(prioriadde, dado, nullptr);
    if (this->cabeca == nullptr)
    {
        this->cabeca = novo_item;
        this->fim = novo_item;
    }
    else if (prioriadde > this->fim->getPrioridade())
    {
        this->fim->setProximo(novo_item);
        this->fim = novo_item;
    }
    else if (this->cabeca->getPrioridade() > prioriadde)
    {
        No *antiga_cabeca = this->cabeca;
        this->cabeca = novo_item;
        novo_item->setProximo(antiga_cabeca);
    }
    else
    {
        inserirNo(this->cabeca, novo_item);
    }
}

void FilaPrioridade::inserirNo(No *atual, No *inserido)
{
    No *proximo = atual->getProximo();
    if (proximo == nullptr)
    {
        atual->setProximo(inserido);
        this->fim = inserido;
    }
    else if (proximo->getPrioridade() > inserido->getPrioridade())
    {
        atual->setProximo(inserido);
        inserido->setProximo(proximo);
    }
    else
    {
        inserirNo(proximo, inserido);
    }
}

int FilaPrioridade::remover()
{
    No *antiga_cabeca = this->cabeca;
    this->cabeca = antiga_cabeca->getProximo();
    int dado = antiga_cabeca->getDado();
    delete (antiga_cabeca);
    return dado;
}

int FilaPrioridade::estaVazio()
{
    return this->cabeca == nullptr;
}

unsigned FilaPrioridade::getTamanho()
{
    this->tamanho = 0;
    this->contarTamanho(this->cabeca);
    return this->tamanho;
}

void FilaPrioridade::contarTamanho(No *next)
{
    this->tamanho++;
    if (next != this->fim)
        this->contarTamanho(next->getProximo());
}

int FilaPrioridade::getMeio()
{
    getTamanho();
    unsigned count = 0;
    return this->encontrarMeio(this->cabeca, &count)->getDado();
}

No *FilaPrioridade::encontrarMeio(No *proximo, unsigned *count)
{
    if ((*count) == (this->getTamanho() / 2))
        return proximo;
    else if (proximo != this->fim)
    {
        (*count) += 1;
        return encontrarMeio(proximo->getProximo(), count);
    }
    else
        return nullptr;
}

int FilaPrioridade::getUltimo()
{
    return fim->getDado();
}

void FilaPrioridade::furaFila(int dado)
{
    No *furador = new No(this->cabeca->getPrioridade() - 1, dado, this->cabeca);
    this->cabeca = furador;
}

void FilaPrioridade::print()
{
    printFila(this->cabeca);
}

void FilaPrioridade::printFila(No *atual)
{
    std::cout << atual->getDado();
    if (atual != this->fim)
    {
        std::cout << " ";
        printFila(atual->getProximo());
    }
}