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

	std::cout << "Введите ваше имя: ";
	std::cin >> name;
	std::cout << "Введите логин: ";
	std::cin >> login;

	if (findByLogin(login)) {
		std::cout << "Пользователь с таким логином уже существует!" << std::endl;
		return;
	}

	std::cout << "Введите пароль: ";
	std::cin >> password;

	_users.emplace_back(name, login, password);
	std::cout << "Ркгистрация успешно завершена!" << std::endl;
}

void Chat::login() {
	std::string login, password;

	std::cout << "Введите логин: ";
	std::cin >> login;
	std::cout << "Введите пароль: ";
	std::cin >> password;

	User* user = findByLogin(login);
	if (user && (user->getPassword() == password)) {
		currentUser = user;
		std::cout << "Добро пожаловать, " << currentUser->getLogin() << std::endl;
	}
	else {
		std::cout << "Вы ввели неверный логин или пароль!" << std::endl;
	}
}

void Chat::sendPrivateMessage() {
	if (!currentUser) {
		std::cout << "Сначала войдите в систему!";
		return;
	}

	std::string recipientLogin, message;
	std::cout << "Введите логин получателя: ";
	std::cin >> recipientLogin;
	User* recipient = findByLogin(recipientLogin);
	if (!recipient) {
		std::cout << "Пользователь не найден!" << std::endl; //
		return;
	}
	std::cout << "\nВведите сообщение: ";
	std::cin >> message;

	recipient->addPrivateMessage(currentUser->getLogin(), message);
	std::cout << "Сообщение отправлено пользователю " << recipientLogin << std::endl;
}

void Chat::sendMessageToChat() {
	if (!currentUser) {
		std::cout << "Сначала войдите в систему!";
		return;
	}

	std::string message;
	std::cout << "Напишите сообщение в чат: ";
	std::cin >> message;
	_chat.push_back(currentUser->getLogin() + ": " + message);
	std::cout << "Сообщение отправлено!" << std::endl;
}

void Chat::viewPrivateMessages() {
	if (!currentUser) {
		std::cout << "Сначала войдите в систему!";
		return;
	}

	currentUser->viewPrivateMessage();
}

void Chat::viewChat() {
	if (!currentUser) {
		std::cout << "Сначала войдите в систему!";
		return;
	}
	else if (_chat.empty()) {
		std::cout << "В чате пока нет сообщений." << std::endl;
	}
	else {
		std::cout << "--------Чат--------" << std::endl;
		for (auto& message : _chat) {
			std::cout << message << std::endl;
		}
	}
}

void Chat::logout() {
	if (currentUser) {
		std::cout << "Вы вышли из системы, " << currentUser->getLogin() << std::endl;
		currentUser = nullptr;
	}
	else {
		std::cout << "Вы не авторизованы." << std::endl;
	}
}