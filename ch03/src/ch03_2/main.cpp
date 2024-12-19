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

/////////////////////////////////////////////////////// (3-8)

void MatOp2() {
	// dog.bmp 강아지 영상을 불러와서 img1에 저장
	cv::Mat img1 = imread("dog.bmp");

	// 복사 생성자와 대입 연산자를 이용하여 img1의 복사본 영상 img2, img3을 생성(얕은 복사)
	cv::Mat img2 = img1;
	cv::Mat img3;
	img3 = img1;

	// Mat::clone()과 Mat::copyTo() 함수를 이용하여 img1의 복사본 영상 img4, img5를 생성 (깊은 복사)
	cv::Mat img4 = img1.clone();
	cv::Mat img5;
	img1.copyTo(img5);

	// img1 영상의 모든 픽셀을 Scalar(0, 255, 255)에 해당하는 노란색으로 설정
	img1.setTo(Scalar(0, 255, 255)); // yellow

	// img1~img5 영상을 모두 새 창으로 출력
	cv::imshow("img1", img1);
	cv::imshow("img2", img2);
	cv::imshow("img3", img3);
	cv::imshow("img4", img4);
	cv::imshow("img5", img5);

	cv::waitKey();
	cv::destroyAllWindows();
}

/////////////////////////////////////////////////////// (3-9)

void MatOp3() {
	// cat.bmp 고양이 영상을 불러와서 img1에 저장
	cv::Mat img1 = cv::imread("cat.bmp");

	// 영상을 불러오는데 실패하여 img1 행렬이 비어있다면 오류 메시지 출력 후 종료
	if (img1.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	// img1 고양이 영상의 특정 사각형 영역 ROI를 설정하여 img2에 저장 (얕은 복사)
	cv::Mat img2 = img1(Rect(220, 120, 340, 240));
	// img1 고양의 영상의 특정 사각형 영역 ROI를 설정 후 해당 값을 모두 복사하여 새로운 메모리를 할당하여 img3에 저장 (깊은 복사)
	cv::Mat img3 = img1(Rect(220, 120, 340, 240)).clone();

	// img2 영상을 색상 반전
	img2 = ~img2;

	// img1, img2, img3 영상을 모두 새 창으로 출력
	cv::imshow("img1", img1);
	cv::imshow("img2", img2);
	cv::imshow("img3", img3);

	cv::waitKey();
	cv::destroyAllWindows();
}

/////////////////////////////////////////////////////// (3-10)

void MatOp4() {

	// 4 × 3 크기의 0으로 이루어진 CV_8UC1 타입의 mat1 행렬 생성
	cv::Mat mat1 = cv::Mat::zeros(3, 4, CV_8UC1);

	// mat1 행렬의 모든 픽셀을 Mat::at() 함수를 통해 순회하며 1씩 증가
	for (int j = 0; j < mat1.rows; j++) {
		for (int i = 0; i < mat1.cols; i++) {
			mat1.at<uchar>(j, i)++;
		}
	}

	// mat1 행렬의 모든 픽셀을 Mat::prt() 함수를 통해 순회하며 1씩 증가
	for (int j = 0; j < mat1.rows; ++j) {
		uchar* p = mat1.ptr<uchar>(j);
		for (int i = 0; i < mat1.cols; ++i) {
			p[i]++;
		}
	}

	// mat1 행렬의 모든 픽셀을 MatIterator_ 반복자를 통해 순회하며 1씩 증가
	for (cv::MatIterator_<uchar> it = mat1.begin<uchar>(); it != mat1.end<uchar>(); ++it) {
		(*it)++;
	}

	// 3번의 순회를 통해 모든 픽셀값이 3으로 저장된 mat1 행렬 출력
	cout << "mat1:\n" << mat1 << endl;
}

/////////////////////////////////////////////////////// (3-11)

void MatOp5() {
	// lenna.bmp 레나 영상을 불러와서 img1에 저장
	cv::Mat img1 = imread("lenna.bmp");

	// 레나 영상의 크기 및 채널 정보를 Mat 클래스 멤버 변수를 이용하여 출력
	cout << "Width: " << img1.cols << endl;
	cout << "Height: " << img1.rows << endl;
	cout << "Channels: " << img1.channels() << endl;

	// Mat 클래스의 type() 멤버 함수를 이용하여 img1 행렬 객체의 데이터 타입 출력
	if (img1.type() == CV_8UC1)
		cout << "img1 is a grayscale image." << endl;
	else if (img1.type() == CV_8UC3)
		cout << "img1 is a truecolor image." << endl;

	// mat1 객체에 새로운 실수 행렬을 저장한 후 << 연산자를 이용하여 객체 원소 값 출력
	float data[] = { 2.f, 1.414f, 3.f, 1.732f };
	cv::Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1:\n" << mat1 << endl;
}

int main() {

	/////////////////////////////////////////////////////// (3-7)

	/*
	아래 함수는 Mat 행렬 생성 및 값 초기화만 수행하고 기타 아무런 동작을 하지 않음
	*/ 

	MatOp1(); 

	/////////////////////////////////////////////////////// (3-8)

	/*
	아래 함수는 다양한 복사 방법을 이용하여 img1에 저장된 강아지 영상을 새로운 영상 img2, img3, img4, img5에 각각 복사
	그리고 img1 영상의 모든 픽셀 값을 노란색에 해당하는 Scalar(0, 255, 255)로 설정한 후, 각각의 영상을 화면에 출력
	*/

	MatOp2();

	/*
	img1 영상만 노란색으로 설정하였으나 img1, img2, img3 영상이 모두 노란색으로 바뀜
	img2와 img3 영상이 img1의 픽셀 데이터를 공유하기 때문에 나타난 결과
	반면에 img4와 img5는 깊은 복사를 수행하였기 때문에 강아지 영상을 그대로 유지
	*/

	/////////////////////////////////////////////////////// (3-9)

	/*
	아래 함수는 img1에 저장된 고양이 영상의 부분 영상 영역을 설정하여 새로운 영상 img2, img3에 각각 복사
	그리고 img2 영상을 색상 반전 후, 각각의 영상을 화면에 출력
	*/

	MatOp3();

	/////////////////////////////////////////////////////// (3-10)

	/*
	아래 함수는 모든 원소 값이 0으로 초기화된 CV_8UC1 타입의 행렬 mat1을 정의하고, 
	Mat::at() 함수와 Mat::ptr() 함수, 그리고 MatIterator_ 반복자를 사용하여 모든 행렬 원소 값을 1씩 증가
	*/

	MatOp4();

	/*
	실행 결과 mat1 행렬의 모든 원소 값이 3으로 출력
	*/

	/////////////////////////////////////////////////////// (3-11)

	/*
	아래 함수는 lenna.bmp 파일에서 불러온 레나 영상의 크기, 채널 수, 타입 정보를 확인하여 화면에 출력
	작은 크기의 행렬 정의 후 std::cout과 << 연산자를 이용하여 행렬의 모든 원소를 화면에 출력
	*/

	MatOp5();

	return 0;
}
