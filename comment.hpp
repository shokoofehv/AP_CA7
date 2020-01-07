#ifndef __COMMENT_H__
#define __COMMENT_H__

#include <string>
#include <vector>
#include "user.hpp"

using namespace std;

class Notification;
class User;


class Comment {

public:
	Comment(int id, string text, User* publisher_);
	void addReply(Comment* newReply);
	int showId();
	void showComment();
	bool matchId(int id);
	void notifyPublisher(Notification newNotif);
private:
	int commentId;
	string text;
	vector <Comment*> replies;
	User* publisher;
};

#endif
