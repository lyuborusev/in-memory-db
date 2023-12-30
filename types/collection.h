#pragma once

#include "record.h"
#include <vector>

/**
Represents a Record Collections
*/
typedef std::vector<QBRecord> QBRecordCollection;

QBRecordCollection QBFindMatchingRecords(const QBRecordCollection &records, const std::string &columnName, const std::string &matchString);