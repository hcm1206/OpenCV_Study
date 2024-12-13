/*
(2-1)
OpenCV에서 사용하는 다양한 클래스와 함수가 선언되어 있는 opencv.hpp 헤더 파일을 포함
opencv.hpp 파일은 OpenCV 헤더 파일이 모여 있는 폴더 위치에서 opencv2라는 이름의 하위 폴더 안에 있기 때문에
#include "opencv2/opencv.cpp" 형태로 코드를 입력해야 함
*/
#include "opencv2/opencv.hpp"

// (2-1) C++ 표준 출력을 위해 iostream 헤더 파일 포함
#include <iostream>


int main() {
	/*
	(2-1)
	C++ 표준 출력으로 OpenCV 라이브러리의 버전을 출력하는 코드
	소스 코드에서 사용된 CV_VERSION은 컴퓨터에 설치되어 있는 OpenCV 라이브러리의 버전 정보를 문자열 형태로 정의한 매크로
	현재 실습 환경에서 OpenCV 4.10.0 버전을 사용하기 때문에 CV_VERSION에는 "4.0.0" 문자열이 저장되어 있음
	*/
	std::cout << "Hello OpenCV " << CV_VERSION << std::endl;

	// (2-3) cv와 std 네임스페이스를 사용하도록 선언하여 이후 소스 코드에서 cv::와 std::을 생략
	using namespace std;
	using namespace cv;

	// (2-2) Mat 클래스 타입의 변수 img 선언
	Mat img;

	/* 
	(2-2)
	OpenCV에서 제공하는 imread() 함수를 사용하여 lenna.bmp 파일을 불러와서 img 변수에 저장
	imread() 함수 이름은 영상 읽기(image read)를 뜻하며, imread() 함수도 cv 네임스페이스 안에서 선언되었기 때문에 cv::imread() 형태로 사용
	*/
	img = imread("lenna.bmp");

	/*
	(2-2)
	lenna.bmp 파일을 제대로 불러오지 못했을 경우에 대한 예외 처리 코드
	프로그램 실행 디렉터리에 lenna.bmp 파일이 존재하지 않거나 혹은 lenna.bmp 파일이 손상되어 제대로 불러오지 못한 경우, Mat 클래스의 맴버 함수 Mat::empty()는 true를 반환
	만약 Mat::empty() 함수가 true를 반환하여 if문 블록 안으로 진입하면 "Image load failed!'라는 문자열을 출력한 후 프로그램을 종료
	정상적으로 lenna.bmp 파일을 불러오면 if문 블록 아래쪽 코드가 실행
	*/
	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	// (2-2) namedWindow() 함수를 이용하여 영상을 화면에 나타내기 위한 새로운 창을 생성하고, 그 창에 "image"라는 이름을 부여
	namedWindow("image");
	/*
	(2-2)
	imshow() 함수를 이용하여 "image"라는 이름의 창에 img 객체가 가지고 있는 lenna.bmp 영상을 출력
	imshow() 함수 이름은 영상 보여 주기(image show)를 의미
	*/
	imshow("image", img);

	/*
	(2-2)
	waitKey() 함수는 사용자의 키보드 입력을 기다리는 함수이며, 사용자가 키보드를 누르기 전까지 영상을 화면에 나타나게 해 줌
	만약 사용자가 키보드에서 아무 키나 누르면 return 구문을 만나 프로그램이 종료
	*/
	waitKey();
	return 0;
}