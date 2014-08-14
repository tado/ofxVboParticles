//
//  ofxVboParticles.cpp
//
//  Created by Atsushi Tadokoro on 8/14/14.
//
//

#include "ofxVboParticles.h"

ofxVboParticles::ofxVboParticles(int _maxParticles, float _pointSize){
    maxParticles = _maxParticles;
    pointSize = _pointSize;
    numParticles = 0;
    
    static GLfloat distance[] = { 0.0, 0.0, 1.0 };
    glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, distance);
    glPointSize(pointSize);
    glEnable(GL_POINT_SMOOTH);
    
    billboards.setUsage(GL_DYNAMIC_DRAW);
    billboards.setMode(OF_PRIMITIVE_POINTS);
    billboards.disableTextures();
    
    billboards.getVertices().resize(maxParticles);
    billboards.getColors().resize(maxParticles);
    billboards.getNormals().resize(maxParticles, ofVec3f(0));
}

void ofxVboParticles::update(){
    
}

void ofxVboParticles::draw(){
    ofPushStyle();
    ofEnableDepthTest();
    ofEnablePointSprites();
    billboards.draw();
    ofDisablePointSprites();
    ofPopStyle();
}

void ofxVboParticles::addParticle(ofVec3f _position, ofColor _color){
    positions.push_back(_position);
    billboardColor.push_back(_color);
    
   
    billboards.getVertices()[numParticles].set(positions[numParticles].x, positions[numParticles].y, positions[numParticles].z);
    billboards.getColors()[numParticles].set(billboardColor[numParticles]);
    
    numParticles++;
    
    if (positions.size() > maxParticles) {
        positions.pop_front();
        billboardColor.pop_front();

        for (int i = 0; i < numParticles-1; i++) {
            billboards.getVertices()[i] = billboards.getVertices()[i + 1];
            billboards.getColors()[i] = billboards.getColors()[i + 1];
        }
        
        numParticles--;
    }
}