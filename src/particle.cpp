//
//  Particle.cpp
//  particle_01
//
//  Created by Ken Ishii on 2016/06/16.
//
//

#include "Particle.hpp"


//constructor
Particle::Particle(){
    pos.x = ofRandom(-500, 500);
    pos.y = ofRandom(-500, 500);
    
    toward.x = ofRandom(-1, 1);
    toward.y = ofRandom(-1, 1);
    
    radius = ofRandom(0.1, 0.3);
}

void Particle::update(){
    pos.x += toward.x;
    pos.y += toward.y;
    
    
    if (pos.x <= -500 || pos.x >= 500) toward.x = -toward.x; // ||（もしくは）
    if (pos.y <= -500 || pos.y >= 500) toward.y = -toward.y;
    
    /*
     if (pos.x < 0) pos.x = ofGetWidth();
     if (pos.x > ofGetWidth()) pos.x = 0;
     
     if (pos.y < 0) pos.y = ofGetHeight();
     if (pos.y > ofGetHeight()) pos.y = 0;
     */
}

void Particle::draw(){
    ofSetColor(pos.x/2, pos.y/2, 200);
    ofCircle(pos.x, pos.y, radius);
}
