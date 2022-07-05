#include "Getter.hpp"

static int *add_traffic_together(std::string *content, std::ifstream *info, int *traffic) {
    int j = 0;

    *content = remove_additional_spaces(*content);

    std::stringstream text_stream(*content);
    std::string item;

    while (std::getline(text_stream, item, ' ')) {
        if (j == 0)
            traffic[0] += stoi(item);
        else if (j == 8)
            traffic[1] += stoi(item);
        j++;
    }
    j = 0;
    std::getline(*info, *content);
    return traffic;
}

static std::string get_network_data(int *traffic) {
    std::ifstream info("/proc/net/dev");
    std::ifstream count_lines("/proc/net/dev");
    std::string content;
    int k = 0;

    for(; std::getline(count_lines, content); k++);
    for (int i = 0; i < 3; i++)
        std::getline(info, content);
    for (int l = 0; l < k - 3; l++) {
        add_traffic_together(&content, &info, traffic);
    }
    return content;
}

int get_network_receive() {
    int after[2] = {0, 0};
    int before[2] = {0, 0};

    get_network_data(before);
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    get_network_data(after);
    int sub = after[0] - before[0];
    float res = (int)(sub * 100 + .5);
    return res / 100;
}

int get_network_send() {
    int after[2] = {0, 0};
    int before[2] = {0, 0};

    get_network_data(before);
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    get_network_data(after);
    int sub = after[1] - before[1];
    float res = (int)(sub * 100 + .5);
    return res / 100;
}
