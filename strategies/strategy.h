#pragma once

#include <iostream>

template <typename Strategy, typename Records>
class Context
{
public:
    void execute(Records data)
    {
        using namespace std::chrono;

        const int operationRepeatTime = 10000;

        // Find a record that contains and measure the perf
        auto startTimer = steady_clock::now();

        for (int i = 0; i < operationRepeatTime; i++)
        {
            auto filteredSet = strategy.QBFindMatchingRecords(data, "column1", "testdata500");
            auto filteredSet2 = strategy.QBFindMatchingRecords(data, "column2", "24");

            // make sure that the function is correct
            assert(filteredSet.size() == 1);
        }
        std::cout << "profiler: " << double((steady_clock::now() - startTimer).count()) * steady_clock::period::num / steady_clock::period::den << std::endl;
    }

private:
    Strategy strategy;
};