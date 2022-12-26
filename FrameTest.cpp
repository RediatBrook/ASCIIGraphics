#include "ASCII.cpp"
bool isNum(string number){
    for(auto i: number){
        if(!isdigit(i)){
            return false;
        }
        return true;
    }
}
int main(int argc, char *argv[]){
    string text;
    int width = ASCII::maxWidth;
    int i;
    if(argc>=2){
        for(i = 1; i < argc-1; i++){
        if(i==1){
            if(isNum(argv[1])){
                width = stoi(argv[1]);
            }else{
                text+=(argv[i]);
                text+=" ";
            }
        }else{
            text+=(argv[i]);
            text+=" ";
        }
    }
    text+=argv[i];
    if(width==ASCII::maxWidth){
        ASCII::frameText(text);
    }else{
        ASCII::frameText(text,width);
    }
    }else{
        cout << "USAGE: [Optional: printWidth] [Required: Text]" << endl;
    }
    return 0;
}