#include "BaseballTicket.h"
#include "BaseballEvent.h"

/**
* Implements the leave method
*/
void BaseballTicket::leave() {
	// FIXME 4: Implement leave for baseball games
	BaseballEvent * actual_event = dynamic_cast<BaseballEvent *>(the_event); // down-cast base class to derived class
	actual_event->remove(me); // call BaseballEvent remove method to erase event goer identified by "me"
}