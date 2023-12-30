#include "seeder.h"

namespace Seeder
{

    /**
        Utility to populate a record collection
        prefix - prefix for the string value for every record
        numRecords - number of records to populate in the collection
    */
    extern QBRecordCollection populateDummyData(const std::string &prefix, int numRecords)
    {
        QBRecordCollection data;
        data.reserve(numRecords);
        for (uint i = 0; i < numRecords; i++)
        {
            QBRecord rec = {i, prefix + std::to_string(i), i % 100, std::to_string(i) + prefix};
            data.emplace_back(rec);
        }
        return data;
    }

    extern QBRecordCollectionSOA populateDummyDataSOA(const std::string &prefix, int numRecords)
    {
        QBRecordCollectionSOA data;
        data.reserve(numRecords);
        for (uint i = 0; i < numRecords; i++)
        {
            QBRecord rec = {i, prefix + std::to_string(i), i % 100, std::to_string(i) + prefix};
            data.emplace_back(rec);
        }
        return data;

    }
}
