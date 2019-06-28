#ifndef _WORLDCUP_EVENT_H_
#define _WORLDCUP_EVENT_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Event.h"
#include "WorldcupTicket.h"

/**
* WorldcupEvent is derived from Event
*/
class WorldcupEvent : public Event
{
private:
	std::list<std::string> stadium; // Data structure for containing the event goers in this worldcup event
	std::string hometeam;
	std::string visitingteam;

	/**
	* Constructor for creating a WorldcupEvent
	*/
	WorldcupEvent(std::string home, std::string visiting) {
		/**
		 *  FIXME 1a:
		 *    store the home team and visiting team names
		 */
		hometeam = home;
		visitingteam = visiting;
	}

	friend class EventFactory;

public:

	/**
	* Add a person to the event
	* @param name the name of the event goer
	*/
	EventTicket * add(std::string name) {
		/**
		* FIXME 1b:
		*   Pseudo-code
		*    1. add name to the front of stadium
		*    2. get iterator to the front of the stadium (this points to the recently added event goer)
		*    3. create a new worldcup ticket (WorldcupTicket) with its constructor
		*            Pass to the constructor "this" event, and the iterator from step 2
		*    4. return this new event ticket 
		*/

		stadium.push_front(name);
		//stadium.begin();

		return new WorldcupTicket(this, stadium.begin());

	}

	/**
	* Show the event's home team and visiting team, then list all the persons currently in the event
	*/
	void list() {
		// FIXME 1c: Show the event's home team and visiting team, then iterate through all the persons here.
		std::cout << "The home team: " << hometeam << std::endl;
		std::cout << "The visiting team: " << visitingteam << std::endl;
		std::cout << "The list of people in the stadium: \n";
		std::list<std::string>::iterator iter = stadium.begin();
		while (iter != stadium.end()) {
			std::cout << *iter << std::endl;
			++iter;
		}
	}

	/**
	* Remove the person identified by the iterator from the event
	*/
	void remove(std::list<std::string>::iterator it) {
		//FIXME 1d: someone's getting out of hand. Ushers have asked them to leave.
		stadium.erase(it);

	}

	/**
	 * Have world cup attendees chant
	 */
	void chant() {
		for (std::list<std::string>::iterator i = stadium.begin(); i != stadium.end(); i++) {
			std::cout << '\t' << *i << " says 'boom boom clap!'" << std::endl;
		}
	}
};
#endif