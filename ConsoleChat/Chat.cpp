#include "Chat.h"

User* Chat::findByLogin(std::string& login) {
	for (auto& user : _users) {
		if (user.getLogin() == login) {
			return &user;
		}
	}
	return nullptr;
}

void Chat::registerUser() {
	std::string name, login, password;

	std::cout << "������� ���� ���: ";
	std::cin >> name;
	std::cout << "������� �����: ";
	std::cin >> login;

	if (findByLogin(login)) {
		std::cout << "������������ � ����� ������� ��� ����������!" << std::endl;
		return;
	}

	std::cout << "������� ������: ";
	std::cin >> password;

	_users.emplace_back(name, login, password);
	std::cout << "����������� ������� ���������!" << std::endl;
}

void Chat::login() {
	std::string login, password;

	std::cout << "������� �����: ";
	std::cin >> login;
	std::cout << "������� ������: ";
	std::cin >> password;

	User* user = findByLogin(login);
	if (user && (user->getPassword() == password)) {
		currentUser = user;
		std::cout << "����� ����������, " << currentUser->getLogin() << std::endl;
	}
	else {
		std::cout << "�� ����� �������� ����� ��� ������!" << std::endl;
	}
}