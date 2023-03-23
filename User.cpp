#include "User.h"
User::User(const std::string& login) : _login(login) {}
std::string User::getUserLogin() const
{
	return _login;
}
void User::setUserLogin(std::string& login) {
	_login =login;
	std::cout << "Логин успешно изменено на " << _login << " !" << std::endl;
	std::cout << std::endl;
};

User::User(const std::string& login, std::string& username, std::string& password)
	: _login(login), _username(username), _password(password)
{
}
User::User(std::string& username, std::string& password)
	: _username(username), _password(password)
{
}
void User::setUserName(std::string username)
{
	_username = username;
	std::cout << "Имя пользователя успешно изменено на " << _username << " !" << std::endl;
	std::cout << std::endl;
}

std::string User::getUserName() const
{
	return _username;
}

void User::setUserPassword(std::string password)
{
	_password = password;
	std::cout << "Ваш пароль успешно изменен на " << _password << " !" << std::endl;
	std::cout << std::endl;
}

std::string User::getUserPassword() const
{
	return _password;
}