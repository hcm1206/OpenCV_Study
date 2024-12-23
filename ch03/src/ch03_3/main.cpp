#include <iostream>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

// 아래 코드는 예시용 스텁 코드로, 실제로 사용하지 않음

/////////////////////////////////////////////////////// (3-14)

// 작은 크기의 행렬을 표현하는 Matx 클래스 정의. 행렬 원소는 val 멤버 변수 배열에 저장
template<typename _Tp, int m, int n> class Matx {
public:
	// ...
	_Tp val[m * n]; // <matrix elements
};

// 작은 크기의 벡터를 표현하는 Vec 클래스 정의. Vec 클래스는 Matx 클래스를 상속받아 만들어지며, cn개의 원소를 갖는 val 배열을 멤버 변수로 가짐
template<typename _Tp, int cn> class Vec : public Matx<_Tp, cn, 1> {
public:
	// ...
	/*! element access */
	// Vec 클래스의 멤버 변수 배열 val에 접근할 수 있는 [] 연산자 재정의
	_Tp& operator[](int i);
};

// C++ 표준 출력 스트림을 이용하여 벡터 원소를 출력하는 연산자 재정의
template<typename _Tp, int n> static inline
std::ostream& operator<< (std::ostream& out, const ::Vec<_Tp, n>& vec);


/////////////////////////////////////////////////////// (3-15)

// 간략화한 Scalar_와 Scalar 클래스 정의

template<typename _Tp> class Scalar_ : public Vec<_Tp, 4> {
public:
	// Scalar_ 클래스 생성자
	Scalar_();
	Scalar_(_Tp v0);
	Scalar_(_Tp v0, _Tp v1, _Tp v2 = 0, _Tp v3 = 0);

	// Scalar::all() 멤버 함수는 네 개의 val 배열 값을 모두 v0으로 설정한 Scalar_ 객체를 반환
	static Scalar_<_Tp> all(_Tp v0);

	// ...
};

// double 자료형을 사용하는 Scalar_ 클래스에 대해 Scalar라는 이름으로 재정의
typedef ::Scalar_<double> Scalar;

/*
위 ::Scalar_ 클래스는 Vec 클래스를 상속받았으며, 네 개의 원소를 가지고 있는 템플릿 클래스
Scalar_ 클래스는 템플릿 클래스이기 때문에 다양한 자료형에 
*/


/////////////////////////////////////////////////////// (3-16)

void ScalarOp() {
	// 128 정수 하나를 이용하여 Scalar 클래스 타입의 변수 gray를 초기화
	// gray 객체의 val 멤버 변수에는 [128, 0, 0, 0] 값이 저장됨
	cv::Scalar gray = 128;
	cout << "gray: " << gray << endl;
	/*
	이 경우 gray 변수가 가지고 있는 네 개의 double형 원소 중에서 첫 번째 원소만 128로 설정되고, 나머지 세 개의 원소는 0으로 초기화됨
	6행의 yellow 변수는 네 개의 double형 원소 중 처음 세 원소가 차례대로 0, 255, 255로 설정되고, 마지막 네 번째 원소는 0으로 초기화됨
	*/

	// yellow 객체에는 노란색을 표현하는 [0, 255, 255, 0] 값이 저장됨
	cv::Scalar yellow(0, 255, 255);
	cout << "yellow: " << yellow << endl;

	// yellow 변수를 Mat 클래스 생성자의 네 번째 인자로 전달하여, 노란색으로 초기화된 256×256 크기의 컬러 영상 img1을 생성
	cv::Mat img1(256, 256, CV_8UC3, yellow);

	// yellow 객체에 저장된 값을 참조하기 위해 [] 연산자 재정의 사용
	for (int i = 0; i < 4; i++)
		cout << yellow[i] << endl;
	/*
	Scalar 클래스에 저장된 데이터 원소에 접근하기 위해 멤버 변수 val 배열을 직접 참조해도 되지만 보통은 [] 연산자 재정의를 사용
	yellow 변수의 0번째 원소 값을 참조하려면 yellow.val[0]이라고 입력해도 되지만 yellow[0] 코드를 더 많이 사용
	*/
}

int main() {
	
	/*
	아래 함수는 Scalar 객체를 생성하고 
	Mat 행렬 객체의 값으로 설정하는 예제 코드와 
	Scalar 객체의 원소들을 [] 연산자 재정의를 이용해 순회 및 출력하는 예제 코드를 실행
	*/

	ScalarOp();

	return 0;
}