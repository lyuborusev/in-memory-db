#pragma once

#include "record.h"
#include <vector>

/**
Represents a Record Collections
*/
typedef std::vector<QBRecord> QBRecordCollection;

struct QBRecordCollectionSOA
{
    size_t size;

    std::vector<uint> column0; // unique id column
    std::vector<std::string> column1;
    std::vector<long> column2;
    std::vector<std::string> column3;

    void reserve(size_t _size);
    void emplace_back(QBRecord rec);
};
