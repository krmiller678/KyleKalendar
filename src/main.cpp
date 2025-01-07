#include <iostream>
#include <vector>
#include "Event.h"
#include "ToDo.h"
using namespace std;

/*
This program is designed to serve as a weekly calendar to keep track of important events,
enable a to-do list to be constructed from stored memory, and keep track of long term goals.
Inspired by Kyle's Office Chalkboard :D
*/
int main () {
    vector<Event> mondayEvents;
    vector<ToDo> weeklyToDos;
    mondayEvents.push_back(Event("11 am to ", "12 pm: ", "NapTime"));
    cout << mondayEvents[0].getStartTime() << mondayEvents[0].getEndTime() << mondayEvents[0].getTitle();
    
    return 0;
}