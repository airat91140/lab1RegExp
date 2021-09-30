#include <iostream>
#include "Dialogue.h"

int main(int argc, char *argv[]) {
    try {
        lab1::Dialogue d(argc, argv);
        d.run();
    }
    catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
