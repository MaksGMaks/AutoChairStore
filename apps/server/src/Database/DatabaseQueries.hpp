#pragma once

#include <iostream>
#include <sqlite3.h>
#include <vector>

#include "Repositories.hpp"

namespace database
{
    bool create_db(sqlite3*& db);

    bool execute_query(const std::string query, sqlite3*& db);
    
    Common::Dataset selectAllFromTable(const std::string &sql, sqlite3* db);
} // namespace database
