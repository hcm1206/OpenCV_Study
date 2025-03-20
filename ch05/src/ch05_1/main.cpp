#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

/////////////////////////////////////////////////////// (5-1)

void brightness1() {

	// lenna.bmp 레너 영상을 그레이스케일 형식으로 불러와 src에 저장
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	// lenna.bmp 파일 불러오기가 실패하면 에러 메시지를 출력하고 종료
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	// src 영상의 모든 픽셀 값을 100만큼 증가시킨 결과 영상을 dst에 저장
	Mat dst = src + 100;

	// src를 새 창에 출력
	imshow("src", src);
	// dst를 새 창에 출력
	imshow("dst", dst);
	// 키 입력이 있을 때까지 대기
	waitKey();

	// 영상 출력 창을 모두 닫음
	destroyAllWindows();
 }

int main() {
	
	/////////////////////////////////////////////////////// (5-1)

	/*
	lenna.bmp 영상의 밝기를 100만큼 증가시켜 화면에 출력하는 함수
	*/

	brightness1();

	return 0;
}