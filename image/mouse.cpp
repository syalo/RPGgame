#include<opencv2/opencv.hpp>

#pragma comment(lib,"opencv_imgproc242d.lib")
#pragma comment(lib,"opencv_core242d.lib")
#pragma comment(lib,"opencv_highgui242d.lib")

CvPoint   L_button_Point = cvPoint(-1,-1);
CvPoint   R_button_Point = cvPoint(-1,-1);

// マウスイベント呼び出し関数
void on_mouse (int event, int x, int y, int flags, void *param)
{
	if ((event == CV_EVENT_LBUTTONDOWN)){ 	// マウス左ボタンが押された時
		L_button_Point = cvPoint (x, y);	// 点追加
	}
	if ((event == CV_EVENT_RBUTTONDOWN)){ 	// マウス左ボタンが押された時
		R_button_Point = cvPoint (x, y);	// 点追加
	}

}

CvPoint get_Lpoint(){
		return L_button_Point;
}
void set_Lpoint(int x,int y){
		L_button_Point = cvPoint(x,y);
}

CvPoint get_Rpoint(){
		return R_button_Point;
}
void set_Rpoint(int x,int y){
		R_button_Point = cvPoint(x,y);
}
