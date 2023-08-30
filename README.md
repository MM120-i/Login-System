# Login-System
Simple Login System in C

## Authentication System

This is a simple command-line authentication system written in C that allows users to sign up, log in, and view registered user information. It provides basic user registration and authentication functionality using a text-based interface.

### Features

1. **Sign Up**: Users can register by providing their full name, email, phone number, and password. The system generates a username based on the email provided.

2. **Login**: Registered users can log in using their username and password. Upon successful login, the system displays their information, including full name, email, username, and phone number.

3. **Display Users**: The system also provides the functionality to display the list of registered users along with their information.

### How to Use

1. Run the program and choose an operation:
    - Sign Up: Register as a new user by providing your information.
    - Login: Log in using your username and password.
    - Exit: Terminate the program.

2. If you choose to sign up, you'll need to provide your full name, email, phone number, and password. The system will confirm the password before completing the registration.

3. If you choose to log in, enter your username and password. Upon successful login, your information will be displayed.

4. You can also view the list of registered users and their information by selecting the "Display Users" option.

### Dependencies

- The program uses the standard C library functions for input/output and file handling.
- It also uses the Windows API for certain features such as clearing the screen and generating a beep sound.

### Notes

- The program stores user data in a binary file named "User.dat."
- The password input is hidden with asterisks for security.

## Credits

This project was inspired by the [Creating Authentication System in C Programming Language](https://www.youtube.com/watch?v=xtk14TcWaN4&list=PL_rcwK265X9egWCUbZs1iBRnSbHR0jCF3&index=17&ab_channel=ADV.LEARNING) video tutorial by ADV.LEARNING on YouTube. The tutorial provided insights and guidance on creating the core functionality of this authentication system.

I would like to express my gratitude to ADV.LEARNING for their informative video that served as a source of inspiration for this project.

