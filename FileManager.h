#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <iostream>
#include <filesystem>
#include <string>

class FileManager {
public:
    void displayCurrentPath();
    void listFiles();
    void createDirectory(const std::string& dirName);
    void copyFile(const std::string& source, const std::string& destination);
    void moveFile(const std::string& source, const std::string& destination);
    void changeDirectory(const std::string& newPath);
};

#endif // FILE_MANAGER_H
