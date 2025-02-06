#pragma once

#include <iostream>
#include <string>
#include <vector>

class User {
private:
	std::string _name;
	std::string _login;
	std::string _password;
	std::vector <std::pair<std::string, std::string>> _privateMessages; //Структура pair для объединения контейнеров, содержащих сообщение и логин отправителя сообщения
public:
	User() = default; 
	User(std::string& name, std::string& login, std::string& password); //Конструктор класса
	void addPrivateMessage(std::string &sender, std::string message);
	void viewPrivateMessage() const;
	std::string getLogin() const;
	std::string getPassword() const;
};