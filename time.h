/* time.h - header file for the class Time */

#ifndef TIME_H
#define TIME_H

#include <iostream>

/*********************** Time Class ***************************/

class Time {

public:
    /* Default constructor for Time class.Initialises time to 00:00:00. */
    Time();

    /** Constructor for Time class.
     * Initialises time with the given hours, minutes, and seconds.
     * If parameters are out of bounds the time is set to 00:00:00 and output to console using std::cout.
     * @param hours: The number of hours, 0 <= hours <24.
     * @param minutes: The number of minutes, 0 <= minutes < 60.
     * @param seconds: The number of seconds, 0 <= seconds < 60. 
     */
    Time(int hours, int mins, int secs);

    /** Adds seconds to seconds, minutes to minutes and hours to hours, taking into account 
     * that a day has 24 hours, an hour has 60 minutes and a minute has 60 seconds.
     * @param anotherTime: The Time object to be added. 
     */
    void add(Time& anotherTime);

    /** Overloaded << operator for Time class, returns the time in the format HH:MM:SS.
     * @param os: The output stream.
     * @param t: The Time object to be printed. 
     * @return Reference to the output stream with HH:MM:SS. 
     */
    friend std::ostream& operator << (std::ostream&, const Time&);

private:
    int theHour;
    int theMins;
    int theSecs;	
		
};

#endif // TIME_H

