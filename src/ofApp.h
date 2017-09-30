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
    
    int fps;
    
    // Screen Size is 840*840,(28*30)*(28*30)
    static constexpr int INPUT_NUM = 28*28;
    ofCamera cam;
    
    int z;
    
    int whichFile = 0;
    bool changeFile = false;
    std::string fileName;
    
    int aggregate[9] = { 0 };
};
