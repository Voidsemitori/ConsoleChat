#pragma once

#include <string>


class User {
private:
	std::string _name;
	std::string _login;
	std::string _password;
public:
	User() = default; 
	User(std::string& name, std::string& login, std::string& password); //Конструктор класса
};