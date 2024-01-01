#include "../types/collection.h"
#include "../types/collection_generic.h"

namespace Seeder
{
    QBRecordCollection populateDummyData(const std::string &prefix, int numRecords);

    QBRecordCollectionSOA populateDummyDataSOA(const std::string &prefix, int numRecords);

    QBGenericCollection populateDummyDataGeneric(const std::string &prefix, int numRecords);
}