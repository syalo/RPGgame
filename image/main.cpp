#include<opencv2/opencv.hpp>
#include"set.h"			//�z��̏������Amine�ݒu�p
#include"mouse.h"		//mouse�����p
#include"character.h"	//�����`��p�B�n���̐���\������
#include"reverse.h"
#include"clear_check.h"	//�Q�[���N���A����
#pragma comment(lib,"opencv_imgproc242d.lib")
#pragma comment(lib,"opencv_core242d.lib")
#pragma comment(lib,"opencv_highgui242d.lib")
//tesadw
#define WIDTH 640				// �E�B���h�E�̕��i�s�N�Z���j
#define HEIGHT 480				// �E�B���h�E�̍����i�s�N�Z���j

int main(int argc,char* argv[])
{
	int w, h;
	int board[12][12];//�\���A��\���̃t���O�i�[�p�z��	
	int mask[12][12];

	int mine_sum = 10;
	IplImage *img,*img_out;
	int point[2];
	bool clear_flag = false;
	bool false_flag = false;

	if((img = cvCreateImage(cvSize(WIDTH, HEIGHT), IPL_DEPTH_32F, 3)) == NULL) {
		printf("�摜���\�[�X���m�ۂł��܂���B\n");
		return -1;
	}
	
	w = WIDTH, h = HEIGHT;
	img_out = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U, 3);	// �����^�摜���\�[�X�m��

	cvNamedWindow("mine_s");
	cvSetMouseCallback("mine_s", on_mouse, point);
	cvSet(img, cvScalar(0,0,0), 0);	// �摜���\�[�X������
	
	img_set(img,h,w);		//img�ɐF��t����
	map_set(board);			//board������
	map_set(mask);			//mask������
	mine_set(mask,mine_sum);//�n���Z�b�g
	mask_set(mask);

	while(1){
			//���N���b�N���ꂽ���̏���
			if(get_Lpoint().x != -1 && get_Lpoint().y != -1){
				L_button_reverse(get_Lpoint().x,get_Lpoint().y,board,mask);
				character(img,mask,board);
				//�n���𓥂񂾂����ׂ�
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
		cvConvertImage(img, img_out);	// ���������_���^���琮���^�摜�ɕϊ�
		cvShowImage("mine_s", img_out);			// �\��
		if(cvWaitKey(33) == 27) break;		// ESC�����������I��
	
	}
	// �E�B���h�E�E�L���v�`���E�摜���\�[�X�̉��
	cvDestroyAllWindows();
	cvReleaseImage( &img_out);
 	cvReleaseImage( &img);
	return 0;
}



