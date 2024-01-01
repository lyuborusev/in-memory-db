#include "compare_fun.h"
#include <functional>
#include <utility>
#include <algorithm>

namespace
{
    std::function<bool(QBRecord)> getCompareFunc(const std::string &columnName, const std::string &matchString)
    {
        if (columnName == "column0")
        {
            uint matchValue = std::stoul(matchString);
            auto lambda = [matchValue](QBRecord rec)
            {
                return matchValue == rec.column0;
            };
            return lambda;
        }
        else if (columnName == "column1")
        {
            return [matchString](QBRecord rec)
            {
                return rec.column1.find(matchString) != std::string::npos;
            };
        }
        else if (columnName == "column2")
        {
            long matchValue = std::stol(matchString);
            return [matchValue](QBRecord rec)
            {
                return matchValue == rec.column2;
            };
        }
        else if (columnName == "column3")
        {
            return [matchString](QBRecord rec)
            {
                return rec.column3.find(matchString) != std::string::npos;
            };
        }
        else
        {
            return [&](QBRecord)
            {
                return false;
            };
        }
    }
}

QBRecordCollection CompareFunStrategy::QBFindMatchingRecords(const QBRecordCollection &records, const std::string &columnName, const std::string &matchString)
{
    std::function<bool(QBRecord)> func = getCompareFunc(columnName, matchString);

    QBRecordCollection result;
    std::copy_if(records.begin(), records.end(), std::back_inserter(result), func);
    return result;
}

void CompareFunStrategy::DeleteRecordByID(QBRecordCollection &records, uint id)
{
    auto iter = std::find_if(records.begin(), records.end(), [&](QBRecord rec)
                             { return rec.column0 == id; });
    if (iter == records.end())
    {
        return;
    }
    *iter = records.back();
    records.pop_back();
}

std::string CompareFunStrategy::Name()
{
    return "CompareFunStrategy";
}