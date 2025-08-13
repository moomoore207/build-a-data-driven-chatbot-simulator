// ffww_build_a_data-dr.cpp

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// Data structure to store chatbot responses
struct Response {
    string keyword; // Keyword to trigger the response
    string message; // The response message
};

// Data structure to store chatbot conversations
struct Conversation {
    string user_id; // User ID
    vector<string> chat_log; // Chat log
    map<string, Response> responses; // Responses mapping
};

// Chatbot Simulator class
class ChatbotSimulator {
private:
    map<string, Conversation> conversations; // Conversations mapping

public:
    // Add a conversation
    void addConversation(string user_id) {
        Conversation conversation;
        conversation.user_id = user_id;
        conversations[user_id] = conversation;
    }

    // Add a response to a conversation
    void addResponse(string user_id, string keyword, string message) {
        Response response;
        response.keyword = keyword;
        response.message = message;
        conversations[user_id].responses[keyword] = response;
    }

    // Process a user input
    string processInput(string user_id, string input) {
        Conversation conversation = conversations[user_id];
        for (auto& response : conversation.responses) {
            if (input.find(response.first) != string::npos) {
                return response.second.message;
            }
        }
        return "I'm not sure I understand. Can you please rephrase?";
    }

    // Display chat log
    void displayChatLog(string user_id) {
        Conversation conversation = conversations[user_id];
        cout << "Chat Log for " << user_id << ":" << endl;
        for (auto& message : conversation.chat_log) {
            cout << message << endl;
        }
    }
};

int main() {
    ChatbotSimulator chatbot;

    // Add conversations
    chatbot.addConversation("user1");
    chatbot.addConversation("user2");

    // Add responses
    chatbot.addResponse("user1", "hello", "Hi! How can I help you today?");
    chatbot.addResponse("user1", "goodbye", "Goodbye! Have a great day!");
    chatbot.addResponse("user2", "hi", "Hey! What's up?");

    // Process user inputs
    string userInput;
    cout << "User 1: ";
    getline(cin, userInput);
    string response = chatbot.processInput("user1", userInput);
    cout << "Chatbot: " << response << endl;
    chatbot.displayChatLog("user1");

    cout << "User 2: ";
    getline(cin, userInput);
    response = chatbot.processInput("user2", userInput);
    cout << "Chatbot: " << response << endl;
    chatbot.displayChatLog("user2");

    return 0;
}