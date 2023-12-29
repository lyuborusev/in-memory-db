#include "base_implementation/collection.h"

#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <chrono>
#include <iostream>
#include <ratio>

int main(int argc, char *argv[])
{
    using namespace std::chrono;
    // populate a bunch of data
    auto data = populateDummyData("testdata", 1000);
    // Find a record that contains and measure the perf
    auto startTimer = steady_clock::now();
    auto filteredSet = QBFindMatchingRecords(data, "column1", "testdata500");
    auto filteredSet2 = QBFindMatchingRecords(data, "column2", "24");
    std::cout << "profiler: " << double((steady_clock::now() - startTimer).count()) * steady_clock::period::num / steady_clock::period::den << std::endl;

    // make sure that the function is correct
    assert(filteredSet.size() == 1);
    return 0;
}
