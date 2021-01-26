#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    shader.load("shaders/shader");
    shader2.load("shaders/noise");
    
    fbo.allocate(ofGetWidth(), ofGetHeight());
    fbo2.allocate(ofGetWidth(), ofGetHeight());
    image.load("aoi.png");
    backImage.load("back.png");
    
    gui.setup();
    gui.add(posDia.setup("pos dia", 0.02, 0.01, 0.1));
    gui.add(timeDia.setup("time dia", 0.5, 0.1, 1.0));
    gui.add(timeAdd.setup("time add", 12.0, 0.0, 30.0));
    gui.add(entireDia.setup("entire dia", 30.0, 0.0, 100.0));
    gui.add(noise.setup("noise", false));
    bHide = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
    ofBackground(250, 194, 219);
    ofSetColor(255);
    
    backImage.setAnchorPercent(0.5, 0.5);
    backImage.resize(ofGetWidth()*1.05, ofGetHeight()*1.05);
    backImage.draw(ofGetWidth()/2, ofGetHeight()/2);
    fbo.end();
    
    fbo2.begin();
    shader.begin();
    float time = ofGetElapsedTimef();
    shader.setUniform1f("time", time);
    shader.setUniform1f("posDia", posDia);
    shader.setUniform1f("timeDia", timeDia);
    shader.setUniform1f("timeAdd", timeAdd);
    shader.setUniform1f("entireDia", entireDia);
    ofSetColor(255);
    fbo.draw(0, 0);
    shader.end();
    fbo2.end();
    
    if(noise){
    shader2.begin();
    shader2.setUniform1f("rand", ofRandom(1));
    fbo2.draw(0,0);
    shader2.end();
    } else {
        fbo2.draw(0, 0);
    }
    
    image.draw(0, 0);
    
    if(!bHide){
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'S' || key == 's') {
           myImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
           myImage.save(ofGetTimestampString("%Y%m%d%H%M%S")+"##.png");
    } else if (key == 'h' || key == 'H') {
        bHide = !bHide;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
