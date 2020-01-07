#include "comment.hpp"

Comment::Comment(int commentId_, string texts_, User* publisher_) {
	commentId = commentId_;
	text = texts_;
	publisher = publisher_;
}

void Comment::addReply(Comment* newReply) {
	replies.push_back(newReply);
}

int Comment::showId() {
	return commentId;
}

void Comment::showComment() {

		cout << text << endl;

	cout << "Replies: " << endl;
	for (int i = 0; i < replies.size(); i++)
	{
		cout << replies[i]->showId() << endl;
	}
}

bool Comment::matchId(int id) {
	if (commentId == id)
		return true;
	return false;
}

void Comment::notifyPublisher(Notification newNotif) {
	publisher->addNotif(newNotif);
}
