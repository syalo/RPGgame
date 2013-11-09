#include<stdlib.h>
#include <time.h>
#include<opencv2/opencv.hpp>

#pragma comment(lib,"opencv_imgproc242d.lib")
#pragma comment(lib,"opencv_core242d.lib")
#pragma comment(lib,"opencv_highgui242d.lib")

#define MINE -2

#define BF(IMG, X,Y) ((float*)((IMG)->imageData + (IMG)->widthStep*(Y)))[(X)*3]
#define GF(IMG, X,Y) ((float*)((IMG)->imageData + (IMG)->widthStep*(Y)))[(X)*3+1]
#define RF(IMG, X,Y) ((float*)((IMG)->imageData + (IMG)->widthStep*(Y)))[(X)*3+2]

void mask_set(int mask[12][12]){
	int count;
	for(int i = 1;i < 11;i++){
		for(int j = 1;j < 11;j++){
			count = 0;
			if(mask[i][j] != MINE){
				//boardに地雷の数を入れる
				if(mask[i-1][j-1] == MINE)count++;
				if(mask[i-1][j] == MINE)count++;
				if(mask[i-1][j+1] == MINE)count++;
				if(mask[i][j-1] == MINE)count++;
				if(mask[i][j+1] == MINE)count++;
				if(mask[i+1][j-1] == MINE)count++;
				if(mask[i+1][j] == MINE)count++;
				if(mask[i+1][j+1] == MINE)count++;
				mask[i][j] = count;
			}
		}
	}
}



//地雷設置
void mine_set(int mask[12][12],int mine_sum){
	
	int a,b;
	srand((unsigned)time(NULL));
	for(int i = 1;i <= mine_sum;i++){
		a = rand()%10+1;
		b = rand()%10+1;
		if(mask[a][b] != MINE){
			mask[a][b] = MINE;
		}else{
			i--;
		}
	}
}

//配列の初期化
void map_set(int map[12][12]){
	
	int i,j;

	for(i = 0;i < 12;i++){
		for(j = 0;j < 12;j++){
			if(i == 0 || i == 11 || j == 0 || j ==11){
				map[i][j] = -1;
			}else{
				map[i][j] = 0;
			}
		}
	}
}

//色づけ用関数
void img_set(IplImage *img ,int h,int w){
	
	int i,j; 	
	
	for(i = 0;i < h;i++){
		for(j = 0;j < w;j++){
			if(i >= 40 && i <= 440 && j >= 80 && j <= 480){
				if(i % 40 == 0 || j % 40 == 0){
					BF(img,j,i) = 255;
					GF(img,j,i) = 255;
					RF(img,j,i) = 255;
				}else{
					BF(img,j,i) = 100;
					GF(img,j,i) = 0;
					RF(img,j,i) = 100;
				}
			}else{
				BF(img,j,i) = 0;
				GF(img,j,i) = 100;
				RF(img,j,i) = 0;
			}
		}
	}
}
