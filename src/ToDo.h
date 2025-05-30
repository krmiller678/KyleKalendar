#pragma once
#include <string>

class ToDo{
    private:
        std::string _title;
        bool _crossOut;
    public:
        // Constructor
        ToDo(std::string title, bool crossout = false)
            : _title{title}, _crossOut(crossout)
            {}

        // Getters
        std::string GetTitle() const {return _title;}
        bool GetCrossOut() const {return _crossOut;}

        // Mutators
        void EditTitle(std::string newTitle) {_title = newTitle;}
        void FlipCrossOut() {_crossOut = !_crossOut;}
};