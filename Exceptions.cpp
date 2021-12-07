#include"Exceptions.h"

IlleglArgument::IlleglArgument(const std::string& message):message(message){}

InvalidNumOfTable::InvalidNumOfTable(const std::string& message):message(message){}

TableAlreadyOpen::TableAlreadyOpen(const std::string& message):message(message){}

TableStillNeedToPay::TableStillNeedToPay(const std::string& message):message(message){}