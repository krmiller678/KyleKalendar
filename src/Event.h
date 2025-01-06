#pragma once
#include <string>

class Event{
    private:
        std::string _startTime;
        std::string _endTime;
        std::string _title;
    public:
        // Constructor
        Event(std::string startTime, std::string endTime, std::string title)
            : _startTime{startTime}, _endTime{endTime}, _title{title} 
            {}

        // Getters
        std::string getStartTime() {return _startTime;}
        std::string getEndTime() {return _endTime;}
        std::string getTitle() {return _title;}

        // Mutators
        void editStartTime(std::string newStart) {_startTime = newStart;}
        void editEndTime(std::string newEnd) {_endTime = newEnd;}
        void editTitle(std::string newTitle) {_title = newTitle;}
};