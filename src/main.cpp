#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <exception>
#include "Event.h"
#include "ToDo.h"
using namespace std;

/*
This program is designed to serve as a weekly calendar to keep track of important events,
enable a to-do list to be constructed from stored memory, and keep track of long term goals.
Inspired by Kyle's Office Chalkboard :D
*/

void EventReadIn(vector<Event>& dailyEvents, string dayOfWeek);
void ToDoReadIn(vector<Event>& toDos);
void EventWriteOut(vector<Event>& dailyEvents, string dayOfWeek);
void ToDoWriteOut(vector<Event>& dailyEvents, string toDoCategory);

int main () {
    vector<Event> mondayEvents;
    vector<Event> tuesdayEvents;
    vector<Event> wednesdayEvents;
    vector<Event> thursdayEvents;
    vector<Event> fridayEvents;
    vector<Event> saturdayEvents;
    vector<Event> sundayEvents;

    vector<ToDo> weeklyToDos;
    vector<ToDo> financialToDos;
    vector<ToDo> personalToDos;

    EventReadIn(mondayEvents, "Monday");
    EventReadIn(tuesdayEvents, "Tuesday");
    EventReadIn(wednesdayEvents, "Wednesday");
    EventReadIn(thursdayEvents, "Thursday");
    EventReadIn(fridayEvents, "Friday");
    EventReadIn(saturdayEvents, "Saturday");
    EventReadIn(sundayEvents, "Sunday");

    mondayEvents.push_back(Event("11 am to ", "12 pm: ", "NapTime!"));
    tuesdayEvents.push_back(Event("11 am to ", "12 pm: ", "NapTime!"));
    wednesdayEvents.push_back(Event("11 am to ", "12 pm: ", "NapTime!"));
    thursdayEvents.push_back(Event("11 am to ", "12 pm: ", "NapTime!"));
    fridayEvents.push_back(Event("11 am to ", "12 pm: ", "NapTime!"));
    saturdayEvents.push_back(Event("11 am to ", "12 pm: ", "NapTime!"));
    sundayEvents.push_back(Event("11 am to ", "12 pm: ", "NapTime!"));
    
    EventWriteOut(mondayEvents, "Monday");
    EventWriteOut(tuesdayEvents, "Tuesday");
    EventWriteOut(wednesdayEvents, "Wednesday");
    EventWriteOut(thursdayEvents, "Thursday");
    EventWriteOut(fridayEvents, "Friday");
    EventWriteOut(saturdayEvents, "Saturday");
    EventWriteOut(sundayEvents, "Sunday");

    return 0;
}

void EventWriteOut(vector<Event>& dailyEvents, string dayOfWeek) {
    string fullPath = "events/" + dayOfWeek + ".txt";
    ofstream outputFile(fullPath);
    if (outputFile.is_open()) {
        for (const Event& event : dailyEvents) {
            outputFile << event.getStartTime() << ',' << event.getEndTime() << ',' << event.getTitle() << '\n';
        }
    }
    else {
        try {
            throw invalid_argument( "error opening file. \n");
        }
        catch (invalid_argument& e) {
            cout << "Caught exception: " << e.what() << '\n';
        }
    }
}

void EventReadIn(vector<Event>& dailyEvents, string dayOfWeek) {
    string fullPath = "events/" + dayOfWeek + ".txt";
    ifstream inputFile(fullPath);
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string start, end, title;
        getline(ss, start,','); 
        getline(ss, end,','); 
        getline(ss, title); 

        dailyEvents.push_back(Event(start,end,title));
    }
}