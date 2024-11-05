#pragma once

#include "ITable.hpp"

class PhotosTable : public ITable {
public:
    PhotosTable(sqlite3*& db);
    virtual ~PhotosTable();

    bool add(Common::Dataset &entity) override;
    bool update(Common::Dataset &data) override;
    bool deleteAt(Common::Dataset &entity) override;
    Common::Dataset getAll() override; 
    void get(Common::Dataset &entity) override;
    void getColumns(Common::Dataset &entity) override;

private:
    sqlite3* dataBase;
};