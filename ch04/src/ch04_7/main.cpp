#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

/////////////////////////////////////////////////////// (4-16)

void mask_setTo() {

	// ���� ������ src ������ ����
	Mat src = imread("lenna.bmp", IMREAD_COLOR);
	// ����ũ ������ mask ������ ����
	Mat mask = imread("mask_smile.bmp", IMREAD_GRAYSCALE);

	// ���� ���� �Ǵ� ����ũ ���� �ε� ���� �� ó���� ���ܹ�
	if (src.empty() || mask.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	// mask ���󿡼� �ȼ� ���� 0�� �ƴ� ��ġ������ src ���� �ȼ��� ��������� ����
	src.setTo(Scalar(0, 255, 255), mask);

	// ����ũ ���� ó���� ���� ����� ����ũ ������ ���� â�� ���
	imshow("src", src);
	imshow("mask", mask);

	waitKey();
	destroyAllWindows();
}

/////////////////////////////////////////////////////// (4-17)

void mask_copyTo() {
	// airplane.bmp ����� ������ src ������ ����
	Mat src = imread("airplane.bmp");
	// mask_plane.bmp ����� ����ũ ������ mask ������ ����
	// mask�� �׷��� ������ �����̸�, 
	// src ���󿡼� ����Ⱑ �ִ� ��ġ������ �ȼ� ���� 255�̰� ������ ������ �ȼ� ���� 0
	Mat mask = imread("mask_plane.bmp");
	// field.bmp ���� ������ dst ������ ����
	Mat dst = imread("field.bmp");

	// ����� ����, ����� ����ũ ����, ���� ���� �� �ϳ� �̻��� ���� �ε� ���� �� ó���� ���ܹ�
	if (src.empty() || mask.empty() || dst.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	// mask ���󿡼� ��� ���� ��ġ�� �ش��ϴ� src ���� �ȼ� ���� dst�� ����
	// src�� dst ������ ���� ũ��� Ÿ���� �����Ƿ� dst ������ ���� �����ǰų� �ʱ�ȭ���� ����
	// ���� ����ũ ���� ���� ������ ����� ���� �ȼ� ���� �����
	src.copyTo(dst, mask);

	// ����ũ ������ ����� �ʵ� ������ ����Ǿ� �ִ� dst ������ â���� ���

	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

/////////////////////////////////////////////////////// (4-18)

// ����ȭ�� TickMeter Ŭ���� ����(���� ������� �ʴ� ���� �ڵ�)

class TickMeter {
public:
	// TickMeter �⺻ ������
	TickMeter();

	// �ð� ������ ������ �� ���
	void start();
	// �ð� ������ ���� �� ���
	void stop();
	// ���Ӱ� ���� �ð��� �����ϰ��� �� �� ����ϸ�, ��� ��� ���� ���� 0���� �ʱ�ȭ
	void reset();

	// ���� �ð��� ����ũ�� �� ������ ��ȯ
	double getTimeMicro() const;
	// ���� �ð��� �и��� ������ ��ȯ
	double getTimeMilli() const;
	// ���� �ð��� �� ������ ��ȯ
	double getTimeSec() const;
	// �ð� ������ ������ Ƚ���� ��ȯ
	int64 getCounter() const;
	// ...
};

/////////////////////////////////////////////////////// (4-19)

void time_inverse() {
	// ���� ������ �ε��Ͽ� src�� ����
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	// ���� ���� �ε� ���� �� ó���� ���ܹ�
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	// ���� ����� ���� ũ��, Ÿ���� ���� ���� ������(���) ���� ����
	Mat dst(src.rows, src.cols, src.type());

	// TickMeter Ŭ���� ��ü tm ����
	cv::TickMeter tm;
	// �ð� ���� ����
	tm.start();

	// src(���� ����)�� ��� �ȼ��� ������ ���� dst�� ����
	for (int j = 0; j < src.rows; ++j) {
		for (int i = 0; i < src.cols; ++i) {
			dst.at<uchar>(j, i) = 255 - src.at<uchar>(j, i);
		}
	}

	// �ð� ������ ����
	tm.stop();
	// ������ �ð��� �ܼ� â�� ���
	cout << " Image inverse took " << tm.getTimeMilli() << "ms." << endl;
}

int main() {
	
	/////////////////////////////////////////////////////// (4-16)

	/*
	lenna.bmp ���� ������ �Ϻ� ������ ���ؼ��� �ȼ� ���� ��������� �����ϴ� �Լ�
	��������� ������ ���� ������ mask_smile.bmp ������ ����
	*/

	mask_setTo();

	/*
	mask ������ �߾ӿ� ���� �� �κ��� ������� �����Ǿ� �ְ�, 
	������ ������ �ȼ� �� 0�� �ش��ϴ� ���������� ä���� ����
	����ũ ���󿡼� ������� ǥ�õ� ������ ���ؼ��� ���� ���� �ȼ��� ��������� ������
	*/

	/////////////////////////////////////////////////////// (4-17)

	/*
	����� ����� ����� ������ ��Ÿ���� ����ũ ����, �׸��� ���� ������ �̿��Ͽ� 
	���� ���� ����Ⱑ ���ư��� �ִ� ������ �ռ��ϴ� �Լ�
	*/

	mask_copyTo();

	/////////////////////////////////////////////////////// (4-19)

	/*
	for �ݺ����� �̿��Ͽ� ���� ������ ���� ������Ű��, �� �� �ҿ�Ǵ� ���� �ð��� �����Ͽ� �ܼ� â�� ����ϴ� �Լ�
	*/

	time_inverse();

	/*
	�� �Լ��� �ҽ� �ڵ��� ���� �ð��� �����ϴ� �ڵ��̹Ƿ� ������ ���� �����Ͽ� �����ؾ� ��
	����� ���� ������ ��쿡�� ������� ���� ������ �߰��Ǳ� ������ ���� ó�� ���� ���� ��Ȯ�� ���� �ð��� ������ �� ����
	*/

	return 0;
}