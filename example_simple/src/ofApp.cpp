#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    cam.setFov(80);
    
    // ofxVboParticles([max particle number], [particle size]);
    vboPartciles = new ofxVboParticles(10000, 1000);

    // set friction (0.0 - 1.0);
    vboPartciles->friction = 0.005;
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < 10; i++) {
        ofVec3f position = ofVec3f(0, 0, 0);
        ofVec3f velocity = ofVec3f(ofRandom(-2, 2), ofRandom(-2, 2), ofRandom(-2, 2));
        ofColor color;
        color.setHsb(ofRandom(255), 63, 200);
        
        // add a particle
        vboPartciles->addParticle(position, velocity, color);
    }

    vboPartciles->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofRotate(ofGetElapsedTimef() * 20, 1, 1, 0);

    // draw particles
    vboPartciles->draw();
    
    cam.end();
    
    ofSetColor(255);
    ofDrawBitmapString(ofToString(ofGetFrameRate(), 4) + "fps", 10, 20);
    ofDrawBitmapString("particle num = " + ofToString(vboPartciles->numParticles, 0), 10, 35);
    ofDrawBitmapString("[f] key : toggle fullscreen", 10, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f') {
        ofToggleFullscreen();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
