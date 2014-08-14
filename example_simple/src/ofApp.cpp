#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetFrameRate(60);
    ofBackground(0);
    vboPartciles = new ofxVboParticles(50000, 1000);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < 10; i++) {
        ofVec3f pos = ofVec3f(ofRandom(-ofGetWidth()/2, ofGetWidth()/2),
                              ofRandom(-ofGetWidth()/2, ofGetWidth()/2),
                              ofRandom(-ofGetWidth()/2, ofGetWidth()/2));
        ofColor col;
        col.setHsb(ofRandom(255), 63, 200);
        
        vboPartciles->addParticle(pos, col);
    }

    vboPartciles->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofRotateX(20);
    ofRotateY(ofGetElapsedTimef() * 20.0);
    vboPartciles->draw();
    cam.end();
    
    ofSetColor(255);
    ofDrawBitmapString(ofToString(ofGetFrameRate(), 4) + "fps", 20, 20);
    ofDrawBitmapString(ofToString(vboPartciles->numParticles, 0), 20, 40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
