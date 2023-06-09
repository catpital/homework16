#include "Chat.h"
#include <map>
#include "user.h"
//#include <string>
//#include <memory>
#include <algorithm>
void Chat::signUp()
{
	try
	{
		std::string login;
		std::cout << "Введите login:" << std::endl;
		std::cout << "> "; //Comand PROMPT
		std::cin >> login; //Wait user input
		if (_users.find(login) != _users.end())
			{
				throw "Такой login уже зарегистрирован!";
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
		auto _currentUser2 = std::make_shared<User>(name, pass);
		auto _currentUser = std::make_shared<User>(login);
		
		_users.insert(std::make_pair(login, *_currentUser2));
		std::cout << GREEN <<"Пользователь успешно зарегистрирован!" <<RESET<< std::endl;
		std::cout << std::endl;
		for (auto& n : _users) {
			std::cout << n.first << " " << n.second.getUserName() << " " << n.second.getUserPassword() << std::endl;
		}
		std::cout << _currentUser->getUserLogin() << " " << _currentUser2->getUserName() << " " << _currentUser2->getUserPassword() << std::endl;
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
				else return;
		}
	}
	std::cout << "Введите сообщение для адреста " << _toUser << " :" << std::endl;
	std::string _textMessage;
	std::cout << "> "; //Comand PROMPT
	std::cin.ignore();
	std::getline(std::cin, _textMessage); //Wait user input _text)
	//std::cin, _textMessage;
	std::cout  << std::endl;
	std::cout <<_textMessage<< std::endl;
	std::cout << _currentUser->getUserLogin() << std::endl;
	//std::cout << _currentUser2->getUserName() << std::endl;

	_messages.push_back(*std::make_shared<Message>(_currentUser->getUserLogin(), _toUser, _textMessage));
	std::cout << GREEN << "Сообщение успешно отправлено!" << RESET << std::endl;
	std::cout << std::endl;
}
void Chat::showUsernames() const
{
	
	for (const auto& n: _users)
	{
	
		std::cout << n.first << std::endl;
	}
	
}
void Chat::readMyMessages() const
{
	int count = 0; // счетчик сообщений если они есть
	for (int i = 0; i < _messages.size(); i++)
	{
		//if (_messages[i].getToUser() == this->_currentUser->getUserName())
		if (_messages[i].getToUser() == this->_currentUser->getUserLogin())
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
std::shared_ptr<User> Chat::getCurrentUserLogin() const
{
	return _currentUser;
}
std::shared_ptr<User> Chat::getCurrentUserName() const
{
	return _currentUser2;
}
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