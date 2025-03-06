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

/////////////////////////////////////////////////////// (4-7)

void drawPolys() {
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

	// �簢���� �β� 2�� ������ �׸�(������)
	rectangle(img, Rect(50, 50, 100, 50), Scalar(0, 0, 255), 2);
	// �簢�� ���θ� ä���� �׸�(����)
	rectangle(img, Rect(50, 150, 100, 50), Scalar(0, 0, 128), -1);

	// ������ 30�� ���� ���θ� ä���� �׸�(�ϴû�)
	circle(img, Point(300, 120), 30, Scalar(255, 255, 0), -1, LINE_AA);
	// ������ 60�� ���� �β� 3�� ������ �׸�(�Ķ���)
	circle(img, Point(300, 120), 60, Scalar(255, 0, 0), 3, LINE_AA);

	// Ÿ���� 0�ƺ��� 270�Ʊ��� ���θ� ä���� �׸�(�ϴû�)
	ellipse(img, Point(120, 300), Size(60, 30), 20, 0, 270, Scalar(255, 255, 0), -1, LINE_AA);
	// Ÿ���� �β� 2�� ������ �׸�(���)
	ellipse(img, Point(120, 300), Size(100, 50), 20, 0, 360, Scalar(0, 255, 0), 2, LINE_AA);

	// ��� ����� �ٰ����� �β� 2�� ������ �׸�(�����)
	vector<Point> pts;
	pts.push_back(Point(250, 250)); pts.push_back(Point(300, 250));
	pts.push_back(Point(300, 300)); pts.push_back(Point(350, 300));
	pts.push_back(Point(350, 350)); pts.push_back(Point(250, 350));
	polylines(img, pts, true, Scalar(255, 0, 255), 2);

	imshow("img", img);
	waitKey();

	destroyAllWindows();
}

/////////////////////////////////////////////////////// (4-8)

void drawText() {
	Mat img(500, 800, CV_8UC3, Scalar(255, 255, 255));

	// �پ��� ��Ʈ�� �̿��Ͽ� ���ڿ� ���
	putText(img, "FONT_HERSHEY_SIMPLEX", Point(20, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255));
	putText(img, "FONT_HERSHEY_PLAIN", Point(20, 100), FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255));
	putText(img, "FONT_HERSHEY_DUPLEX", Point(20, 150), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255));
	putText(img, "FONT_HERSHEY_COMPLEX", Point(20, 200), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255));
	putText(img, "FONT_HERSHEY_TRIPLEX", Point(20, 250), FONT_HERSHEY_TRIPLEX, 1, Scalar(0, 0, 255));
	putText(img, "FONT_HERSHEY_COMPLEX_SMALL", Point(20, 300), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(0, 0, 255));
	putText(img, "FONT_HERSHEY_SCRIPT_SIMPLEX", Point(20, 350), FONT_HERSHEY_SCRIPT_SIMPLEX, 1, Scalar(0, 0, 255));
	putText(img, "FONT_HERSHEY_SCRIPT_COMPLEX", Point(20, 400), FONT_HERSHEY_SCRIPT_COMPLEX, 1, Scalar(0, 0, 255));
	// FONT_HERSHEY_COMPLEX ��Ʈ�� FONT_ITALIC ����� �Բ� ����Ͽ� ���Ÿ�ü�� ���ڿ��� ���
	putText(img, "FONT_HERSHEY_COMPLEX | FONT_ITALIC", Point(20, 450), FONT_HERSHEY_COMPLEX | FONT_ITALIC, 1, Scalar(0, 0, 255));

	imshow("img", img);
	waitKey();
}

/////////////////////////////////////////////////////// (4-9)

