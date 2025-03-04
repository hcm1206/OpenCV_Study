#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

/////////////////////////////////////////////////////// (4-6)

void drawLines() {

	// 400 �� 400 ũ���� 3ä�� �÷� ������ �����ϰ�, ��� �ȼ��� ������� �ʱ�ȭ
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

	// ���� ������ ���� �� ���� ���� �ٸ� ����� �β��� �׸�
	line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255));
	line(img, Point(50, 100), Point(200, 100), Scalar(255, 0, 255), 3);
	line(img, Point(50, 150), Point(200, 150), Scalar(255, 0, 0), 10);

	// �밢�� ������ ���� �� ���� ���� �ٸ� ����� ���� Ÿ������ �׸�
	line(img, Point(250, 50), Point(350, 100), Scalar(0, 0, 255), 1, LINE_4);
	line(img, Point(250, 70), Point(350, 120), Scalar(255, 0, 255), 1, LINE_8);
	line(img, Point(250, 90), Point(350, 140), Scalar(255, 0, 0), 1, LINE_AA);

	// ���� ������ ȭ��ǥ �� ���� ���� �ٸ� ����� ���� Ÿ������ �׸�
	arrowedLine(img, Point(50, 200), Point(150, 200), Scalar(0, 0, 255), 1);
	arrowedLine(img, Point(50, 250), Point(350, 250), Scalar(255, 0, 255), 1);
	arrowedLine(img, Point(50, 300), Point(350, 300), Scalar(255, 0, 0), 1, LINE_8, 0, 0.05);

	// �پ��� ����� ��Ŀ�� �׸�
	drawMarker(img, Point(50, 350), Scalar(0, 0, 255), MARKER_CROSS);
	drawMarker(img, Point(100, 350), Scalar(0, 0, 255), MARKER_TILTED_CROSS);
	drawMarker(img, Point(150, 350), Scalar(0, 0, 255), MARKER_STAR);
	drawMarker(img, Point(200, 350), Scalar(0, 0, 255), MARKER_DIAMOND);
	drawMarker(img, Point(250, 350), Scalar(0, 0, 255), MARKER_SQUARE);
	drawMarker(img, Point(300, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_UP);
	drawMarker(img, Point(350, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_DOWN);

	imshow("img", img);
	waitKey();

	destroyAllWindows();

}

int main() {

	/////////////////////////////////////////////////////// (4-6)

	/*
	������� �ʱ�ȭ�� 400��400 ũ�� ���� �پ��� ������ ȭ��ǥ ���� �׸��� ȭ�鿡 ��Ÿ���� �Լ�
	*/

	drawLines();

	/*
	imgâ ���� ��ܿ� �׷��� �� ���� ������ ù 3���� line() �Լ��� ���� �׸��� ���
	�� ���� �� �� ���� ������ ������ �� �β��� 1�� ����, ������� �Ķ��� ������ �� �β��� ���� 3�� 10���� ����

	imgâ ���� ��ܿ� �׷��� �� ���� �缱�� �� ���� 3���� line() �Լ� ���� ���
	�� �缱 �� �� ���� ������ �缱�� ���� Ÿ���� LINE_4��, ��� ����� �缱�� LINE_8��, ������ �Ķ��� �缱�� LINE_AA Ÿ������ �׸� ����
	LINE_4 Ÿ������ �׸� ������ �����¿� �� �������� ������ ����Ǿ� �ְ�, LINE_8 Ÿ���� ������ �ȼ��� �밢�� �������ε� ����Ǿ� ������, LINE_AA Ÿ���� ������ ��Ƽ���ϸ����(anti-aliasing) ����� ����Ǿ� �ε巯�� ���̰� �����

	imgâ �߰��� �׷��� �� ���� ȭ��ǥ ������ 3���� arrowedLine() �Լ� ���� ���
	�� ���� ������ ȭ��ǥ ������ ����� ȭ��ǥ ������ �׸��� ����� �����ϰ� �ڵ尡 �ԷµǾ� ������ ���̰� �ٸ��� ������ ȭ��ǥ ũ�⵵ �ٸ�
	���� ���̰� �� ������ ���Ͽ� ȭ��ǥ ũ�⸦ �۰� �׸����� �Ķ��� ȭ��ǥ ���� �ڵ�ó�� tipLength�� ���� �⺻���� 0.1���� �۰� �ۼ��ϸ� ��

	�� �Ʒ��� �׷��� �ϰ� ���� ������ drawMarker() �Լ��� ���� �׷��� ��Ŀ
	���� ���ʺ��� ���ʴ�� MARKER_CROSS, MARKER_TILTED_CROSS, MARKER_STAR, MARKER_DIAMOND, MARKER_SQUARE, MARKER_TRIANGLE_UP, MARKER_TRIANGLE_DOWN�� �ش��ϴ� ��Ŀ ������ �׸� ���
	*/

	return 0;
}