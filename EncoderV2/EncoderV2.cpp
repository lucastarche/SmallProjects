//tarche did dis shit
#include <iostream>
#include <fstream>
#include <random>

const int BUFSIZE = 1024 * 1024;
std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<> distrib(0, 255);

void encode(char* text, char* key, char* out, int amount) {
    for (int i = 0; i < amount; i++) {
        out[i] = text[i] ^ key[i];
    }
}

void generateKey(char* key, int size) {
    for (int i = 0; i < size; i++) {
        key[i] = (char)distrib(mt);
    }
}

int main() {
    char keyAns;
    std::string file, key, out;

    std::cout << "File encoder\nInsert input file with extension: ";
    std::cin >> file;
    std::cout << "Do you have a key? (Y/N) ";
    std::cin >> keyAns;

    bool hasKey = (keyAns == 'Y' || keyAns == 'y');

    std::cout << "Enter the key " << ((hasKey) ? "input" : "output") << " file with extension: ";
    std::cin >> key;

    std::cout << "Enter encoded output file: ";
    std::cin >> out;

    std::ifstream textIn(file, std::ios::binary);
    std::ofstream textOut(out, std::ios::binary);

    if (!textIn.is_open()) {
        std::cerr << "There was an error opening the input file\n";
        return 1;
    }
    else if (!textOut.is_open()) {
        std::cerr << "There was an error opening the output file\n";
        return 1;
    }

    char textStr[BUFSIZE] = {0}, keyStr[BUFSIZE] = {0}, outStr[BUFSIZE] = {0};

    if (hasKey) {
        std::ifstream keyIn(key, std::ios::binary);
        
        if (!keyIn.is_open()) {
            std::cerr << "There was an error opening the key input file\n";
            return 1;
        }

        while (!(textIn.eof() && keyIn.eof())) {
            textIn.read(textStr, BUFSIZE);
            keyIn.read(keyStr, BUFSIZE);
            int count = textIn.gcount();

            encode(textStr, keyStr, outStr, count);
            textOut.write(outStr, count);
        }
    }
    else {
        std::ofstream keyOut(key, std::ios::binary);
        
        if (!keyOut.is_open()) {
            std::cerr << "There was an error opening the key input file\n";
            return 1;
        }

        while (!textIn.eof()) {
            textIn.read(textStr, BUFSIZE);
            int count = textIn.gcount();

            generateKey(keyStr, count);
            encode(textStr, keyStr, outStr, count);

            textOut.write(outStr, count);
            keyOut.write(keyStr, count);
        }
    }
}
