#include <iostream>
#include <cstdlib>
#include <ctime>

class GuessTheNumber {
private:
    int numberToGuess;  // The number that the player has to guess
    int maxAttempts;    // Maximum number of attempts allowed
    int attempts;       // Number of attempts made by the player

public:
    // Constructor to initialize the game
    GuessTheNumber(int maxAttempts = 5) {
        this->maxAttempts = maxAttempts;
        this->attempts = 0;
        // Seed the random number generator and generate a random number between 1 and 100
        srand(static_cast<unsigned>(time(0)));
        numberToGuess = rand() % 100 + 1;
    }

    // Method to play the game
    void play() {
        int guess;
        std::cout << "Welcome to the Guess the Number Game!\n";
        std::cout << "I have selected a number between 1 and 100. Can you guess it?\n";

        // Loop until the player runs out of attempts or guesses the number
        while (attempts < maxAttempts) {
            std::cout << "Attempt " << (attempts + 1) << " of " << maxAttempts << ": Enter your guess: ";
            std::cin >> guess;

            // Increase the attempt counter
            attempts++;

            // Check if the guess is correct, too high, or too low
            if (guess == numberToGuess) {
                std::cout << "Congratulations! You've guessed the correct number in " << attempts << " attempts.\n";
                return;
            } else if (guess < numberToGuess) {
                std::cout << "Too low! Try again.\n";
            } else {
                std::cout << "Too high! Try again.\n";
            }
        }

        // If the player runs out of attempts
        std::cout << "Sorry, you've used all " << maxAttempts << " attempts. The correct number was " << numberToGuess << ".\n";
    }
};

int main() {
    // Create an instance of the game and start it
    GuessTheNumber game;
    game.play();

    return 0;
}
