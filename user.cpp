#include "user.hpp"

User::User(string username_, string displayName_, string password_){
  username = username_;
  displayName = displayName_;
  password = password_;
  jeeks.clear();
  comments.clear();
  replies.clear();
  followers.clear();
  followings.clear();
}

bool User::matchUser(string username_){
  if (username == username_)
    return true;
  return false;
}

bool User::matchPass(string password_) {
  if (password == password_)
    return true;
  return false;
}

void User::addJeek(Jeek* newJeek) {
	jeeks.push_back(newJeek);
}



void User::showName() {
	cout << displayName << endl;
}

string User::showUsername() {
	return username;
}

void User::showJeekPro(Jeek* jeek) {
	cout << jeek->showId() << endl;
	cout << displayName << endl;
	//jeek->showJeek();
}

void User::showProfile() {
	for (int i = 0; i < jeeks.size(); i++)
	{
    //cout << jeeks[i]->showId();
		jeeks[i]->showJeek1();
	}
}

void User::showTagPro(string tag) {
  cout << jeeks.size() << endl;
  for (int i = 0; i < jeeks.size(); i++) {
    if (jeeks[i]->matchTag(tag)) {
    	showJeekPro(jeeks[i]);
  	}
   }

}

void User::addComment(Comment* newComment) {
	comments.push_back(newComment);
}

void User::addReply(Comment* newReply) {
	replies.push_back(newReply);
}

void User::showComment(int commentId) {
	for (int i = 0; i < comments.size(); i++) {
		if (comments[i]->matchId(commentId)) {
			cout << displayName << endl;
			comments[i]->showComment();
		}
	}
}

void User::showReply(int commentId) {
	for (int i = 0; i < replies.size(); i++) {
		if (replies[i]->matchId(commentId)) {
			cout << displayName << endl;
			replies[i]->showComment();
		}
	}
}

void User::addLike(int jeekId) {
	likes.push_back(jeekId);
}

bool User::canDislike(int jeekId) {
	for (int i = 0; i < likes.size(); i++) {
		if (likes[i] == jeekId)
			return true;
	}
	return false;
}

void User::addDislike(int jeekId) {
	for (int i = 0; i < likes.size(); i++) {
		if (likes[i] == jeekId)
			likes.erase(likes.begin() + i);
	}
}

void User::follow(User* following) {
 	followings.push_back(following);
}

void User::unfollow(string username) {
	for (int i = 0; i < followings.size(); i++) {
		if(followings[i]->matchUser(username))
			followings.erase(followings.begin() + i);
	}
}
void User::addFollower(User* follower) {
 	followers.push_back(follower);
}

void User::removeFollower(User* follower) {
	for (int i = 0; i < followings.size(); i++) {
		if(followers[i] == follower)
			followers.erase(followers.begin() + i);
	}
}

void User::addNotif(Notification notif) {
	notifications.push_back(notif);
}

void User::broadcastFollowers(Notification notif) {
	for (int i = 0; i < followers.size(); i++) {
		followers[i]->addNotif(notif);
	}
}

void User::showNotifs() {
	for (int i = 0; i < notifications.size(); i++)
	{
		notifications[i].show();
	}
  notifications.clear();
}
