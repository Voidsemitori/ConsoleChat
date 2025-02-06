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

void Chat::sendPrivateMessage() {
	if (!currentUser) {
		std::cout << "������� ������� � �������!";
		return;
	}

	std::string recipientLogin, message;
	std::cout << "������� ����� ����������: ";
	std::cin >> recipientLogin;
	User* recipient = findByLogin(recipientLogin);
	if (!recipient) {
		std::cout << "������������ �� ������!" << std::endl; //
		return;
	}
	std::cin.ignore();
	std::cout << "\n������� ���������: ";
	std::getline(std::cin, message);

	recipient->addPrivateMessage(currentUser->getLogin(), message);
	std::cout << "��������� ���������� ������������ " << recipientLogin << std::endl;
}

void Chat::sendMessageToChat() {
	if (!currentUser) {
		std::cout << "������� ������� � �������!";
		return;
	}

	std::string message;
	std::cin.ignore();
	std::cout << "�������� ��������� � ���: ";
	std::getline(std::cin, message);
	_chat.push_back(currentUser->getLogin() + ": " + message);
	std::cout << "��������� ����������!" << std::endl;
}

void Chat::viewPrivateMessages() {
	if (!currentUser) {
		std::cout << "������� ������� � �������!";
		return;
	}

	currentUser->viewPrivateMessage();
}

void Chat::viewChat() {
	if (!currentUser) {
		std::cout << "������� ������� � �������!";
		return;
	}
	else if (_chat.empty()) {
		std::cout << "� ���� ���� ��� ���������." << std::endl;
	}
	else {
		std::cout << "--------���--------" << std::endl;
		for (auto& message : _chat) {
			std::cout << message << std::endl;
		}
	}
}

void Chat::logout() {
	if (currentUser) {
		std::cout << "�� ����� �� �������, " << currentUser->getLogin() << std::endl;
		currentUser = nullptr;
	}
	else {
		std::cout << "�� �� ������������." << std::endl;
	}
}

void Chat::run() {
	int choice;
	do {
		std::cout << "\n-------����-------" << std::endl;;
		std::cout << "1. �����������" << std::endl;
		std::cout << "2. ���� � �������" << std::endl;
		std::cout << "3. ��������� ��������� ������������" << std::endl;
		std::cout << "4. ��������� ��������� � ���" << std::endl;
		std::cout << "5. ���������� ���" << std::endl;
		std::cout << "6. ���������� ������ ���������" << std::endl;
		std::cout << "7. ����� �� �������" << std::endl;
		std::cout << "0. �����" << std::endl;
		std::cout << "������� ����� ����������� ��������: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			registerUser();
			break;
		case 2:
			login();
			break;
		case 3:
			sendPrivateMessage();
			break;
		case 4:
			sendMessageToChat();
			break;
		case 5:
			viewChat();
			break;
		case 6:
			viewPrivateMessages();
			break;
		case 7:
			logout();
			break;
		case 0:
			std::cout << "����� �� ���������.\n";
			break;
		default:
			std::cout << "������������ �����. ���������� �����.\n";
		}
	} while (choice != 0);
}