void drawText2() {
	Mat img(200, 640, CV_8UC3, Scalar(255, 255, 255));

	// ����� ���ڿ��� ��Ʈ ����, ũ�� ����, �� �β� ����
	const String text = "Hello, OpenCV";
	int fontFace = FONT_HERSHEY_TRIPLEX;
	double fontScale = 2.0;
	int thickness = 1;

	// ����� ���ڿ��� ������ �簢�� ������ ũ�⸦ ���Ͽ� sizeText ������ ����
	Size sizeText = getTextSize(text, fontFace, fontScale, thickness, 0);
	// ����� ��� ���� ũ�⸦ sizeImg ������ ����
	Size sizeImg = img.size();

	// sizeText�� sizeImg ũ�� ������ �̿��Ͽ� ���ڿ��� ����� ��ǥ�� ���
	Point org((sizeImg.width - sizeText.width) / 2, (sizeImg.height + sizeText.height) / 2);
	// ���� ���ڿ��� ����ϰ� ���ڿ��� ���δ� �簢�� ������ �׸�
	putText(img, text, org, fontFace, fontScale, Scalar(255, 0, 0), thickness);
	rectangle(img, org, org + Point(sizeText.width, -sizeText.height), Scalar(255, 0, 0), 1);

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

	/////////////////////////////////////////////////////// (4-7)

	/*
	������� �ʱ�ȭ�� 400 �� 400 ũ���� ���� �پ��� �簢��, ��, Ÿ��, �ٰ����� �׷��� ȭ�鿡 ����ϴ� �Լ�
	*/

	drawPolys();

	/*
	imgâ ���� ��ܿ� �׷��� �� ���� �簢���� ù 2���� rectangle() �Լ� ���� ���
	������ �簢���� �β��� 2�� ����, ���� �簢���� �β��� -1�� �����Ͽ� ���θ� ä��

	imgâ ���� ��ܿ� �׷��� �� ���� ���� �� ���� 2���� circle() �Լ� ���� ���
	�� ���� ���� �߽� ��ǥ�� ������ ������ �ϴû� ���� �������� 30�̰� ���ΰ� ä���� �ְ�, �Ķ��� ���� �������� 60�̰� ���θ� ä���� �ʰ� �� �β��� 3���� ������

	imgâ ���� �ϴܿ� �׷��� Ÿ���� ȣ�� �� ���� 2���� ellipse() �Լ� ���� ���
	Ÿ���� ȣ�� ���� �߽� ��ǥ�� ������ ������ �ϴû� ȣ�� �������� 60, 30�̰� 0�ƺ��� 270�Ʊ��� ���θ� ä�� ȣ�̰�, ��� Ÿ���� �������� 120, 300�̰� �� �β��� 2�� �����Ǿ� ���θ� ä���� ���� Ÿ��

	imgâ ���� �ϴܿ� �׷��� �ٰ����� ������ polylines() �Լ� ���� ���
	������ ��ǥ�� �ǹ��ϴ� Point ��ü���� ������ vector �迭�� �̿��Ͽ� ��� ����� �ٰ����� �׸�
	*/

	/////////////////////////////////////////////////////// (4-8)

	/*
	800 �� 500 ũ���� ��� ���� �پ��� ��Ʈ�� ���ڿ��� ����ϴ� �Լ�
	*/

	drawText();

	/*
	�� putText() �Լ��� ���� ��µǴ� ���ڿ����� ��Ʈ ��� �̸��� �����Ͽ� ���
	*/

	/////////////////////////////////////////////////////// (4-9)

	/*
	640 �� 200 ũ���� ��� ���� ���߾ӿ� "Hello, OpenCV" ���ڿ��� ����ϴ� �Լ�
	*/

	drawText2();

	/*
	img.size() �ڵ带 �̿��Ͽ� img ���� ũ�⸦ sizeImg ������ ����
	����� ���ڿ��� ������ ������ ũ��� getTextSize() �Լ��� �̿��Ͽ� sizeText ������ ����
	�� �� ���� Size �������� �̿��Ͽ� ���ڿ��� ��µ� �簢�� ������ ���� �ϴ� ��ǥ ��� ����
	*/

	return 0;
}