#pragma once

#include "../types/collection.h"

class BaseStrategy
{
public:
    /**
        Return records that contains a string in the StringValue field
        records - the initial set of records to filter
        matchString - the string to search for
    */
    QBRecordCollection QBFindMatchingRecords(
        const QBRecordCollection &records,
        const std::string &columnName,
        const std::string &matchString);
};