#ifndef RESULTTRASH_HPP
#define RESULTTRASH_HPP

#include <vector>
#include <string>
#include "../Result.hpp"

/**
 * @class ResultKeeperTrash
 * @author mgr inż Wojciech Kogut
 *
 * Klasa anihilująca wszystkie przekazywane do niej dane.
 */

class ResultKeeperTrash : public ResultKeeper
{
public:
    ResultKeeperTrash();
    virtual void append(std::vector<float>, float, std::string = "");
    virtual std::string report() const;
};

#endif
