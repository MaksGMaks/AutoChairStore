#pragma once

#include "ITable.hpp"

class ProductsTable : public ITable {
public:
    explicit ProductsTable(sqlite3*& db);
    ~ProductsTable() = default;

    bool add(Common::Dataset &entity) override;
    bool update(Common::Dataset &data) override;
    bool deleteAt(Common::Dataset &entity) override;
    Common::Dataset getAll() override; 
    void get(Common::Dataset &entity) override;
    void getColumns(Common::Dataset &entity) override;

private:
    sqlite3* dataBase;
};