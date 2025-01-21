#pragma once
#include <string>

class Event{
    private:
        std::string _startTime;
        std::string _endTime;
        std::string _title;
    public:
        // Constructor
        Event(std::string startTime = "0", std::string endTime = "0", std::string title = "NA")
            : _startTime{startTime}, _endTime{endTime}, _title{title} 
            {}

        // Getters
        std::string GetStartTime() const {return _startTime;}
        std::string GetEndTime() const {return _endTime;}
        std::string GetTitle() const {return _title;}

        // Mutators
        void EditStartTime(std::string newStart) {_startTime = newStart;}
        void EditEndTime(std::string newEnd) {_endTime = newEnd;}
        void EditTitle(std::string newTitle) {_title = newTitle;}
};