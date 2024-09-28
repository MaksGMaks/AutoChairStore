#pragma once

#include "ITable.hpp"

class ProductInfoTable : public ITable {
public:
    ProductInfoTable(sqlite3*& db);
    virtual ~ProductInfoTable();

    bool add(Common::Dataset &entity) override;
    bool update(Common::Dataset &data) override;
    bool deleteAt(Common::Dataset &entity) override;
    Common::Dataset getAll() override; 
    void get(Common::Dataset &entity) override;

private:
    sqlite3* dataBase;
};