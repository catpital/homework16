#pragma once
#pragma warning(disable:4786)
#include "color_txt.h"
#include "User.h"
#include "Message.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
//#include <cliext/map>
//#include <map>
#include <string>
#include <map>
//using namespace std;

class Chat
{
private:
	bool _workStatus = false; // Chat work status: "ON" - true, "OFF" - false (default is "OFF")
	//std::vector<User> _users;
	std::map <UserLog, User> _users;
	//cliext::map < std::string, std::string, less <std::string>>::const_iterator iter;
	std::shared_ptr<UserLog> _currentUser = nullptr;
	void logIn();
	void signUp();
	std::vector<Message> _messages;
	void sendMessages();
	void showUsernames() const;
	void readMyMessages() const;
	void readAllMessages() const;

public:
	void start(); //Change work status to "ON"
	bool isChatWork() const; //Return current work status
	void showLogInMenu(); //Show Log In menu
	std::shared_ptr<UserLog> getCurrentUser() const;
	void showUserMenu(); //Show User menu
	
};

class bad_sing : public std::exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "неверный логин или пароль";
		std::cout << std::endl;
	}
};