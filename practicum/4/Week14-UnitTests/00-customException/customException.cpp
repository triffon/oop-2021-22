#include <iostream>
#include <string>

class PepiKNotAvailableException : public std::exception
{
private:
    std::string message;

public:
    PepiKNotAvailableException(const std::string& message) : message(message) {}

    const char* what() const noexcept override final
    {
        return this->message.c_str();
    }
};

int main ()
{
    try
    {
        throw PepiKNotAvailableException("mnogo tajno");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}