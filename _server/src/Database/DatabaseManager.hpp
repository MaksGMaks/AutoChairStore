#pragma once

#include <iostream>
#include <sqlite3.h>

namespace database
{
    bool create_db(sqlite3*& db);
} // namespace database
