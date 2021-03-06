#ifndef EVOLUTION_HPP
#define EVOLUTION_HPP

#include "../Searcher.hpp"
#include <limits>
#include <random>
#include "../res.hpp"

/**
 * @class Evolution
 * @author mgr inż. Wojciech Kogut
 *
 * Algorytm maksymalizowania funkcji zysku oparty na metodzie ewolucyjnej.
 *
 * Algorytm zatrzymuje działanie jeżeli co najmniej jeden z poniższych warunków zostanie spełniony:
 * 1. Liczba symulowanych pokoleń przekroczy wartość population podaną w konstruktorze.
 * 2. Funkcja jakości najlepszego osobnika w populacji przekroczy wartość endValue.
 *
 * W trakcie każdego kroku ewolucji mogą wystąpić różne zdarzenia z określonym prawdopodobieństwem:
 * 1. Część kolejnego pokolenia zostanie wygenerowana losowo.
 * 2. Część zostanie wygenerowana poprzez pomieszanie parametrów z dwóch różnych osobników poprzedniego pokolenia.
 * 3. Część zostanie wygenerowana poprzez losowe zmiany parametrów.
 *
 * <TODO> Jakieś lepsze warunki zakończenia?
 * <TODO> Lepsze dobieranie skoków przeszukiwania?
 */

class Evolution : public Searcher
{
public:
    Evolution(std::shared_ptr<Instance> ins,
              unsigned int population,
              unsigned int steps,
              std::shared_ptr<ResultKeeper> res = std::shared_ptr<ResultKeeper>(),
              float endValue = std::numeric_limits<float>::max());

    virtual void run();
    virtual void stop(){}

private:
    const unsigned int _population;
    unsigned int _steps;
    const float _endValue;

    std::mt19937 _gen;
    std::normal_distribution<float> _normHigh;
    std::normal_distribution<float> _normLow;
    std::normal_distribution<float> _normMid;

    std::vector<res> _vPopulation;

    std::vector<float> getRandomParams();
    std::vector<float> getChildParams(const std::vector<float>& parent);
    std::vector<float> makeHybrid();

    void genNewPopulation();
    void simulateAndSortPopulation();
    bool checkEnd();
    void makeNextGeneration();
};

#endif
