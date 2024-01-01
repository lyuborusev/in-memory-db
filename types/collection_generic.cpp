#include "collection_generic.h"

void QBGenericCollection::remove(uint id)
{
    for (auto col : columns)
    {
        col.second->remove(id);
    }
}

template <typename T>
void QBColumn<T>::reserve(size_t size)
{
    data.reserve(size);
}
template <typename T>
void QBColumn<T>::emplace_back(std::any value)
{
    T val = std::any_cast<T>(value);
    data.emplace_back(val);
}
template <typename T>
std::vector<int> QBColumn<T>::matchValue(std::string matchString)
{
    return std::vector<int>();
}
template <typename T>
std::any QBColumn<T>::at(size_t index)
{
    return data[index];
}

template <typename T>
void QBColumn<T>::remove(uint index)
{
    data[index] = data.back();
    data.pop_back();
}

void remove(uint index);
template <>
std::vector<int> QBColumn<uint>::matchValue(std::string matchString)
{
    uint matchValue = std::stoul(matchString);
    std::vector<int> result;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == matchValue)
        {
            result.push_back(i);
        }
    }
    return result;
}

template <>
std::vector<int> QBColumn<long>::matchValue(std::string matchString)
{
    long matchValue = std::stol(matchString);
    std::vector<int> result;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == matchValue)
        {
            result.push_back(i);
        }
    }
    return result;
}

template <>
std::vector<int> QBColumn<std::string>::matchValue(std::string matchString)
{
    std::vector<int> result;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].find(matchString) != std::string::npos)
        {
            result.push_back(i);
        }
    }
    return result;
}

template struct QBColumn<uint>;
template struct QBColumn<long>;
template struct QBColumn<std::string>;