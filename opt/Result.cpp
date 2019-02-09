#include "Result.hpp"
#include <stdexcept>
#include <sstream>

/**
 * Czyści przechowywane rezultaty.
 */
void ResultKeeper::clear()
{
    _res.clear();
}

/**
 * Dodaje wynik symulacji.
 * @param params - wektor parametrów przy jakich dokonano symulacji.
 * @param result - wynik symulacji.
 * @param description - opcjonalny opis.
 */
void ResultKeeper::append(std::vector<float> params, float result, std::string description)
{
    _res.push_back(res{params, result, description});
}

/**
 * Zwraca strukturę opisującą najlepszy wynik symulacji.
 */
res ResultKeeper::getMax() const
{
    if(_res.empty())
        throw std::logic_error("ResultKeeper::getMax(): brak danych");
    uint maxi = 0;
    for(uint i=1;i<_res.size();i++)
    {
        if(_res.at(i).result > _res.at(maxi).result)
            maxi = 1;
    }
    return _res.at(maxi);
}

/**
 * Zwraca tekst opisujący przechowywane dane.
 */
std::string ResultKeeper::report() const
{
    std::ostringstream ss;
    ss.precision(3);
    for(auto res: _res)
    {
        ss << res.result << " [ ";
        for(auto par: res.params)
            ss << par << " ";
        ss << " ] " << res.description << std::endl << std::endl;
    }
    return ss.str();
}
