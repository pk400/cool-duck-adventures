// Settings hold data that allow for easy configuration to the game without
// having to recompile the game everytime a change is needed.

struct Settings {
	// Determines whether a debug version of the game needs to be run
	bool debug;

	// Defines game name
	string title;

	// Defines game screen dimensions
	int width;
	int height;

	// Defines game frame rate
	int frame_rate;

	// Defines game vertical sync
	bool vertical_sync;
};