#include "Chat.h"
#include "User.h"


int main()
{
	Chat chat; //Create chat object

	chat.start(); //Set chat`s status is "ON"

	while (chat.isChatWork()) //Verify that chat is "ON"
	{
		chat.showLogInMenu(); //Show Log In menu

		while (chat.getUserLogin())
		{
			//UserLog currentUser;
			//currentUser = chat.getCurrentUser();
			std::cout <<GREEN<< "Добро пожаловать , " <<RESET<< chat.getUserLogin() << " !" << std::endl;
			std::cout << std::endl;
			chat.showUserMenu();
		}
	}
	return 0;
}