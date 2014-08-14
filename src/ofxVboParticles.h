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
    ofxVboParticles(int maxParticles = 10000, float pointSize = 1000);
    void update();
    void draw();
    void addParticle(ofVec3f position = ofVec3f(0, 0, 0),
                     ofVec3f velocity = ofVec3f(0, 0, 0),
                     ofColor color = 0xffffff);
    
    int maxParticles;
    float pointSize;

    int numParticles;
    deque<ofVec3f> positions;
    deque<ofVec3f> velocitys;
    deque<ofVec3f> forces;
    deque<ofColor> colors;
    float friction;
    
    ofShader billboardShader;
    ofImage texture;
    ofVboMesh billboards;
};


