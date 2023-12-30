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

    void reserve(size_t _size)
    {
        size = _size;

        column0.reserve(size);
        column1.reserve(size);
        column2.reserve(size);
        column3.reserve(size);
    }

    void emplace_back(QBRecord rec)
    {
        column0.emplace_back(rec.column0);
        column1.emplace_back(rec.column1);
        column2.emplace_back(rec.column2);
        column3.emplace_back(rec.column3);
    }
};
