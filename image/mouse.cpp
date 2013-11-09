#include<opencv2/opencv.hpp>

#pragma comment(lib,"opencv_imgproc242d.lib")
#pragma comment(lib,"opencv_core242d.lib")
#pragma comment(lib,"opencv_highgui242d.lib")

CvPoint   L_button_Point = cvPoint(-1,-1);
CvPoint   R_button_Point = cvPoint(-1,-1);

// �}�E�X�C�x���g�Ăяo���֐�
void on_mouse (int event, int x, int y, int flags, void *param)
{
	if ((event == CV_EVENT_LBUTTONDOWN)){ 	// �}�E�X���{�^���������ꂽ��
		L_button_Point = cvPoint (x, y);	// �_�ǉ�
	}
	if ((event == CV_EVENT_RBUTTONDOWN)){ 	// �}�E�X���{�^���������ꂽ��
		R_button_Point = cvPoint (x, y);	// �_�ǉ�
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
