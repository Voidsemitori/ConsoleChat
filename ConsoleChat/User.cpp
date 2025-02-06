#include "User.h"

User::User(std::string& name, std::string& login, std::string& password) :
	_name(name), _login(login), _password(password) {

}

void User::addPrivateMessage(std::string& sender, std::string message) { //������� ��� ���������� ���������� ������������ ��������� � ������ ��� �����������
	_privateMessages.emplace_back(sender, message);
}

void User::viewPrivateMessage() const{
	if (_privateMessages.empty()) {
		std::cout << "��� ������ ���������." << std::endl;
	}
	else {
		std::cout << "------������ ���������------" << std::endl;
		for (auto& message : _privateMessages) {  //���� ��� ������ ������ ���������
			std::cout << "�� " << message.first << ": " << message.second << std::endl;
		}
	}
}