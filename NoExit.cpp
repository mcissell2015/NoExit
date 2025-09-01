#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

int main() {
    // Create 100 files
    for (int i = 0; i < 100; ++i) {
        std::string filename = "file" + std::to_string(i) + ".txt";
        std::ofstream outfile(filename);
        if (outfile.is_open()) {
            outfile << "This is file " << i << std::endl;
            outfile.close();
        } else {
            std::cerr << "Unable to create file: " << filename << std::endl;
        }
    }

    // Change username and password (Note: This is a simplified example and doesn't actually change system settings)
    std::cout << "Attempting to change username to NO EXIT and password to MY COMPUTER..." << std::endl;

    // Set theme to red (Note: This is a placeholder as setting the theme requires OS-specific code)
    std::cout << "Attempting to set theme to red..." << std::endl;

    // Schedule shutdown (Note: This requires admin privileges and is OS-specific)
    std::cout << "Scheduling shutdown..." << std::endl;
    std::time_t shutdown_time = std::time(nullptr) + 5; // Shutdown in 5 seconds
    std::tm* timeinfo = std::localtime(&shutdown_time);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    std::string shutdown_command = "shutdown /s /t 5 /c \"System will shut down shortly.\"";
    int result = std::system(shutdown_command.c_str());
    if (result != 0) {
          std::cerr << "Shutdown failed." << std::endl;
    }


    return 0;
}