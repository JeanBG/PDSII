#include "No.hpp"

No::No(int prioridade, int dado, No *proximo)
{
    this->_dado = dado;
    this->_prioridade = prioridade;
    this->setProximo(proximo);
}

void No::setProximo(No *proximo)
{
    this->_proximo = proximo;
}

No *No::getProximo()
{
    return this->_proximo;
}

int No::getDado()
{
    return this->_dado;
}

void No::setDado(int dado)
{
    this->_dado = dado;
}

int No::getPrioridade()
{
    return this->_prioridade;
}

void No::setPrioridade(int prioridade)
{
    this->_prioridade = prioridade;
}