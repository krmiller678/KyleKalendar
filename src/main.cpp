#include <iostream>
#include <vector>
#include <fstream>
#include <exception>
#include "Event.h"
#include "ToDo.h"
using namespace std;

/*
This program is designed to serve as a weekly calendar to keep track of important events,
enable a to-do list to be constructed from stored memory, and keep track of long term goals.
Inspired by Kyle's Office Chalkboard :D
*/

void EventReadIn(vector<Event>& dailyEvents);
void ToDoReadIn(vector<Event>& toDos);
void EventWriteOut(vector<Event>& dailyEvents, string dayOfWeek);
void ToDoWriteOut(vector<Event>& dailyEvents, string toDoCategory);

int main () {
    vector<Event> mondayEvents;
    vector<ToDo> weeklyToDos;
    mondayEvents.push_back(Event("11 am to ", "12 pm: ", "NapTime!"));
    cout << mondayEvents[0].getStartTime() << mondayEvents[0].getEndTime() << mondayEvents[0].getTitle();
    EventWriteOut(mondayEvents, "Monday");
    return 0;
}

void EventWriteOut(vector<Event>& dailyEvents, string dayOfWeek) {
    string fullPath = "events/" + dayOfWeek + ".txt";
    ofstream outputFile(fullPath);
    if (outputFile.is_open()) {
        outputFile << "testing";
        outputFile.close();
        cout << "testing";
    }
    else {
        throw invalid_argument( "error opening file. \n");
    }
}