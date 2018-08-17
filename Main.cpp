#include "src/Game.hpp"
#include "src/tinytoml/toml.h"
#include <fstream>
#include <unistd.h>
#include <cstdlib>

// std::addressof
#include <memory>

Settings parse_config(std::string file_path) {
	// Read settings from configuration file.
	// File location is relative to the location of the binary after
	// running make.
	std::ifstream settings_file(file_path);
	if(!settings_file.good()) {
		std::cout << "Error opening file!" << std::endl;
		exit(EXIT_FAILURE);
	}

	toml::ParseResult pr = toml::parse(settings_file);
	if (!pr.valid()) {
	    std::cout << pr.errorReason << std::endl;
	    exit(EXIT_FAILURE);
	}

	const toml::Value& config_data = pr.value;

	Settings settings = {
		(config_data.find("game.debug"))->as<bool>(),
		(config_data.find("game.title"))->as<string>(),
		(config_data.find("game.width"))->as<int>(),
		(config_data.find("game.height"))->as<int>(),
		(config_data.find("game.frame_rate"))->as<int>(),
		(config_data.find("game.vertical_sync"))->as<bool>()
	};

	return settings;
}

// Main entry-point to initialize game and load settings.
int main() {
	Settings settings = parse_config("../config.toml");

	int term_code = 0;

	// Initialize game variables with setting variables
    Game game(settings);

    // Setup screen with values from settings
    if(game.setupWindow() == 1 && term_code == 1){
    	std::cout << "Window setup error" << std::endl;
    }

    game.setupGSM();

    return game.gameRun();
}
