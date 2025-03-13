#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

/*
lenna.bmp ���� ������ �ҷ��ͼ� ȭ�鿡 ����ϰ�, Ű������ i �Ǵ� I Ű�� ���� ������ ������ �������� ���� ��
���� Ű���忡�� Esc �Ǵ� q �Ǵ� Q Ű�� ������ ���α׷��� ����
�̿��� Ű���带 ������ ��쿡�� �ƹ��� ������ �������� ������, �ٽ� waitKey() �Լ��� ����Ǿ� ���ο� Ű �Է��� ��ٸ��� ��
*/

int main() {

	// lenna.bmp ������ �׷��̽����� ���� ���·� �ҷ��ͼ� img ������ ����
	Mat img = imread("lenna.bmp");

	// �̹��� �ε� ���� �� ó���� ���ܹ� ����
	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	// �̹����� ���� â�� ȭ�鿡 ���
	namedWindow("img");
	imshow("img", img);

	// while ����� ������ �ݺ�
	while (true) {
		// waitKey() �Լ��� ��ȯ���� keycode ������ ����
		int keycode = waitKey();

		// Ű������ i �Ǵ� I Ű�� ������ img ������ �����Ͽ� "img" â�� ��Ÿ��
		if (keycode == 'i' || keycode == 'I') {
			img = ~img;
			imshow("img", img);
		}
		// Ű������ Esc �Ǵ� q �Ǵ� Q Ű�� ������ while �ݺ����� ��������
		else if (keycode == 27 || keycode == 'q' || keycode == 'Q') {
			break;
		}
	}

	return 0;
}