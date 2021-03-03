#include "Partida.hpp"
#include "Jogador.hpp"
#include "Carta.hpp"

Partida::Partida(int num_jogadores)
{
    this->_num_jogadores = num_jogadores;
}

void Partida::addJogadorCarta(string nomeJogador, int numero_pontos_carta, string naipe)
{
    int i;
    Carta carta(numero_pontos_carta, naipe);
    for (i = 0; i < this->_num_jogadores; ++i)
    {
        if (!this->_jogadores)
        {
            this->_jogadores = new Jogador[this->_num_jogadores];
        }
        if (this->_jogadores[i].getNomeJogador() == "")
        {
            this->_jogadores[i].setNomeJogador(nomeJogador);
            this->_jogadores[i].adicionaCarta(carta);
            break;
        }
        else if (this->_jogadores[i].getNomeJogador() == nomeJogador)
        {
            this->_jogadores[i].adicionaCarta(carta);
            break;
        }
    }
}

int Partida::getNumJogadores()
{
    return this->_num_jogadores;
}

int Partida::getNumAtualJogadores()
{
    return this->_atualSize;
}

void Partida::setJogadores(Jogador *jogadores)
{
    this->_jogadores = jogadores;
}

Jogador *Partida::getJogadores()
{
    return this->_jogadores;
}

Jogador Partida::getCampeao()
{
    return this->getJogadoresOrdenados()[this->_num_jogadores-1];
}

Jogador *Partida::getJogadoresOrdenados()
{
    Jogador *jogadores = this->_jogadores;
    for (int i = 0; i < this->_num_jogadores; ++i)
    {
        for (int j = i + 1; j < this->_num_jogadores; ++j)
        {
            if (jogadores[i].calcularPontuacao() > jogadores[j].calcularPontuacao())
            {
                Jogador hold = jogadores[i];
                jogadores[i] = jogadores[j];
                jogadores[j] = hold;
            }
        }
    }
    return jogadores;
}

void Partida::imprimeJogadoresOrdenados()
{
    Jogador *jogadores = this->getJogadoresOrdenados();
    for (int i = 0; i < this->_num_jogadores; ++i)
    {
        cout << jogadores[i].getNomeJogador() << " " << jogadores[i].calcularPontuacao() << endl;
    }
}