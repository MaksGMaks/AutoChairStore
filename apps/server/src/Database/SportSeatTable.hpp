#pragma once

#include "ITable.hpp"

class SportSeatTable : public ITable {
public:
    explicit SportSeatTable(sqlite3*& db);
    ~SportSeatTable() = default;

    bool add(Common::Dataset &entity) override;
    bool update(Common::Dataset &data) override;
    bool deleteAt(Common::Dataset &entity) override;
    Common::Dataset getAll() override; 
    void get(Common::Dataset &entity) override;

private:
    sqlite3* dataBase;
};