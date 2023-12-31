#pragma once

#include "../types/collection.h"

class SOALayouStrategy
{
public:
    QBRecordCollection QBFindMatchingRecords(
        const QBRecordCollectionSOA &records,
        const std::string &columnName,
        const std::string &matchString);
};