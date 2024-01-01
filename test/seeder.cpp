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

    extern QBGenericCollection populateDummyDataGeneric(const std::string &prefix, int numRecords)
    {
        QBGenericCollection data;

        data.size = numRecords;
        /*
                data.columns["column0"] = std::make_shared<QBColumnInterface>(QBColumn<int>());
                data.columns["column1"] = std::make_shared<QBColumnInterface>(QBColumn<std::string>());
                data.columns["column2"] = std::make_shared<QBColumnInterface>(QBColumn<long>());
                data.columns["column3"] = std::make_shared<QBColumnInterface>(QBColumn<std::string>());
        */
        data.columns["column0"] = std::shared_ptr<QBColumnInterface>(new QBColumn<uint>());
        data.columns["column1"] = std::shared_ptr<QBColumnInterface>(new QBColumn<std::string>());
        data.columns["column2"] = std::shared_ptr<QBColumnInterface>(new QBColumn<long>());
        data.columns["column3"] = std::shared_ptr<QBColumnInterface>(new QBColumn<std::string>());

        data.columns["column0"]->reserve(numRecords);
        data.columns["column1"]->reserve(numRecords);
        data.columns["column2"]->reserve(numRecords);
        data.columns["column3"]->reserve(numRecords);

        for (uint i = 0; i < numRecords; i++)
        {
            data.columns["column0"]->emplace_back((uint)i);
            data.columns["column1"]->emplace_back(prefix + std::to_string(i));
            data.columns["column2"]->emplace_back((long)i % 100);
            data.columns["column3"]->emplace_back(std::to_string(i) + prefix);
        }
        return data;
    }
}
