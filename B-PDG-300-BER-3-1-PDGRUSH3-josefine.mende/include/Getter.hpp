#ifndef _GETTER_HPP
    #define _GETTER_HPP

#include <iostream>
#include <unistd.h>
#include <climits>
#include <sys/utsname.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <fstream>
#include <utility>
#include <vector>
#include <sstream>
#include <cmath>

//Tools
std::string remove_additional_spaces(std::string content);
std::vector<int> add_together(std::string content);
std::string get_content(int n);

//Network
int get_network_receive();
int get_network_send();

//RAM
float get_ram_free();
float get_ram_av();

//CPU
std::string get_cpu_freq(int n);
std::string get_cpu_model();
double get_cpu_usage(int n);
unsigned int get_core_amount();

//System
char *get_time();
struct utsname *get_os();
char *get_hostname();
char *get_username();

#endif