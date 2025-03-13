#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

/*
image �̸��� �� â�� 0���� 16 ������ ���� ������ �� �ִ� Ʈ���ٸ� �����ϴ� ���α׷�
Ʈ���� �ݹ� �Լ��� ��ϵ� on_level_change() �Լ��� ����ڰ� ������ Ʈ���� ��ġ�� 16�� ���Ͽ� ������ ��ü �ȼ� ������ ����
��, �׷��̽����� ������ 16�ܰ�� ������
*/

// Ʈ���� �ݹ� �Լ� ����
void on_level_change(int pos, void* userdata);

int main() {
	// �ȼ� ���� 0���� �ʱ�ȭ�� 400 �� 700 ũ���� ���� img ����
	Mat img = Mat::zeros(400, 700, CV_8UC1);

	// Ʈ���ٸ� ������ imageâ ����
	namedWindow("image");
	// Ʈ���� ���� �� Ʈ���� �ݹ��Լ��� ���, 
	// Ʈ���� �̸��� "level", �ִ� ��ġ�� 16, Ʈ���� �ݹ� �Լ��� on_level_change�� ���� 
	// img ��ü �ּҸ� ����� �����ͷ� �����Ͽ� ����
	createTrackbar("level", "image", 0, 16, on_level_change, (void*)&img);

	// img������ image â�� ����ϰ�, Ű �Է��� ���� ������ â�� ���� �ʰ� ����
	imshow("image", img);
	waitKey();

	return 0;
}

void on_level_change(int pos, void* userdata) {
	// void* Ÿ������ �޾ƿ� userdata�� Mat* Ÿ������ ����ȯ �� img ������ ����
	Mat img = *(Mat*)userdata;

	// Ʈ���� ��ġ(��) pos�� 16�� ���� ����� img ������ ��ü �ȼ� ������ ����
	// ���� pos * 16 ����� 255���� ũ�� ��ȭ ������ �����
	img.setTo(pos * 16);
	// �ȼ� ���� ������ img ������ image â�� ���
	// waitKey()�� ���� �Լ��� �����Ǿ� �����Ƿ� ���ʿ�
	imshow("image", img);
}

/*
createTrackbar() �Լ����� ����� �����ʹ� void* Ÿ������ �����ؾ� �ϸ�, 
�� �ڵ忡�� createTrackbar() �Լ� ���� ��° ���ڸ� (void*)&img ���·� ����

on_level_change() �Լ������� ���޵� userdata�� ���� Mat* Ÿ������ ����ȯ�� ��, �̸� Mat Ÿ�� ���� ���� img�� ����
�ᱹ on_level_change() �Լ����� ����ϴ� img ������ main() �Լ��� img ����� ���� ���� �����͸� ���

���α׷� ù ���� �� ��ü�� ������ ���������� ä���� ������ ��Ÿ������
����ڰ� ���콺�� �̿��Ͽ� Ʈ���� ��ġ�� �����ϸ� �׿� �ش��ϴ� ���� ������ �����
���� ��� Ʈ���� ��ġ�� 12�̸� 12 * 16 = 192�� �ش��ϴ� ���� �ȼ����� ������
*/