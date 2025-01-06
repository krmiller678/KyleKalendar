#pragma once
#include <string>

class ToDo{
    private:
        std::string _title;
        bool crossOut;
    public:
        // Constructor
        ToDo(std::string title)
            : _title{title}, crossOut(false)
            {}

        // Getters
        std::string getTitle() {return _title;}

        // Mutators
        void editTitle(std::string newTitle) {_title = newTitle;}
        void flipCrossOut() {crossOut = !crossOut;}
};