#ifndef LOGIN_H
#define LOGIN_H

struct user {

    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char phoneNumber[50];
};

void takeInput(char ch[50]);
char generateUsername(char email[50], char userName[50]);
void takePassword(char pwd[50]);
void signUp();
void login();
void displayUsers();

#endif // LOGIN_H
