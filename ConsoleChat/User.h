#pragma once

#include <iostream>
#include <string>
#include <vector>

class User {
private:
	std::string _name; // ���������� ������ ��� �������������
	std::string _login; //���������� ������ ����� ������������
	std::string _password; //���������� ������ ������ �������������
	std::vector <std::pair<std::string, std::string>> _privateMessages; //��������� pair ��� ����������� �����������, ���������� ��������� � ����� ����������� ���������
public:
	User() = default;
	User(std::string& name, std::string& login, std::string& password); //����������� ������
	void addPrivateMessage(std::string sender, std::string message); //������� ��� ���������� ���������� ������������ ��������� � ������ ��� �����������
	void viewPrivateMessage() const; //������� ��� ��������� ������ ���������

	//�������:
	std::string getName() const;
	std::string getLogin() const;
	std::string getPassword() const;
	//______________________________

	//�������:
	void setName(std::string name);
	void setLogin(std::string login);
	void setPassword(std::string password);
	//_______________________________
	~User() = default;
};