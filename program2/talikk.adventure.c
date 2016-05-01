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


		//For the last room, it will not make a new connection
		if (i != 6){
			//adds the next room as a connection to the current room
			next_room = (rand()%10) + 1 ;
			link_index = (*the_forest).rooms[i].link_count;
			(*the_forest).rooms[i].connections[ link_index ] = next_room;
			(*the_forest).rooms[i].link_count++;

			//sets the last room to the current room
			last_room = current_room;
		}
	}

}


//this will give each of the rooms all of the connections
//specified (between 3-6 per room) and will need to link
//back to the origonal room (room A will connect to room B
//and vice versa)
//
void _finalize_connections( struct forest* the_forest ){

	int i;
	int numRooms = sizeof( (*the_forest).curr_room_list ) / sizeof( int) 
	struct room* roomTeemp;	
	int viableRooms[ 7 ]; //max numbers of rooms
   int k= 0; //an index for the viable rooms
	int j = 0; //counter for second loop
	int m = 0; //yet another counter...
	int n = 0;
	int marker; //marks to see if there is a choice int a loop


	//For each of the rooms, we will see if we need to 
	//add more connections (We need 3-6 randomly between
	//each room)
	for( i = 0; i < numRooms; i++){

		roomTemp = (*the_forest).rooms[ i ];


		
		if( (*roomTemp).link_count < 3 ){ //we need to add more connections

			//Creating a list of connections
			//we will use this as an iterator when connecting the rooms
			srand(time(NULL));
			int newConnections =( rand() % 6 ) + 4  //range from 3-6 I PRESUME
			newConnections = newConnections - (*roomTemp).link_count;

			//make a list of names (represented by numbers) to represent
			// a collection of viable rooms
			// rooms that have == 6 are not viable
			//rooms that have already been connected to the room are not viable
			
				for ( n = 0; n < numRooms; n++){
					int roomNameTemp = (*the_forest).curr_name_list[ n ]

					for( m = 0; m < (*roomTemp).link_count; m++){

						if ( (*roomTemp).connections[ m ] == roomNameTemp ){
							break;
						}
							
						if( (*the_forest).rooms[ roomNameTemp  ].link_count != 6 ){
							viableRooms[ k ] = roomNameTemp;
							k++;
						}	
					} 
				}

			//Now comes the actual linking
			//DONT GO OUT OF RANGE ON THE VIABLE ROom array
			//the loop limit is whatever is smaller; the
			//size of viableRoom array or the #of connections we need to add
			

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
