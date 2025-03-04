#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

/////////////////////////////////////////////////////// (4-6)

void drawLines() {

	// 400 × 400 크기의 3채널 컬러 영상을 생성하고, 모든 픽셀을 흰색으로 초기화
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

	// 수평 방향의 직선 세 개를 서로 다른 색상과 두께로 그림
	line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255));
	line(img, Point(50, 100), Point(200, 100), Scalar(255, 0, 255), 3);
	line(img, Point(50, 150), Point(200, 150), Scalar(255, 0, 0), 10);

	// 대각선 방향의 직선 세 개를 서로 다른 색상과 직선 타입으로 그림
	line(img, Point(250, 50), Point(350, 100), Scalar(0, 0, 255), 1, LINE_4);
	line(img, Point(250, 70), Point(350, 120), Scalar(255, 0, 255), 1, LINE_8);
	line(img, Point(250, 90), Point(350, 140), Scalar(255, 0, 0), 1, LINE_AA);

	// 수평 방향의 화살표 세 개를 서로 다른 색상과 직선 타입으로 그림
	arrowedLine(img, Point(50, 200), Point(150, 200), Scalar(0, 0, 255), 1);
	arrowedLine(img, Point(50, 250), Point(350, 250), Scalar(255, 0, 255), 1);
	arrowedLine(img, Point(50, 300), Point(350, 300), Scalar(255, 0, 0), 1, LINE_8, 0, 0.05);

	// 다양한 모양의 마커를 그림
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
	흰색으로 초기화된 400×400 크기 영상에 다양한 직선과 화살표 등을 그리고 화면에 나타내는 함수
	*/

	drawLines();

	/*
	img창 좌측 상단에 그려진 세 개의 수평선은 첫 3개의 line() 함수에 의한 그리기 결과
	세 수평선 중 맨 위의 빨간색 직선은 선 두께를 1로 지정, 보라색과 파란색 직선은 선 두께를 각각 3과 10으로 지정

	img창 우측 상단에 그려진 세 개의 사선은 그 다음 3개의 line() 함수 실행 결과
	세 사선 중 맨 위의 빨간색 사선은 직선 타입을 LINE_4로, 가운데 보라색 사선은 LINE_8로, 마지막 파란색 사선은 LINE_AA 타입으로 그린 직선
	LINE_4 타입으로 그린 직선은 상하좌우 네 방향으로 직선이 연결되어 있고, LINE_8 타입의 직선은 픽셀이 대각선 방향으로도 연결되어 있으며, LINE_AA 타입의 직선은 안티에일리어싱(anti-aliasing) 기법이 적용되어 부드러워 보이게 연결됨

	img창 중간에 그려진 세 개의 화살표 직선은 3개의 arrowedLine() 함수 실행 결과
	맨 위의 빨간색 화살표 직선과 보라색 화살표 직선은 그리는 방식이 동일하게 코드가 입력되어 있지만 길이가 다르기 때문에 화살표 크기도 다름
	만약 길이가 긴 직선에 대하여 화살표 크기를 작게 그리려면 파란색 화살표 직선 코드처럼 tipLength의 값을 기본값인 0.1보다 작게 작성하면 됨

	맨 아래에 그려진 일곱 개의 도형은 drawMarker() 함수에 의해 그려진 마커
	가장 왼쪽부터 차례대로 MARKER_CROSS, MARKER_TILTED_CROSS, MARKER_STAR, MARKER_DIAMOND, MARKER_SQUARE, MARKER_TRIANGLE_UP, MARKER_TRIANGLE_DOWN에 해당하는 마커 종류로 그린 결과
	*/

	return 0;
}