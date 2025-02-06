#pragma once

#include <iostream>
#include <string>
#include <vector>

class User {
private:
	std::string _name; // переменная хранит имя пользователся
	std::string _login; //переменная хранит логин пользователя
	std::string _password; //переменная хранит пароль пользоваетеля
	std::vector <std::pair<std::string, std::string>> _privateMessages; //Структура pair для объединения контейнеров, содержащих сообщение и логин отправителя сообщения
public:
	User() = default;
	User(std::string& name, std::string& login, std::string& password); //Конструктор класса
	void addPrivateMessage(std::string sender, std::string message); //Функция для сохранения пришедшего пользователю сообщения и логина его отправителя
	void viewPrivateMessage() const; //Функция для просмотра личных сообщений

	//Геттеры:
	std::string getName() const;
	std::string getLogin() const;
	std::string getPassword() const;
	//______________________________

	//Сеттеры:
	void setName(std::string name);
	void setLogin(std::string login);
	void setPassword(std::string password);
	//_______________________________
	~User() = default;
};