#include <iostream>

#include <memory>
#include "opt/fun2d/InstanceF2D.hpp"
#include "opt/imp/StupidSearcher.hpp"
#include "opt/Result.hpp"
#include "opt/imp/Evolution.hpp"

using namespace std;

int main()
{
    std::vector<std::pair<float, float> > pts = {
                                                {-1, 4},
                                                {0, 1},
                                                {1, 2},
                                                {2, 7},
                                                {3, 16},
                                                {-2, 11},
                                                {-3, 22}
                                                };

    std::shared_ptr<Instance> ins(new InstanceF2D(pts, 2, {-50000, -50000, -50000}, {50000, 50000, 50000}));

    std::shared_ptr<ResultKeeper> res(new ResultKeeper());

    Evolution ss(ins, 60, 400000, res, -0.01);

    ss.run();
    cout << res->report() << endl << endl << endl;

    cout << ss.getResult().toString() << endl;

    return 0;
}

