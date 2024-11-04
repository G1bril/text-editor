#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

// TextEditor class handles file operations like opening, editing, and displaying contents
class TextEditor
{
private:
    std::filesystem::path filepath; // Store the file path
    std::ifstream openedFile;       // Stream to read the file
    std::vector<std::string> lines; // Stores the lines of the file content

public:
    TextEditor();                   // Default constructor
    void openFile(const std::string &fileName); // Opens a file and reads content into `lines`
    void editFile(const std::string &fileName); // Allows modification of a specific line
    void displayMenu();              // Displays the main menu for user interaction
};

#endif // TEXTEDITOR_H
