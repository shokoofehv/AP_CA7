#ifndef __JEEK_H__
#define __JEEK_H__

#include <string>
#include <vector>
#include "comment.hpp"
#include "notification.hpp"
using namespace std;

#define JEEKSIZE 140

class Comment;

class Jeek{

public:

  Jeek(int jeekId_, string texts_, vector <string> tags_, vector <string> mentions_, User* publisher_);

  bool validJeek();
  bool matchId(int jeekId_);
  void showJeek1();
  int showId();
  void print_tag(vector <string> str);
  bool matchTag(string tag);
  void addComment(Comment* newComment);
  void addRejeek();
  void changeId(int jeekId_);
  void changePublisher(User* newPublisher);
  void addLike();
  void addDislike();
  //void notifyPublisher(User* currentUser);
  void notifyPublisher(Notification newNotif);

private:
  int jeekId;
  string text;
  vector <string> tags;
  vector <string> mentions;
  int likes;
  int rejeeks;
  vector <Comment*> comments;
  User* publisher;

};

#endif
