#ifndef RES_HPP
#define RES_HPP

#include <vector>
#include <string>
#include <sstream>
#include <limits>

/**
 * Struktura opisująca wynik symulacji.
 */
struct res
{
    res(std::vector<float> v=std::vector<float>(), std::string d="", float r=std::numeric_limits<float>::min()):
        params(v),
        result(r),
        description(d)
    {}

    std::vector<float> params; /**<Parametry przy których dokonano symulacji.*/
    float result; /**<Wynik symulacji.*/
    std::string description; /**<Opcjonalny opis.*/

    std::string toString()
    {
        std::ostringstream ss;
        ss.precision(3);
        ss << "f( ";
        for(auto v: params)
            ss << v << " ";
        ss << ") = " << result;
        if(!description.empty())
            ss << "(" << description << ")";
        return ss.str();
    }
    bool operator<(const res& r)
    {
        return result<r.result;
    }
};

#endif
