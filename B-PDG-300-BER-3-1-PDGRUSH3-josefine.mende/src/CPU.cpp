#include "Getter.hpp"

static double calc_result(std::string content_before, std::string content_after) {
    std::vector<int> before = add_together(std::move(content_before));
    std::vector<int> after = add_together(std::move(content_after));

    int total = after[0] - before[0];
    int work = after[1] - before[1];
    float res = (int)((((float)work / (float)total) * 100) * 100 + .5);
    return ((float)res / 100);
}

unsigned int get_core_amount() {
    const auto n = std::thread::hardware_concurrency();
    return n;
}

double get_cpu_usage(int n) {
    std::string content_before = get_content(n);
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    std::string content_after = get_content(n);
    return calc_result(content_before, content_after);
}

std::string get_cpu_model() {
    std::ifstream info("/proc/cpuinfo");
    std::string content;

    for (int i = 0; i <= 4; i++)
        std::getline(info, content);
    content.replace(0, 13, "");
    return content;
}

std::string get_cpu_freq(int n) {
    std::ifstream info("/proc/cpuinfo");
    std::string content;

    for (int i = 0; i < 28 * n + 8; i++)
        std::getline(info, content);
    content.replace(0, 11, "");
    return content;
}