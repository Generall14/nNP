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
    while(min.size()<params)
        min.push_back(std::numeric_limits<float>::min());
    while(max.size()<params)
        max.push_back(std::numeric_limits<float>::max());

    if(params!=min.size())
        throw std::logic_error("Instance::Instance(unsigned int params, std::vector<float> min, std::vector<float> max): "
                               "nieprawidłowy rozmiar wektora min");
    if(params!=max.size())
        throw std::logic_error("Instance::Instance(unsigned int params, std::vector<float> min, std::vector<float> max): "
                               "nieprawidłowy rozmiar wektora max");

    _mins = min;
    _maxs = max;
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
 * Metoda sprawdza czy wskazane wartości są poprawne, domyślna metoda sprawdza czy każda wartość
 * mieści się pomiędzy min i max.
 * @return true - parametry są ok, false - co najmniej jeden parametr jest nieprawidłowy.
 */
bool Instance::isOk(const std::vector<float> &params) const
{
    if(params.size()!=_mins.size())
        throw std::logic_error("Instance::isOk(std::vector<float> params): Niezgodne rozmiary wektorów.");
    for(uint i=0;i<params.size();i++)
    {
        if((params.at(i)<_mins.at(i))||(params.at(i)>_maxs.at(i)))
            return false;
    }
    return true;
}

/**
 * Metoda wykonuje symulacje na podstawie wskazanych parametrów, zwraca wartość float proporcjonalną do jakości
 * aktualnego wyniku (większe wartości oznaczają lepsze parametry).
 */
float Instance::sim(const std::vector<float> &params) const
{
    if(!isOk(params))
        throw std::logic_error(
                "Instance::sim(std::vector<float> params): próba symulacji przy nieprawidłowych parametrach.");
    return lsim(params);
}
