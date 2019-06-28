#include "WorldcupTicket.h"
#include "WorldcupEvent.h"

/**
* Implements the leave method
*/
void WorldcupTicket::leave() {
	WorldcupEvent * actual_event = dynamic_cast<WorldcupEvent *>(the_event); // down-cast base class to derived class
	actual_event->remove(me); // call WorldcupEvent remove method to erase event goer identified by "me"
}