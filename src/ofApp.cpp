#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  

  ofSetFullscreen(true);
  ofSetBackgroundAuto(false);
  ofEnableBlendMode(OF_BLENDMODE_ADD);
  ofSetBackgroundColor(0);
  
  width = ofGetWidth();
  height = ofGetHeight();
  
  noise.resize(height + 1, vector<float> (width + 1));
  xnoises.resize(height + 1, vector<float> (width + 1));
  ynoises.resize(height + 1, vector<float> (width + 1));

  xstart = ofRandom(10);
  xnoise = xstart;
  ynoise = ofRandom(10);
  znoise = 0;
  
  
  field_vec.resize(height + 1, vector<ofVec2f> (width + 1));
  
  particle_pos.resize(particle_num);
  
  for (int i = 0; i < particle_num; i++) {
    particle_pos[i].set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
  }
  

  gap = 10;
  
  for (int y = 0; y < height; y += gap) {
    ynoise += 0.01;
    xnoise = xstart;
    for (int x = 0; x < width; x += gap) {
      xnoise += 0.01;
      xnoises[y][x] = xnoise;
      ynoises[y][x] = ynoise;
    }
  }
}

//--------------------------------------------------------------
void ofApp::update(){
  
  for (int y = 0; y < height; y += gap) {
    for (int x = 0; x < width; x += gap) {
      noise[y][x] = ofNoise(xnoises[y][x], ynoises[y][x], znoise);
      float rad = (noise[y][x] * ofDegToRad(360));
  
      field_vec[y][x].x = cos(rad);
      field_vec[y][x].y = sin(rad);
    }
  }
  

  for (int i = 0; i < particle_num; i++) {
    
    if(particle_pos[i].x > width) particle_pos[i].x = 0;
    if(particle_pos[i].y > height) particle_pos[i].y = 0;
    if(particle_pos[i].x < 0) particle_pos[i].x = width;
    if(particle_pos[i].y < 0) particle_pos[i].y = height;
    
    int x_pos = int(particle_pos[i].x) / gap * gap;
    int y_pos = int(particle_pos[i].y) / gap * gap;
    

    particle_pos[i].x += field_vec[y_pos][x_pos].x * 10;
    particle_pos[i].y += field_vec[y_pos][x_pos].y * 10;
   
  //  if(particle_pos[i].x > width) particle_pos[i].x = 0;
  //  if(particle_pos[i].y > height) particle_pos[i].y = 0;
  //  if(particle_pos[i].x < 0) particle_pos[i].x = width;
  //  if(particle_pos[i].y < 0) particle_pos[i].y = height;
    
  }
  
  
  znoise += 0.005;

}




//--------------------------------------------------------------
void ofApp::draw(){
  
//  for (int y = 0; y < height; y += gap) {
//    for (int x = 0; x < width; x += gap) {
//        ofPushMatrix();
//        ofTranslate(x, y);
//        ofRotateRad(noise[y][x] * ofDegToRad(360));
//        ofSetColor(0);
//        ofDrawLine(0, 0, gap * 2, 0);
//        ofPopMatrix();
//    }
//  }
  
//  for (int y = 0; y < height; y += gap) {
//    for (int x = 0; x < width; x += gap) {
//
//      ofSetColor(255 * noise[y][x]);
//      ofDrawCircle(x, y, gap);
//
//    }
//  }
  
  ofSetColor(255, 60);
             
  for (int i = 0; i < particle_num; i++) {
    ofDrawCircle(particle_pos[i], radius);
  }
  
  
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
