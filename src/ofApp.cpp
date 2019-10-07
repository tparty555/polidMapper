#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofxSubscribeOsc(PORT,"/time",time);
        ofxSubscribeOsc(PORT,"/state",state);
    
   // fbo.allocate(1000, 1800);
    setupQuadWarper();
    
    testShader.setup("passthru.vert","test.frag");
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    testShader.CheckandCompile();
    
    
    fbo.begin();
    ofClear(0.0,0.0,0.0,255);
        ofSetColor(255);
    testShader.begin();
    testShader.setBasicUniforms();
    ofDrawRectangle(0.0,0.0,1000,1800);
    testShader.end();
    fbo.end();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    
    //--------
    
    ofMatrix4x4 mat = warper.getMatrix();
    
    //======================== use the matrix to transform our fbo.
    
    ofPushMatrix();
    ofMultMatrix(mat);
    fbo.draw(0, 0);
    ofPopMatrix();
    
    ofSetColor(ofColor::magenta);
    warper.drawQuadOutline();
    
    ofSetColor(ofColor::yellow);
    warper.drawCorners();
    
    ofSetColor(ofColor::magenta);
    warper.drawHighlightedCorner();
    
    ofSetColor(ofColor::red);
    warper.drawSelectedCorner();
        ofSetColor(255);
    
    
    
    if(bDebug){
        fbo.draw(ofGetWidth()/4+100,0.0,ofGetHeight()*1000/1800.0,ofGetHeight());
        ofDrawBitmapString("timeCode: "+ofToString(time), 0.0, 10);
        ofDrawBitmapString("state: "+ofToString(state), 0.0, 20);
    }
    
}

void ofApp::allocateFbos(){
    
}


    void ofApp::setupQuadWarper(){
        
        
        int x = (ofGetWidth() - WIDTH) * 0.5;       // center on screen.
        int y =  10;     // center on screen.
        int w = WIDTH/2;
        int h = HEIGHT/3;
        fbo.allocate(w, h);
        warper.setSourceRect(ofRectangle(0, 0, w, h));              // this is the source rectangle which is the size of the image and located at ( 0, 0 )
        warper.setTopLeftCornerPosition(ofPoint(x, y));             // this is position of the quad warp corners, centering the image on the screen.
        warper.setTopRightCornerPosition(ofPoint(x + w, y));        // this is position of the quad warp corners, centering the image on the screen.
        warper.setBottomLeftCornerPosition(ofPoint(x, y + h));      // this is position of the quad warp corners, centering the image on the screen.
        warper.setBottomRightCornerPosition(ofPoint(x + w, y + h)); // this is position of the quad warp corners, centering the image on the screen.
        warper.setup();
        warper.load(); // reload last saved changes.
    }




//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'a'){
        bDebug = !bDebug;
    }
    if(key == 's' || key == 'S') {
        warper.toggleShow();
    }
    
    if(key == 'l' || key == 'L') {
        warper.load();
    }
    
    if(key == 'h' || key == 'H') {
        warper.save();
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
