#include <string>
#include "../types/collection.h"

class IStrategy
{
public:
    virtual QBRecordCollection QBFindMatchingRecords(
        const QBRecordCollection &records,
        const std::string &columnName,
        const std::string &matchString) = 0;

    virtual ~IStrategy() {}
};