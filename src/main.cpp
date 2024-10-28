#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class TextEditor {
    public:
    void OpenFile(std::string filename){
        std::ifstream myfile (filename);
        if (!myfile.is_open()) {
            std::cout << "Failed to open the file" << std::endl;
        }
        
        else {
            std::string mystring;   
            myfile >> mystring;
            std::cout << mystring;
        }
    }

};

int main(){
    TextEditor text;
    std::string filename;
    std::cout << "Please type file name: " << std::endl;
    std::cin >> filename;
    std::cout << filename << std::endl;
    text.OpenFile(filename);
}