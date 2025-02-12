#include <iostream>
#include <windows.h>
#include <time.h>
#include <vector>
#include <conio.h>

using namespace std;
const int height=20;
const int width=30;

int x,y,fruitX,fruitY;
int ntail;
int tailX[100],tailY[100];
int score=0;


bool gameOver;


enum eDirection{ stop=0, UP , DOWN , LEFT , RIGHT };
eDirection dir;


void setup(){
    gameOver=false;
    dir=stop;
    x=width/2;
    y=height/2;
    fruitX= 1 + rand() % (width-2);
    fruitY= 1 + rand() % (height-2);
}


void draw(){

    system("CLS");

    for(int i=0;i<width;i++){
        cout<<"#";
    }
    cout<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(j==0 || j==width-1){
                cout<<"#";
            }
            else if(i==y && j==x){
                cout<<"O";
            }
            else if(i==fruitY && j==fruitX){
                cout<<"*";
            }
            else  {

                bool print=false;
                for(int k=0;k<ntail;k++){
                    if(i==tailX[k] && j==tailY[k]){
                    cout<<"o";
                    print=true;
                    }
                }if(!print){
                cout<<" ";
            }
            }
            }
        cout<<endl;
    }
    for(int i=0;i<width;i++){
        cout<<"#";
    }
    cout<<endl<<endl;
    cout<<"Score : "<<score<<endl;
    return;
}


void input(){
    if(_kbhit()){
        switch(_getch()){
            case 'w':
            dir=UP;
            break;
            case 's' :
            dir=DOWN;
            break;
            case 'a' :
            dir=LEFT;
            break;
            case 'd' :
            dir=RIGHT;
            break;
            case 'x' :
            gameOver=true;
            break;
            default :
            break;
        }
    }
}


void logic(){

    int prevX=tailX[0];
    int prevY=tailY[0];
    tailX[0]=y;
    tailY[0]=x;
    int prev2X,prev2Y;

    for(int i=1;i<ntail;i++){
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
    switch(dir){
        case UP :
            y--;
            break;
        case DOWN :
            y++;
            break;
        case LEFT :
            x--;
            break;
        case RIGHT :
            x++;
            break;
        default :
            break;
    }
    if(x<0 || y<0 || x>=width-1 || y>=height){
            gameOver=true;
        }

    for(int i=0;i<ntail;i++){
        if(y==tailX[i] && x==tailY[i]){
            gameOver=true;
        }
    }

    if(x==fruitX && y==fruitY){
            score++;
            ntail++;
            fruitX= 1 + rand() % (width-2);
            fruitY= 1 + rand() % (height-2);
        }
}

void GameOver(){
        system("CLS");
    cout<<"GAME OVER"<<endl;
}

int main(){
    setup();
    while(!gameOver){
    draw();
    input();
    logic();
    Sleep(200);
    }
    while(gameOver){
        GameOver();
        break;
    }
    return 0;
}
