#pragma once

#include "../types/collection.h"

class CompareFunStrategy
{
public:
    QBRecordCollection QBFindMatchingRecords(
        const QBRecordCollection &records,
        const std::string &columnName,
        const std::string &matchString);
};