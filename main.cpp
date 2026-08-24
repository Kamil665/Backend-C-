#include <iostream>
#include "database.h"
#include "user.h"

int main() {
    std::cout << "C++ Backend starting..." << std::endl;

    Database database;

    if (!database.connect("data/database.db")) {
        std::cerr << "Failed to connect to database." << std::endl;
        return 1;
    }

    std::cout << "Database connected successfully." << std::endl;

    User user(1, "Alex", "alex@example.com");
    std::cout << "Created user: " << user.getName()
        << " (" << user.getEmail() << ")" << std::endl;

    std::cout << "Backend is running." << std::endl;

    return 0;
}