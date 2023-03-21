#include "User.h"
UserLog::UserLog(const std::string& login) : _login(login) {}
std::string UserLog::getUserLogin() const
{
	return _login;
}
void UserLog::setUserLogin(std::string& login) {
	_login =login;
	std::cout << "Логин успешно изменено на " << _login << " !" << std::endl;
	std::cout << std::endl;
};

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