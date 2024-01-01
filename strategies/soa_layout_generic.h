#pragma once

#include "../types/collection.h"
#include "../types/collection_generic.h"

class SOAGenericStrategy
{
public:
    QBRecordCollection QBFindMatchingRecords(
        const QBGenericCollection &records,
        const std::string &columnName,
        const std::string &matchString);

    void DeleteRecordByID(
        QBGenericCollection &records,
        uint id);

    std::string Name();
};