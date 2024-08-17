#include <iostream>
#include <string>
#include <unordered_map>

class Chatbot {
private:
    std::unordered_map<std::string, std::string> responses;

public:
    // Constructor to initialize the chatbot with some predefined responses
    Chatbot() {
        responses["hello"] = "Hello! How can I assist you today?";
        responses["hi"] = "Hi there! What can I do for you?";
        responses["how are you?"] = "I'm just a bot, but I'm functioning as expected!";
        responses["bye"] = "Goodbye! Have a great day!";
        responses["your name?"] = "I am a simple chatbot created to assist you.";
        responses["thank you"] = "You're welcome! If you have more questions, feel free to ask.";
    }

    // Method to get a response based on user input
    std::string getResponse(const std::string& input) {
        std::string lowerInput = toLower(input);
        if (responses.find(lowerInput) != responses.end()) {
            return responses[lowerInput];
        } else {
            return "I'm sorry, I don't understand that. Can you please rephrase?";
        }
    }

private:
    // Helper function to convert string to lowercase
    std::string toLower(const std::string& str) {
        std::string result = str;
        for (char& c : result) {
            c = tolower(c);
        }
        return result;
    }
};

int main() {
    Chatbot chatbot;
    std::string userInput;

    std::cout << "Chatbot: Hello! I am your assistant. Type 'bye' to exit." << std::endl;

    // Chat loop
    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, userInput);

        // Exit condition
        if (userInput == "bye") {
            std::cout << "Chatbot: " << chatbot.getResponse(userInput) << std::endl;
            break;
        }

        // Get and display the chatbot's response
        std::cout << "Chatbot: " << chatbot.getResponse(userInput) << std::endl;
    }

    return 0;
}
