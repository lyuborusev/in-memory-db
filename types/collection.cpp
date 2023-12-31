#include "collection.h"

void QBRecordCollectionSOA::reserve(size_t _size)
{
    size = _size;

    column0.reserve(size);
    column1.reserve(size);
    column2.reserve(size);
    column3.reserve(size);
}

void QBRecordCollectionSOA::emplace_back(QBRecord rec)
{
    column0.emplace_back(rec.column0);
    column1.emplace_back(rec.column1);
    column2.emplace_back(rec.column2);
    column3.emplace_back(rec.column3);
}