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

#include <stdlib.h>
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
	int link_count;
	int room_type; //0 for start, 1 for middle, and 2 for end
};

struct forest{
	struct room rooms[7]; //7 rooms 
	int curr_name_list[7]; // seven names from the origonal list
};

//Helper variables

int current_room;
int next_room;
int last_room = 0; //look in init_rooms. This needs to happen
int link_index;

/***************************************************
 * Room creation functions
 * ************************************************/


//This will assign all of the rooms names (as 
//signified by a number from 1-10) and link each room
//to each other so the whole graph of the maze is 
//connected
void _init_rooms( struct forest* the_forest ){

	srand(time(NULL));

	int i; //counter
	for ( i = 0; i < 7; i++){
		
		current_room = (rand()%10) + 1 ; //gives range from 1-10

		//assign it to the list of names
		(*the_forest).curr_name_list[i] = current_room;
		(*the_forest).rooms[i].name = current_room;

		//if there was an instance of the last room,
		//this will set the backwards connection to it
		if (last_room == 0){
			link_index = (*the_forest).rooms[i].link_count;
			(*the_forest).rooms[i].connections[ link_index ] = last_room;
			(*the_forest).rooms[i].link_count++;
		}


		//adds the next room as a connection to the current room
		next_room = (rand()%10) + 1 ;
		link_index = (*the_forest).rooms[i].link_count;
		(*the_forest).rooms[i].connections[ link_index ] = next_room;
		(*the_forest).rooms[i].link_count++;

		//sets the last room to the current room
		last_room = current_room;
	}

}


//this will give each of the rooms all of the connections
//specified (between 3-6 per room) and will need to link
//back to the origonal room (room A will connect to room B
//and vice versa)
//
void _finalize_connections( struct forest* the_forest ){


}

//This will give each of the rooms in the forest a room
//type from 0,1,2
//
//	0 == START_ROOM
// 1 == MID_ROOM
// 2 == END_ROOM
void _add_room_type( struct forest* the_forest ){

}


//This will
//
//1. create a directory
//
//2. for every room
//	a. make a file
//	b. match the corresponding number to 
//		the name
//	c. print to file
//	d. close that file
//

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
