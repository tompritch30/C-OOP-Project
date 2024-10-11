/* trafficLights.h - header file for the class TrafficLights */
#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "time.h"
#include <iostream>

enum LightColour { Red, Yellow, Green };

class TrafficLight {
public:
    /**
     * Initialises a traffic light with a name and delay time.
     * @param initTime Initial delay time for light changes.
     * @param initName Identifier for the light, stored on the heap.
     */
    TrafficLight(const Time& initTime, const char* initName);

    /**
     * Initialises a traffic light paired with another light, including name and delay time.
     * @param initTime Initial delay time for light changes.
     * @param initName Identifier for the light, stored on the heap.
     * @param pairedLight Reference to the paired TrafficLight.
     */
    TrafficLight(const Time& initTime, const char* initName, TrafficLight& pairedLight);
 
    /**
     * Cleans up dynamically allocated memory for the light's identifier.
     */
    ~TrafficLight();

    /**
     * Initiates the predetermined light change sequence dependent on the colour of this 
     * and the paired traffic light. It assumes both traffic lights are instantiated, and 
     * lights start in 'Red' state. 
     * This method will change the colour of this traffic light, its pair (if applicable), 
     * and update the global time accordingly.
     */
    void carWantsToCross();

    /**
     * Assigns the initial shared global time for all traffic lights.
     * Intended to be used once at the system's start up.
     * @param newTime The time to initiate it to.
     */
    static void setTheTime(const Time& newTime);

    /**
     * Retrieves the light's current colour as a string literal.
     * @return The string literal representing the current colour of the light.
     */
    const char * getColour() const;

    /**
     * Outputs the state of a traffic light to an output stream, without modification.
     * Assumes the stream overloads '<<' for Time and const char* types.
     * @param os Output stream.
     * @param trafficLight Traffic light to display.
     * @return Modified output stream, with globalTime, strName, colour.
     */
    friend std::ostream& operator<<(std::ostream& os, const TrafficLight* trafficLight);
  
private:
    /**
     * The dynamically allocated string identifier for the traffic light.
     */
    const char* strName;  

    /**
     * Delay time for traffic light changes. Modification after instantiation is not expected.
     * It's mutable to allow adjustment to the non-const globalTime for efficiency.
     */
    Time delayTime;      

    /**
     * Pointer to a paired traffic light, allowing for coordination between the two.
     */
    TrafficLight* otherPair;

    /**
     * Shared global time for all traffic lights, to synchronise changes across instances.
     */
    static Time globalTime;   

    /**
     * Current colour of the traffic light, determining its state.
     */
    LightColour colour;

    /**
     * Changes the current colour of the traffic light and updates the global time.
     * The changes are printed to the standard output using std::cout.
     * @param newColour The new colour to change to.
     */
    void changeColour(LightColour newColour); 

};

#endif // TRAFFICLIGHT_H

