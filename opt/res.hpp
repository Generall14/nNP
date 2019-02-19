#ifndef RES_HPP
#define RES_HPP

#include <vector>
#include <string>
#include <sstream>

/**
 * Struktura opisująca wynik symulacji.
 */
struct res
{
    std::vector<float> params; /**<Parametry przy których dokonano symulacji.*/
    float result; /**<Wynik symulacji.*/
    std::string description; /**<Opcjonalny opis.*/

    std::string toString()
    {
        std::ostringstream ss;
        ss.precision(3);
        ss << "f( ";
        for(auto v: params)
            ss << v << " ";
        ss << ") = " << result;
        if(!description.empty())
            ss << "(" << description << ")";
        return ss.str();
    }
};

#endif
