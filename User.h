#pragma once
#include <string>
#include <iostream>
class UserLog
{ private:
	const std::string _login;
public:
	UserLog(const std::string& login);
	std::string getUserLogin() const;
	void setUserLogin(std::string& UserLogin);
};

class User
{
private:
	
	std::string _username;
	std::string _password;

public:
	User(std::string& username, std::string& password);
	void setUserName(std::string& username);
	std::string getUserName() const;
	void setUserPassword(std::string& password);
	std::string getUserPassword() const;
};