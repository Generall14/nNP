#ifndef RESULT_HPP
#define RESULT_HPP

#include <vector>
#include <string>
#include "res.hpp"

/**
 * @class ResultKeeper
 * @author mgr inż Wojciech Kogut
 *
 * Klasa do przechowywania wyników otrzymanych w procesie optymalizacji, ma na celu umożliwienie prezentacji przebiegu
 * poszukiwań oraz wyników wszystkich zbadanych elementów.
 */

class ResultKeeper
{
public:
    void clear();
    virtual void append(std::vector<float> params, float result, std::string description = "");
    res getMax() const;

    virtual std::string report() const;

protected:
    std::vector<res> _res;
};

#endif
