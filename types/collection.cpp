#include "collection.h"
#include <algorithm>

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

void QBRecordCollectionSOA::remove(uint id)
{
    auto iter = std::find_if(column0.begin(), column0.end(), [&](uint rec)
                             { return rec == id; });

    if (iter == column0.end())
    {
        return;
    }

    const int index = iter - column0.begin();
    /*
        std::iter_swap(column0.begin() + index, column0.back());
        std::iter_swap(column1.begin() + index, column1.back());
        std::iter_swap(column2.begin() + index, column2.back());
        std::iter_swap(column3.begin() + index, column3.back());
    */
    column0.pop_back();
    column1.pop_back();
    column2.pop_back();
    column3.pop_back();
}