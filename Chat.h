#pragma once
#pragma warning(disable:4786)
#include "color_txt.h"
#include "User.h"
#include "Message.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <string>
#include <map>

class Chat
{
private:
	bool _workStatus = false; // Chat work status: "ON" - true, "OFF" - false (default is "OFF")
	//std::vector<User> _users;
	std::map <std::string, User> _users;
	
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
    std::shared_ptr<UserLog> getUserLogin() const;
	std::shared_ptr<User> getCurrentUserName() const;
	void showUserMenu(); //Show User menu
	std::shared_ptr<UserLog> _currentUser = nullptr;
	std::shared_ptr<User> _currentUser2 = nullptr;
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