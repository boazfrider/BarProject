#ifndef _EXCEPTIONS_
#define _EXCEPTIONS_

#include <iostream>
#include <string>

class IlleglArgument : public std::exception{
    private:
        std::string message;
    public:
        explicit IlleglArgument(const std::string& message);
        const char* what() const noexcept override{
            return message.c_str();
        }
};

class InvalidNumOfTable : public std::exception{
    private:
        std::string message;
    public:
        explicit InvalidNumOfTable(const std::string& message);
        const char* what() const noexcept override{
            return message.c_str();
        }
};

class TableAlreadyOpen : public std::exception{
    private:
        std::string message;
    public:
        explicit TableAlreadyOpen(const std::string& message);
        const char* what() const noexcept override{
            return message.c_str();
        }
};

class TableStillNeedToPay : public std::exception{
    private:
        std::string message;
    public:
        explicit TableStillNeedToPay(const std::string& message);
        const char* what() const noexcept override{
            return message.c_str();
        }
};

#endif