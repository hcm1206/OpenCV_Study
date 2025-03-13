#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

/*
마우스 왼쪽 버튼이 눌리거나 떼어진 좌표를 콘솔 창에 출력하고 
마우스 왼쪽 버튼을 누른 상태로 마우스를 움직이면 마우스 움직임 궤적을 영상 위에 노란색으로 표시하는 프로그램
*/


// 메인 함수와 on_mouse() 함수에서 함께 사용할 영상 img를 전역 변수로 선언
Mat img;
// on_mouse() 함수에서 이전 마우스 이벤트 발생 위치를 저장하기 위한 용도로 pt0ld 변수를 전역 변수 형태로 선언
Point pt0ld;
// on_mouse() 함수 선언문
void on_mouse(int event, int x, int y, int flags, void*);

int main() {
	// 이미지 로드
	img = imread("lenna.bmp");

	// 이미지 로드 실패 시 처리할 예외문
	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	// setMouseCallback() 함수 사용 전 마우스 이벤트를 받을 창을 미리 선언
	namedWindow("img");
	// setMouseCallback 마우스 콜백 함수를 "img" 창에 on_mouse 함수를 매개로 설정
	setMouseCallback("img", on_mouse);

	// 이미지 출력 후 키보드 입력 시 종료
	imshow("img", img);
	waitKey();

	return 0;
}

// 마우스 이벤트, 마우스 위치, 이벤트 플래그를 매개로 하여 on_mouse() 함수 정의
void on_mouse(int event, int x, int y, int flags, void*) {
	// 마우스 이벤트에 따라 아래 동작 중 하나 실행
	switch (event) {
	// 마우스 왼쪽 버튼이 눌렸을 때
	case EVENT_LBUTTONDOWN:
		// 마우스 왼쪽 버튼이 눌린 좌표를 전역 변수 pt0ld에 저장
		pt0ld = Point(x, y);
		// 마우스 왼쪽 버튼이 눌린 좌표를 콘솔 창에 출력
		cout << "EVENT_LBUTTONDOWN: " << x << ", " << y << endl;
		break;
	// 마우스 왼쪽 버튼이 떼졌을 때
	case EVENT_LBUTTONUP:
		// 마우스 왼쪽 버튼이 떼어진 좌표를 콘솔 창에 출력
		cout << "EVENT_LBUTTONUP: " << x << ", " << y << endl;
		break;
	// 마우스 이동 시
	case EVENT_MOUSEMOVE:
		// 마우스 왼쪽 버튼이 눌려있는 상태라면
		if (flags & EVENT_FLAG_LBUTTON) {
			// pt0ld 좌표부터 현재 마우스 이벤트 발생 좌표까지 노란색 직선을 그리고
			line(img, pt0ld, Point(x, y), Scalar(0, 255, 255), 2);
			// 직선이 그려진 img를 출력
			imshow("img", img);
			// pt0ld를 현재 좌표로 갱신
			pt0ld = Point(x, y);
		}
		break;
	default:
		break;
	}
}

/*
레나 영상을 전역 변수 img로 선언하여 main() 함수와 on_mouse() 콜백 함수에서 사용
전역 변수 대신 setMouseCallback() 함수의 세 번째 인자를 사용하여 영상 데이터를 마우스 콜백 함수로 전달하는 것도 가능
*/

/*
on_mouse() 함수에서는 switch ~ case 구문을 이용하여 다양한 마우스 이벤트를 처리
사용자가 마우스 왼쪽 버튼을 누르면 "EVENT_LBUTTONDOWN:" 문자열과 마우스 버튼이 눌린 좌표를 출력
눌렸던 왼쪽 마우스 버튼을 떼는 경우에는 "EVENT_LBUTTONUP: " 문자열과 해당 마우스 좌표를 출력

EVENT_MOUSEMOVE 케이스의 경우에는 마우스가 움직이는 MOUSE_MOVE 이벤트 처리 구문 
이 때 flags 인자에 EVENT_FLAG_LBUTTON 상태가 설정되어 있으면 line() 함수를 이용하여 img 영상에 노란색 마우스 궤적을 그림
flags 인자에서 EVENT_FLAG_LBUTTON 비트가 설정되어 있는지를 확인하기 위해 & 연산자를 사용
*/