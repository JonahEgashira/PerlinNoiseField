#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
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
  ofxFloatSlider radiusSlider;
  ofxIntSlider gapSlider;
  ofxIntSlider speedSlider;
  ofxFloatSlider znoiseSlider;
  ofxFloatSlider colornoiseSlider;
  
  ofxIntSlider alphaSlider;
  
  ofxColorSlider particleColorSlider;
  
  ofColor particle_color;
  
  ofxButton startstopButton;
  ofxButton resetButton;
  
  bool start = false;

  void startstopButtonPressed();
  void resetButtonPressed();

  int width;
  int height;
  
  
  

  vector<vector<float>> noise;

  float xstart;
  float xnoise;
  float ynoise;
  vector<vector<float>> xnoises;
  vector<vector<float>> ynoises;
  float znoise;
  float znoise_add;
  
  vector<vector<ofVec2f>> field_vec;

  // particles

  float radius;
  
  int gap;
  int speed;
  int particle_num;
  
  int alpha;
  
  float rednoise;
  float greennoise;
  float bluenoise;
  
  float color_noise_add;
  
  
  vector<ofVec2f> particle_pos;


};
