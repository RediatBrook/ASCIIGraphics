#include<iostream>
#include<vector>
using namespace std;
class ASCII{
    public:
    const static int maxWidth = 100;
    const static int stdLength = 3;
    const static int stdWidth = 9;
    static void printGraphic(vector<vector<string>> graphic){
        for(auto i: graphic){
            for(auto line: i){
                cout << line;
            }
            cout << endl;
        }
    }
    static vector<vector<string>> getSquare(int size){
        vector<vector<string>> square(3 + stdLength*size);
        int line = 0;
        square[line].push_back(" ");
        for(int i = 0; i < size*stdWidth;i++){
            square[line].push_back("_");
        }
        square[line].push_back(" ");
        line++;
        square[line].push_back("|");
        for(int i= 0;i<stdWidth*size;i++){
            square[line].push_back(" ");
        }
        square[line].push_back("|");
        line++;
        for(int i = 0; i < stdLength*size; i++){
            square[line].push_back("|");
            for(int i =0; i < stdWidth*size;i++){
                square[line].push_back(" ");
            }
            square[line].push_back("|");
            line++;
        }
        square[line].push_back("|");
        for(int i = 0 ; i < stdWidth*size; i++){
            square[line].push_back("_");
        }
        square[line].push_back("|");
        line++;
        return square;
    }
    static vector<vector<string>> getSquare(int size, int length, int width){
        vector<vector<string>> square(3 + length*size);
        int line = 0;
        square[line].push_back(" ");
        for(int i = 0; i < size*width;i++){
            square[line].push_back("_");
        }
        square[line].push_back(" ");
        line++;
        square[line].push_back("|");
        for(int i= 0;i<width*size;i++){
            square[line].push_back(" ");
        }
        square[line].push_back("|");
        line++;
        for(int i = 0; i < length*size; i++){
            square[line].push_back("|");
            for(int i =0; i < width*size;i++){
                square[line].push_back(" ");
            }
            square[line].push_back("|");
            line++;
        }
        square[line].push_back("|");
        for(int i = 0 ; i < width*size; i++){
            square[line].push_back("_");
        }
        square[line].push_back("|");
        line++;
        return square;
    }
    static void drawSquare(int size){
        cout<< "Drawing Board Below:" << endl;
        vector<vector<string>> square = getSquare(size);
        printGraphic(square);
    }
    static void frameText(int size, string text){
        vector<vector<string>> frame = getSquare(size);
        int textPointer = 0;
        bool breakOut = false;
        for(int i = 2; i < frame.size();i++){
            int linePointer = 2;
            while(linePointer < frame[i].size()-2 && frame[i][linePointer]==" "){
                if(textPointer >= text.size()){
                    breakOut  = true;
                    break;
                }
                frame[i][linePointer] = text[textPointer];
                linePointer++;
                textPointer++;
            }
            if(breakOut){
                break;
            }
        }
        printGraphic(frame);
    }
    static void frameText(int size, int length, int width, string text){
        vector<vector<string>> frame = getSquare(size,length,width);
        int textPointer = 0;
        bool breakOut = false;
        for(int i = 2; i < frame.size();i++){
            int linePointer = 2;
            while(linePointer < frame[i].size()-2 && frame[i][linePointer]==" "){
                if(textPointer >= text.size()){
                    breakOut  = true;
                    break;
                }
                frame[i][linePointer] = text[textPointer];
                linePointer++;
                textPointer++;
            }
            if(breakOut){
                break;
            }
        }
        printGraphic(frame);
    }
    static void frameText(string text){
        int length =  1 + text.size()/maxWidth;
        int width  = maxWidth;
        if(text.size()+2  < maxWidth){
            width = text.size()+2;
        }
        frameText(1,length,width,text);
    }
    static void frameText(string text, int width){
        int length = 1 + text.size()/width;
        frameText(1,length,width+2,text); //Changed width so that it now represents textWidth instead of frameWidth
    }
    static void drawSquare(int size, int unitLength, int unitWidth){
        cout<< "Drawing Board Below:" << endl;
        cout << " ";
        for(int i = 0; i < size*unitWidth;i++){
            cout << "_";
        }
        cout<<" \n|";
        for(int i= 0;i<unitWidth*size;i++){
            cout<< " ";
        }
        cout<<"|" << endl;
        for(int i = 0; i < unitLength*size; i++){
            cout << "|";
            for(int i =0; i < unitWidth*size;i++){
                cout << " ";
            }
            cout<<"|" << endl;
        }
        cout << "|";
        for(int i = 0 ; i < unitWidth*size; i++){
            cout<< "_";
        }
        cout <<"|" << endl;
    }
    static vector<vector<string>> getCartesianPlane(){
        int planeWidth = 30;
        int planeLength = 10;
        vector<string> xAxis(planeWidth);
        vector<vector<string>> plane(planeLength,xAxis);
        vector<string> topYaxis;
        for(int i = 0; i < planeWidth; i++){
            if(i == planeWidth/2 ){
                topYaxis.push_back("^");
            }else{
                topYaxis.push_back(" ");
            }
        }
        plane[0] = (topYaxis);
        for(int i = 1; i < planeLength; i++){
            if(i==planeLength/2){
                plane[i].push_back("< ");
                for(int j = 0; j < planeWidth;j++){
                    if(j==planeWidth/2 -2){
                        plane[i].push_back("|");
                    }else{
                        plane[i].push_back("-");
                    }
                }
                plane[i].push_back(" >");
            }else{
                for(int j = 0; j < planeWidth;j++){
                    if(j==planeWidth/2){
                        plane[i].push_back("|");
                    }else{
                        plane[i].push_back(" ");
                    }
                }
            }
        }
        vector<string> bottomYaxis;
        for(int i = 0; i < planeWidth; i++){
            if(i == planeWidth/2){
                bottomYaxis.push_back("v");
            }else{
                bottomYaxis.push_back(" ");
            }
        }
        plane.push_back(bottomYaxis);
        return plane;
    }
    static void debugGraphic(vector<vector<string>> graphic){
        cout << "Graphic has " << graphic.size() << " lines" << endl;
        int characters = 0;
        for(auto i: graphic){
            characters+=i.size();
        }
        cout << "It has " << characters << " characters" << endl;
    }
    static void drawCartesian(){
        vector<vector<string>> cartesianPlane = getCartesianPlane();
        //debugGraphic(cartesianPlane);
        printGraphic(cartesianPlane);
    }
};