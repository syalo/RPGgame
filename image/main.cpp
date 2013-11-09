#include<opencv2/opencv.hpp>
#include"set.h"			//配列の初期化、mine設置用
#include"mouse.h"		//mouse処理用
#include"character.h"	//文字描画用。地雷の数を表示する
#include"reverse.h"
#include"clear_check.h"	//ゲームクリア判定
#pragma comment(lib,"opencv_imgproc242d.lib")
#pragma comment(lib,"opencv_core242d.lib")
#pragma comment(lib,"opencv_highgui242d.lib")
//tesadw
#define WIDTH 640				// ウィンドウの幅（ピクセル）
#define HEIGHT 480				// ウィンドウの高さ（ピクセル）

int main(int argc,char* argv[])
{
	int w, h;
	int board[12][12];//表示、非表示のフラグ格納用配列	
	int mask[12][12];

	int mine_sum = 10;
	IplImage *img,*img_out;
	int point[2];
	bool clear_flag = false;
	bool false_flag = false;

	if((img = cvCreateImage(cvSize(WIDTH, HEIGHT), IPL_DEPTH_32F, 3)) == NULL) {
		printf("画像リソースを確保できません。\n");
		return -1;
	}
	
	w = WIDTH, h = HEIGHT;
	img_out = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U, 3);	// 整数型画像リソース確保

	cvNamedWindow("mine_s");
	cvSetMouseCallback("mine_s", on_mouse, point);
	cvSet(img, cvScalar(0,0,0), 0);	// 画像リソース初期化
	
	img_set(img,h,w);		//imgに色を付ける
	map_set(board);			//board初期化
	map_set(mask);			//mask初期化
	mine_set(mask,mine_sum);//地雷セット
	mask_set(mask);

	while(1){
			//左クリックされた時の処理
			if(get_Lpoint().x != -1 && get_Lpoint().y != -1){
				L_button_reverse(get_Lpoint().x,get_Lpoint().y,board,mask);
				character(img,mask,board);
				//地雷を踏んだか調べる
				if(mask[get_Lpoint().y/40][get_Lpoint().x/40-1] == -2){
					false_flag = true;
				}
				set_Lpoint(-1,-1);
			}
			//GameClearCheck
			clear_flag = clear_check(board,mask,mine_sum);
			if(get_Rpoint().x != -1 && get_Rpoint().y != -1){
				R_button_reverse(get_Rpoint().x,get_Rpoint().y,board);
				exclamation_draw(img,board);
			}

		if(clear_flag){
			printf("GameClear\n");
			//break;
		}
		if(false_flag){
			printf("GameOver\n");
			//break;
		}
		cvConvertImage(img, img_out);	// 浮動小数点数型から整数型画像に変換
		cvShowImage("mine_s", img_out);			// 表示
		if(cvWaitKey(33) == 27) break;		// ESCを押した時終了
	
	}
	// ウィンドウ・キャプチャ・画像リソースの解放
	cvDestroyAllWindows();
	cvReleaseImage( &img_out);
 	cvReleaseImage( &img);
	return 0;
}



