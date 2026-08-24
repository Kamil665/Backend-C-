#pragma once

#include <string>

// Forward declaration — ускоряет сборку и не замусоривает глобальное пространство
struct sqlite3;

class Database {
private:
    sqlite3* db{ nullptr };

public:
    Database() = default;
    ~Database();

    // Запрещаем копирование во избежание двойного освобождения ресурсов
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    // Разрешаем перемещение
    Database(Database&& other) noexcept;
    Database& operator=(Database&& other) noexcept;

    bool connect(const std::string& path);
};