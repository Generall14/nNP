#include "InstanceF2D.hpp"
#include <cmath>

/**
 * @param pts - wektor par punktów <x, y>.
 * @param n - stopień wielomianu.
 */
InstanceF2D::InstanceF2D(std::vector<std::pair<float, float> > pts, unsigned int n, std::vector<float> min, std::vector<float> max):
    Instance(n+1, min, max),
    _pts(pts),
    _n(n+1)
{

}

float InstanceF2D::lsim(const std::vector<float> &params) const
{
    float err = 0;
    for(auto pair: _pts)
        err -= pow(pair.second - getVal(params, pair.first), 2);
    return err;
}

float InstanceF2D::getVal(const std::vector<float> &params, float x) const
{
    float acc = 0;
    for(unsigned int i=0;i<_n;i++)
        acc += params.at(i)*std::pow(x, i);
    return acc;
}
