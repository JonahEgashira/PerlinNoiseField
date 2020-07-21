#pragma once

#include "ofMain.h"

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
  

  int width = 1200;
  int height = 800;
  
  int gap = 5;
  int particle_num = 100000;
  
  vector<vector<float>> noise;

  float xstart;
  float xnoise;
  float ynoise;
  vector<vector<float>> xnoises;
  vector<vector<float>> ynoises;
  float znoise;
  
  vector<vector<ofVec2f>> field_vec;
  
  


  // particles
  
  
  float radius = 0.2;
  
//  vector<ofVec2f> particle_vec;
  vector<ofVec2f> particle_pos;

  

};
