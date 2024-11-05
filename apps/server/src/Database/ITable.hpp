#pragma once
#include <sqlite3.h>

#include "DatabaseQueries.hpp"
#include "Repositories.hpp"

class ITable {

public:
    virtual ~ITable() {};

    virtual bool add(Common::Dataset &entity) = 0;
    virtual bool update(Common::Dataset &data) = 0;
    virtual bool deleteAt(Common::Dataset &entity) = 0;
    virtual Common::Dataset getAll() = 0;
    virtual void get(Common::Dataset &entity) = 0;
    virtual void getColumns(Common::Dataset &entity) = 0;

};