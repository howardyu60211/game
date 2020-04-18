#include <iostream>
#include <windows.h>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#define UP 72
#define LEFT 75
#define DOWN 80
#define RIGHT 77
#define DIRECTION 224
#define BORDER 4
using namespace std;
//int gotoxy(int,int);
void newnum();               // 生成新數字 
void up();	                 // 上 
void down();                 // 下 
void right();                // 右 
void left();                 // 左 
void winfin(double,double);		//改int 
void losefin(double,double);		//改int 
int block[BORDER][BORDER] = {0};
int checkblock[BORDER][BORDER] = {0};
int point = 0;
int check = 3;
void copy();                 // 複製到 checkbolock  
void Align_display();        // 顯示+對齊 
int win();                 // 勝利判斷 
bool restart();
int judgment = 3;
int main(){
	while(true){
		double start,end;
		for (int x = 0; x < BORDER; x++) {
	  		for (int y = 0; y < BORDER; y++) {
	            		block[x][y] = 0;
	            		checkblock[x][y] = 0;
	        }
	    }
		checkblock[0][0] = 1;
		newnum();
		copy();
		Align_display();
		int keep;
		int key;
		start = clock();
		while(key = getch()){	
			if(key == DIRECTION){
				key = getch();
	            		copy();
				switch(key){
					case UP:
						up();
						break;
					case DOWN:
						down();
						break;
					case RIGHT:
						right();
						break;
					case LEFT:
						left();
						break;
				}
				Align_display();
				
				check = win();
				if(check == 0){
					winfin(start,end);
					keep = restart();
					break;
				}else if(check == 1){
					losefin(start,end);
					keep = restart();
					break;
				}
				cout << "\n 分數：" << point; 
			}	
		}
		if(!keep) break;
	}
	return 0;
}

void newnum() {
    int check = 1;
    if (check == 1){
        srand((unsigned)time(NULL));
        while(1){
            int all = rand() % (BORDER * BORDER);
            int x = all / BORDER;
            int y = all % BORDER;
            if (block[x][y] != 0) {
                continue;
            }else{
            	int newadd = rand() % 10;
            	if(newadd == 0){
            		block[x][y] = BORDER;
				}else{
                	block[x][y] = 2;
				}
            }
	break;
        }
    }
}

