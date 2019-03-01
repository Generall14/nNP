#include "Evolution.hpp"
#include <exception>
#include <iostream>
#include <algorithm>
#include <ctime>
#include "../Instance.hpp"

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
          std::shared_ptr<ResultKeeper> res,
          float endValue):
    Searcher(ins, res),
    _population(population),
    _steps(steps),
    _endValue(endValue),
    _normHigh(1, 20),
    _normLow(1, .002),
    _normMid(1, 2)
{
    _gen.seed(std::time(nullptr));

    if(population<10)
        throw std::logic_error("Evolution::Evolution: zbyt mała populacja.");

}

void Evolution::run()
{
    genNewPopulation();
    while(true)
    {
        simulateAndSortPopulation();
        if(checkEnd())
            break;
        makeNextGeneration();
    }
    _done = true;
}

/**
 * Generuje losowe wartości parametrów zgodne z zakresami _ins.
 */
std::vector<float> Evolution::getRandomParams()
{
    std::vector<float> temp;
    const std::vector<float>& min = (_ins->getMinParams());
    const std::vector<float>& max = (_ins->getMaxParams());
    temp.assign(min.size(), .0);

    while(true)
    {
        for(unsigned int p=0;p<min.size();p++)
            temp[p]=(std::uniform_real_distribution<float>(min.at(p), max.at(p))(_gen));
        if(_ins->isOk(temp))
            break;
    }
    return temp;
}

/**
 * Generuje losowo zmodyfikowany wektor parametrów na podstawie przekazanego rodzica.
 */
std::vector<float> Evolution::getChildParams(const std::vector<float>& parent)
{
    std::vector<float> temp(parent);
    std::random_device rd;

    while(true)
    {
        for(unsigned int p=0;p<parent.size();p++)
        {
            if((rd()%70)<25)
                temp[p]=(parent.at(p)*_normHigh(_gen));
            else if((rd()%70)<25)
                temp[p]=(parent.at(p)+_normHigh(_gen)-1);
            else if((rd()%70)<25)
                temp[p]=(parent.at(p)*_normMid(_gen));
            else
                temp[p]=(parent.at(p)*_normLow(_gen));
        }
        if(_ins->isOk(temp))
            break;
    }
    return temp;
}

/**
 * Generuje hybrydę z dwóch losowych rodziców z _vPopulation.
 */
std::vector<float> Evolution::makeHybrid()
{
    const std::vector<float> b = _vPopulation.at(_gen()%_vPopulation.size()).params;
    std::vector<float> temp(_vPopulation.at(_gen()%_vPopulation.size()).params);

    for(unsigned int i=0;i<temp.size();i++)
    {
        if(_gen()%2)
            temp[i] = b[i];
    }

    return temp;
}

/**
 * Tworzy nową, losową populację.
 */
void Evolution::genNewPopulation()
{
    _vPopulation.clear();
    while(_vPopulation.size()<_population)
        _vPopulation.push_back(res{getRandomParams()});
}

/**
 * Symuluje wszystkie osobniki oraz szereguje _vPopulation od najlepszego do najsłabszego wyniku.
 */
void Evolution::simulateAndSortPopulation()
{
    for(std::vector<res>::iterator it = _vPopulation.begin();it!=_vPopulation.end(); it++)
        it->result = _ins->sim(it->params);
    std::sort(_vPopulation.rbegin(), _vPopulation.rend());
}

/**
 * Sprawdza spełnienie warunków końcowych, przyjmuje się, że wektor _vPopulation jest posegregowany z najlepszym
 * osobnikiem pod indeksem zerowym. Ustawia nalepszego osobnika w _best.
 * @return true - warunek zakończenia spełniony.
 */
bool Evolution::checkEnd()
{
    _best = _vPopulation.at(0);
    std::cout << "The best at " << _steps << ": " << _best.toString() << std::endl;
    if(!--_steps)
        return true;
    if(_best.result>_endValue)
        return true;
    return false;
}

/**
 * Generuje kolejne pokolenie _vPopulation.
 */
void Evolution::makeNextGeneration()
{
    std::vector<res> temp;
    // około 5% populacji całkowicie losowej
    while(temp.size()<(_population/20))
        temp.push_back(res{getRandomParams()});
    // około 15% populacji jako hybrydy
    while(temp.size()<(_population/5))
        temp.push_back(res{makeHybrid()});
    // skopiuj najlepszego osobnika bez zmian
    temp.push_back(_vPopulation.at(0));

    float th = 1;
    while(temp.size()<_population)
    {
        for(int i=0;i<th;i++)
        {
            temp.push_back(res{getChildParams(_vPopulation.at(i).params)});
            if(temp.size()>=_population)
                break;
        }
        th+=.15;
    }

//    for(unsigned int i=0;i<_vPopulation.size();i++)
//    {
//        temp.push_back(res{getChildParams(_vPopulation.at(i).params)});
//        if(temp.size()>=_population)
//            break;
//        temp.push_back(res{getChildParams(_vPopulation.at(i).params)});
//        if(temp.size()>=_population)
//            break;
//        temp.push_back(res{getChildParams(_vPopulation.at(i).params)});
//        if(temp.size()>=_population)
//            break;
//        temp.push_back(res{getChildParams(_vPopulation.at(i).params)});
//        if(temp.size()>=_population)
//            break;
//    }
    _vPopulation.swap(temp);
}
