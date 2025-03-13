#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

/*
image 이름의 새 창에 0부터 16 사이의 값을 선택할 수 있는 트랙바를 생성하는 프로그램
트랙바 콜백 함수로 등록된 on_level_change() 함수는 사용자가 선택한 트랙바 위치에 16을 곱하여 영상의 전체 픽셀 값으로 설정
즉, 그레이스케일 레벨을 16단계로 보여줌
*/

// 트랙바 콜백 함수 선언문
void on_level_change(int pos, void* userdata);

int main() {
	// 픽셀 값이 0으로 초기화된 400 × 700 크기의 영상 img 생성
	Mat img = Mat::zeros(400, 700, CV_8UC1);

	// 트랙바를 부착할 image창 생성
	namedWindow("image");
	// 트랙바 생성 후 트랙바 콜백함수를 등록, 
	// 트랙바 이름은 "level", 최대 위치는 16, 트랙바 콜백 함수는 on_level_change로 설정 
	// img 객체 주소를 사용자 데이터로 지정하여 전달
	createTrackbar("level", "image", 0, 16, on_level_change, (void*)&img);

	// img영상을 image 창에 출력하고, 키 입력이 있을 때까지 창을 닫지 않고 유지
	imshow("image", img);
	waitKey();

	return 0;
}

void on_level_change(int pos, void* userdata) {
	// void* 타입으로 받아온 userdata를 Mat* 타입으로 형변환 후 img 변수로 참조
	Mat img = *(Mat*)userdata;

	// 트랙바 위치(값) pos에 16을 곱한 결과를 img 영상의 전체 픽셀 값으로 설정
	// 만약 pos * 16 결과가 255보다 크면 포화 연산이 적용됨
	img.setTo(pos * 16);
	// 픽셀 값이 설정된 img 영상을 image 창에 출력
	// waitKey()는 메인 함수에 설정되어 있으므로 불필요
	imshow("image", img);
}

/*
createTrackbar() 함수에서 사용자 데이터는 void* 타입으로 설정해야 하며, 
위 코드에서 createTrackbar() 함수 여섯 번째 인자를 (void*)&img 형태로 지정

on_level_change() 함수에서는 전달된 userdata를 먼저 Mat* 타입으로 형변환한 후, 이를 Mat 타입 지역 변수 img에 복사
결국 on_level_change() 함수에서 사용하는 img 변수는 main() 함수의 img 영상과 같은 영상 데이터를 사용

프로그램 첫 실행 시 전체가 완전히 검은색으로 채워진 영상이 나타나지만
사용자가 마우스를 이용하여 트랙바 위치를 조정하면 그에 해당하는 밝기로 영상이 변경됨
예를 들어 트랙바 위치가 12이면 12 * 16 = 192에 해당하는 밝기로 픽셀값이 설정됨
*/