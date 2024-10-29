#pragma once

#include "ITable.hpp"

class LuxurySeatTable : public ITable {
public:
    explicit LuxurySeatTable(sqlite3*& db);
    ~LuxurySeatTable() = default;

    bool add(Common::Dataset &entity) override;
    bool update(Common::Dataset &data) override;
    bool deleteAt(Common::Dataset &entity) override;
    Common::Dataset getAll() override; 
    void get(Common::Dataset &entity) override;

private:
    sqlite3* dataBase;
};