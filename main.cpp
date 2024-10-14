#include "FileManager.h"

int main() {
    FileManager fileManager;
    std::string command;

    while (true) {
        fileManager.displayCurrentPath();
        fileManager.listFiles();

        std::cout << "Enter command (cd, mkdir, cp, mv, exit): ";
        std::cin >> command;

        if (command == "cd") {
            std::string newPath;
            std::cout << "Enter new path: ";
            std::cin >> newPath;
            fileManager.changeDirectory(newPath);
        } else if (command == "mkdir") {
            std::string dirName;
            std::cout << "Enter directory name: ";
            std::cin >> dirName;
            fileManager.createDirectory(dirName);
        } else if (command == "cp") {
            std::string source, destination;
            std::cout << "Enter source file: ";
            std::cin >> source;
            std::cout << "Enter destination file: ";
            std::cin >> destination;
            fileManager.copyFile(source, destination);
        } else if (command == "mv") {
            std::string source, destination;
            std::cout << "Enter source file: ";
            std::cin >> source;
            std::cout << "Enter destination file: ";
            std::cin >> destination;
            fileManager.moveFile(source, destination);
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command!" << std::endl;
        }
    }

    return 0;
}
