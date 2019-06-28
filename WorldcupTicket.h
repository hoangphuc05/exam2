#ifndef _WORLDCUP_TICKET_H_
#define _WORLDCUP_TICKET_H_

#include <list>
#include <string>
#include "Event.h"
#include "EventTicket.h"

class WorldcupTicket : public EventTicket
{
private:
	Event * the_event; // the event this ticket is associated with
	std::list<std::string>::iterator me; // an iterator containing the event goer this ticket is associated with

public:

	/**
	* Constructor for creating a WorldcupTicket.  
	* @param the_event	event to which this ticket belongs
	* @param me			event goer to which this ticket is associated with
	*/
	WorldcupTicket(Event* the_event, const std::list<std::string>::iterator &me) :
		the_event(the_event), me(me) {}

	/**
	* Allows the event goer, "me", to leave the event, "the_event"
	* The implementation for this is in WorldcupTicket.cpp
	*/
	void leave();
};

#endif