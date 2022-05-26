#include <iostream>
#include <cstring>
#include <fstream>

enum class MessageType
{
    UNKNOWN,
    INFO,
    WARNING,
    // ERROR,
    // CRITICAL_ERROR
};

class Message
{
private:
    const MessageType type;
    char* message;

public:
    Message() : type(MessageType::UNKNOWN), message(nullptr) {}

    Message(const MessageType& type, const char* message) : type(type)
    {
        this->message = new char[strlen(message) + 1];
        strcpy(this->message, message);
    }

    friend std::ostream& operator << (std::ostream& out, const Message& message)
    {
        switch (message.type)
        {
        case MessageType::INFO:
            out << "INFO: " << message.message << '\n';
            break;
        case MessageType::WARNING:
            out << "WARNING: " << message.message << '\n';
            break;
        default:
            out << "Invalid command!\n";
            break;
        }

        return out;
    }
};

class Logger
{
private:
    char* fileName;

public:
    Logger(const char* fileName)
    {
        this->fileName = new char[strlen(fileName) + 1];
        strcpy(this->fileName, fileName);
    }

    Logger& operator << (const Message& message)
    {
        std::ofstream file(this->fileName);

        if (!file.is_open())
        {
            return *this;
        }

        file << message;

        file.close();

        return *this;
    }
};

int main (int argc, char** argv)
{
    if (argc == 2)
    {
        Logger l(argv[1]);
        Message m(MessageType::INFO, "Machkai, Grisho!");

        l << m;
    }

    return 0;
}