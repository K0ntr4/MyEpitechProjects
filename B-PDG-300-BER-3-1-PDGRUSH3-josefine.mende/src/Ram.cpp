#include "Getter.hpp"

float get_ram_av() {
    std::ifstream info("/proc/meminfo");
    std::string content;
    int x = 0;

    for (int i = 0; i < 3; i++)
        std::getline(info, content);
    content.replace(0, 13, "");
    content.erase(0, content.find_first_not_of(' '));

    std::stringstream text_stream(content);
    std::string item;

    std::getline(text_stream, item, ' ');
    x = stoi(item);

    float res = (int)(((float)x / (float)125000) * 100 + .5);
    return (float)res / (float)100;
}

float get_ram_free() {
    std::ifstream info("/proc/meminfo");
    std::string content;
    int x = 0;

    for (int i = 0; i < 2; i++)
        std::getline(info, content);
    content.replace(0, 8, "");
    content.erase(0, content.find_first_not_of(' '));

    std::stringstream text_stream(content);
    std::string item;

    std::getline(text_stream, item, ' ');
    x = stoi(item);

    float res = (int)(((float)x / (float)125000) * 100 + .5);
    return (float)res / (float)100;
}