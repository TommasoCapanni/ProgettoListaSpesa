//
// Created by Tommaso Capanni on 18/07/2021.
//

#ifndef PROGETTOLISTASPESA_NEGATIVENUMBEREXCEPTION_H
#define PROGETTOLISTASPESA_NEGATIVENUMBEREXCEPTION_H

#include <stdexcept>
#include <string>

class NegativeNumberException : public std::logic_error {
public:
    NegativeNumberException(const std::string &msg = " ") : logic_error(msg.c_str()) {};
};

#endif //PROGETTOLISTASPESA_NEGATIVENUMBEREXCEPTION_H
