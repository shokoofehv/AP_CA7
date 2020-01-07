#include "jeek.hpp"



Jeek::Jeek(int jeekId_, string texts_, vector <string> tags_, vector <string> mentions_, User* publisher_) {
	jeekId = jeekId_;
	text = texts_;
	tags = tags_;
	mentions = mentions_;
	publisher = publisher_;
	likes = 0;
	rejeeks = 0;
}


bool Jeek::validJeek() {
	return true;

}

bool Jeek::matchId(int jeekId_) {
	if (jeekId == jeekId_)
		return true;
	return false;
}

void Jeek::print_tag(vector <string> str) {
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}
}

void Jeek::showJeek1() {
	cout << jeekId <<endl;
	publisher->showName();
	cout << text;
	cout << endl;
	print_tag(tags);
	cout << endl;
	print_tag(mentions);
	cout << endl;
	cout << "Likes " << likes << endl;
	cout << "Rejeeks " << rejeeks << endl;
	cout << "Comments: " << endl;
	cout << comments.size() << endl;
	for (int i = 0; i < comments.size(); i++) {
		cout << comments[i]->showId() <<endl;
	}
}

int Jeek::showId() {
	return jeekId;
}

bool Jeek::matchTag(string tag) {
	for (int i = 0; i < tags.size(); i++)
	{
		if (tags[i] == tag)
			return true;
	}
	return false;
}

void Jeek::addComment(Comment* newComment) {
	comments.push_back(newComment);
}

void Jeek::addRejeek() {
	rejeeks++;
}

void Jeek::changeId(int jeekId_) {
	jeekId = jeekId_;
}

void Jeek::changePublisher(User* newPublisher) {
	publisher = newPublisher;
}


void Jeek::addLike() {
	likes++;
}

void Jeek::addDislike() {
	likes--;
}

void Jeek::notifyPublisher(Notification newNotif) {
	publisher->addNotif(newNotif);
}
