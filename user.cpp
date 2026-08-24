#include "user.h"
#include <utility>

User::User(int id, std::string name, std::string email)
    : id(id), name(std::move(name)), email(std::move(email)) {
}

int User::getId() const {
    return id;
}

const std::string& User::getName() const {
    return name;
}

const std::string& User::getEmail() const {
    return email;
}

void User::setName(const std::string& newName) {
    name = newName;
}

void User::setEmail(const std::string& newEmail) {
    email = newEmail;
}