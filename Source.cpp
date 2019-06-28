/**
* CS-273 Exam 2 Summer 2018
* Who doesn't like sports ?!
*
* @authors Everyone!
*/

//Code by Phuc Cai
#include <iostream>
#include <string>
#include <typeinfo>
#include "Event.h"
#include "EventTicket.h"
#include "EventFactory.h"

using std::cout;
using std::endl;

const int EVENT_COUNT = 3;

int main()
{
	// FIXME 5: Create a third kind of event, and test it 

	Event* events[EVENT_COUNT]; //Create a worldcup match and a baseball game
	events[0] = EventFactory::factory("worldcup", "germany", "mexico"); // Create a worldcup match with the event factory
	events[1] = EventFactory::factory("baseball", "everett", "spokane");
	events[2] = EventFactory::factory("tennis", "Vietnam", "China");
	//FIXME 5a: generate an event object for your new kind of event


	//Let's go through and test each one
	for (int i=0; i<EVENT_COUNT; i++) {
		// Let's add a couple of people to the match, and store their tickets in variables
		EventTicket *ticket1 = events[i]->add("Mike");
		EventTicket *ticket2 = events[i]->add("Jane");
		EventTicket *ticket3 = events[i]->add("Antonio");
		EventTicket *ticket4 = events[i]->add("Sue");

		cout << "Event before Jane leaves\n";
		events[i]->list(); // List the people currently at the event

		

		if (typeid(WorldcupEvent) == typeid(*events[i]))
			dynamic_cast<WorldcupEvent*>(events[i])->chant();
		if (typeid(BaseballEvent) == typeid(*events[i]))
			dynamic_cast<BaseballEvent*>(events[i])->stretch();
		if (typeid(TennisEvent) == typeid(*events[i]))
			dynamic_cast<TennisEvent*>(events[i])->cheer();
		//FIXME 5b: if this is a baseball game, include a call to have attendees at the baseball game stretch
		//FIXME 5c: if this is your event, include a call to your event's special behavior

		// Jane decides to leave the event. Darn! She was really fun to have around!
		ticket2->leave();

		cout << "Event after Jane leaves:\n";
		events[i]->list(); // List the people remaining
		
	}
	std::system("pause");
}