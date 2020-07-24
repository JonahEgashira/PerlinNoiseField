#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  
  start = false;
  
  /*
   Parameters that I want to change
   radius
   gap
   speed
   znoise
   opacity
   */

  ofSetFullscreen(true);
  ofSetBackgroundAuto(false);
  ofSetBackgroundColor(0);
  
  //width = 1200;
  //height = 800;
  width = ofGetWidth();
  height = ofGetHeight();

  particle_num = 100000;
  radius = 0.5;
  
  noise.resize(height + 1, vector<float> (width + 1));
  xnoises.resize(height + 1, vector<float> (width + 1));
  ynoises.resize(height + 1, vector<float> (width + 1));
  field_vec.resize(height + 1, vector<ofVec2f> (width + 1));
  particle_pos.resize(particle_num);

  xstart = ofRandom(20);
  xnoise = xstart;
  ynoise = ofRandom(20);
  znoise = 0;

  znoise_add = 0.002;
  color_noise_add = 0.002;
  
  for (int i = 0; i < particle_num; i++) {
    particle_pos[i].set(ofRandom(width), ofRandom(height));
  }

  gap = 5;
  speed = 2;
  alpha = 10;
  
  rednoise = ofRandom(10);
  greennoise = ofRandom(10);
  bluenoise = ofRandom(10);
  
  gui.setup();
  gui.add(radiusSlider.setup("radius", 0.5, 0.01, 10.0));
  gui.add(gapSlider.setup("gap", 5, 1, 100));
  gui.add(speedSlider.setup("speed", 2, 1, 20));
  gui.add(znoiseSlider.setup("znoise", 0.002, 0.000001, 0.01));
  gui.add(colornoiseSlider.setup("colornoise", 0.001, 0.000001, 0.01));
  gui.add(alphaSlider.setup("alpha", 10, 0, 100));
  gui.add(particleColorSlider.setup("color", 255, 255, 255));
  
  gui.add(startstopButton.setup("Start/Stop"));
  startstopButton.addListener(this, &ofApp::startstopButtonPressed);
  gui.add(resetButton.setup("Reset"));
  resetButton.addListener(this, &ofApp::resetButtonPressed);

  for (int y = 0; y <= height; y += gap) {
    ynoise += 0.01;
    xnoise = xstart;
    for (int x = 0; x <= width; x += gap) {
      xnoise += 0.01;
      xnoises[y][x] = xnoise;
      ynoises[y][x] = ynoise;
    }
  }
  
}

void ofApp::startstopButtonPressed() {
  start = !start;
}

void ofApp::resetButtonPressed() {
  
  ofClear(0);
  particle_pos.clear();
  xnoises.clear();
  ynoises.clear();
  noise.clear();
  ofApp::setup();

  start = false;
}

//--------------------------------------------------------------
void ofApp::update(){
  
  radius = radiusSlider;
  gap = gapSlider;
  speed = speedSlider;
  znoise_add = znoiseSlider;
  color_noise_add = colornoiseSlider;
  alpha = alphaSlider;
  particle_color = particleColorSlider;

  
  if(!start) {
    return;
  }
  
  
  
  for (int y = 0; y <= height; y += gap) {
    for (int x = 0; x <= width; x += gap) {
      noise[y][x] = ofNoise(xnoises[y][x], ynoises[y][x], znoise);
      float rad = (noise[y][x] * ofDegToRad(360));
  
      field_vec[y][x].x = cos(rad);
      field_vec[y][x].y = sin(rad);
    }
  }
  

  for (int i = 0; i < particle_num; i++) {

    if(particle_pos[i].x > float(width)) particle_pos[i].x = 0.0;
    if(particle_pos[i].y > float(height)) particle_pos[i].y = 0.0;
    if(particle_pos[i].x < 0.0) particle_pos[i].x = float(width);
    if(particle_pos[i].y < 0.0) particle_pos[i].y = float(height);
    
    int x_pos = int(particle_pos[i].x) / gap * gap;
    int y_pos = int(particle_pos[i].y) / gap * gap;

    particle_pos[i].x += field_vec[y_pos][x_pos].x * speed;
    particle_pos[i].y += field_vec[y_pos][x_pos].y * speed;


  }
  
  
  particle_color.set(255 * ofNoise(rednoise), 255 * ofNoise(greennoise), 255 * ofNoise(bluenoise));
  
  rednoise += color_noise_add;
  greennoise += color_noise_add;
  bluenoise += color_noise_add;

  znoise += znoise_add;

}


//--------------------------------------------------------------
void ofApp::draw(){
 
  gui.draw();

  if(!start) {
    return;
  }

  ofSetColor(particle_color, alpha);

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
