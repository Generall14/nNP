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

    std::shared_ptr<Instance> ins(new InstanceF2D(pts, 2, {-5, -5, -5}, {5, 5, 5}));

    std::shared_ptr<ResultKeeper> res(new ResultKeeper());


//    StupidSearcher ss(10000, ins, StupidSearcher::samples, res);
    Evolution ss(ins, 100, 1000, res, 1);

    ss.run();
    cout << res->report() << endl << endl << endl;

    cout << ss.getResult().toString() << endl;

    return 0;
}

