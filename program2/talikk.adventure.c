/* Program 2: Adventure
 * Kevin Talik, 931 835 689
 * CS 344, Operating systems
 * Ben Brewster
 *
 * Spring 2016, April 29th
 *
 */

// Program 2 is supposed to make a series of rooms
// for usage in a maze, then, will supply the user
// with an interface to navagiate this maze
//
// This is split into three notable sections:
//
// 1. The room creation process
// 2. The interface
// 3. main()

#include <stdio.h>
#include <time.h>


/************************************************
 * 				Room Creation process
 * 				Section 1
 *
 * 	This will first, create the necessary structs
 * 	for the rooms. This will include:
 *
 * 		A forest struct to maintain a collection of
 * 	all of the rooms, a anme list of all available
 * 	room names, and a current name list of all of 
 * 	the rooms we are using
 *
 * 		A room struct that will simulate a whole room.
 * 	It will contain a name, connections[3-6], a count of connections
 * 	and a room type
 *
 * 	Then, it will finalize the connections, add the
 * 	room type, then it will print each room to a file
 * 	so that the interface can access them and play
 * 	the game
 *
 *		
 *		It should be noted that the room names will be 
 *		substituted with some numbers instead of their
 *		actual name. once they are printed to the file, 
 *		the program will replace all the numbers wiht 
 *		their real name.
 *
 * **********************************************/

struct room{
	int name; //Names will be substituted with numbers
	int connections[6]; //3-6 by the end of creation
	int connection_count;
	int room_type; //0 for start, 1 for middle, and 2 for end
};

struct forest{
	struct room rooms[7]; //7 rooms 
	int curr_name_list[7]; // seven names from the origonal list
};

//Helper variables

char* current_room;
char* next_room;
char* last_room;

//constructor functions for the rooms
//

void _init_rooms( struct forest* the_forest ){

}

void _finalize_connections( struct forest* the_forest ){


}

void _add_room_type( struct forest* the_forest ){

}

void _print_room_files( struct forest* the_forest ){
	
}



void _create_room_files(){

	struct forest the_forest;

	_init_rooms( &the_forest );

	_finalize_connections( &the_forest );

	_add_room_type( &the_forest );

	_print_room_files( &the_forest );


};






int main(){

	_create_room_files();


return 0;
}