void Align_display(){
	system("cls");
	for (int x = 0; x < BORDER; x++) {
        for (int y = 0; y < BORDER; y++) {
           	cout << setw(5) << block[x][y];
        }
        cout << "\n\n";
    }
}
void copy(){
	for (int x = 0; x < BORDER; x++) {
        for (int y = 0; y < BORDER; y++) {
            checkblock[x][y] = block[x][y];
            //cout << block[x][y];
        }
    }	
}
void up(){
	int add = 0;
	copy();
	for(int time = 0; time < BORDER - 1; time++){
		for(int x = 0; x < BORDER - 1; x++){
			for(int y = 0; y < BORDER; y++){
				if(block[x][y] == 0){
					block[x][y] = block[x+1][y];
					block[x+1][y] = 0;
				}
			}
		}
	}
	for(int x = 0; x < BORDER - 1; x++){
		for(int y = 0; y < BORDER; y++){
			if(block[x+1][y] == block[x][y]){
				point += block[x][y];
				block[x][y] += block[x+1][y];
				block[x+1][y] = 0; 
			}
		}
	}
	for(int time = 0; time < BORDER - 1; time++){
		for(int x = 0; x < BORDER - 1; x++){
			for(int y = 0; y < BORDER; y++){
				if(block[x][y] == 0){
					block[x][y] = block[x+1][y];
					block[x+1][y] = 0;
				}
			}
		}
	}
	for(int x = 0; x < BORDER; x++){
		for(int y = 0; y < BORDER; y++){
			if(checkblock[x][y] != block[x][y]){
				add += 1;
	     		break;
			}	
		}
	}
	if(add != 0){
		newnum();
	}
}
void down(){
	int add = 0;
	copy();
	for(int time = 0; time < BORDER - 1; time++){
		for(int x = BORDER - 1; x > 0; x--){
			for(int y = 0; y < BORDER; y++){
				if(block[x][y] == 0){
					block[x][y] = block[x-1][y];
					block[x-1][y] = 0;
				}
			}
		}
	}
	for(int x = BORDER - 1; x > 0; x--){
		for(int y = 0; y < BORDER; y++){
			if(block[x][y] == block[x-1][y]){
				point += block[x][y];
				block[x][y] += block[x-1][y];
				block[x-1][y] = 0; 
			}
		}
	}
	for(int time = 0; time < BORDER - 1; time++){
		for(int x = BORDER - 1; x > 0; x--){
			for(int y = 0; y < BORDER; y++){
				if(block[x][y] == 0){
					block[x][y] = block[x-1][y];
					block[x-1][y] = 0;
				}
			}
		}
	}
	for(int x = 0; x < BORDER; x++){
		for(int y = 0; y < BORDER; y++){
			if(checkblock[x][y] != block[x][y]){
				add += 1;
	     		break;
			}	
		}
	}
	
	if(add != 0){
		newnum();
	}
}
void right(){
	int add = 0;
	copy();
	for(int time = 0; time < BORDER - 1; time++){
		for(int x = 0; x < BORDER; x++){
			for(int y = BORDER - 1; y > 0; y--){
				if(block[x][y] == 0){
					block[x][y] = block[x][y-1];
					block[x][y-1] = 0;
				}
			}
		}
	}
	for(int x = 0; x < BORDER; x++){
		for(int y = BORDER - 1; y > 0; y--){
			if(block[x][y] == block[x][y-1]){
				point += block[x][y];
				block[x][y] += block[x][y-1];
				block[x][y-1] = 0; 
			}
		}
	}
	for(int time = 0; time < BORDER - 1; time++){
		for(int x = 0; x < BORDER; x++){
			for(int y = BORDER - 1; y > 0; y--){
				if(block[x][y] == 0){
					block[x][y] = block[x][y-1];
					block[x][y-1] = 0;
				}
			}
		}
	}
	for(int x = 0; x < BORDER; x++){
		for(int y = 0; y < BORDER; y++){
			if(checkblock[x][y] != block[x][y]){
				add += 1;
	     		break;
			}	
		}
	}
	
	if(add != 0){
		newnum();
	}
}
void left(){
	int add = 0;
	copy();
	for(int time = 0; time < BORDER - 1; time++){
		for(int x = 0; x < BORDER; x++){
			for(int y = 0; y < BORDER - 1; y++){
				if(block[x][y] == 0){
					block[x][y] = block[x][y+1];
					block[x][y+1] = 0;
				}
			}
		}
	}
	for(int x = 0; x < BORDER; x++){
		for(int y = 0; y < BORDER - 1; y++){
			if(block[x][y] == block[x][y+1]){ 
				point += block[x][y];
				block[x][y] += block[x][y+1];
				block[x][y+1] = 0;
			}
		}
	}
	for(int time = 0; time < BORDER - 1; time++){
		for(int x = 0; x < BORDER; x++){
			for(int y = 0; y < BORDER - 1; y++){
				if(block[x][y] == 0){
					block[x][y] = block[x][y+1];
					block[x][y+1] = 0;
				}
			}
		}
	}
	for(int x = 0; x < BORDER; x++){
		for(int y = 0; y < BORDER; y++){
			if(checkblock[x][y] != block[x][y]){
				add += 1;
	     		break;
			}	
		}
	}
	if(add != 0){
		newnum();
	}
}
int win(){
	int full = 1;          // 0未滿 1滿 
	for(int  x = 0; x < BORDER; x++){
		for(int y = 0; y < BORDER; y++){
			if(block[x][y] == 2048) {
				return 0;
			}
		} 
	}
	for(int x = 0; x < BORDER; x++){
		for(int y = 0; y < BORDER; y++){
			if(block[x][y] == 0){
				full = 0;
			}
		} 
	}
	for(int x = 0; x < BORDER; x++){
		for(int y = 0; y < BORDER; y++){
			if( x - 1 > 0 && block[x][y] == block[x - 1][y] ||
				x + 1 < BORDER && block[x][y] == block[x + 1][y] ||
				y + 1 < BORDER && block[x][y] == block[x][y + 1] ||
				y - 1 > 0 && block[x][y] == block[x][y - 1]){
				full = 0;
				break;
			}
		}
	} 
	if(full == 1){
		return 1;
	}
	return 3;
}

void winfin(double start,double end){
	cout << "\n You Win\n Your grade is : " << point;
	end = clock();
	cout << "\n 花費時間：" <<  (end - start) / 1000 << " S"; 
}

void losefin(double start,double end){
	cout << "\n You'er lose, keep working\n Your grade is : " << point;
	end = clock();
	cout << "\n 花費時間：" <<  (end - start) / 1000 << " S"; 
}

bool restart(){
	bool rst;
	cout << "\n\n輸入0以結束，輸入1以繼續：";
	cin >> rst;
	return rst;
}

/*void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}  */
