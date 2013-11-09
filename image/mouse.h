#include<opencv2/opencv.hpp>

#pragma comment(lib,"opencv_imgproc242d.lib")
#pragma comment(lib,"opencv_core242d.lib")
#pragma comment(lib,"opencv_highgui242d.lib")

void on_mouse (int event, int x, int y, int flags, void *param);
CvPoint get_Lpoint();
void set_Lpoint(int,int);
CvPoint get_Rpoint();
void set_Rpoint(int,int);