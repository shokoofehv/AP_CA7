#ifndef __NOTIFICATION_H__
#define __NOTIFICATION_H__

#include <string>
#include <vector>
#include <iostream>
#include "user.hpp"

using namespace std;

class User;

class Notification {

public:
	Notification(User* user_, string command_, int id_);
	void show();
private:
	User* user;
	string command;
	int id;
};


#endif
