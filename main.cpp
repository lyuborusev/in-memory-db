#include "strategies/strategy.h"
#include "strategies/base.h"
#include "strategies/compare_fun.h"
#include "strategies/soa_layout.h"
#include "test/seeder.h"

int main(int argc, char *argv[])
{
    // populate a bunch of data
    const int numberOfRecords = 1000;

    Context<BaseStrategy, QBRecordCollection>().execute(
        Seeder::populateDummyData("testdata", numberOfRecords));

    Context<CompareFunStrategy, QBRecordCollection>().execute(
        Seeder::populateDummyData("testdata", numberOfRecords));

    Context<SOALayouStrategy, QBRecordCollectionSOA>().execute(
        Seeder::populateDummyDataSOA("testdata", numberOfRecords));

    return 0;
}
