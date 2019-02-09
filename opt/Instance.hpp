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
 *
 * Klasy dziedziczące po Instance muszą być wątkowo bezpieczne.
 */

class Instance
{
public:
    Instance(unsigned int params,
             std::vector<float> min=std::vector<float>(),
             std::vector<float> max = std::vector<float>());

    float sim(const std::vector<float> &params) const;

    virtual bool isOk(const std::vector<float> &params) const;

    const std::vector<float>& getMinParams() const;
    const std::vector<float>& getMaxParams() const;

protected:
    /**
     * Metoda wykonuje symulacje na podstawie wskazanych parametrów, zwraca wartość float proporcjonalną do jakości
     * aktualnego wyniku (większe wartości oznaczają lepsze parametry). Przekazane parametry są sprawdzone w kwestii
     * liczby danych oraz poprawności (metodą isOk() ).
     */
    virtual float lsim(const std::vector<float> &params) const = 0;

private:
    std::vector<float> _mins;                           /**<Minimalne wartości dla poszczególnych parametrów.*/
    std::vector<float> _maxs;                           /**<Maksymalne wartości dla poszczególnych parametrów.*/
};

#endif
