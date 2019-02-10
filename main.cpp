#include <iostream>

#include "opt/fun2d/InstanceF2D.hpp"

using namespace std;

int main()
{
    std::vector<std::pair<float, float> > pts = {
                                                {0, 3},
                                                {0, 1},
                                                {-1, 0}
                                                };
    std::vector<float> pars = {1, 1};

    InstanceF2D f2d(pts, 1);
    cout << f2d.sim(pars) << endl;

    cout << "Hello World!" << endl;
    return 0;
}

