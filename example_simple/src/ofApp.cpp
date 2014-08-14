#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    cam.setFov(80);
    
    vboPartciles = new ofxVboParticles(10000, 1000);
    vboPartciles->friction = 0.005;
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < 10; i++) {
        ofVec3f pos = ofVec3f(0, 0, 0);
        ofVec3f vel = ofVec3f(ofRandom(-2, 2), ofRandom(-2, 2), ofRandom(-2, 2));
        ofColor col;
        col.setHsb(ofRandom(255), 63, 200);
        vboPartciles->addParticle(pos, vel, col);
    }

    vboPartciles->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofRotateX(20);
    ofRotate(ofGetElapsedTimef() * 20, 1, 1, 0);
    vboPartciles->draw();
    cam.end();
    
    ofSetColor(255);
    ofDrawBitmapString(ofToString(ofGetFrameRate(), 4) + "fps", 20, 20);
    ofDrawBitmapString("particle num = " + ofToString(vboPartciles->numParticles, 0), 20, 40);
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
