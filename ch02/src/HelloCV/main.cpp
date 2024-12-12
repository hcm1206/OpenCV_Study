/*
OpenCV에서 사용하는 다양한 클래스와 함수가 선언되어 있는 opencv.hpp 헤더 파일을 포함
opencv.hpp 파일은 OpenCV 헤더 파일이 모여 있는 폴더 위치에서 opencv2라는 이름의 하위 폴더 안에 있기 때문에
#include "opencv2/opencv.cpp" 형태로 코드를 입력해야 함
*/
#include "opencv2/opencv.hpp"

// C++ 표준 출력을 위해 iostream 헤더 파일 포함
#include <iostream>


int main() {
	/*
	C++ 표준 출력으로 OpenCV 라이브러리의 버전을 출력하는 코드
	소스 코드에서 사용된 CV_VERSION은 컴퓨터에 설치되어 있는 OpenCV 라이브러리의 버전 정보를 문자열 형태로 정의한 매크로
	현재 실습 환경에서 OpenCV 4.10.0 버전을 사용하기 때문에 CV_VERSION에는 "4.0.0" 문자열이 저장되어 있음
	*/
	std::cout << "Hello OpenCV " << CV_VERSION << std::endl;

	return 0;
}