#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

class ChatRoom {
public:
    static void sendMessage(const std::string& sender, const std::string& message) {
        std::ofstream outFile("chat_log.txt", std::ios::app);
        outFile << sender << ": " << message << "\n";
        outFile.close();
    }

    static void displayChat() {
        std::ifstream inFile("chat_log.txt");
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << "\n";
        }
        inFile.close();
    }
};

void userThread(const std::string& username) {
    while (true) {
        std::string message;
        std::cout << username << ": ";
        std::getline(std::cin, message);

        if (message == "/exit") {
            break;
        }

        ChatRoom::sendMessage(username, message);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // 模拟延迟
    }
}

int main() {
    std::cout << "Welcome to the Chat Room!\n";

    std::string username;
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);

    std::thread displayThread([]() {
        while (true) {
            ChatRoom::displayChat();
            std::this_thread::sleep_for(std::chrono::seconds(1));  // 定期刷新
        }
    });

    std::thread userInputThread(userThread, username);

    userInputThread.join();
    displayThread.join();
    std::cout<<"SBGithub";
    return 0;
}
