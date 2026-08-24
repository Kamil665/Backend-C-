#include "database.h"
#include <sqlite3.h>
#include <iostream>
#include <utility>

Database::~Database() {
    if (db != nullptr) {
        sqlite3_close(db);
        db = nullptr;
    }
}

Database::Database(Database&& other) noexcept : db(other.db) {
    other.db = nullptr;
}

Database& Database::operator=(Database&& other) noexcept {
    if (this != &other) {
        if (db != nullptr) {
            sqlite3_close(db);
        }
        db = other.db;
        other.db = nullptr;
    }
    return *this;
}

bool Database::connect(const std::string& path) {
    // Безопасно закрываем старое соединение при повторном вызове
    if (db != nullptr) {
        sqlite3_close(db);
        db = nullptr;
    }

    int result = sqlite3_open(path.c_str(), &db);

    if (result != SQLITE_OK) {
        std::cerr << "Database connection error: "
            << (db ? sqlite3_errmsg(db) : "Unknown error")
            << std::endl;
        if (db != nullptr) {
            sqlite3_close(db);
            db = nullptr;
        }
        return false;
    }

    std::cout << "Connected to SQLite Database: " << path << std::endl;
    return true;
}