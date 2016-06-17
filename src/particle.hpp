#include "ofMain.h"

class Particle {
    
public:
    //method
    void update(); //update position
    void draw(); //draw particle
    
    Particle(); //constructor
    
    //property
    ofVec2f pos; //position
    
    ofVec2f toward; //velocity
    
    float radius = 0;
    
};