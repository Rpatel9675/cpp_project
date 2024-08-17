#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

class PasswordGenerator {
private:
    int length;
    std::string characters;
    
public:
    // Constructor to initialize the password length and available characters
    PasswordGenerator(int len) {
        length = len;
        characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}|;:,.<>?";
    }

    // Method to generate the password
    std::string generatePassword() {
        std::string password = "";
        srand(time(0));  // Seed for random number generator
        
        for (int i = 0; i < length; i++) {
            int index = rand() % characters.length();
            password += characters[index];
        }

        return password;
    }
};

int main() {
    int passwordLength;

    std::cout << "Enter the desired password length: ";
    std::cin >> passwordLength;

    // Create an instance of PasswordGenerator
    PasswordGenerator passwordGen(passwordLength);
    
    // Generate and display the password
    std::string password = passwordGen.generatePassword();
    std::cout << "Generated Password: " << password << std::endl;

    return 0;
}
