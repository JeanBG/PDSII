#include "Indice.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <map>

int main()
{
    std::map<std::string, Palavra, compara_palavra> words;
    std::string word;
    int total = 0;
    while (std::cin >> word)
    {
        total++;
        if (word.length() >= 3)
        {
            auto search = words.find(word);
            if (search != words.end())
            {
                search->second.ocorrencias++;
            }
            else
            {
                std::pair<std::string, Palavra> new_word;
                new_word.first = word;
                new_word.second.ocorrencias = 1;
                words.insert(new_word);
            }
        }
    }
    for (auto it = words.begin(); it != words.end(); it++)
    {
        std::cout << it->first << " " << it->second.ocorrencias
                  << " " << std::fixed << std::setprecision(2)
                  << it->second.calcularPercentual(total) << std::endl;
    }
}