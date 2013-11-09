#include<opencv2/opencv.hpp>

#pragma comment(lib,"opencv_imgproc242d.lib")
#pragma comment(lib,"opencv_core242d.lib")
#pragma comment(lib,"opencv_highgui242d.lib")

#define BF(IMG, X,Y) ((float*)((IMG)->imageData + (IMG)->widthStep*(Y)))[(X)*3]
#define GF(IMG, X,Y) ((float*)((IMG)->imageData + (IMG)->widthStep*(Y)))[(X)*3+1]
#define RF(IMG, X,Y) ((float*)((IMG)->imageData + (IMG)->widthStep*(Y)))[(X)*3+2]

//文字表示用関数 左クリックしたときに発生する
void character(IplImage *img,int mask[12][12],int board[12][12]){
	//board[][]==0 非表示　==1表示 == -3 !表示
	CvFont font;
	for(int i = 1;i < 11;i++){
		for(int j = 1;j < 11;j++){
			if(board[i][j] == 1 /*&& board[i][j] == -3*/){
				switch(mask[i][j]){
				case 0:
					cvInitFont(&font,CV_FONT_HERSHEY_PLAIN,3.0,3.0,0,2,CV_AA);
					cvPutText(img,"0",cvPoint(j*40+43,i*40+40),&font,CV_RGB(255,255,255));
					break;
				case 1:
					cvInitFont(&font,CV_FONT_HERSHEY_PLAIN,3.0,3.0,0,2,CV_AA);
					cvPutText(img,"1",cvPoint(j*40+43,i*40+40),&font,CV_RGB(255,255,255));
					break;
				case 2:
					cvInitFont(&font,CV_FONT_HERSHEY_PLAIN,3.0,3.0,0,2,CV_AA);
					cvPutText(img,"2",cvPoint(j*40+43,i*40+40),&font,CV_RGB(255,255,255));
					break;
				case 3:
					cvInitFont(&font,CV_FONT_HERSHEY_PLAIN,3.0,3.0,0,2,CV_AA);
					cvPutText(img,"3",cvPoint(j*40+43,i*40+40),&font,CV_RGB(255,255,255));
					break;
				case 4:
					cvInitFont(&font,CV_FONT_HERSHEY_PLAIN,3.0,3.0,0,2,CV_AA);
					cvPutText(img,"4",cvPoint(j*40+43,i*40+40),&font,CV_RGB(255,255,255));
					break;
				case 5:
					cvInitFont(&font,CV_FONT_HERSHEY_PLAIN,3.0,3.0,0,2,CV_AA);
					cvPutText(img,"5",cvPoint(j*40+43,i*40+40),&font,CV_RGB(255,255,255));
					break;
				case 6:
					cvInitFont(&font,CV_FONT_HERSHEY_PLAIN,3.0,3.0,0,2,CV_AA);
					cvPutText(img,"6",cvPoint(j*40+43,i*40+40),&font,CV_RGB(255,255,255));
					break;
				case 7:
					cvInitFont(&font,CV_FONT_HERSHEY_PLAIN,3.0,3.0,0,2,CV_AA);
					cvPutText(img,"7",cvPoint(j*40+43,i*40+40),&font,CV_RGB(255,255,255));
					break;
				case 8:
					cvInitFont(&font,CV_FONT_HERSHEY_PLAIN,3.0,3.0,0,2,CV_AA);
					cvPutText(img,"8",cvPoint(j*40+43,i*40+40),&font,CV_RGB(255,255,255));
					break;
				case -2:
					cvInitFont(&font,CV_FONT_HERSHEY_PLAIN,3.0,3.0,0,2,CV_AA);
					cvPutText(img,"B",cvPoint(j*40+43,i*40+40),&font,CV_RGB(255,255,255));
					break;
				default:
					break;
				}
			}
		}
	}
}

//　!　表示用関数 右クリックしたときに発生する
void exclamation_draw(IplImage *img,int board[12][12]){
	
	CvFont font;
	
	for(int i = 1;i < 11;i++){
		for(int j = 1;j < 11;j++){
			if(board[i][j] == -3){
				cvInitFont(&font,CV_FONT_HERSHEY_PLAIN,3.0,3.0,0,2,CV_AA);
				cvPutText(img,"!",cvPoint(j*40+50,i*40+40),&font,CV_RGB(255,255,0));	
			}
		}
	}
}