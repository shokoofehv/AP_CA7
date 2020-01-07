#include "jeeker.hpp"

Jeeker::Jeeker() {
  currentId = 0;
  currentUser = NULL;
  jeeks.clear();
}

void Jeeker::getCommand() {
  string command;
  string username, displayName, password;
  int id;
  string searched;
  while(true){
    cin >> command;
    if (command == SIGNUP) {
      cin >> username >> displayName >> password;
      signup(username, displayName, password);
    }
    else if(command == LOGIN) {
      cin >> username >> password;
      login(username, password);
    }
    else if(command == LOGOUT) {
      logout();
    }
    else if (command == JEEK) {
      jeek();
    }
    else if (command == SHOWJEEK) {
      cin >> id;
      showJeek(id);
    }
    else if (command == SEARCH) {
      cin >> searched;
      searching(searched);
    }
    else if (command == COMMENT) {
      cin >> id;
      comment(id);
    }
    else if (command == REPLY) {
      cin >> id;
      reply(id);
    }
    else if (command == REJEEK) {
      cin >> id;
      rejeek(id);
    }
    else if (command == SHOWCOMMENT) {
      cin >> id;
      showComment(id);
    }
    else if (command == SHOWREPLY) {
      cin >> id;
      showReply(id);
    }
    else if (command == LIKE) {
      cin >> id;
      like(id);
    }
    else if (command == DISLIKE) {
      cin >> id;
      dislike(id);
    }
    else if (command == FOLLOW) {
      cin >> username;
      follow(username);
    }
    else if (command == UNFOLLOW) {
      cin >> username;
      unfollow(username);
    }
    else if (command == NOTIFICATIONS) {
      notification();
    }
    else if(command == "exit"){
      break;
    }
  }
}

bool Jeeker::validUser(string username) {
  for (int i = 0; i < users.size(); i++) {
    if (users[i].matchUser(username))
      return false;
  }
  return true;
}

void Jeeker::signup(string username, string displayName, string password) {
  if (validUser(username)) {
    User temp(username, displayName, password);
    users.push_back(temp);
  }
  else cout << "invalid username." << endl;
}

User* Jeeker::wantedUser(string username) {
  for (int i = 0; i < users.size(); i++) {
    if (users[i].matchUser(username))
      return &(users[i]);
  }
  cout << "user not found" << endl;
  return NULL;
}

void Jeeker::login(string username, string password) {
  User* temp = wantedUser(username);
  if (temp == NULL) {
    cout << "Wrong username." << endl;
    return;
  }
  if (temp->matchPass(password))
    currentUser = wantedUser(username);
  else cout << "Wrong password." << endl;
}

void Jeeker::logout() {
  currentUser = NULL;
}




void Jeeker::jeek() {

  string jeekDetail;
  string text;
  vector <string> tags;
  vector <string> mentions;
  string temp;
  if(currentUser == NULL){
    cout << "error" << endl;
    return;
  }
  while (true) {
    cin >> jeekDetail;
    if (jeekDetail == TEXT) {
      getline(cin,temp);
      temp.erase(0,1);
      text = temp;
    }
    else if (jeekDetail == TAG) {
      cin >> temp;
      tags.push_back(temp);
    }
    else if (jeekDetail == MENTION) {
      cin >> temp;
      mentions.push_back(temp);
    }
    else if (jeekDetail == PUBLISH) {
      //cout << currentId << endl;
      Jeek newJeek(currentId, text, tags, mentions, currentUser);
      //newJeek.showId();
      if (newJeek.validJeek() && currentUser != NULL) {
        jeeks.push_back(newJeek);
        currentUser->addJeek(&newJeek);
        //newJeek.showJeek1();
        //currentUser->showProfile();

        // Notification newNotif(currentUser, "jeeked ", currentId);
        // notifications.push_back(newNotif);
        // currentUser->broadcastFollowers(newNotif);
         currentId++;
      }
      else cout << "Not valid. " << endl;
      break;
    }
    else if (jeekDetail == ABORT) {
      break;
    }
  }

}

Jeek* Jeeker::wantedJeek(int jeekId) {
  for (int i = 0; i < jeeks.size(); i++)
    if (jeeks[i].matchId(jeekId))
      return &(jeeks[i]);

  return NULL;
}


