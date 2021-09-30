//
// Created by airat on 30.09.2021.
//

#include "CheckStr.h"

using std::chrono::steady_clock;

bool lab1::CheckStr::check(const std::string &str) {
    isAccepted = std::regex_match(str, rex);
    return isAccepted;
}

std::string lab1::CheckStr::extractHash(const std::string &str) {
    std::smatch results;
    if(std::regex_search(str, results, substr)) {
        hash = results[results.size() - 1];
        return results[results.size() - 1];
    }
    return "";
}

bool lab1::CheckStr::getIsAccepted() const {
    return isAccepted;
}

void lab1::CheckStr::reset() {
    hash = "";
    isAccepted = false;

}

void lab1::CheckStr::runTiming() {
    std::string str;
    steady_clock::duration duration = steady_clock::duration::zero();
    steady_clock::time_point t;
    srand(time(nullptr));
    for (int l = 1000; l <= 10000; l += 500) {
        {
            duration = steady_clock::duration::zero();
            str = genAcceptedStr(l);
            t = std::chrono::steady_clock::now();
            this->check(str);
            this->extractHash(str);
            duration += std::chrono::steady_clock::now() - t;
        }
        {
            str = genInacceptedStr(l);
            t = std::chrono::steady_clock::now();
            this->check(str);
            this->extractHash(str);
            duration += std::chrono::steady_clock::now() - t;
        }
        std::cout/* << "symbols: " */<< 50 + l * 2 << " "/*" time: "*/ << duration.count() << std::endl;
    }
}

// ed2k://|file|имя_файла|размер_файла|хэш_файла|/
std::string lab1::CheckStr::genAcceptedStr(int len) {
    std::string str = "ed2k://|file|";
    str.reserve(50 + len * 2 );
    for (int i = 0; i < len; ++i) {
        str += rand() % ('z' - 'a' + 1) + (rand() & 1 ? 'a' : 'A');
    }
    str += '|';
    for (int i = 0; i < len; ++i) {
        str += rand() % ('9' - '0' + 1) + '0';
    }
    str += '|';
    for (int i = 0; i < 32; ++i) {
        str += (rand() & 1) ? ((rand() % ('9' - '0' + 1)) + '0') : (rand() % ('f' - 'a' + 1) + (rand() & 1 ? 'a' : 'A')); //generating random hash
    }
    str += "|/";
    return str;
}

std::string lab1::CheckStr::genInacceptedStr(int len) {
    std::string str;
    str.reserve(50 + len * 2);
    for (int i = 0; i < 50 + len * 2; ++i) {
        str += rand() % ('~' - '(' + 1) + '(';
    }
    return str;
}

std::string lab1::CheckStr::getHash() const {
    return hash;
}
