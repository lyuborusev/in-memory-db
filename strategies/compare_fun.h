#pragma once

#include "strategy.h"

class CompareFunStrategy : public IStrategy
{
public:
    virtual QBRecordCollection QBFindMatchingRecords(
        const QBRecordCollection &records,
        const std::string &columnName,
        const std::string &matchString);
};