#pragma once

#include "strategy.h"

class SOALayouStrategy //: public IStrategy
{
public:
    /*virtual*/ QBRecordCollection QBFindMatchingRecords(
        const QBRecordCollectionSOA &records,
        const std::string &columnName,
        const std::string &matchString);
};