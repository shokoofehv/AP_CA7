#ifndef __JEEKER_H__
#define __JEEKER_H__

#include <iostream>
#include <string>
#include <vector>
#include "user.hpp"
#include "jeek.hpp"
#include "comment.hpp"
#include "notification.hpp"
using namespace std;

#define SIGNUP "signup"
#define LOGIN "login"
#define LOGOUT "logout"
#define JEEK "jeek"
#define TEXT "text"
#define TAG "tag"
#define MENTION "mention"
#define PUBLISH "publish"
#define ABORT "abort"
#define COMMENT "comment"
#define REPLY "reply"
#define SHOWJEEK "showJeek"
#define SHOWCOMMENT "showComment"
#define SHOWREPLY "showReply"
#define LIKE "like"
#define DISLIKE "dislike"
#define NOTIFICATIONS "notifications"
#define SEARCH "search"
#define REJEEK "rejeek"
#define FOLLOW "follow"
#define UNFOLLOW "unfollow"


class Jeeker{

public:
  Jeeker();
  void getCommand();
  void signup(string username, string displayName, string password);
  void login(string username, string password);
  void logout();
  vector <string> get();
  void jeek();
  void showJeek(int jeekId);
  void searching(string searched);
  void comment(int jeekId);
  void reply(int commentId);
  void rejeek(int jeekId);
  void showComment(int commentId);
  void showReply(int commentId);
  void like(int jeekId);
  void dislike(int jeekId);
  void follow(string username);
  void unfollow(string username);
  void notification();
  bool validUser(string username);
  User* wantedUser(string username);
  Jeek* wantedJeek(int jeekId);
  Comment* wantedComment(int commentId);

private:
  vector <User> users;
  vector <Jeek> jeeks;
  vector <Comment> comments;
  vector <Notification> notifications;

  User* currentUser;
  static int currentId;




};



#endif
