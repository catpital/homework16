#include "Chat.h"
#include "User.h"

int main()
{
	Chat chat; //Create chat object
	
	chat.start(); //Set chat`s status is "ON"
	std::shared_ptr<UserLog> _currentUser = nullptr;
	while (chat.isChatWork()) //Verify that chat is "ON"
	{
		chat.showLogInMenu(); //Show Log In menu

		while (chat.getUserLogin())
		{
			//UserLog currentUser;
			
			_currentUser=chat.getUserLogin();
			std::cout <<GREEN<< "Добро пожаловать , " <<RESET<< chat.getUserLogin() << " !" << std::endl;
			std::cout << std::endl;
			chat.showUserMenu(_currentUser);
		}
	}
	return 0;
}