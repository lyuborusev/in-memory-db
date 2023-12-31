#include "strategies/strategy.h"
#include "strategies/base.h"
#include "strategies/compare_fun.h"
#include "strategies/soa_layout.h"
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
    // populate a bunch of data
    auto data = Seeder::populateDummyData("testdata", 1000);

    auto dataSOA = Seeder::populateDummyDataSOA("testdata", 1000);

    auto baseStrategy = Context<BaseStrategy, QBRecordCollection>();
    baseStrategy.execute(data);

    auto compareFunStrategy = Context<CompareFunStrategy, QBRecordCollection>();
    compareFunStrategy.execute(data);

    auto soaLayoutStrategy = Context<SOALayouStrategy, QBRecordCollectionSOA>();
    soaLayoutStrategy.execute(dataSOA);

    return 0;
}
