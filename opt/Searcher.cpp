#include "Searcher.hpp"
#include <stdexcept>

Searcher::Searcher(std::shared_ptr<Instance> ins, std::shared_ptr<ResultKeeper> res):
    _ins(ins),
    _res(res)
{}

bool Searcher::isDone() const
{
    return _done;
}

res Searcher::getResult() const
{
    if(!_done)
        throw std::logic_error("Searcher::getResult(): wyniki nie są jeszcze gotowe.");
    return _best;
}
