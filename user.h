#pragma once

#include <string>

class User {
private:
    int id;
    std::string name;
    std::string email;

public:
    User(int id, std::string name, std::string email);

    int getId() const;
    const std::string& getName() const;
    const std::string& getEmail() const;

    void setName(const std::string& newName);
    void setEmail(const std::string& newEmail);
};