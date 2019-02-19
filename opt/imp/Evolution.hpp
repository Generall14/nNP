#ifndef EVOLUTION_HPP
#define EVOLUTION_HPP

#include "../Searcher.hpp"
#include <limits>

/**
 * @class Evolution
 * @author mgr inż. Wojciech Kogut
 *
 * Algorytm maksymalizowania funkcji zysku oparty na metodzie ewolucyjnej.
 *
 * Algorytm zatrzymuje działanie jeżeli co najmniej jeden z poniższych warunków zostanie spełniony:
 * 1. Liczba symulowanych pokoleń przekroczy wartość population podaną w konstruktorze.
 * 2. Przyrost funkcji jakości najlepszego osobnika w populacji przez trzy pokolenia będzie się utrzymywał poniżej wartości endIncrease.
 * 3. Funkcja jakości najlepszego osobnika w populacji przekroczy wartość endValue.
 *
 * W trakcie ewolucji dla każdej wartości V instnieje 40% szans na wykonanie operacji:
 * 1. V(t+1) = V(t)*k, gdzie k jest wartością losową (rozkład normalny wokół jedynki) dobraną tak, aby w <TODO> k przyjmowało wartość z
 * zakresu <0.8, 1.2>.
 * W pozostałych przypadkach wartości są przepisywane bez zmian.
 */

class Evolution : public Searcher
{
public:
    Evolution(std::shared_ptr<Instance> ins,
              unsigned int population,
              unsigned int steps,
              float endIncrease = 0,
              std::shared_ptr<ResultKeeper> res = std::shared_ptr<ResultKeeper>(),
              float endValue = std::numeric_limits<float>::max());

    virtual void run();
    virtual void stop(){}

private:
    const unsigned int _population;
    unsigned int _steps;
    const float _endIncrease;
    const float _endValue;
};

#endif
