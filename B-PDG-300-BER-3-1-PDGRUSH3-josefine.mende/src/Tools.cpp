#include "Getter.hpp"

std::string remove_additional_spaces(std::string content) {
    std::string str = content.erase(0, content.find_first_not_of(' '));
    int j = 0;

    for(int i = content.size() - 1; i >= 0; i--) {
        if(content[i] == ' ' && content[i] == content[i - 1]) {
            content.erase(content.begin() + i);
        }
    }
    while (content[j - 2] != ':')
        j++;
    content.replace(0, j, "");
    return content;
}

std::vector<int> add_together(std::string content) {
    std::vector<int> numbers;
    int added_together = 0;
    int added_together_two = 0;

    std::stringstream text_stream(content);
    std::string item;
    while (std::getline(text_stream, item, ' '))
        numbers.push_back(stoi(item));
    for (int number : numbers)
        added_together += number;
    numbers.clear();
    while (std::getline(text_stream, item, ' '))
        numbers.push_back(stoi(item));
    for (long unsigned int i = 0; i < 3; i++)
        added_together_two += numbers[i];
    numbers.clear();
    numbers.push_back(added_together);
    numbers.push_back(added_together_two);
    return numbers;
}

std::string get_content(int n) {
    std::ifstream info("/proc/stat");
    std::string content;

    for (int i = 0; i <= n; i++)
        std::getline(info, content);
    content.replace(0, 5, "");
    return content;
}