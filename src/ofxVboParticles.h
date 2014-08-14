//
//  ofxVboParticles.h
//
//  Created by Atsushi Tadokoro on 8/14/14.
//
//

#pragma once
#include "ofMain.h"

class ofxVboParticles {
public:
    ofxVboParticles(int maxParticles = 1000, float pointSize = 1000);
    void update();
    void draw();
    void addParticle(ofVec3f position = ofVec3f(0, 0, 0), ofColor color = 0xffffff);
    
    int maxParticles;
    float pointSize;

    int numParticles;
    //deque<float> billboardSize;
    deque<ofVec3f> positions;
    deque<ofColor> billboardColor;
    ofShader billboardShader;
    ofImage texture;
    ofVboMesh billboards;
};


