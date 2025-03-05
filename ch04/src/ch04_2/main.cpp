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

/////////////////////////////////////////////////////// (4-7)

void drawPolys() {
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

	// 사각형을 두께 2인 선으로 그림(빨간색)
	rectangle(img, Rect(50, 50, 100, 50), Scalar(0, 0, 255), 2);
	// 사각형 내부를 채워서 그림(갈색)
	rectangle(img, Rect(50, 150, 100, 50), Scalar(0, 0, 128), -1);

	// 반지름 30인 원을 내부를 채워서 그림(하늘색)
	circle(img, Point(300, 120), 30, Scalar(255, 255, 0), -1, LINE_AA);
	// 반지름 60인 원을 두께 3인 선으로 그림(파란색)
	circle(img, Point(300, 120), 60, Scalar(255, 0, 0), 3, LINE_AA);

	// 타원을 0°부터 270°까지 내부를 채워서 그림(하늘색)
	ellipse(img, Point(120, 300), Size(60, 30), 20, 0, 270, Scalar(255, 255, 0), -1, LINE_AA);
	// 타원을 두께 2인 선으로 그림(녹색)
	ellipse(img, Point(120, 300), Size(100, 50), 20, 0, 360, Scalar(0, 255, 0), 2, LINE_AA);

	// 계단 모양의 다각형을 두께 2인 선으로 그림(보라색)
	vector<Point> pts;
	pts.push_back(Point(250, 250)); pts.push_back(Point(300, 250));
	pts.push_back(Point(300, 300)); pts.push_back(Point(350, 300));
	pts.push_back(Point(350, 350)); pts.push_back(Point(250, 350));
	polylines(img, pts, true, Scalar(255, 0, 255), 2);

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

	/////////////////////////////////////////////////////// (4-7)

	/*
	흰색으로 초기화된 400 × 400 크기의 영상에 다양한 사각형, 원, 타원, 다각형을 그려서 화면에 출력하는 함수
	*/

	drawPolys();

	/*
	img창 좌측 상단에 그려진 두 개의 사각형은 첫 2개의 rectangle() 함수 실행 결과
	빨간색 사각형은 두께를 2로 설정, 갈색 사각형은 두께를 -1로 설정하여 내부를 채움

	img창 우측 상단에 그려진 두 개의 원은 그 다음 2개의 circle() 함수 실행 결과
	두 원은 같은 중심 좌표를 가지고 있지만 하늘색 원은 반지름이 30이고 내부가 채워져 있고, 파란색 원은 반지름이 60이고 내부를 채우지 않고 선 두께가 3으로 설정됨

	img창 좌측 하단에 그려진 타원과 호는 그 다음 2개의 ellipse() 함수 실행 결과
	타원과 호는 같은 중심 좌표를 가지고 있지만 하늘색 호는 반지름이 60, 30이고 0°부터 270°까지 내부를 채운 호이고, 녹색 타원은 반지름이 120, 300이고 선 두께가 2로 설정되어 내부를 채우지 않은 타원

	img창 우측 하단에 그려진 다각형은 마지막 polylines() 함수 실행 결과
	꼭지점 좌표를 의미하는 Point 객체들을 저장한 vector 배열을 이용하여 계단 모양의 다각형을 그림
	*/


	return 0;
}