#pragma once

#include <sys/types.h>
#include <string>

/**
    Represents a Record Object
*/

struct QBRecord
{
    uint column0; // unique id column
    std::string column1;
    long column2;
    std::string column3;
};