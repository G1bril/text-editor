#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

class TextEditor
{
private:
    std::filesystem::path filepath; // Store the file path
    std::ifstream openedFile;       // File stream
    std::vector<std::string> lines; // Store the file content lines

public:
    // Constructor to initialize member variables if needed
    TextEditor() = default;

    // Method to open the file
    void openFile(const std::string &fileName)
    {
        // clear lines each openFile calls
        lines.clear();
        /* Set the filepath member variable
        not a good way to do so */
        filepath = fileName;

        // Attempt to open the file
        openedFile.open(fileName);

        // Check if the file name is correct
        if (!openedFile.is_open())
        {
            std::cerr << "File not found" << std::endl;
            return;
        }

        // Check file extension
        else if (!(filepath.extension() == ".txt" || filepath.extension() == ".md" ||
                   filepath.extension() == ".csv" || filepath.extension() == ".json" ||
                   filepath.extension() == ".xml" || filepath.extension() == ".html" ||
                   filepath.extension() == ".log"))
        {
            std::cout << "Unsupported file extension" << std::endl;
            openedFile.close();
            return;
        }
        else
        {
            // Read the file content into the vector
            std::string buffer;
            while (std::getline(openedFile, buffer))
            {
                lines.push_back(buffer);
            }
            openedFile.close(); // Close the file after reading

            /* Print the lines read from the file.
            still not sure why size_t is better*/
            for (size_t i = 0; i < lines.size(); i++)
            {
                // i+1 cuz line 0 doesn't exist
                std::cout << i + 1 << ". " << lines[i] << std::endl;
            }
            std::cout << "File successfully closed" << std::endl;
        }
    }

    void editFile(const std::string &fileName)
    {
        // Open the file and load its content into lines
        openFile(fileName);

        // Get line number to modify and new content from the user
        int selectedLine;
        std::string editBuffer;

        std::cout << "Choose a line to modify (1 - " << lines.size() << "): ";
        std::cin >> selectedLine;

        // Ensure line number is valid
        // if (selectedLine < 1 || selectedLine > lines.size()) {
        //    std::cerr << "Invalid line number." << std::endl;
        //    return;
        //}

        std::cin.ignore(); // Clear newline from input buffer
        std::cout << "Enter your modification: ";
        std::getline(std::cin, editBuffer);

        // Update the selected line
        lines[selectedLine - 1] = editBuffer;

        // Write modified content back to the file
        std::ofstream file(fileName, std::ios::trunc); // Truncate file to replace content
        for (const auto &line : lines)
        {
            file << line << std::endl;
        }

        file.close();
        std::cout << "File successfully updated and saved." << std::endl;
    }

    void displayMenu()
    {
        int choice; // Move choice declaration outside the loop
        do
        {
            std::string fileName; // Keep fileName declaration here
            std::cout << "----- Menu -----" << std::endl;
            std::cout << "1. Read File" << std::endl;
            std::cout << "2. Edit File" << std::endl;
            std::cout << "3. Delete File" << std::endl;
            std::cout << "4. Other" << std::endl;
            std::cout << "5. Exit Program" << std::endl;
            std::cout << "Choisissez une option: ";
            std::cin >> choice;

            if (choice >= 1 && choice <= 4)
            {
                std::cout << "Please type file name: " << std::endl;
                std::cin >> fileName;
                std::cout << "Your file name is: " << fileName << std::endl; // Debug purpose
            }

            switch (choice)
            {
            case 1:
                openFile(fileName);
                break;
            case 2:
                editFile(fileName);
                break;
            case 3:
                std::cout << "This functionality is in development" << std::endl;
                break;
            case 4:
                std::cout << "This functionality is in development" << std::endl;
                break;
            case 5:
                std::cout << "See you later!" << std::endl;
                break;
            default:
            std::cin.clear();
            std::cin.ignore();
                std::cout << "Invalid option" << std::endl;
                break;
            }
        } while (choice != 5);
    }
};

int main()
{
    TextEditor textFile; // Creates a textFile Object
    textFile.displayMenu();
    return 0;
}
