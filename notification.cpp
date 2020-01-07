#include "notification.hpp"


Notification::Notification(User* user_, string command_, int id_) {
	user = user_;
	command = command_;
	id = id_;
}


void Notification::show() {
	cout << user->showUsername() << " "
		 << command
		 << id << endl;
}
