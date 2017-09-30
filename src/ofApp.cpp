#include "ofApp.h"


void ofApp::setup(){
    // Setup the screen.
    ofSetVerticalSync(true);
    //ofEnableBlendMode(OF_BLENDMODE_ADD);
    glEnable(GL_DEPTH_TEST);
    ofSetFrameRate(60);
    ofBackground(0);
    
    // 円の解像度
    ofSetCircleResolution(120);
    
    z = 5000;
}

void ofApp::update(){
    // Setup the fps and time.
    fps = ceil(ofGetFrameRate());
    float time = ofGetElapsedTimef();
    ofSetWindowTitle("fps : "+ofToString(fps)+"  time : "+ofToString(ceil(time)));
    
    cam.setPosition(0, 0, z);
    cam.lookAt(ofVec3f(0, -1, 0), ofVec3f(0, 0, -1));
    
    if (whichFile < 9999){
        whichFile++;
        changeFile = false;
    }
}

void ofApp::draw(){
    ofNoFill();
    ofSetColor(200);
    
    ofPushMatrix();
    cam.begin();
    // 表示の調整 // TODO:画像が回転してしまっている．python側で解決できるはず．
    ofRotateZ(-90);
    
    
    // Input a text as image
    std::string directory = "/Users/ken/Documents/openFrameworks/apps/myApps/numberRecognition/bin/data/";
    fileName = directory + std::to_string(whichFile) + ".txt";
    std::ifstream ifs(fileName);
    std::string str;
    if(ifs.fail()) {
        cerr << "File do not exist.\n";
        std::exit(0);
    }
    // Input a "TeacherNumber"
    getline(ifs, str);
    if (changeFile == false)
        ++aggregate[std::stoi(str)];
    changeFile = true;
    // Output a image as perceptron
    for (int i = 0; i < sqrt(INPUT_NUM); i++){
        for (int j = 0; j < sqrt(INPUT_NUM); j++){
            getline(ifs, str);
            ofSetColor(std::stoi(str));
            ofDrawSphere(ofMap(i, 0, 27, -500, 500), ofMap(j, 0, 27, -500, 500), 4000, 10);
        }
    }
    
    cam.end();
    ofPopMatrix();
    
    for (int i = 0; i < 10; i++){
        // log
        ofSetColor(255, 255, 255);
        std::string info = ofToString(aggregate[i], 2) + "\n";
        ofDrawBitmapString(info, 30, 30 + i*30);
    }
}

void ofApp::keyPressed(int key){
    switch (key) {
        case OF_KEY_RETURN:
            whichFile++;
            changeFile = false;
            break;
        case OF_KEY_DEL:
            //whichFile--;
            break;
        default:
            break;
    }
}

void ofApp::keyReleased(int key){
    
}

void ofApp::mouseMoved(int x, int y ){
    
}

void ofApp::mouseDragged(int x, int y, int button){
    
}

void ofApp::mousePressed(int x, int y, int button){
    
}

void ofApp::mouseReleased(int x, int y, int button){
    
}

void ofApp::mouseEntered(int x, int y){
    
}

void ofApp::mouseExited(int x, int y){
    
}

void ofApp::windowResized(int w, int h){
    
}

void ofApp::gotMessage(ofMessage msg){
    
}

void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
