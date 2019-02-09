#ifndef INSTANCE_HPP
#define INSTANCE_HPP

#include <vector>

/**
 * @class Instance
 * @author mgr inż. Wojciech Kogut
 *
 * Interfejs klas reprezentujących obiekty do optymalizacji.
 *
 * Parametry optymalizacji są przekazywane jako wektor wartości float, w procesie optymalizacji parametry będą
 * dobierane tak, aby zmaksymalizować wartość zwróconą z metody sim().
 */

class Instance
{
public:
    Instance(unsigned int params,
             std::vector<float> min=std::vector<float>(),
             std::vector<float> max = std::vector<float>());

    /**
     * Metoda wykonuje symulacje na podstawie aktualnych parametrów, zwraca wartość float proporcjonalną do jakości
     * aktualnego wyniku (większe wartości oznaczają lepsze parametry).
     */
    virtual float sim() const = 0;

    const std::vector<float>& getParams() const;
    void setParams(std::vector<float> params);
    virtual bool isOk() const;

    const std::vector<float>& getMinParams() const;
    const std::vector<float>& getMaxParams() const;

private:
    std::vector<float> _pars;                           /**<Parametry podlegające optymalizacji.*/
    std::vector<float> _mins;                           /**<Minimalne wartości dla poszczególnych parametrów.*/
    std::vector<float> _maxs;                           /**<Maksymalne wartości dla poszczególnych parametrów.*/
};

#endif
