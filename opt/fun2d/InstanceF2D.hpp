#ifndef INSTANCEF2D_HPP
#define INSTANCEF2D_HPP

#include <vector>
#include "../Instance.hpp"

/**
 * @class InstanceF2D
 * @author mgr inż. Wojciech Kogut
 *
 * Klasa reprezentująca problem aproksymacji funkcją n-tego stopnia (v0*x^0 + v1*x^1 + v2*x^2 ...). W konstruktorze
 * przyjmuje punkty aproksymacji oraz stopień funkcji docelowej. Zwraca przeciwność sumy kwadratów błedów.
 *
 * Głównym celem tej klasy jest testowanie algorytmów optymalizacji.
 */

class InstanceF2D : public Instance
{
public:
    InstanceF2D(std::vector<std::pair<float, float> > pts, unsigned int n,
                std::vector<float> min=std::vector<float>(),
                std::vector<float> max = std::vector<float>());

protected:
    virtual float lsim(const std::vector<float> &params) const;

private:
    std::vector<std::pair<float, float> > _pts;
    unsigned int _n;

    float getVal(const std::vector<float> &params, float x) const;
};

#endif
