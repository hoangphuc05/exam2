#include "TennisTicket.h"
#include "TennisEvent.h"

/**
* Implements the leave method
*/
void TennisTicket::leave() {
	TennisEvent * actual_event = dynamic_cast<TennisEvent *>(the_event); // down-cast base class to derived class
	actual_event->remove(me); // call WorldcupEvent remove method to erase event goer identified by "me"
}