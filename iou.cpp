#include<vector>
#include<iostream>
using namespace std;

float iou(vector<int>box1, vector<int> box2){
    // """
    // box1:x1,y1,w,h
    // box2:x2,y2,w,h
    // return iou percence
    // """
    int up_x1 = box1[0],up_y1 = box1[1];
    int up_x2 = box2[0], up_y2 = box2[1];
    int down_x1= box1[2]+up_x1, down_y1 =box1[3]+up_y1;
    int down_x2 = box2[2]+up_x2,down_y2 = box2[3]+up_y2;
    int in_h = min(down_y1,down_y2) - max(up_y1,up_y2);
    int in_w = min(down_x2,down_x1) - max(up_x1,up_x2);
   
    // int inter = in_h<=0?||in_w<=0? 0:in_w*in_h;
    float inter = 0;
    if(in_w>0 && in_h>0){
        inter = in_w*in_h;
    }
    cout<<inter<<endl;
    int union1 = (box1[2]*box1[3]+box2[2]*box2[3]-inter);
    
    float iou = float(inter)/float(union1);
    cout<<"union1:"<<endl<<iou<<endl;
    return iou;
    
}

int main(){
    vector<int> box1 = {1,1,4,5};
    vector<int> box2 = {2,2,2,3};
    float percent = iou(box1,box2);
    cout<<percent<<endl;
    return 0;
}