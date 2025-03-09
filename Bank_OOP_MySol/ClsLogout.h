#pragma once
#include <iostream>
#include"ClsHeaderScreen.h"

class ClsLogout : protected ClsHeaderScreen
{
	static void ShowLogOutScreen()
	{
		_ShowHeaderScreen("Logout screen");


	}
};

