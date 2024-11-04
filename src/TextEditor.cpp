#include "../include/TextEditor.h"

// Constructor to initialize member variables if needed
TextEditor::TextEditor() = default;

// Method to open the file
void TextEditor::openFile(const std::string &fileName)
{
    // Clear lines on each openFile call to avoid stacking read and edited content
    lines.clear();

    /* Set the filepath member variable.
       This might not be the ideal approach long-term. */
    filepath = fileName;

    // Attempt to open the file
    openedFile.open(fileName);

    // Check if the file opened successfully
    if (!openedFile.is_open())
    {
        std::cerr << "File not found" << std::endl;
        return;
    }

    // Check for supported file extensions
    else if (!(filepath.extension() == ".txt" || filepath.extension() == ".md" ||
               filepath.extension() == ".csv" || filepath.extension() == ".json" ||
               filepath.extension() == ".xml" || filepath.extension() == ".html" ||
               filepath.extension() == ".log"))
    {
        std::cerr << "Unsupported file extension" << std::endl;
        openedFile.close();
        return;
    }
    else
    {
        // Read the file content into the `lines` vector
        std::string buffer;
        while (std::getline(openedFile, buffer))
        {
            lines.push_back(buffer);
        }
        openedFile.close(); // Close the file after reading

        /* Print the lines read from the file.
           Here, `size_t` is generally better for indexes in loops */
        for (size_t i = 0; i < lines.size(); i++)
        {
            std::cout << i + 1 << ". " << lines[i] << std::endl; // Print line with a 1-based index
        }
        std::cout << "File successfully closed" << std::endl;
    }
}

void TextEditor::editFile(const std::string &fileName) {
    // Open the file and load its content into lines
    openFile(fileName);

    // Prompt for line number and new content
    int selectedLine;
    std::string editBuffer;
    bool proceed = false;

    do {
        std::cout << "Choose a line to modify (1 - " << lines.size() << "): ";
        std::cin >> selectedLine;

        // Clear newline from the input buffer
        std::cin.ignore();
        
        // Validate selected line number
        if (selectedLine < 1 || selectedLine > lines.size()) {
            std::cerr << "Invalid line number. Please try again." << std::endl;
            continue; // Restart the loop
        }

        std::cout << "Enter your modification: ";
        std::getline(std::cin, editBuffer);

        // Update the selected line
        lines[selectedLine - 1] = editBuffer;

        // Write modified content back to the file
        std::ofstream file(fileName, std::ios::trunc); // Truncate the file to replace content
        for (const auto &line : lines) {
            file << line << std::endl;
        }

        std::cout << "Do you wish to modify another line? [Y/n]: ";
        std::string input;
        std::cin >> input;

        if (input == "Y" || input == "y") {
            proceed = true;  // Proceed
        } else if (input == "N" || input == "n") {
            proceed = false; // Do not proceed
        } else {
            std::cerr << "Invalid input. Please enter 'Y' or 'n'." << std::endl;
            continue; // restarts loop
        }

    } while (proceed);

    std::cout << "File successfully updated and saved." << std::endl;
}


void TextEditor::displayMenu()
{
    int choice; // Move choice declaration outside the loop
    do
    {
        std::string fileName;
        std::cout << "----- Menu -----" << std::endl;
        std::cout << "1. Read File" << std::endl;
        std::cout << "2. Edit File" << std::endl;
        std::cout << "3. Delete File" << std::endl;
        std::cout << "4. Write file" << std::endl;
        std::cout << "5. Exit Program" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 4)
        {
            std::cout << "Please type file name: ";
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
            std::cerr << "Invalid option" << std::endl;
            break;
        }
    } while (choice != 5);
}
