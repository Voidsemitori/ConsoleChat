#pragma once

#include <iostream>
#include "User.h"

class Chat {
private:
	std::vector <User> _users; //���������, �������� ������������������ �������������
	std::vector <std::string> _chat; //���������, �������� ��������� ������ ����
	User* currentUser = nullptr;  // ��������� �� �������� ������������
	User* findByLogin(std::string& login); //������� ������ ������������ �� ������

public:
	void registerUser();
	void login();
	void sendPrivateMessage();
	void sendMessageToChat();
	void viewPrivateMessages();
	void viewChat();
	void logout();
};