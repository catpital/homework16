#include "Chat.h"
void Chat::logIn()
{
	std::string login;
	std::string pass;
	
	std::cout << "Введите login:" << std::endl;
	std::cout << "> "; //Comand PROMPT
	std::cin >> login; //Wait user input
	std::cout << "Введите пароль:" << std::endl;
	std::cout << "> "; //Comand PROMPT
	std::cin >> pass; //Wait user input
	bool n = false;// счетчик совпадений
	int k;// счетчик местоположения
	//for (int i = 0; i < _users.size(); i++)
	//{
		//if (login == _users[i].getUserLogin())
		//{
			//n++; // отмечаем, что такой логин есть
			//k = i;
		//}
	//}
	if (_users.find(login) != _users.end())
	{
		n++;
		k = 1;
	}
			try
	{
		if (n == 0) { throw bad_sing(); }
		else if (_users.find(login)->second.getUserPassword() == pass) 
		{
			std::string name = _users.find(login)->second.getUserName();
			auto _currentUser = std::make_shared<UserLog>(login);
			auto _currentUser2 = std::make_shared<User>(name, pass);
		}
		else if (_users.find(login)->second.getUserPassword() != pass)
		{
			throw bad_sing();
		}

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	n = 0;
	k = 0;
}

