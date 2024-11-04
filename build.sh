#using a shell script because i'm too lazy to do otherwise for now
#uses -g flag for debugging purpose
#!/bin/bash
g++ -g -std=c++17 -Iinclude src/main.cpp src/TextEditor.cpp -o build/text_editor
echo "Build complete. Run the program with ./build/text_editor"
    