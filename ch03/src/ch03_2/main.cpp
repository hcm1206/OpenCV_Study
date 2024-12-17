#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

// 아래 코드는 예시용 스텁 코드로, 실제로 사용하지 않음

/////////////////////////////////////////////////////// (3-6)

class Mat {
public:

	// Mat 클래스의 다양한 생성자와 소멸자
	Mat();
	Mat(int rows, int cols, int type);
	Mat(Size size, int type);
	Mat(int rows, int cols, int type, const Scalar& s);
	Mat(const Mat& m);
	~Mat();

	// Mat 크래스의 맴버 함수. Mat 클래스의 맴버 함수에는 연산자 재정의 함수와 정적 맴버 함수도 포함됨
	void create(int rows, int cols, int type);
	bool empty() const;

	Mat clone() const;
	void copyTo(OutputArray m) const;
	Mat& setTo(InputArray value, InputArray mask = noArray());

	static MatExpr zeros(int rows, int cols, int type);
	static MatExpr ones(int rows, int cols, int type);

	Mat& operator = (const Mat& m);
	Mat operator() (const Rect& roi) const;

	template<typename _Tp> _Tp* ptr(int i0 = 0);
	template<typename _Tp> _Tp& at(int row, int col);

	// Mat 클래스의 주요 맴버 변수
	int dims;
	int rows, cols;
	uchar* data;
	MatSize size;
	
	// 이후의 일부 코드 생략
	// ...
};

/*
Mat::dims 맴버 변수는 Mat 행렬의 차원을 나타내며,
영상과 같은 2차원 행렬의 경우 Mat::dims 값은 2

Mat::rows와 Mat::cols 맴버 변수는 2차원 행렬의 크기를 나타냄
Mat::rows는 행렬의 행 개수를 나타내고, Mat::cols는 열 개수를 나타냄

만약 Mat 객체에 정지 영상이 저장되어 있는 경우라면
Mat::rows는 영상의 세로 픽셀 크기이고, Mat::cols는 영상의 가로 픽셀 크기

Mat::rows와 Mat::cols 맴버 변수는 Mat 객체가 2차원 행렬일 경우에만 의미 있는 값을 가지며, 
3차원 이상의 행렬에서는 -1이 저장됨
3차원 이상 행렬의 크기 정보는 Mat::size 맴버 변수를 이용하여 참조할 수 있음

Mat::data는 행렬의 원소 데이터가 저장되어 있는 메모리 공간을 가리키는 포인터형 맴버 변수
만약 행렬에 아무것도 저장되어 있지 않은 상태라면 Mat::data는 0(NULL) 값을 가짐

Mat 클래스의 모든 맴버 변수는 public 접근 지시자로 선언되어 있어서 클래스 외부에서 직접 접근할 수 있음
*/

/////////////////////////////////////////////////////// (3-7)

// 아래 함수는 Mat 행렬 생성 및 값 초기화만 수행하고 기타 아무런 동작을 하지 않음

void MatOp1() {

	// 비어 있는 행렬을 생성하는 Mat 기본 생성자 
	cv::Mat img1;	// empty matrix

	// 메모리 공간을 할당하여 행렬을 생성하는 Mat 생성자
	cv::Mat img2(480, 640, CV_8UC1);			// unsigned char, 1-channel
	cv::Mat img3(480, 640, CV_8UC3);			// unsigned char, 3-channels
	cv::Mat img4(Size(640, 480), CV_8UC3);		// Size(width, height)

	// 메모리 공간을 할당하고 초기화한 값이 저장된 행렬을 생성하는 Mat 생성자
	cv::Mat img5(480, 640, CV_8UC1, cv::Scalar(128));			// initial values, 128
	cv::Mat img6(480, 640, CV_8UC3, cv::Scalar(0, 0, 255));		// initial values, red

	// 메모리 공간을 할당하고 특정 값으로 초기화된 행렬을 생성하는 Mat 생성 함수
	cv::Mat mat1 = cv::Mat::zeros(3, 3, CV_32SC1);		// 0's matrix
	cv::Mat mat2 = cv::Mat::ones(3, 3, CV_32FC1);		// 1's matrix
	cv::Mat mat3 = cv::Mat::eye(3, 3, CV_32FC1);		// identify matrix

	// 이미 생성된 외부 메모리 값을 이용하여 행렬을 생성하는 Mat 생성자
	float data[] = { 1, 2, 3, 4, 5, 6 };
	cv::Mat mat4(2, 3, CV_32FC1, data);

	// C++ 초기화 리스트(initializer list) 문법을 이용하여 행렬 값 초기화
	cv::Mat mat5 = (cv::Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);
	cv::Mat mat6 = cv::Mat_<uchar>({ 2, 3 }, { 1, 2, 3, 4, 5, 6 });

	// 기존 Mat 객체에 새로운 행렬을 저장하는 Mat::create() 메소드
	mat4.create(256, 256, CV_8UC3); // uchar, 3-channels
	mat5.create(4, 4, CV_32FC1); // float, 1-channel

	// = 연산자 재정의 및 Mat 객체 메소드를 이용하여 행렬 전체 원소 값을 한꺼번에 지정
	mat4 = cv::Scalar(255, 0, 0); 
	mat5.setTo(1.f);
}

int main() {

	return 0;
}
