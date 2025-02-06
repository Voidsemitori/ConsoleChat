#pragma once

#include <string>
#include <vector>

class User {
private:
	std::string _name;
	std::string _login;
	std::string _password;
	std::vector <std::pair<std::string, std::string>> _privateMessages;
public:
	User() = default; 
	User(std::string& name, std::string& login, std::string& password); //Конструктор класса
};