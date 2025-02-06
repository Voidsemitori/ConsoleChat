#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "User.h"

class Chat {
private:
	std::vector <User> _users; //���������, �������� ������������������ �������������
	std::vector <std::string> _chat; //���������, �������� ��������� ������ ����
	User* currentUser = nullptr;  // ��������� �� �������� ������������
	User* findByLogin(std::string& login); //������� ������ ������������ �� ������

public:
	Chat() = default;
	void registerUser(); //�������� ��� ����������� ������ ������������
	void login(); //������� ��� ����� � ������� ������������
	void sendPrivateMessage(); //������� ��� �������� ��������� ������������
	void sendMessageToChat(); //������� ��� �������� ��������� � ���
	void viewPrivateMessages(); //������� ��� ��������� ������ ���������
	void viewChat(); // ������� ��� ��������� ����
	void logout(); //������� ��� ������ �� ��������
	void run();
};