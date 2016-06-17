#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetFrameRate(60);
    ofEnableSmoothing();
    ofSetCircleResolution(64);
    
    for (int i = 0; i < particleNum; i++) {
        //constructor
        Particle * p = new Particle();
        particles[i] = *p;
    }
    
    ofxRollingCam();
    rollingcam.setup();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < particleNum; i++){
        particles[i].update();
    }
    
    rollingcam.update();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    /* draw circles
     for (int i = 0; i < particleNum; i++) {
     particles[i].draw();
     }
     */
    
    rollingcam.begin();
    
    //draw lines
    for (int i = 0; i < particleNum; i++){
        particles[i].draw();
        
        float x1 = particles[i].pos.x;
        float y1 = particles[i].pos.y;
        
        for (int j = 0; j < particleNum; j++){
            float x2 = particles[j].pos.x;
            float y2 = particles[j].pos.y;
            
            float length = sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
            if (length < ofGetWidth()) {
                particles[i].draw();
                ofSetColor(x2/2, x1/2, 200);
                ofSetLineWidth(0.5);
                ofLine(x1, y1, x2, y2);
            }
        }
    }
    
    rollingcam.end();
    
    ofPushStyle();
    ofSetColor(255);
    if(!hide){
        string info = "";
        info += "PressKey '1' : set camera all random.\n";
        info += "PressKey '2' : set random camera rotate.\n";
        info += "PressKey '3' : set camera position (0,0,0)\n";
        info += "PressKey '4' : set random camera distance.\n";
        info += "PressKey '5' : set camera distance by window height.\n";
        info += "PressKey 'f' : toggle fullscreen.\n";
        info += "PressKey 'd' : hide explanation.\n";
        info += "Now Angle    : "+ofToString(rollingcam.posN)+"\n";
        ofDrawBitmapString(info, 10,10);
    }
    ofPopStyle();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key=='1') {//All Random.
        rollingcam.setRandomScale(0.5, 1.5);
        rollingcam.setRandomPos(270);
    }
    if (key=='2') {//Random rotate.
        rollingcam.setRandomPos(270);
    }
    if (key=='3') {//Inputting optional rotate.
        rollingcam.setPos(0, 0, 0);
    }
    if (key=='4') {//Random distance.
        rollingcam.setRandomScale(0.5, 1.5);
    }
    if (key=='5') {//Inputting optional distance.
        rollingcam.setScale(1);
    }
    
    if (key=='f') {
        ofToggleFullscreen();
    }
    if (key=='h') {
        hide= !hide;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
