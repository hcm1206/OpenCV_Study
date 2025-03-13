#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

/*
lenna.bmp 레나 영상을 불러와서 화면에 출력하고, 키보드의 i 또는 I 키를 누를 때마다 영상을 반전시켜 보여 줌
만약 키보드에서 Esc 또는 q 또는 Q 키를 누르면 프로그램이 종료
이외의 키보드를 눌렀을 경우에는 아무런 동작을 수행하지 않으며, 다시 waitKey() 함수가 실행되어 새로운 키 입력을 기다리게 됨
*/

int main() {

	// lenna.bmp 파일을 그레이스케일 영상 형태로 불러와서 img 변수에 저장
	Mat img = imread("lenna.bmp");

	// 이미지 로드 실패 시 처리할 예외문 구성
	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	// 이미지를 담은 창을 화면에 출력
	namedWindow("img");
	imshow("img", img);

	// while 블록을 무한히 반복
	while (true) {
		// waitKey() 함수의 반환값을 keycode 변수에 저장
		int keycode = waitKey();

		// 키보드의 i 또는 I 키를 누르면 img 영상을 반전하여 "img" 창에 나타냄
		if (keycode == 'i' || keycode == 'I') {
			img = ~img;
			imshow("img", img);
		}
		// 키보드의 Esc 또는 q 또는 Q 키를 누르면 while 반복문을 빠져나감
		else if (keycode == 27 || keycode == 'q' || keycode == 'Q') {
			break;
		}
	}

	return 0;
}