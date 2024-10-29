#using a shell script because i'm too lazy to do otherwise for now
#!/bin/bash
g++ -std=c++17 src/main.cpp -o build/text_editor
echo "Build complete. Run the program with ./build/text_editor"
    