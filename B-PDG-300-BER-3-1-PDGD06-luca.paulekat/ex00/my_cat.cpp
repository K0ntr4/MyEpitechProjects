#include <string>
#include <iostream>
#include <vector>
#include <fstream>

void my_read_file(std::ifstream& fs) {
    std::string content;

    while ( !fs.eof() ) {
        std::getline(fs, content);
        std::cout << content;
        if ( !fs.eof() )
            std::cout << std::endl;
    }
    fs.close();
}

int main(int argc, char **argv) {
    std::vector<std::string> files = {};
    std::ifstream fs;

    if (argc == 1)
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
    for (int i = 1; argv[i] != NULL; i++) {
        files.push_back(argv[i]);
    }
    for (int i = 0; i < argc - 1; i++) {
        fs.open(files[i]);
        if(!fs)
            std::cerr << "my_cat: " << files[i] << ": No such file or directory" << std::endl;
        else
            my_read_file(fs);
    }
    std::cout << std::endl;
    return 0;
}