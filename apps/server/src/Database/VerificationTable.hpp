#pragma once

#include "ITable.hpp"
#include <chrono>
#include <iomanip>
#include <ctime>

class VerificationTable : public ITable {
public:
    explicit VerificationTable(sqlite3*& db);
    ~VerificationTable() = default;

    bool add(Common::Dataset &entity) override;
    bool update(Common::Dataset &data) override;
    bool deleteAt(Common::Dataset &entity) override;
    Common::Dataset getAll() override; 
    void get(Common::Dataset &entity) override;
    void getColumns(Common::Dataset &entity) override;

private:
    sqlite3* dataBase;
    std::string getCurrentTime();
    std::string getValidTime();
};