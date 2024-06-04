#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

void compute();
void write(const int* data);
void read(int* data);
void save();
void load();f
void display();
void input();

int ram_data[8] = {0};
void compute() {
    int sum = 0;
    for (int i = 0; i < 8; ++i) {
        sum += ram_data[i];
    }
    std::cout << "сумма: " << sum << std::endl;
}
void write(const int* data) {
    for (int i = 0; i < 8; ++i) {
        ram_data[i] = data[i];
    }
}
void read(int* data) {
    for (int i = 0; i < 8; ++i) {
        data[i] = ram_data[i];
    }
}
void save() {
    std::ofstream file("data.txt");
    if (file.is_open()) {
        for (int i = 0; i < 8; ++i) {
            file << ram_data[i] << " ";    
        }
        file.close();
        std::cout << "данные сохранены в data.txt\n";
    } else {
        std::cout << "ошибка сохранения в data.txt\n";
    }
}
void load() {
    std::ifstream file("data.txt");
    if (file.is_open()) {
        for (int i = 0; i < 8; ++i) {
            file >> ram_data[i];
        }
        file.close();
        std::cout << "данные загружены из data.txt\n";
    } else {
        std::cout << "лшибка загрузки из data.txt\n";
    } 
}
void display() {
    for (int i = 0; i < 8; ++i) {
        std::cout << ram_data[i] << " ";
    }
    std::cout << std::endl;
}
void input() {
    std::cout << "введите 8 чисел: ";
    for (int i = 0; i < 8; ++i) {
        std::cin >> ram_data[i];
    }
}

int main() {
    while (true) {
        std::string command;
        std::cout << "введите команду (sum, save, load, input, display, exit): ";
        std::cin >> command;

        if (command == "sum") {
            compute();
        } else if (command == "save") {
            save();
        } else if (command == "load") {
            load();
        } else if (command == "input") {
            input();
        } else if (command == "display") {
            display();
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "неизвестная команда!\n";
        }
    }

    return 0;
}