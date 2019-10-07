#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxLiveShader.h"
#include "ofxPubSubOsc.h"
#include "ofxQuadWarp.h"
#include "ofxPubSubOsc.h"


#define PORT 8000

#define WIDTH 1000
#define HEIGHT 1800










class ofApp : public ofBaseApp{
    
    void setup();
public:
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    


    ofxPanel gui;
    ofEasyCam cam;
    
    ofxLiveShader testShader;
    
    //utils
    void setupQuadWarper();
    void allocateFbos();
    bool bDebug = true;
    //--------
    
    

    
    
    //scene
    float time = 0;
    int state = 0;
    //--------
    
    //warper
    ofxQuadWarp warper;
    ofFbo fbo;
    ofPoint points[10];
    //-----
  
    

    
    
    
    
    
    
    
    

    
    
};
