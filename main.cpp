#include <iostream>

#include <memory>
#include "opt/fun2d/InstanceF2D.hpp"
#include "opt/imp/StupidSearcher.hpp"

using namespace std;

int main()
{
    std::vector<std::pair<float, float> > pts = {
                                                {0, 3},
                                                {0, 1},
                                                {-1, 0}
                                                };
    std::vector<float> pars = {1, 1};

    std::shared_ptr<Instance> ins(new InstanceF2D(pts, 1, {0, 0}, {8, 6}));
    cout << ins->sim(pars) << endl;


    StupidSearcher ss(100, ins, StupidSearcher::samples);
    ss.run();

    return 0;
}

