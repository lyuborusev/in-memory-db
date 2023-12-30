#include "strategies/base.h"
#include "strategies/compare_fun.h"
#include "test/seeder.h"

#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <chrono>
#include <iostream>
#include <ratio>
#include <memory>

int main(int argc, char *argv[])
{
    using namespace std::chrono;

    // populate a bunch of data
    auto data = Seeder::populateDummyData("testdata", 1000);

    std::vector<std::shared_ptr<IStrategy>> strategies = {
        std::shared_ptr<IStrategy>(new BaseStrategy()),       /**/
        std::shared_ptr<IStrategy>(new CompareFunStrategy()), /**/
    };

    // How many times to repeat the operation in order to get more meaningful profiler data
    const int operationRepeatTime = 10000;

    for (auto s : strategies)
    {
        // Find a record that contains and measure the perf
        auto startTimer = steady_clock::now();

        for (int i = 0; i < operationRepeatTime; i++)
        {
            auto filteredSet = s->QBFindMatchingRecords(data, "column1", "testdata500");
            auto filteredSet2 = s->QBFindMatchingRecords(data, "column2", "24");

            // make sure that the function is correct
            assert(filteredSet.size() == 1);
        }
        std::cout << "profiler: " << double((steady_clock::now() - startTimer).count()) * steady_clock::period::num / steady_clock::period::den << std::endl;
    }

    return 0;
}
