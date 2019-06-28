#ifndef _EVENT_FACTORY_H_
#define _EVENT_FACTORY_H_

#include <stdexcept>
#include <string>
#include "BaseballEvent.h"
#include "WorldcupEvent.h"
#include "TennisEvent.h"

/**
* The Event Factory
* This class is used for making events!
*/
class EventFactory
{
public:

	/**
	* The factory method is the only way of making an event
	* Please see the main() function to understand how it works!
	*/
	static Event *factory(std::string type, std::string hometeam, std::string visitingteam) {
		if (type == "worldcup") {
			return new WorldcupEvent(hometeam, visitingteam); // Creates a worldcup match
		} 
		else if (type == "baseball") { // Creates a baseball game
			return new BaseballEvent(hometeam, visitingteam);
		} 
		else if (type == "tennis") { //create a tennis match
			return new TennisEvent(hometeam, visitingteam);
		}
		else
			throw std::invalid_argument("unknown type of event");
	}
};
#endif