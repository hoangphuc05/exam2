#ifndef _TENNIS_EVENT_H_
#define _TENNIS_EVENT_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Event.h"
#include "TennisTicket.h"

// FIXME 2: Create BaseballEvent and BaseballTicket to for good baseball games!
// FIXME 2a: Create a function stretch so that the attendees can stand up an stretch for the 7th inning
// FIXME 3: Update EventFactory::factory() to allow it to be the ONLY method for creating a BaseballEvent
/**
* BaseballEvent is derived from Event
*/
class TennisEvent : public Event
{
private:
	std::list<std::string> stadium;
	std::string homeTeam;
	std::string visitingTeam;

	TennisEvent(std::string home, std::string visiting) {
		homeTeam = home;
		visitingTeam = visiting;
	}

	friend class EventFactory;

public:

	/**
	* Add a person to the event
	* @param name the name of the event goer
	*/
	EventTicket * add(std::string name) {
		

		stadium.push_front(name);

		return new TennisTicket(this, stadium.begin());

	}

	/**
	* Show the event's home team and visiting team, then list all the persons currently in the event
	*/
	void list() {
		// FIXME 1c: Show the event's home team and visiting team, then iterate through all the persons here.
		std::cout << "The home team from: " << homeTeam << std::endl;
		std::cout << "The visiting team from: " << visitingTeam << std::endl;
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
	 * Have tennis attendees cheer
	 */
	void cheer() {
		for (std::list<std::string>::iterator i = stadium.begin(); i != stadium.end(); i++) {
			std::cout << '\t' << *i << " clap as the the team score." << std::endl;
		}
	}
};

#endif