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
	std::cin.ignore();
	std::cout << "\nВведите сообщение: ";
	std::getline(std::cin, message);

	recipient->addPrivateMessage(currentUser->getLogin(), message);
	std::cout << "Сообщение отправлено пользователю " << recipientLogin << std::endl;
}

void Chat::sendMessageToChat() {
	if (!currentUser) {
		std::cout << "Сначала войдите в систему!";
		return;
	}

	std::string message;
	std::cin.ignore();
	std::cout << "Напишите сообщение в чат: ";
	std::getline(std::cin, message);
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

void Chat::run() {
	int choice;
	do {
		std::cout << "\n-------Меню-------" << std::endl;;
		std::cout << "1. Регистрация" << std::endl;
		std::cout << "2. Вход в систему" << std::endl;
		std::cout << "3. Отправить сообщение пользователю" << std::endl;
		std::cout << "4. Отправить сообщение в чат" << std::endl;
		std::cout << "5. Посмотреть чат" << std::endl;
		std::cout << "6. Посмотреть личные сообщения" << std::endl;
		std::cout << "7. Выйти из системы" << std::endl;
		std::cout << "0. Выход" << std::endl;
		std::cout << "Введите число необходимой операции: ";
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
			std::cout << "Выход из программы.\n";
			break;
		default:
			std::cout << "Некорректный выбор. Попробуйте снова.\n";
		}
	} while (choice != 0);
}