#include "User.h"

User::User(std::string& name, std::string& login, std::string& password) :
	_name(name), _login(login), _password(password) {

}

void User::addPrivateMessage(std::string sender, std::string message) {
	_privateMessages.emplace_back(sender, message);
}

void User::viewPrivateMessage() const {
	if (_privateMessages.empty()) {
		std::cout << "Нет личных сообщений." << std::endl;
	}
	else {
		std::cout << "------Личные сообщения------" << std::endl;
		for (auto& message : _privateMessages) {  //Цикл для вывода личных сообщений
			std::cout << "От " << message.first << ": " << message.second << std::endl;
		}
	}
}

std::string User::getName() const {
	return _name;
}

std::string User::getLogin() const {
	return _login;
}

std::string User::getPassword() const {
	return _password;
}

void User::setName(std::string name) {
	_name = name;
}

void User::setLogin(std::string login) {
	_login = login;
}

void User::setPassword(std::string password) {
	_password = password;
}