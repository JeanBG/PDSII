#include "Estudante.hpp"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    Estudante estudante[10];
    int i = 0;
    int j = 0;
    while (i < 10)
    {
        cin >> estudante[i].matricula >> estudante[i].nome >>
            estudante[i].notas[0] >> estudante[i].notas[1] >>
            estudante[i].notas[2] >> estudante[i].notas[3] >>
            estudante[i].notas[4];
        i++;
    }
    for (i = 0; i < 10; i++)
    {
        int max = i;
        for (j = i + 1; j < 10; j++)
        {
            if (estudante[j].calcularRSG() > estudante[max].calcularRSG())
            {
                max = j;
            }
        }
        if (max != i)
        {
            Estudante temp = estudante[i];
            estudante[i] = estudante[max];
            estudante[max] = temp;
        }
    }
    for (i = 0; i < 10; ++i)
    {
        for (j = i + 1; j < 10; ++j)
        {
            if (estudante[i].calcularRSG() == estudante[j].calcularRSG() && estudante[j].matricula < estudante[i].matricula)
            {
                Estudante aux = estudante[i];
                estudante[i] = estudante[j];
                estudante[j] = aux;
            }
        }
    }
    for (i = 0; i < 3; ++i)
    {
        cout << estudante[i].matricula << " "
             << estudante[i].nome << " "
             << fixed << setprecision(2)
             << estudante[i].calcularRSG() << endl;
    }
}