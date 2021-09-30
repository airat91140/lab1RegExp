//
// Created by airat on 30.09.2021.
//

#ifndef LAB1REGEXP_CHECKSTR_H
#define LAB1REGEXP_CHECKSTR_H

#include <regex>
#include <chrono>
#include <iostream>

namespace lab1 {
    class CheckStr {
    private:
        const std::regex rex = std::regex(R"([eE][dD]2[kK]:\/\/\|file\|[A-Za-z+-_.]+\|[0-9]+\|[0-9a-fA-F]{32}\|\/)");
        const std::regex substr = std::regex("([0-9a-fA-F]{32})");
        std::string hash;
        bool isAccepted;
        static std::string genAcceptedStr(int len);

        static std::string genInacceptedStr(int len);
    public:
        CheckStr() : isAccepted(false) {}

        bool check(const std::string &str);

        std::string extractHash(const std::string &str);

        bool getIsAccepted() const;

        void reset();

        void runTiming();

        std::string getHash() const;
    };
}

#endif //LAB1REGEXP_CHECKSTR_H
