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

int main() {

	return 0;
}
