#include "VerificationTable.hpp"

VerificationTable::VerificationTable(sqlite3*& db) {
    dataBase = db;
}

bool VerificationTable::add(Common::Dataset &entity) {
    std::string query = "INSERT INTO " + std::string(Common::Verification::TABLE_NAME) + " (email, code, created_at) "
                        "VALUES ('" + entity[Common::Verification::EMAIL_KEY].front() + "', '" + entity[Common::Verification::CODE_KEY].front() + "', '" 
                        + getValidTime() + "');";
    
    return database::execute_query(query, dataBase);
}

bool VerificationTable::update(Common::Dataset &data) {
    std::string query = "";

    auto email_list = data[Common::Verification::EMAIL_KEY];
    auto code_list = data[Common::Verification::CODE_KEY];
    
    for(auto element : data[Common::Verification::EMAIL_KEY]) {
        query += "UPDATE " + std::string(Common::Verification::TABLE_NAME) + " SET " + std::string(Common::Verification::CODE_KEY) + " = '" + 
        code_list.front() + "', " + std::string(Common::Verification::CREATEDAT_KEY) + " = '" + 
        getValidTime() + "' WHERE " + std::string(Common::Verification::EMAIL_KEY) + " = '" + 
        email_list.front() + "';";

        code_list.pop_front();
        email_list.pop_front();
    }

    return database::execute_query(query, dataBase);   
}

bool VerificationTable::deleteAt(Common::Dataset &entity) {
    const std::string query =
        "DELETE FROM " + std::string(Common::Verification::TABLE_NAME) + " WHERE email = '" + entity[Common::Verification::EMAIL_KEY].front() + "';";
    return database::execute_query(query, dataBase);
}

Common::Dataset VerificationTable::getAll() {
    std::string sql = "SELECT * FROM " + std::string(Common::Verification::TABLE_NAME) + "WHERE created_at > " + getCurrentTime() + ";";
    return database::selectAllFromTable(sql, dataBase);
}

void VerificationTable::get(Common::Dataset &entity) {
    Common::Data values = entity[Common::COLUMN_KEY];
    std::string sql = "SELECT " + values.front();
    values.pop_front();
    while (!values.empty()) {
        sql += ", " + values.front();
        values.pop_front();
    }
    sql += " FROM " + std::string(Common::Verification::TABLE_NAME) + " WHERE email = '" + entity[Common::Verification::EMAIL_KEY].front() 
    + "AND created_at > " + getCurrentTime() + "';";
    entity = database::selectAllFromTable(sql, dataBase);
}

void VerificationTable::getColumns(Common::Dataset &entity) {
    Common::Data columns = entity[Common::COLUMN_KEY];
    std::string sql = "SELECT * FROM " + std::string(Common::Verification::TABLE_NAME) + " WHERE " + columns.front() + " IN ('";
    Common::Data values = entity[columns.front()];
    sql += values.front();
    values.pop_front();
    for(auto value : values) {
        sql += "', '" + value;
    }
    sql += "')";
    columns.pop_front();
    for(auto column : columns) {
        values = entity[column];
        sql += " AND " + column + " IN ('" + values.front();
        values.pop_front();
        for(auto value : values) {
            sql += "', '" + value;
        }
        sql += "')";
    }
    sql += "AND created_at > " + getCurrentTime() + ";";
    entity = database::selectAllFromTable(sql, dataBase);
}

std::string VerificationTable::getCurrentTime() {
    // Get current time as time_t
    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

    // Convert time_t to tm structure
    std::tm now_tm;
    #if defined(_MSC_VER) || defined(__MINGW32__) // For Windows
        localtime_s(&now_time_t, &now_tm);
    #else // For Linux and others
        localtime_r(&now_time_t, &now_tm);
    #endif

    // Create a stringstream for formatting
    std::stringstream ss;
    ss << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

std::string VerificationTable::getValidTime() {
    // Get current time as time_t
    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

    // Add 15 minutes to current time
    now_time_t += 15 * 60;

    // Convert time_t to tm structure
    std::tm now_tm;
    #if defined(_MSC_VER) || defined(__MINGW32__) // For Windows
        localtime_s(&now_time_t, &now_tm);
    #else // For Linux and others
        localtime_r(&now_time_t, &now_tm);
    #endif

    // Create a stringstream for formatting
    std::stringstream ss;
    ss << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}