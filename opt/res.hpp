#ifndef RES_HPP
#define RES_HPP

#include <vector>
#include <string>

/**
 * Struktura opisująca wynik symulacji.
 */
struct res
{
    std::vector<float> params; /**<Parametry przy których dokonano symulacji.*/
    float result; /**<Wynik symulacji.*/
    std::string description; /**<Opcjonalny opis.*/
};

#endif
