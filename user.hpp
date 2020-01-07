#ifndef __USER_H__
#define __USER_H__

#include <string>
#include <vector>
#include "jeek.hpp"
#include "comment.hpp"
#include "notification.hpp"

using namespace std;

class Jeek;
class Comment;
class Notification;

class User{
public:
  User(string username_, string displayName_, string password_);
  bool matchUser(string username_);
  bool matchPass(string password_);
  void addJeek(Jeek* newJeek);
  void showName();
  string showUsername();
  void showProfile();
  void showTagPro(string tag);
  void showJeekPro(Jeek* jeek);
  void addComment(Comment* newComment);
  void addReply(Comment* newReply);
  void showComment(int commentId);
  void showReply(int commentId);
  void addLike(int jeekId);
  bool canDislike(int jeekId);
  void addDislike(int jeekId);
  void follow(User* following);
  void addFollower(User* follower);
  void removeFollower(User* username);
  void unfollow(string username);
  void addNotif(Notification notif);
  void broadcastFollowers(Notification notif);
  void showNotifs();

private:
  string username;
  string displayName;
  string password;
  vector <Jeek*> jeeks;
  vector <Comment*> comments;
  vector <Comment*> replies;
  vector <int> likes;
  vector <User*> followers;
  vector <User*> followings;
  vector <Notification> notifications;
  ///notification;
};



#endif