void Jeeker::showJeek(int jeekId) {
  if(currentUser == NULL || wantedJeek(jeekId) == NULL){
    cout << "Error" << endl;
    return;
  }
  wantedJeek(jeekId)->showJeek1();
}


void Jeeker::searching(string searched) {
  if (searched[0] == '@') {
    searched = searched.erase(0,1);
    for(int i=0;i<users.size();i++){
      if(users[i].matchUser(searched)){
        users[i].showProfile();
      }
    }
  }
  else if (searched[0] == '#') {
    for (int i = 0; i < users.size(); i++) {

      users[i].showTagPro(searched);
    }
  }
}


void Jeeker::comment(int jeekId) {
  string text;
  getline(cin, text);
  text.erase(0, 1);
  Comment newComment(currentId, text, currentUser);
  currentId++;
  comments.push_back(newComment);
  if(currentUser == NULL || wantedJeek(jeekId) == NULL){
    cout << "error" << endl;
    return;
  }
  wantedJeek(jeekId)->addComment(&newComment);
  currentUser->addComment(&newComment);

  // Notification newNotif(currentUser, "commented on ", jeekId);
  // notifications.push_back(newNotif);
  // wantedJeek(jeekId)->notifyPublisher(newNotif);
}

Comment* Jeeker::wantedComment(int commentId) {
  for (int i = 0; i < comments.size(); i++) {
    if (comments[i].matchId(commentId))
      return &(comments[i]);
  }
}
void Jeeker::reply(int commentId) {
  string text;
  cin >> text;
  Comment newReply(currentId, text, currentUser);
  currentId++;
  comments.push_back(newReply);
  wantedComment(commentId)->addReply(&newReply);
  currentUser->addReply(&newReply);

  Notification newNotif(currentUser, "replied ", commentId);
  wantedComment(commentId)->notifyPublisher(newNotif);
  notifications.push_back(newNotif);
}

void Jeeker::rejeek(int jeekId) {
  if(currentUser == NULL || wantedJeek(jeekId) == NULL){
    cout << "error" << endl;
    return;
  }
  wantedJeek(jeekId)->addRejeek();
  for(int i=0;i<jeeks.size();i++){
    if(jeeks[i].matchId(jeekId)){
      Jeek rejeeked = jeeks[i];  //ATTENTION
      jeeks.push_back(rejeeked);
      rejeeked.changeId(currentId);
      currentId++;
      rejeeked.changePublisher(currentUser);
      currentUser->addJeek(&(rejeeked));
      Notification newNotif(currentUser, "rejeeked ", jeekId);
      notifications.push_back(newNotif);
      wantedJeek(jeekId)->notifyPublisher(newNotif);
    }
  }




}

void Jeeker::showComment(int commentId) {
  for (int i = 0; i < users.size(); i++) {
    users[i].showComment(commentId);
  }
}

void Jeeker::showReply(int commentId) {
  for (int i = 0; i < users.size(); i++) {
    users[i].showReply(commentId);
  }
}

void Jeeker::like(int jeekId) {
  if(currentUser == NULL || wantedJeek(jeekId) == NULL){
    cout << "error" << endl;
    return;
  }
  wantedJeek(jeekId)->addLike();
  currentUser->addLike(jeekId);

  Notification newNotif(currentUser, "liked ", jeekId);
  notifications.push_back(newNotif);
  wantedJeek(jeekId)->notifyPublisher(newNotif);
}

void Jeeker::dislike(int jeekId) {
  if(currentUser == NULL || wantedJeek(jeekId) == NULL){
    cout << "error" << endl;
    return;
  }
  if (currentUser->canDislike(jeekId)) {
    wantedJeek(jeekId)->addDislike();
    currentUser->addDislike(jeekId);
  }

  Notification newNotif(currentUser, "disliked ", jeekId);
  notifications.push_back(newNotif);
  wantedJeek(jeekId)->notifyPublisher(newNotif);

}

void Jeeker::follow(string username) {
  wantedUser(username)->addFollower(currentUser);
  currentUser->follow(wantedUser(username));
}

void Jeeker::unfollow(string username) {
  wantedUser(username)->removeFollower(currentUser);
  currentUser->unfollow(username);
}

void Jeeker::notification() {
  currentUser->showNotifs();
}
