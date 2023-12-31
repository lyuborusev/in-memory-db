#include "soa_layout.h"
#include <algorithm>

namespace
{
    std::function<bool(int)> getCompareFunc(const QBRecordCollectionSOA &records, const std::string &columnName, const std::string &matchString)
    {
        if (columnName == "column0")
        {
            uint matchValue = std::stoul(matchString);
            return [&](int index)
            {
                return matchValue == records.column0[index];
            };
        }
        else if (columnName == "column1")
        {
            return [&](int index)
            {
                return records.column1[index].find(matchString) != std::string::npos;
            };
        }
        else if (columnName == "column2")
        {
            long matchValue = std::stol(matchString);
            return [&](int index)
            {
                return matchValue == records.column2[index];
            };
        }
        else if (columnName == "column3")
        {
            return [&](int index)
            {
                return records.column3[index].find(matchString) != std::string::npos;
            };
        }
        else
        {
            return [&](int index)
            {
                return false;
            };
        }
    }
}

QBRecordCollection SOALayouStrategy::QBFindMatchingRecords(
    const QBRecordCollectionSOA &records,
    const std::string &columnName,
    const std::string &matchString)
{
    QBRecordCollection collection;

    std::function<bool(int)> func = getCompareFunc(records, columnName, matchString);

    for (int i = 0; i < records.size; i++)
    {
        if (func(i))
        {
            collection.emplace_back(QBRecord{
                records.column0[i],
                records.column1[i],
                records.column2[i],
                records.column3[i],
            });
        }
    }
    return collection;
}

void SOALayouStrategy::DeleteRecordByID(QBRecordCollectionSOA &records, uint id)
{
    records.remove(id);
}