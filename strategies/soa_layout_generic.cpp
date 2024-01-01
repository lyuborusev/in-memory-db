#include "soa_layout_generic.h"
#include <algorithm>

QBRecordCollection SOAGenericStrategy::QBFindMatchingRecords(
    const QBGenericCollection &records,
    const std::string &columnName,
    const std::string &matchString)
{
    auto column = records.columns.find(columnName);
    std::vector<int> result = column->second->matchValue(matchString);

    QBRecordCollection collection;

    for (int i = 0; i < result.size(); i++)
    {
        int index = result[i];
        collection.emplace_back(QBRecord{
            std::any_cast<uint>(records.columns.find("column0")->second->at(index)),
            std::any_cast<std::string>(records.columns.find("column1")->second->at(index)),
            std::any_cast<long>(records.columns.find("column2")->second->at(index)),
            std::any_cast<std::string>(records.columns.find("column3")->second->at(index)),
        });
    }
    return collection;
}

void SOAGenericStrategy::DeleteRecordByID(QBGenericCollection &records, uint id)
{
    records.remove(id);
}

std::string SOAGenericStrategy::Name()
{
    return "SOAGenericStrategy";
}