#include"time.h"
#include<iostream>

/* Constructor initialising to 00:00:00 */
Time::Time() : theHour(0), theMins(0), theSecs(0) {}

/* Constructor intialising to HH:MM:SS using parameters, enforcing logical input. */
Time::Time(int hours, int minutes, int seconds) {
    // Check if the input values are within valid ranges
    if (hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60) {
        theHour = hours;
        theMins  = minutes;
        theSecs  = seconds;
    } else { // Handle invalid input by setting time to 00:00:00 and inform the user.        
        theHour = 0;
        theMins  = 0;
        theSecs  = 0;
        std::cout << "Invalid input. Time values set to 00:00:00." << std::endl;
    }
}

/* Add times from another Time object to the current Time object.*/
void Time::add(Time& anotherTime) {
    theSecs += anotherTime.theSecs;

    // Handles overflow minutes and hours.
    theMins += theSecs / 60 + anotherTime.theMins;
    theHour += theMins / 60 + anotherTime.theHour;

    // Wrapping around to ensure time values remain within valid ranges.
    theSecs %= 60;
    theMins %= 60;
    theHour %= 24;
}

/* Overloaded << operator for the Time class returned in the format HH:MM:SS */
std::ostream& operator<<(std::ostream& os, const Time& t) {
    os << t.theHour << ":" << t.theMins << ":" << t.theSecs;
    return os;
}




