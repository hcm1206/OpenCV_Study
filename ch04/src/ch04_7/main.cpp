#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

/////////////////////////////////////////////////////// (4-16)

void mask_setTo() {

	// 레나 영상을 src 변수에 저장
	Mat src = imread("lenna.bmp", IMREAD_COLOR);
	// 마스크 영상을 mask 변수에 저장
	Mat mask = imread("mask_smile.bmp", IMREAD_GRAYSCALE);

	// 레나 영상 또는 마스크 영상 로드 실패 시 처리할 예외문
	if (src.empty() || mask.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	// mask 영상에서 픽셀 값이 0이 아닌 위치에서만 src 영상 픽셀을 노란색으로 설정
	src.setTo(Scalar(0, 255, 255), mask);

	// 마스크 연산 처리된 레나 영상과 마스크 영상을 각각 창에 출력
	imshow("src", src);
	imshow("mask", mask);

	waitKey();
	destroyAllWindows();
}

/////////////////////////////////////////////////////// (4-17)

void mask_copyTo() {
	// airplane.bmp 비행기 영상을 src 변수에 저장
	Mat src = imread("airplane.bmp");
	// mask_plane.bmp 비행기 마스크 영상을 mask 변수에 저장
	// mask는 그레이 스케일 영상이며, 
	// src 영상에서 비행기가 있는 위치에서만 픽셀 값이 255이고 나머지 영역은 픽셀 값이 0
	Mat mask = imread("mask_plane.bmp");
	// field.bmp 들판 영상을 dst 변수에 저장
	Mat dst = imread("field.bmp");

	// 비행기 영상, 비행기 마스크 영상, 들판 영상 중 하나 이상의 영상 로드 실패 시 처리할 예외문
	if (src.empty() || mask.empty() || dst.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	// mask 영상에서 흰색 영역 위치에 해당하는 src 영상 픽셀 값을 dst로 복사
	// src와 dst 영상은 서로 크기와 타입이 같으므로 dst 영상이 새로 생성되거나 초기화되지 않음
	// 오직 마스크 영상에 의해 지정된 비행기 영역 픽셀 값만 복사됨
	src.copyTo(dst, mask);

	// 마스크 영상이 복사된 필드 영상이 저장되어 있는 dst 영상을 창으로 출력

	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

/////////////////////////////////////////////////////// (4-18)

// 간략화한 TickMeter 클래스 정의(실제 사용하지 않는 스텁 코드)

class TickMeter {
public:
	// TickMeter 기본 생성자
	TickMeter();

	// 시간 측정을 시작할 때 사용
	void start();
	// 시간 측정을 멈출 때 사용
	void stop();
	// 새롭게 연산 시간을 측정하고자 할 때 사용하며, 모든 멤버 변수 값을 0으로 초기화
	void reset();

	// 연산 시간을 마이크로 초 단위로 반환
	double getTimeMicro() const;
	// 연산 시간을 밀리초 단위로 반환
	double getTimeMilli() const;
	// 연산 시간을 초 단위로 반환
	double getTimeSec() const;
	// 시간 측정을 수행한 횟수를 반환
	int64 getCounter() const;
	// ...
};

/////////////////////////////////////////////////////// (4-19)

void time_inverse() {
	// 레나 영상을 로드하여 src에 저장
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	// 레나 영상 로드 실패 시 처리할 예외문
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	// 레나 영상과 같은 크기, 타입을 갖는 영상 데이터(행렬) 변수 생성
	Mat dst(src.rows, src.cols, src.type());

	// TickMeter 클래스 객체 tm 선언
	cv::TickMeter tm;
	// 시간 측정 시작
	tm.start();

	// src(레나 영상)의 모든 픽셀을 반전한 값을 dst에 저장
	for (int j = 0; j < src.rows; ++j) {
		for (int i = 0; i < src.cols; ++i) {
			dst.at<uchar>(j, i) = 255 - src.at<uchar>(j, i);
		}
	}

	// 시간 측정을 종료
	tm.stop();
	// 측정된 시간을 콘솔 창에 출력
	cout << " Image inverse took " << tm.getTimeMilli() << "ms." << endl;
}

int main() {
	
	/////////////////////////////////////////////////////// (4-16)

	/*
	lenna.bmp 레나 영상의 일부 영역에 대해서만 픽셀 값을 노란색으로 설정하는 함수
	노란색으로 설정할 여역 정보는 mask_smile.bmp 파일이 제공
	*/

	mask_setTo();

	/*
	mask 영상은 중앙에 웃는 얼굴 부분이 흰색으로 설정되어 있고, 
	나머지 영역은 픽셀 값 0에 해당하는 검은색으로 채워져 있음
	마스크 영상에서 흰색으로 표시된 영역에 대해서만 레나 영상 픽셀이 노란색으로 설정됨
	*/

	/////////////////////////////////////////////////////// (4-17)

	/*
	비행기 영상과 비행기 영역을 나타내는 마스크 영상, 그리고 들판 사진을 이용하여 
	들판 위에 비행기가 날아가고 있는 영상을 합성하는 함수
	*/

	mask_copyTo();

	/////////////////////////////////////////////////////// (4-19)

	/*
	for 반복문을 이용하여 레나 영상을 직접 반전시키고, 이 때 소요되는 연산 시간을 측정하여 콘솔 창에 출력하는 함수
	*/

	time_inverse();

	/*
	위 함수는 소스 코드의 연산 시간을 측정하는 코드이므로 릴리스 모드로 빌드하여 실행해야 함
	디버그 모드로 빌드할 경우에는 디버깅을 위한 연산이 추가되기 때문에 영상 처리 만을 위한 정확한 연산 시간을 측정할 수 없음
	*/

	return 0;
}