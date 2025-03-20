#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

/////////////////////////////////////////////////////// (5-1)

void brightness1() {

	// lenna.bmp ���� ������ �׷��̽����� �������� �ҷ��� src�� ����
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	// lenna.bmp ���� �ҷ����Ⱑ �����ϸ� ���� �޽����� ����ϰ� ����
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	// src ������ ��� �ȼ� ���� 100��ŭ ������Ų ��� ������ dst�� ����
	Mat dst = src + 100;

	// src�� �� â�� ���
	imshow("src", src);
	// dst�� �� â�� ���
	imshow("dst", dst);
	// Ű �Է��� ���� ������ ���
	waitKey();

	// ���� ��� â�� ��� ����
	destroyAllWindows();
 }

int main() {
	
	/////////////////////////////////////////////////////// (5-1)

	/*
	lenna.bmp ������ ��⸦ 100��ŭ �������� ȭ�鿡 ����ϴ� �Լ�
	*/

	brightness1();

	return 0;
}