#ifndef STUPIDSEARCHER_HPP
#define STUPIDSEARCHER_HPP

#include <memory>
#include "../Searcher.hpp"

/**
 * @class StupidSearcher
 * @author mgr inż. Wojciech Kogut
 *
 * Prymitywna metoda wyszukiwania rozwiązania, przeszukuje cały obszar pomiędzy min i max ze stałym ziarnem. Ziarmo przeszukiwania
 * może być podane w sposób bezpośredni lub jako liczba próbek na którą podzielić obszar.
 */

class Instance;
class ResultKeeper;

class StupidSearcher : public Searcher
{
public:
    enum SS
    {
        seed,
        samples
    };
    StupidSearcher(float val, std::shared_ptr<Instance> ins, SS type = seed,
                   std::shared_ptr<ResultKeeper> res = std::shared_ptr<ResultKeeper>());

    virtual void run();
    virtual void stop(){}

private:
    float _seed = 1.0;

    std::vector<float> _next;
    bool calcNext();
};

#endif
