#include "Evolution.hpp"
#include <exception>

/**
 * @param ins - instancja optymalizowanego obiketu.
 * @param population - liczba osoblików w populacji, minimum 10.
 * @param steps - liczba kroków po których algorytm zostanie zatrzymany.
 * @param endIncrease - graniczna wartość przyrostu jakości nalepszego osobnika populacji (algorytm zostanie zatrzymany, jeżeli jakość
 * najlepszego osobnika w ciągu trzech populacji nie zwiększy się o wartość endIncrease).
 * @param res - zbieraczka rezultatów.
 * @param endValue - wartość oczekiwana funkcji jakości, algorytm zatrzyma się jeżeli najlepszy osobnik w populacji przekroczy
 * wartość endValue.
 */
Evolution::Evolution(std::shared_ptr<Instance> ins,
          unsigned int population,
          unsigned int steps,
          float endIncrease,
          std::shared_ptr<ResultKeeper> res,
          float endValue):
    Searcher(ins, res),
    _population(population),
    _steps(steps),
    _endIncrease(endIncrease),
    _endValue(endValue)
{
    if(population<10)
        throw std::logic_error("Evolution::Evolution: zbyt mała populacja.");

}

void Evolution::run()
{
    _done = true;
}
