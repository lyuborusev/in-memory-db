#include "strategies/strategy.h"
#include "strategies/base.h"
#include "strategies/compare_fun.h"
#include "strategies/soa_layout.h"
#include "test/seeder.h"

int main(int argc, char *argv[])
{
    // populate a bunch of data
    const int numberOfRecords = 1000;
    auto data = Seeder::populateDummyData("testdata", numberOfRecords);
    auto dataSOA = Seeder::populateDummyDataSOA("testdata", numberOfRecords);

    Context<BaseStrategy, QBRecordCollection>().execute(data);

    data = Seeder::populateDummyData("testdata", numberOfRecords);
    Context<CompareFunStrategy, QBRecordCollection>().execute(data);

    Context<SOALayouStrategy, QBRecordCollectionSOA>().execute(dataSOA);

    return 0;
}
