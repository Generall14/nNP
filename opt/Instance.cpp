#include "Instance.hpp"
#include <limits>
#include <stdexcept>

/**
 * @param params - liczba parametrów obiektu.
 * @param min - wektor minimalnych wartości, pusty jeżeli brak granic.
 * @param max - wektor maksymalnych wartości, pusty jeżeli brak granic.
 */
Instance::Instance(unsigned int params, std::vector<float> min, std::vector<float> max)
{
    _pars.resize(params, 0.0);
    while(min.size()<params)
        min.push_back(std::numeric_limits<float>::min());
    while(min.size()<params)
        max.push_back(std::numeric_limits<float>::max());

    _mins = min;
    _maxs = max;
}

/**
 * Zwraca aktualne wartości parametrów.
 */
const std::vector<float>& Instance::getParams() const
{
    return _pars;
}

/**
 * Zwraca minimalne wartości parametrów (ograniczenie nie musi przebiegać w sposób liniony, więc to że wszystkie
 * parametry znajdują się pomiędzy min i max nie oznacza, że parametry te są prawidłowe, należy to sprawdzić
 * za pomicą metody isOk(), zwrócone wartości oznaczają tylko że każdy parametr mniejszy od tej wartości będzie
 * nieprawidłowy).
 */
const std::vector<float>& Instance::getMinParams() const
{
    return _mins;
}

/**
 * Zwraca maksymalne wartości parametrów (ograniczenie nie musi przebiegać w sposób liniony, więc to że wszystkie
 * parametry znajdują się pomiędzy min i max nie oznacza, że parametry te są prawidłowe, należy to sprawdzić
 * za pomicą metody isOk(), zwrócone wartości oznaczają tylko że każdy parametr większy od tej wartości będzie
 * nieprawidłowy).
 */
const std::vector<float>& Instance::getMaxParams() const
{
    return _maxs;
}

/**
 * Ustawia parametry z jakimi zostanie wykonana symulacja.
 */
void Instance::setParams(std::vector<float> params)
{
    if(params.size()!=_pars.size())
        throw std::logic_error("Instance::setParams: Niezgodne rozmiary wektorów.");
    _pars = params;
}

/**
 * Metoda sprawdza czy aktualne wartości parametrów są poprawne, domyślna metoda sprawdza czy każda wartość
 * mieści się pomiędzy min i max.
 * @return true - parametry są ok, false - co najmniej jeden parametr jest nieprawidłowy.
 */
bool Instance::isOk() const
{
    for(uint i=0;i<_pars.size();i++)
    {
        if((_pars.at(i)<_mins.at(i))||(_pars.at(i)>_maxs.at(i)))
            return false;
    }
    return true;
}
