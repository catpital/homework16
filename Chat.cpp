#include "Chat.h"
#include <map>
#include "user.h"
#include <string>
#include <memory>
#include <algorithm>
void Chat::signUp()
{
	try
	{
		std::string login;
		std::cout << "Введите login:" << std::endl;
		std::cout << "> "; //Comand PROMPT
		std::cin >> login; //Wait user input

		//for (int i = 0; i < _users.size(); i++)
		//{
			//if (login == _users[i].getUserLogin())
			if (_users.find(login) != _users.end())
			{
				throw "Такой login уже зарегистрирован!";
			//std::cout<< "Такой login уже зарегистрирован!";
			}
	//	}
		std::string name;
		std::cout << "Введите отображаемое имя пользователя:" << std::endl;
		std::cout << "> "; //Comand PROMPT
		std::cin >> name; //Wait user input
		std::string pass;
		std::cout << "Введите пароль:" << std::endl;
		std::cout << "> "; //Comand PROMPT
		std::cin >> pass; //Wait user input

		_currentUser2 = std::make_shared<User>(name, pass);
		_currentUser = std::make_shared<UserLog>(login);
		User user(name, pass);
		UserLog userlog(login);
		_users.insert(std::make_pair(userlog, user));
		std::cout << GREEN <<"Пользователь успешно зарегистрирован!" <<RESET<< std::endl;
		std::cout << std::endl;
	}
	catch (const char* exception)
	{
		std::cout << std::endl;
		std::cout << exception << std::endl;
		std::cout << std::endl;
	}
}
void Chat::start()
{
	_workStatus = true;
}
bool Chat::isChatWork() const
{
	return _workStatus;
}
void Chat::sendMessages()
{
	std::string _toUser="";
	while (_toUser == "")
	{
		std::cout << "Выберите адресата из списка: или all- для всех" << std::endl;
		showUsernames();
		std::string choice = "0";
		std::cout << "> "; //Comand PROMPT
		std::cin >> choice; //Wait user input
		std::cout << std::endl;
			if (choice == "all" || choice=="ALL")
		{
			_toUser = "all";
		}
		else
		{
			if (_users.find(choice) != _users.end())
			{
				_toUser = choice;
			}

		}
	}
	std::cout << "Введите сообщение для адреста " << _toUser << " :" << std::endl;
	std::string _textMessage;
	std::cout << "> "; //Comand PROMPT
	std::cin.ignore();
	std::getline(std::cin, _textMessage); //Wait user input _text)
	std::cout << std::endl;		
	_messages.push_back(*std::make_shared<Message>(_currentUser, _toUser, _textMessage));

	std::cout << GREEN << "Сообщение успешно отправлено!" << RESET << std::endl;
	std::cout << std::endl;
}
void Chat::showUsernames() const
{
	
	//map::const_iterator cit = _users.begin();
	for (auto& n: _users)
	{
		std::cout << n.first.getUserLogin()<<std::endl;
	}
	
	//for (int i = 0; i < _users.size(); i++)
	//{
		//std::cout << i + 1 << ". " << _users[i].getUserName() << std::endl;
	//}
	//std::cout << "0. Общий чат" << std::endl;
}
void Chat::readMyMessages() const
{
	int count = 0; // счетчик сообщений если они есть
	for (int i = 0; i < _messages.size(); i++)
	{
		//if (_messages[i].getToUser() == this->_currentUser->getUserName())
		if (_messages[i].getToUser() == _currentUser->getUserLogin())
		{
			std::cout << _messages[i].getFromUser() << " : " << _messages[i].getTextMessage() << std::endl;
			count++;
		}
	}
	if (count == 0) std::cout <<RED<< "Сообщений нет" <<RESET<< std::endl;
}
void Chat::readAllMessages() const
{
	int count = 0; // счетчик сообщений если они есть
	for (int i = 0; i < _messages.size(); i++)
	{
		if (_messages[i].getToUser() == "all")
		{
			std::cout << _messages[i].getFromUser() << " : " << _messages[i].getTextMessage() << std::endl;
			count++;
		}
	}
	if (count == 0) std::cout << RED << "Сообщений нет" << RESET << std::endl;
}
void Chat::showLogInMenu()
{
	std::cout <<YELLOW<< "*** Введите желаемую команду: ***" << std::endl;
	std::cout << "* Вход ...................... 1 *" << std::endl;
	std::cout << "* Регистрация ............... 2 *" << std::endl;
	std::cout << "* Выход из программы ........ 0 *" <<RESET<< std::endl;
	
	int userInputLogIn;
	std::cout << "> "; //Comand PROMPT
	std::cin >> userInputLogIn; //Wait user input
	std::cout << std::endl;
	switch (userInputLogIn)
	{
	case 1: 
	{	logIn();
		break; }
	case 2:
	{
		signUp();
		break;
	}
	case 0:
	{
		_currentUser = nullptr;
		_currentUser2 = nullptr;
		_workStatus = false; //Change work status to "OFF"
		return;
		break; }
	default:
	{
		std::cout << RED << "Вы ввели неверную команду!" << RESET << std::endl; //Error message if user input not define
		std::cout << std::endl;
		_workStatus = false; //Change work status to "OFF"
		break;
	}
	}
}
std::shared_ptr<UserLog> Chat::getCurrentUser()
{
	return _currentUser;
}
//std::shared_ptr<User> Chat::getCurrentUser() const
//{
	//return _currentUser2;
