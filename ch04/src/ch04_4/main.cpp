#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

/*
���콺 ���� ��ư�� �����ų� ������ ��ǥ�� �ܼ� â�� ����ϰ� 
���콺 ���� ��ư�� ���� ���·� ���콺�� �����̸� ���콺 ������ ������ ���� ���� ��������� ǥ���ϴ� ���α׷�
*/


// ���� �Լ��� on_mouse() �Լ����� �Բ� ����� ���� img�� ���� ������ ����
Mat img;
// on_mouse() �Լ����� ���� ���콺 �̺�Ʈ �߻� ��ġ�� �����ϱ� ���� �뵵�� pt0ld ������ ���� ���� ���·� ����
Point pt0ld;
// on_mouse() �Լ� ����
void on_mouse(int event, int x, int y, int flags, void*);

int main() {
	// �̹��� �ε�
	img = imread("lenna.bmp");

	// �̹��� �ε� ���� �� ó���� ���ܹ�
	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	// setMouseCallback() �Լ� ��� �� ���콺 �̺�Ʈ�� ���� â�� �̸� ����
	namedWindow("img");
	// setMouseCallback ���콺 �ݹ� �Լ��� "img" â�� on_mouse �Լ��� �Ű��� ����
	setMouseCallback("img", on_mouse);

	// �̹��� ��� �� Ű���� �Է� �� ����
	imshow("img", img);
	waitKey();

	return 0;
}

// ���콺 �̺�Ʈ, ���콺 ��ġ, �̺�Ʈ �÷��׸� �Ű��� �Ͽ� on_mouse() �Լ� ����
void on_mouse(int event, int x, int y, int flags, void*) {
	// ���콺 �̺�Ʈ�� ���� �Ʒ� ���� �� �ϳ� ����
	switch (event) {
	// ���콺 ���� ��ư�� ������ ��
	case EVENT_LBUTTONDOWN:
		// ���콺 ���� ��ư�� ���� ��ǥ�� ���� ���� pt0ld�� ����
		pt0ld = Point(x, y);
		// ���콺 ���� ��ư�� ���� ��ǥ�� �ܼ� â�� ���
		cout << "EVENT_LBUTTONDOWN: " << x << ", " << y << endl;
		break;
	// ���콺 ���� ��ư�� ������ ��
	case EVENT_LBUTTONUP:
		// ���콺 ���� ��ư�� ������ ��ǥ�� �ܼ� â�� ���
		cout << "EVENT_LBUTTONUP: " << x << ", " << y << endl;
		break;
	// ���콺 �̵� ��
	case EVENT_MOUSEMOVE:
		// ���콺 ���� ��ư�� �����ִ� ���¶��
		if (flags & EVENT_FLAG_LBUTTON) {
			// pt0ld ��ǥ���� ���� ���콺 �̺�Ʈ �߻� ��ǥ���� ����� ������ �׸���
			line(img, pt0ld, Point(x, y), Scalar(0, 255, 255), 2);
			// ������ �׷��� img�� ���
			imshow("img", img);
			// pt0ld�� ���� ��ǥ�� ����
			pt0ld = Point(x, y);
		}
		break;
	default:
		break;
	}
}

/*
���� ������ ���� ���� img�� �����Ͽ� main() �Լ��� on_mouse() �ݹ� �Լ����� ���
���� ���� ��� setMouseCallback() �Լ��� �� ��° ���ڸ� ����Ͽ� ���� �����͸� ���콺 �ݹ� �Լ��� �����ϴ� �͵� ����
*/

/*
on_mouse() �Լ������� switch ~ case ������ �̿��Ͽ� �پ��� ���콺 �̺�Ʈ�� ó��
����ڰ� ���콺 ���� ��ư�� ������ "EVENT_LBUTTONDOWN:" ���ڿ��� ���콺 ��ư�� ���� ��ǥ�� ���
���ȴ� ���� ���콺 ��ư�� ���� ��쿡�� "EVENT_LBUTTONUP: " ���ڿ��� �ش� ���콺 ��ǥ�� ���

EVENT_MOUSEMOVE ���̽��� ��쿡�� ���콺�� �����̴� MOUSE_MOVE �̺�Ʈ ó�� ���� 
�� �� flags ���ڿ� EVENT_FLAG_LBUTTON ���°� �����Ǿ� ������ line() �Լ��� �̿��Ͽ� img ���� ����� ���콺 ������ �׸�
flags ���ڿ��� EVENT_FLAG_LBUTTON ��Ʈ�� �����Ǿ� �ִ����� Ȯ���ϱ� ���� & �����ڸ� ���
*/