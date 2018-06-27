#include "src/Game.hpp"

int main() {
    int game_width = 800;
    int game_height = 480;
    std::string game_title = "Sprout";

    Game game(game_width, game_height, game_title);

    return game.gameRun();
}
