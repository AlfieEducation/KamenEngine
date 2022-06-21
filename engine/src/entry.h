#pragma once

#include "core/application.h"
#include "core/logger.h"
#include "game_types.h"

// Externally_defined function to create a game.
extern b8 create_game(game* out_game);

// The main entry point of the application
int main(void) {

    // Requst the game instance from the application
    game game_inst;
    if (!create_game(&game_inst)) {
        KFATAL("Could not create game!");
        return -1;
    }

    // Ensdure the function pointers are exist
    if (!game_inst.render || !game_inst.update || !game_inst.initialize || !game_inst.on_resize) {
        KFATAL("The game's function pointers must be assigned");
        return -2;
    }


    if (!application_create(&game_inst))  {
        KINFO("Application failed to create!");
        return 1;
    }

    // Begin the game loop
    if (!application_run())  {
        KINFO("Application didn't shutdown gracefully");
        return 2;
    }
    
    return 0;
}