//
// Created by Luca on 1/26/22.
//

#include <cstring>
#include "ToyStory.hpp"

void ToyStory::tellMeAStory(const std::string &filename, Toy &toy1, bool (Toy::*func1)(std::string), Toy &toy2, bool
(Toy::*func2)(std::string)) {
    Toy toy_arr[2] = { toy1, toy2 };
    std::ifstream fs(filename, std::ios::in);
    std::string content;
    int i = 0;

    if (!fs) {
        std::cout << "Bad Story" << std::endl;
        return;
    }
    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;
    while ( std::getline(fs, content) ) {
        if (content.starts_with("picture:")) {
            if (!toy_arr[i].setAscii(content.replace(0, 8, ""))) {
                std::cout << toy_arr[i].getLastError().where() << ": " << toy_arr[i].getLastError().what() << std::endl;
                return;
            }
            std::cout << toy_arr[i].getAscii() << std::endl;
            i = i ? 0 : 1;
            continue;
        }
        if (i == 0) {
            if (!(toy1.*func1)(content)) {
                Toy::Error err = (i ? toy1 : toy2).getLastError();
                std::cout << err.where() << " : " << err.what() << std::endl;
                break;
            }
        } else if (i == 1) {
            if (!(toy2.*func2)(content)) {
                Toy::Error err = (i ? toy1 : toy2).getLastError();
                std::cout << err.where() << " : " << err.what() << std::endl;
                break;
            }
        }
        i = i ? 0 : 1;
    }
    fs.close();
}
