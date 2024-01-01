#pragma once

#include <vector>
#include <any>
#include <map>
#include <string>

#include <sys/types.h>

struct QBColumnInterface
{
    virtual ~QBColumnInterface() {}

    virtual void reserve(size_t size) = 0;
    virtual void emplace_back(std::any value) = 0;
    virtual std::vector<int> matchValue(std::string matchString) = 0;
    virtual std::any at(size_t index) = 0;
    virtual void remove(uint index) = 0;
};

template <typename T>
struct QBColumn : QBColumnInterface
{
    void reserve(size_t size);
    void emplace_back(std::any value);
    std::vector<int> matchValue(std::string matchString);
    void remove(uint index);
    std::any at(size_t index);

    std::vector<T> data;
};

struct QBGenericCollection
{
    size_t size;
    void remove(uint id);
    std::map<std::string, std::shared_ptr<QBColumnInterface>> columns;
};