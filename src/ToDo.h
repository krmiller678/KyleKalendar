#pragma once
#include <string>

class ToDo{
    private:
        std::string _title;
        bool _crossOut;
    public:
        // Constructor
        ToDo(std::string title)
            : _title{title}, _crossOut(false)
            {}

        // Getters
        std::string getTitle() const {return _title;}
        bool getCrossOut() const {return _crossOut;}

        // Mutators
        void editTitle(std::string newTitle) {_title = newTitle;}
        void flipCrossOut() {_crossOut = !_crossOut;}
};