/*
(2-1)
OpenCV���� ����ϴ� �پ��� Ŭ������ �Լ��� ����Ǿ� �ִ� opencv.hpp ��� ������ ����
opencv.hpp ������ OpenCV ��� ������ �� �ִ� ���� ��ġ���� opencv2��� �̸��� ���� ���� �ȿ� �ֱ� ������
#include "opencv2/opencv.cpp" ���·� �ڵ带 �Է��ؾ� ��
*/
#include "opencv2/opencv.hpp"

// (2-1) C++ ǥ�� ����� ���� iostream ��� ���� ����
#include <iostream>


int main() {
	/*
	(2-1)
	C++ ǥ�� ������� OpenCV ���̺귯���� ������ ����ϴ� �ڵ�
	�ҽ� �ڵ忡�� ���� CV_VERSION�� ��ǻ�Ϳ� ��ġ�Ǿ� �ִ� OpenCV ���̺귯���� ���� ������ ���ڿ� ���·� ������ ��ũ��
	���� �ǽ� ȯ�濡�� OpenCV 4.10.0 ������ ����ϱ� ������ CV_VERSION���� "4.0.0" ���ڿ��� ����Ǿ� ����
	*/
	std::cout << "Hello OpenCV " << CV_VERSION << std::endl;

	// (2-3) cv�� std ���ӽ����̽��� ����ϵ��� �����Ͽ� ���� �ҽ� �ڵ忡�� cv::�� std::�� ����
	using namespace std;
	using namespace cv;

	// (2-2) Mat Ŭ���� Ÿ���� ���� img ����
	Mat img;

	/* 
	(2-2)
	OpenCV���� �����ϴ� imread() �Լ��� ����Ͽ� lenna.bmp ������ �ҷ��ͼ� img ������ ����
	imread() �Լ� �̸��� ���� �б�(image read)�� ���ϸ�, imread() �Լ��� cv ���ӽ����̽� �ȿ��� ����Ǿ��� ������ cv::imread() ���·� ���
	*/
	img = imread("lenna.bmp");

	/*
	(2-2)
	lenna.bmp ������ ����� �ҷ����� ������ ��쿡 ���� ���� ó�� �ڵ�
	���α׷� ���� ���͸��� lenna.bmp ������ �������� �ʰų� Ȥ�� lenna.bmp ������ �ջ�Ǿ� ����� �ҷ����� ���� ���, Mat Ŭ������ �ɹ� �Լ� Mat::empty()�� true�� ��ȯ
	���� Mat::empty() �Լ��� true�� ��ȯ�Ͽ� if�� ��� ������ �����ϸ� "Image load failed!'��� ���ڿ��� ����� �� ���α׷��� ����
	���������� lenna.bmp ������ �ҷ����� if�� ��� �Ʒ��� �ڵ尡 ����
	*/
	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	// (2-2) namedWindow() �Լ��� �̿��Ͽ� ������ ȭ�鿡 ��Ÿ���� ���� ���ο� â�� �����ϰ�, �� â�� "image"��� �̸��� �ο�
	namedWindow("image");
	/*
	(2-2)
	imshow() �Լ��� �̿��Ͽ� "image"��� �̸��� â�� img ��ü�� ������ �ִ� lenna.bmp ������ ���
	imshow() �Լ� �̸��� ���� ���� �ֱ�(image show)�� �ǹ�
	*/
	imshow("image", img);

	/*
	(2-2)
	waitKey() �Լ��� ������� Ű���� �Է��� ��ٸ��� �Լ��̸�, ����ڰ� Ű���带 ������ ������ ������ ȭ�鿡 ��Ÿ���� �� ��
	���� ����ڰ� Ű���忡�� �ƹ� Ű�� ������ return ������ ���� ���α׷��� ����
	*/
	waitKey();
	return 0;
}