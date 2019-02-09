#ifndef SEARCHER_HPP
#define SEARCHER_HPP

#include <memory>
#include "res.hpp"

/**
 * @class Searcher
 * @author mgr inż. Wojciech Kogut
 *
 * Interfejs klas wyszukujących optymalne parametry dla obiektów Instance.
 *
 * Klasy implementujące ten interfejs powinny działać wielowątkowo.
 */

class Instance;
class ResultKeeper;

class Searcher
{
public:
    Searcher(std::shared_ptr<Instance> ins, std::shared_ptr<ResultKeeper> res);

    /**
     * Metoda wykonuje optymalizacje wskazanego obiektu.
     */
    virtual void run() = 0;
    /**
     * Metoda zatrzymuje proces optymalizacji.
     */
    virtual void stop() = 0;

    bool isDone() const;
    res getResult() const;

protected:
    std::shared_ptr<Instance> _ins;
    std::shared_ptr<ResultKeeper> _res;
    bool _done = false;
    res _best;
};

#endif
