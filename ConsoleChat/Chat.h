#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "User.h"

class Chat {
private:
	std::vector <User> _users; //Контейнер, хранящий зарегистрированных пользователей
	std::vector <std::string> _chat; //Контейнер, хранящий сообщения общего чата
	User* currentUser = nullptr;  // Указатель на текущего пользователя
	User* findByLogin(std::string& login); //Функция поиска пользователя по логину

public:
	Chat() = default;
	void registerUser(); //Фунцкция для регистрация нового пользователя
	void login(); //Функция для входа в аккаунт пользователя
	void sendPrivateMessage(); //Функция для отправки сообщения пользователю
	void sendMessageToChat(); //Функция для отправки сообщений в чат
	void viewPrivateMessages(); //Функция для просмотра личных сообщений
	void viewChat(); // Функция для просмотра чата
	void logout(); //функция для выхода из аккаунта
};