#pragma once

#include "User.h"

class Chat {
private:
	std::vector <User> _users; //Контейнер, хранящий зарегистрированных пользователей
	std::vector <std::string> _chat; //Контейнер, хранящий сообщения общего чата
	User* currentUser = nullptr;  // Указатель на текущего пользователя
	User* findByLogin(std::string& login); //Функция поиска пользователя по логину

public:
	void registerUser();
	void login();
	void sendPrivateMessage();
	void sendMessageToChat();
	void viewPrivateMessages();
	void viewChat();
	void logout();
};