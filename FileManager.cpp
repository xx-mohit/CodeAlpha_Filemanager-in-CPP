#include "FileManager.h"

namespace fs = std::filesystem;

void FileManager::displayCurrentPath() {
    std::cout << "Current Path: " << fs::current_path() << std::endl;
}

void FileManager::listFiles() {
    for (const auto& entry : fs::directory_iterator(fs::current_path())) {
        std::cout << entry.path().filename() << (entry.is_directory() ? " [DIR]" : "") << std::endl;
    }
}

void FileManager::createDirectory(const std::string& dirName) {
    if (fs::create_directory(dirName)) {
        std::cout << "Directory created: " << dirName << std::endl;
    } else {
        std::cout << "Failed to create directory: " << dirName << std::endl;
    }
}

void FileManager::copyFile(const std::string& source, const std::string& destination) {
    try {
        fs::copy(source, destination);
        std::cout << "File copied from " << source << " to " << destination << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cout << "Error copying file: " << e.what() << std::endl;
    }
}

void FileManager::moveFile(const std::string& source, const std::string& destination) {
    try {
        fs::rename(source, destination);
        std::cout << "File moved from " << source << " to " << destination << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cout << "Error moving file: " << e.what() << std::endl;
    }
}

void FileManager::changeDirectory(const std::string& newPath) {
    try {
        fs::current_path(newPath);
        std::cout << "Changed directory to: " << fs::current_path() << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cout << "Error changing directory: " << e.what() << std::endl;
    }
}
