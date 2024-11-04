#pragma once

#include "ITable.hpp"

class ChildSeatTable : public ITable {
public:
    explicit ChildSeatTable(sqlite3*& db);
    ~ChildSeatTable() = default;

    bool add(Common::Dataset &entity) override;
    bool update(Common::Dataset &data) override;
    bool deleteAt(Common::Dataset &entity) override;
    Common::Dataset getAll() override; 
    void get(Common::Dataset &entity) override;

private:
    sqlite3* dataBase;
};