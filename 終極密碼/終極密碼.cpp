#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void PlayerInput(); //玩家輸入
void ComputerInput(); //電腦輸入
void judge(int, int); //判斷數字
void play(); //遊戲主框架
int again(); //是否在開局
int LowerBound, UpperBound; //上下限
int ans; //答案
int keep; //是否結束
int win = 0; //判斷獲勝
int TimesForWin[2] = {};

int main(){
    srand(time(NULL));
    do{
        LowerBound = 0;
        UpperBound = 100;
        win = 0;
      play();
    }while(again());
}

void play(){
    system("clear");
    cout << "Player's win : " << TimesForWin[0] << "\n";
    cout << "Computer's win : " << TimesForWin[1] << "\n\n";
    ans = rand() % 99 + 1;
    keep = 1;
    do{
        
        PlayerInput(); 
        if(keep)
            system("clear");
            ComputerInput();
    }while(keep);
}


void PlayerInput(){
    cout << "\nKey number is between " << LowerBound << " and " << UpperBound;
    cout << "\nPlease enter your guess : ";
    int guess;
    cin >> guess;
    judge(guess, 1);
}

void ComputerInput(){
    cout << "\nKey number is between " << LowerBound << " and " << UpperBound;
    int guess = rand() % (UpperBound - LowerBound - 1) + LowerBound + 1;
    cout << "\nComputer's guess is : " << guess << "\n";
    judge(guess, 2);
}

void judge(int input, int who){
    if(input == ans){
        win = who;
        keep = 0;
    }else if(input < ans && input > LowerBound){
        LowerBound = input;
    }else if(input > ans && input < UpperBound){
        UpperBound = input;
    }else{
        cout << "Invalid Input";
        PlayerInput();
    }
}

int again(){
    if(win == 1){
        cout << "You got the answer!\n";
        TimesForWin[win - 1] += 1;
    }else if(win == 2){
        cout << "Computer got the answer!\n\n";
        TimesForWin[win - 1] += 1;
    }
    cout << "Press 1 to restart, press 0 to exit : ";
    int ask;
    cin >> ask;
    return ask;
}
