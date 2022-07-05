#include "Getter.hpp"

char *get_hostname() {
    char *hostname = new char[HOST_NAME_MAX];

    if (gethostname(hostname, HOST_NAME_MAX) == 0)
        return hostname;
    return nullptr;
}

char *get_username() {
    char *username = new char[LOGIN_NAME_MAX];

    if (getlogin_r(username, LOGIN_NAME_MAX) == 0)
        return username;
    return nullptr;
}

struct utsname *get_os() {
    auto *name = new struct utsname;
    if (uname(name) < 0)
        return nullptr;

    return name;
}

char *get_time() {
    std::time_t t = std::time(nullptr);
    return std::asctime(std::localtime(&t));
}
