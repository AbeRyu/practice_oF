#include "ofApp.h"
#define NUM_OF_POLYGONS 200

//--------------------------------------------------------------
void ofApp::setup(){
    //ofEnableDepthTest();
    // z軸の前後の判定を直してくれるやーつ。
//    ofSetVerticalSync(true);
    ofEnableNormalizedTexCoords();
//   ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofSetVerticalSync(true);//画面の垂直同期をONに,素早い動きをした際に画面が途中までしか更新されずちらついてしまう現象を防いでいます。
    //ofEnableDepthTest();
    //背景画像の読込み
    firstBg.loadImage("tech.png");
    
    //ボックス用メンター画像の読込み
    mentor[0].loadImage("mentor/1.png");
    
    //背景用メンター画像の読み込み
    bg[0].loadImage("mentor/1_2.jpg");
    
    //時計を描く
    //    ofEnableSmoothing();
    
    
    for (int i = 0; i < NUM_OF_POLYGONS ; i++){
        polygons.push_back(new Polygon3d);
    }
    
    num = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    camera.setPosition(3000*cos((double)ofGetElapsedTimeMillis()/1000), 0, 3000*sin((double)ofGetElapsedTimeMillis()/1000));
    camera.lookAt(ofVec3f(0,0,0));
    
    time = time + 1;
    
    //半径1の円において　(x,y) = (cosθ,sinθ);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDisableNormalizedTexCoords();
    ofBackground(255);
    firstBg.draw(0,0,ofGetWidth(),ofGetHeight());
    ofEnableNormalizedTexCoords();
    //時刻を取得
    //秒を取得
    float s = ofGetSeconds();
    //秒の影響を加えた、分の算出
    float m = ofGetMinutes() + (s/60.0);
    //分の影響を加えた、時の算出
    float h = ofGetHours()%12 + (m/60);
    
    //時計の大きさ
    float clockSize = ofGetWidth()/8 ;
    
    //座標全体を中心に移動
    ofTranslate(ofGetWidth()-150, ofGetHeight()/5);
    
    //時計の背景
    ofSetColor(0,0,0);
    ofFill();
    
    //分の目盛を描く
    for (int i=0; i<60; i++) {
        ofRotateZ(6);
        ofCircle(clockSize, 0, 2);
    }
    
    //時の目盛を描く
    for (int i=0; i<12; i++) {
        ofRotateZ(30);
        ofCircle(clockSize, 0, 4);
    }
    
    ofSetColor(0, 0, 0);
    ofNoFill();
    
    //秒針
    ofPushMatrix();
    ofRotateZ(time*11);
    ofSetLineWidth(1);
    ofLine(0, 0, 0, -clockSize);
    ofPopMatrix();
    
    //分
    ofPushMatrix();
    ofRotateZ(time*5);
    ofSetLineWidth(2);
    ofLine(0, 0, 0, -clockSize);
    ofPopMatrix();
    
    //時針
    ofPushMatrix();
    ofRotateZ(time);
    ofSetLineWidth(4);
    ofLine(0, 0, 0, -clockSize*0.75);
    ofPopMatrix();
    
    ofSetColor(255, 255, 255);
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    
    //    if(num == 1){
    //myImage.loadImage("mochi.jpg");
    //    }
    
    
    camera.begin();
    
    for(int i = 0; i < num ; i++){
        ofFill();
        mentor[0].bind();
        
        //ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        ofRotateZ(180);
        polygons.at(i)->draw();
        ofRotateZ(-180);
        mentor[0].unbind();
    }
    
    for(int j = 0; j < num ; j ++){
        ofSetColor(255,255,255,90);
        if(j != 0){
            ofLine(polygons.at(j-1)->mPolygonPosition,polygons.at(j)->mPolygonPosition);
        }
    }
    
    camera.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'a'){
        if(num < 100){
            num = num + 1;
        }
    }
    
    if(key == 'b'){
        num = 0;
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
