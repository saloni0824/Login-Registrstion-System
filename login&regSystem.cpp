#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// User struct to hold user information
struct User {
    string username;
    string password;
};

// Function to register a new user
void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Open users file in append mode
    ofstream usersFile("users.txt", ios::app);
    usersFile << username << "," << password << endl;
    usersFile.close();

    cout << "User registered successfully!\n";
}

// Function to login an existing user
void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Open users file in read mode
    ifstream usersFile("users.txt");
    string line;
    bool userFound = false;
    while (getline(usersFile, line)) {
        size_t pos = line.find(",");
        string storedUsername = line.substr(0, pos);
        string storedPassword = line.substr(pos+1);
        if (username == storedUsername && password == storedPassword) {
            userFound = true;
            break;
        }
    }
    usersFile.close();

    if (userFound) {
        cout << "Login successful!\n";
    } else {
        cout << "Invalid username or password. Please try again.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "You have successfully exited\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
