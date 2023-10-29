#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include "Login.h"

#define ENTER 13
#define TAB 9
#define BACK_SPACE 8

struct user{

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

int main(){

    int opt;

    printf("\n\t\t\t\t==============Welcome to Authentication System==============");
    printf("\nPlease choose your operation: ");
    printf("\n1.Signup");
    printf("\n2.Login");
    printf("\n3.Exit");

    printf("\n\nYour choice:\t");
    scanf("%d", &opt);
    fgetc(stdin);

    switch(opt){
        
        case 1:

            signUp();
            break;

        case 2: 

            login();
            break;

        case 3:

            displayUsers();
            printf("\t\t\tBye!");
            break;
    
    default:
        break;
    }

    return 0;
}

void displayUsers() {

    struct user usr;
    FILE *fp = fopen("User.dat", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nRegistered Users:\n");

    while (fread(&usr, sizeof(struct user), 1, fp)) {
        printf("\nFull Name: %s", usr.fullName);
        printf("\nEmail: %s", usr.email);
        printf("\nUsername: %s", usr.username);
        printf("\nPhone Number: %s\n", usr.phoneNumber);
    }

    fclose(fp);
}


void signUp(){
    
    struct user user;
    char password2[50];

    system("cls");
    printf("\nEnter your full name:\t");
    takeInput(user.fullName);

    printf("Enter your email:\t");
    takeInput(user.email);

    printf("Enter your phone number:\t");
    takeInput(user.phoneNumber);

    printf("Enter your password:\t");
    takePassword(user.password);
    printf("\nConfirm your password:\t");
    takePassword(password2);

    if (!strcmp(user.password, password2)) {
        generateUsername(user.email, user.username);
        FILE *fp = fopen("User.dat", "a+");
        fwrite(&user, sizeof(struct user), 1, fp);

        if (fwrite != 0) {
            printf("\n\nUser registration success, Your username is %s", user.username);
        } else {
            printf("\n\nSomething went wrong...");
        }
        fclose(fp);
    } else {
        printf("\npassword does not match");
        Beep(750, 300);
    }
}

void login() {

    struct user usr;
    FILE *fp;
    char username[50], pword[50], enteredPassword[50]; // Separate array for entered password

    printf("\nEnter your username:\t");
    takeInput(username);
    printf("\nEnter your password:\t");
    takePassword(enteredPassword); // Capture entered password in a separate array

    fp = fopen("User.dat", "r");
    int usrFound = 0;

    while (fread(&usr, sizeof(struct user), 1, fp)) {
        if (!strcmp(usr.username, username)) {
            if (!strcmp(usr.password, enteredPassword)) { 
                system("cls");
                printf("\n\t\t\t\t\tWelcome %s!", usr.fullName);
                printf("\n\n|Full Name: \t%s", usr.fullName);
                printf("\n|Email:\t\t%s", usr.email);
                printf("\n|Username:\t%s", usr.username);
                printf("\n|Contact Number:\t%s", usr.phoneNumber);
            } else {
                printf("\n\nInvalid Password");
                Beep(800, 300);
            }
            usrFound = 1;
        }
    }

    if (!usrFound) {
        printf("\n\nUser is not registered");
        Beep(800, 300);
    }
    
    fclose(fp);
}

void takePassword(char pwd[50]){

    int i = 0;
    char ch;

    while(1){

        ch = getch();

        if(ch == ENTER || ch == TAB){

            pwd[i] = '\0';
            break;
        }
        else if(ch == BACK_SPACE){

            if(i > 0){

                i--;
                printf("\b \b");
            }
        }
        else{

            pwd[i++] = ch;
            printf("* \b");
        }
    }
}

void takeInput(char ch[50]){

    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = '\0';
}

char generateUsername(char email[50], char userName[50]){

    int i;
    for(i = 0; i < strlen(email); i++){

        if(email[i] == '@'){
            break;
        }
        else{
            userName[i] = email[i];
        }
    }
    userName[i] = '\0';
}
