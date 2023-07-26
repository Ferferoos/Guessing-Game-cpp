#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits> // For numeric_limits

int main() {
    // Generate a random number between 1 and 100
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;
    int maxAttempts = 7;

    std::cout << "Welcome to the Guessing Game!" << std::endl;
    std::cout << "I have picked a number between 1 and 100." << std::endl;
    std::cout << "You have " << maxAttempts << " attempts to guess the number." << std::endl;

    // Main game loop
    while (attempts < maxAttempts) {
        std::cout << "Enter your guess: ";
        if (std::cin >> guess) {
            if (guess == secretNumber) {
                std::cout << "Congratulations! You guessed the correct number: " << secretNumber << std::endl;
                break;
            } else if (guess < secretNumber) {
                std::cout << "Too low! Try again." << std::endl;
            } else {
                std::cout << "Too high! Try again." << std::endl;
            }
            attempts++;
        } else {
            // Handle invalid input (non-integer input)
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
            std::cin.clear(); // Clear the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the input buffer
        }
    }

    if (attempts == maxAttempts) {
        std::cout << "Sorry, you've reached the maximum number of attempts." << std::endl;
        std::cout << "The secret number was: " << secretNumber << std::endl;
    }

    return 0;
}
