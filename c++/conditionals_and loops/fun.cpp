#include <iostream>
#include <chrono>
#include <thread>

void printSlowWithDashes(const std::string& text, int delayMilliseconds) {
    for (char c : text) {
        std::cout << '-' << c << '-';
        std::cout.flush(); // Ensure character is printed immediately
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMilliseconds));
    }
    std::cout << std::endl;
}
void hacked(const char hack[11]){
    std::string text = std::string(hack) + " is hacked";
    int delay = 100; // Delay in milliseconds
    printSlowWithDashes(text, delay);
}

int main() {
    std::cout<<"Enter the company name:"<<std::endl;
    char hou[10];
    std::cin>>hou;
    hacked(hou);
}
