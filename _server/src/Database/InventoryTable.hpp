#pragma once

#include "ITable.hpp"

class InventoryTable : public ITable {
public:
    InventoryTable(sqlite3*& db);
    virtual ~InventoryTable();

    bool add(Common::Dataset &entity) override;
    bool update(Common::Dataset &data) override;
    bool deleteAt(Common::Dataset &entity) override;
    Common::Dataset getAll() override; 
    void get(Common::Dataset &entity) override;

private:
    sqlite3* dataBase;
};