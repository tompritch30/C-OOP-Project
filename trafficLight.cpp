#include "trafficLight.h"
#include "time.h"
#include <iostream>
#include <cstring>

Time TrafficLight::globalTime;

/* Constructor initialising with delay time and name, allocating name on heap. */
TrafficLight::TrafficLight(const Time& initTime, const char* initName) 
    : delayTime(initTime), otherPair(nullptr), colour(Red)
{
    strName = new char[std::strlen(initName) + 1];
    // Copying name to the allocated memory.
    std::strcpy(const_cast<char*>(strName), initName);
}

/* Constructor for paired light initialisation with bidirectional linking. */
TrafficLight::TrafficLight(const Time& initTime, const char* initName, TrafficLight& pairedLight) 
    : delayTime(initTime), otherPair(&pairedLight), colour(Red)
{
    strName = new char[std::strlen(initName) + 1];
    // Copying name to the allocated memory.
    std::strcpy(const_cast<char*>(strName), initName);
    // Establishing bidirectional pairing.
    pairedLight.otherPair = this;
}

/* Destructor releasing dynamically allocated name memory. */
TrafficLight::~TrafficLight() {
    delete[] strName;
}

/* Returns the string representation of the light's colour. */
const char * TrafficLight::getColour() const {
    // Returning colour based on the current state.
    switch (this->colour) {
        case Red:    return "red";
        case Yellow: return "yellow";
        case Green:  return "green"; 
        default:     return "error: undefined colour"; 
    }
}

/* Outputs the state of the traffic light to the output stream. */
std::ostream& operator<<(std::ostream& os, const TrafficLight* trafficLight) {
    // Defensively checking for null pointers.
    if (trafficLight == nullptr) {
        os << "Error: Null pointer to TrafficLight.";
        return os;
    }
    // Displaying state including global time, name, and colour.
    os << "     at " << TrafficLight::globalTime << " " 
       << trafficLight->strName << " changes colour to " 
       << trafficLight->getColour() << std::endl;
    return os;
}

/* Handles the logic of changing light colours when a car wants to cross. */
void TrafficLight::carWantsToCross() {
    // Printing current light status.
    std::cout << "\n***  at " << globalTime << " a car wants to cross light "
              << strName << ", with colour: " << getColour() << std::endl;

    // Logic to change light sequence considering the state of paired light.
    if (Red == colour) {
        if(otherPair != nullptr && Red == otherPair->colour) {
            changeColour(Yellow);
            changeColour(Green);
        } else if (Red == colour && otherPair != nullptr && Green == otherPair->colour) {
            otherPair->changeColour(Yellow);
            changeColour(Yellow);
            otherPair->changeColour(Red);
            changeColour(Green);
	} else {
	  std::cerr << "Error, unexpected state of pair traffic light while "
		    << strName << " is red." << std::endl;
	}  
    } else {
      // No-operation, intentionally left blank.
      // This accounts for scenarios where the light might already be green.
    }    
}

/* Sets the global time for all instances of TrafficLight. */
void TrafficLight::setTheTime(const Time& newTime) {
    globalTime = newTime;
}

/* Changes the colour of this traffic light and updates the global time. */
void TrafficLight::changeColour(LightColour newColour) {
    // Updates traffic light colour to the enum parameter value.
    colour = newColour;
    // Incrementing global time by the delay time of this light.
    globalTime.add(delayTime);
    // Printing new state to standard output.
    std::cout << this;
}
