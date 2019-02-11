#include "StupidSearcher.hpp"
#include "../Instance.hpp"
#include <iostream>

StupidSearcher::StupidSearcher(float val, std::shared_ptr<Instance> ins, SS type, std::shared_ptr<ResultKeeper> res):
    Searcher(ins, res)
{
    if(type==SS::seed)
        _seed = val;
    else
    {
        for(unsigned int i=0;i<_ins->getMinParams().size();i++)
            _seed*= _ins->getMaxParams().at(i)-_ins->getMinParams().at(i);
        _seed /= val; // <TODO> krok symulacji jest obliczany błędnie
    }
    std::cout << _seed << std::endl;
}

void StupidSearcher::run()
{
    _next = _ins->getMinParams();
    int k = 0;
    while(calcNext())
    {
        std::cout << ++k << ": ";
        for(auto v: _next)
            std::cout << v << " ";
        std::cout << std::endl;
    }
}

bool StupidSearcher::calcNext()
{
    unsigned int cinc = 0;
    while(cinc<_next.size())
    {
        _next[cinc] += _seed;
        if(_next.at(cinc)<=_ins->getMaxParams().at(cinc))
            return true;
        _next[cinc] = _ins->getMinParams().at(cinc);
        cinc++;
    }
    return false;
}
