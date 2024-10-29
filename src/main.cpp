#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

class TextEditor
{
public:
    void OpenFile(std::string filename)
    {
        // creates two objects for the filepath and the currently opened file
        std::filesystem::path filepath(filename);
        std::ifstream openedFile(filename);
        // checks if the file name is correct
        if (!openedFile.is_open())
        {
            std::cerr << "Failed to open the file" << std::endl;
        }
        // check file extension. Can be done in a little less lazy way.
        else if (!(filepath.extension() == ".txt" || filepath.extension() == ".md" ||
                   filepath.extension() == ".csv" || filepath.extension() == ".json" ||
                   filepath.extension() == ".xml" || filepath.extension() == ".html" ||
                   filepath.extension() == ".log"))
        {
            std::cout << "Unsupported file extension" << std::endl;
        }

        else
        {
            // open file and copy it's content into a vector
            std::vector<std::string> lines;
            std::string buffer; // super cool variable name that makes me look like a cool cpp prgmer
            while (std::getline(openedFile, buffer))
            {
                lines.push_back(buffer);
            }
            openedFile.close();
            // Print vector elements using a loop
            for (int i = 0; i < lines.size(); i++)
            {
                std::cout << i << ". " << lines[i] << std::endl;
            }
            openedFile.close();
            std::cout << "File Successfully closed" << std::endl;
        }

        /*openedFile >> fileData;
        std::cout << fileData;*/
    }
}

;

int main()
{
    TextEditor text;
    std::string filename;
    std::cout << "Please type file name: " << std::endl;
    std::cin >> filename;
    std::cout << "Your file name is: " << filename << std::endl; // debug purpose
    text.OpenFile(filename);
    return 0;
}