//}
void Chat::showUserMenu()
{
	std::cout << "*** Введите желаемую команду: ***" << std::endl;
	std::cout << "* Изменить имя .............. 1 *" << std::endl;
	std::cout << "* Изменить пароль ........... 2 *" << std::endl;
	std::cout << "* Отправить сообщение ........3 *" << std::endl;
	std::cout << "* Прочитать сообщения ........4 *" << std::endl;
	std::cout << "* Сменить пользователя .......0 *" << RESET << std::endl;

	int userInputUserMenu;
	std::cout << "> "; //Comand PROMPT
	std::cin >> userInputUserMenu; //Wait user input
	std::cout << std::endl;
	switch (userInputUserMenu)
	{
	case 1:
	{
		std::cout << "Введите новое отображаемое имя пользователя:" << std::endl;
		std::string name;
		std::cout << "> "; //Comand PROMPT
		std::cin >> name; //Wait user input
		_currentUser2->setUserName(name);
		break;
	}
	case 2:
	{
		std::cout << "Введите новый пароль:" << std::endl;
		std::string password;
		std::cout << "> "; //Comand PROMPT
		std::cin >> password; //Wait user input
		_currentUser2->setUserPassword(password);
		break;
	}
	case 3:
	{
		sendMessages();
		break;
	}
	case 4:
	{
		std::cout << "*** Какие сообщения прочитать: ***" << std::endl;
		std::cout << "* Личные сообщения ........... 1 *" << std::endl;
		std::cout << "* Общий чат .................. 2 *" << std::endl;

		int userInput;
		std::cout << "> "; //Comand PROMPT
		std::cin >> userInput; //Wait user input
		std::cout << std::endl;
		switch (userInput)
		{
		case 1:
		{
			readMyMessages();
			std::cout << std::endl;
			break;
		}
		case 2:
		{
			readAllMessages();
			std::cout << std::endl;
			break;
		}
		default:
			break;
		}
	}
	case 0:
	{
		_currentUser = nullptr;
		_currentUser2 = nullptr;
		break;
	}
	default:
	{
		std::cout << RED << "Вы ввели неверную команду!" << RESET << std::endl; //Error message if user input not define
		std::cout << std::endl;
		_workStatus = false; //Change work status to "OFF"
		break;
	}
	}
}