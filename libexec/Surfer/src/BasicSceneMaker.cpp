// Scene Maker

#include "SurferConsoleHeader.h"
#include "GetInputAs.hpp"

//Scene standards
std::string key;
std::string value;
// Scenes are Config files that tell the compiler the name of the project and all that good stuff : )
void CreateScene() {
    std::cout << "Making a new scene. . ." << std::endl;
    std::ofstream sc("project.surfer");
    sc << "# Generated by the 'Scene Generator'.\n# Copyright Kai-Builder 2021.\n# 2:20AM 2/27/20\n# Maybe edit these files using the given Interface. It works better.\n# If you're wondering, You can mark this file as .INI Config in your IDE.";
    sc.close();
    std::cout << "Created new Scene." << std::endl;
}
int main(int argc, char* argv[]) {
    try {
        std::string arg1(argv[1]);
        if (arg1 == "-c")
            CreateScene();
        else if (arg1 == "-help" || arg1 == "-h") {
            std::cout << "Help Menu" << std::endl;
            std::cout << "[-c] Create Scene" << std::endl;
            std::cout << "[-help | -h] Help Menu." << std::endl;
            std::cout << "[-load | -l] Load Scene" << std::endl;
        }
        else if (arg1 == "-load" || arg1 == "-l") {
            std::cout << "Choose a Scene to load" << std::endl;
            std::cout << ">";
            std::string scene;
            std::cin >> scene;
            std::ifstream scenefile(scene);
            if (!scenefile)
                std::cout << "Failed to load scene." << std::endl;
            std::cout << "Loading " << scene << ". . ." << std::endl;
            scenefile >> key;
            std::cout << "SceneName: " << key << std::endl;
            while (scenefile >> value) {
                std::cout << "Content Found. . " << value << std::endl;
            }
        }
    }
    catch (std::logic_error&) {
        std::cout << "Help Menu" << std::endl;
        std::cout << "[-c] Create Scene" << std::endl;
        std::cout << "[-help | -h] Help Menu." << std::endl;
    }
}