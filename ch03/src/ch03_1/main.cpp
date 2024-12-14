#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv; // 실제로는 자체 재정의한 클래스와 실제 opencv 클래스를 구분하기 위해 cv::를 붙여서 사용


// 아래 코드는 일종의 예시용 수도 코드로, 실제로 사용하지 않음

/////////////////////////////////////////////////////// (3-1)

// 간략한 Point_ 클래스 정의와 이름 재정의
template<typename _Tp> class Point_ {
public:
	// 기본 생성자. x=0, y=0으로 초기화됨
	Point_();
	// (_x, _y) 좌표를 인자로 받는 생성자. x = _x, y = _y로 초기화됨
	Point_(_Tp _x, _Tp _y);
	// 복사 생성자. x = pt.x, y = pt.y로 초기화됨
	Point_(const Point_& pt);

	// 대입 연산자 재정의
	Point_& operator = (const Point_& pt);

	// Point::dot() 맴버 변수는 두 점 사이의 내적(dot product)을 계산하여 반환
	_Tp dot(const Point_& pt) const;
	// Point::ddot() 맴버 함수는 두 점 사이의 내적을 실수형으로 계산하여 double 자료형으로 반환
	double ddot(const Point_& pt) const;
	// Point::cross() 맴버 함수는 두 점 사이의 외적(cross conduct)을 반환
	double cross(const Point_& pt) const;
	// Point::insdie() 맴버 함수는 점의 좌표가 사각형 r 영역 안에 있으면 true를 반환
	bool inside(const Rect_<_Tp>& r) const;
	
	// ...

	// 맴버 변수. x는 x축 좌표, y는 y축 좌표를 나타냄
	_Tp x, y;
};

// 다양한 자료형에 대한 Point_ 클래스 이름 재정의
typedef ::Point_<int>		Point2i;
typedef ::Point_<int64>		Point2l;
typedef ::Point_<float>		Point2f;
typedef ::Point_<double>	Point2d;
typedef ::Point2i			Point;
// cv의 Point 클래스와의 충돌을 피하기 위해 전역 클래스(::Point_)에 재지정 수행


/////////////////////////////////////////////////////// (3-2)


// 간략한 Size_ 클래스 정의와 이름 재정의
template<typename _Tp> class Size_ {
public:
	// 기본 생성자. width = 0, height = 0으로 초기화
	Size_();
	// (_width, _height) 크기를 인자로 받는 생성자. width = _width, height = _height로 초기화됨
	Size_(_Tp _width, _Tp _height);
	// 복사 생성자. width = sz.width, height = sz.height로 초기화됨
	Size_(const Size_& sz);

	// 대입 연산자 재정의
	Size_& operator = (const Size_& sz);

	// Size::area() 맴버 함수는 사각형 크기에 해당하는 면적(width × height)을 반환
	_Tp area() const;
	// Size::empty() 맴버 함수는 유효하지 않은 크기면 true를 반환
	bool empty() const;

	// 맴버 변수. width는 사격형 영역의 가로 크기, height는 사각형 영역의 세로 크기를 나타냄
	_Tp width, height;
};

// 다양한 자료 형에 대한 Size_ 클래스 이름 재정의
typedef ::Size_<int>	Size2i;
typedef ::Size_<int64>	Size2l;
typedef ::Size_<float>	Size2f;
typedef ::Size_<double> Size2d;
typedef ::Size2i		Size;
// cv의 Size_ 클래스와의 충돌을 피하기 위해 전역 클래스(::Size_)에 재지정 수행


/////////////////////////////////////////////////////// (3-3)


// 간략화한 Rect_ 클래스 정의와 이름 재정의
template<typename _Tp> class Rect_ {
public:
	// 기본 생성자. 모든 맴버 변수를 0으로 초기화
	Rect_();
	// (_x, _y, _width, _height) 사각형 정보를 인자로 받는 생성자. x = _x, y = _y, width = _width, height = _height로 초기화
	Rect_(_Tp _x, _Tp _y, _Tp _width, _Tp _height);
	// 복사 생성자. x = r.x, y = r.y, width = r.width, height = r.height로 초기화
	Rect_(const Rect_& r);
	// 좌측 상단 점의 좌표와 사각형의 크기 정보를 인자로 받는 생성자
	Rect_(const ::Point_<_Tp>& org, const ::Size_<_Tp>& sz);
	// 사각형에서 서로 대각 위치에 있는 두 점의 좌표를 인자로 받는 생성자
	Rect_(const ::Point_<_Tp>& pt1, const ::Point_<_Tp>& pt2);

	// 대입 연산자 재정의
	Rect_& operator = (const Rect_& r);

	// Rect::tl() 맴버 함수는 사각형의 좌측 상단 점의 좌표를 반환
	::Point_<_Tp> tl() const;
	// Rect::br() 맴버 함수는 사각형의 우측 하단 점의 좌표를 반환
	::Point_<_Tp> br() const;
	// Rect::size() 맴버 함수는 사각형의 크기 정보를 반환
	::Size_<_Tp> size() const;
	// Rect::area() 맴버 함수는 사각형의 면적(width×height)을 반환
	_Tp area() const;
	// Rect::empty() 맴버 함수는 유효하지 않은 사각형이면 true를 반환
	bool empty() const;
	// Rect::contains() 맴버 함수는 인자로 전달된 pt 점이 사각형 내부에 있으면 true를 반환
	bool contains(const ::Point_<_Tp>& pt) const;
	
	// 맴버 변수, x, y는 사각형 좌측 상단 점의 좌표, width, height는 사각형의 가로와 세로 크기를 나타냄
	_Tp x, y, width, height;
};

// 다양한 자료형에 대하여 Rect_ 클래스 이름 재정의
typedef ::Rect_<int>	Rect2i;
typedef ::Rect_<float>	Rect2f;
typedef ::Rect_<double>	Rect2d;
typedef ::Rect2i		Rect;
// cv의 Rect_ 클래스와의 충돌을 피하기 위해 전역 클래스(::Rect_)에 재지정 수행


/////////////////////////////////////////////////////// (3-4)


// 간략화한 RotatedRect 클래스 정의
class RotatedRect {
public:
	// 기본 생성자. 모든 맴버 변수를 0으로 초기화
	RotatedRect();
	// (_center, _size,_angle)을 인자로 받는 생성자. center = _center, size = _size, angle = _angle로 초기화
	RotatedRect(const ::Point2f& _center, const ::Size2f& _size, float _angle);
	// (point1, point2, point3)을 인자로 받는 생성자, 인자로 전달된 세 점은 회전된 사각형의 세 꼭지점 좌표를 나타냄
	RotatedRect(const ::Point2f& point1, const ::Point2f& point2, const ::Point2f& point3);

	// RotatedRect::points() 맴버 함수는 회전된 사각형을 포함하는 최소 크기의 사각형 정보를 반환(정수 단위)
	void points(::Point2f pts[]) const;
	// RotatedRect::boundingRect() 맴버 함수는 회전된 사각형을 포함하는 최소 크기의 사각형 정보를 반환(실수 단위)
	::Rect boundingRect() const;
	// RotatedRect::boundingRect2f() 맴버 함수는 회전된 사각형을 포함하는 최소 크기의 사각형 정보를 반환(실수 단위)
	::Rect_<float> boundingRect2f() const;

	// 맴버 변수. center는 사각형의 중심 좌표, size는 사각형의 크기, angle은 시계 방향 회전 각도를 나타냄
	::Point2f center;
	::Size2f size;
	float angle;
};

/////////////////////////////////////////////////////// (3-5)

// 간략화한 Range 클래스 정의
class Range {
public:
	// 기본 생성자. start = end = 0으로 초기화
	Range();
	// 두 개의 정수를 인자로 받는 생성자. start = _start, end = _end로 초기화
	Range(int _start, int _end);

	// Range::size() 맴버 함수는 범위 크기(end - start)를 반환
	int size() const;
	// Range::empty() 맴버 함수는 start와 end가 같으면 true를 반환
	bool empty() const;
	// Range::all() 맴버 함수는 start = INT_MIN, end = INT_MAX로 설정한 Range 객체를 반환
	static Range all();

	// 맴버 변수, start는 범위의 시작, end는 범위의 끝을 나타냄
	int start, end;
};


int main() {

	/////////////////////////////////////////////////////// (3-1-1)

	cv::Point pt1;			// pt1 = (0, 0)
	pt1.x = 5; pt1.y = 10;	// pt1 = (5, 10)
	cv::Point pt2(10, 30);	// pt2 = (10, 30)

	/* 
	변수 pt1은 기본 생성자를 사용하여 생성되어 pt1.x와 pt1.y는 0으로 초기화됨
	그러므로 기본 생성자로 생성된 변수 pt1은 (0, 0) 좌표를 나타냄

	위 코드의 두 번째 행에서는 pt1.x에 5를 대입하고, pt1.y에는 10을 대입함으로써
	pt1 변수가 (5, 10) 좌표를 나타내도록 변경

	변수 pt2는 생성과 동시에 (10, 30) 좌표를 나타냄
	*/


	/* 
	Point_ 클래스는 다양한 연산자에 대해 연산자 재정의가 되어 있어
	다음과 같은 코드를 이용하여 좌표 연산 수행 가능
	*/

	// pt1 = [5, 10], pt2 = [10, 30] 
	cv::Point pt3 = pt1 + pt2;	// pt3 = [15, 40]
	cv::Point pt4 = pt1 * 2;	// pt4 = [10, 20]
	int d1 = pt1.dot(pt2);		// d1 = 350
	bool b1 = (pt1 == pt2);		// b1 = false;

	/*
	위 코드에서 주석 부분은 연산자에 의해 생성되는 Point 객체의 좌표를 의미

	Point 객체 끼리 덧셈 연산 시 x 좌표와 y 좌표를 각각 더하여 새로운 좌표를 생성
	위 코드에서 pt1은 (5, 10), pt2는 (10, 30) 좌표를 표현하고 있으므로 pt3에는 (15, 40) 좌표가 저장

	변수 pt4는 pt1에 정수 2를 곱한 결과이며, 
	이 경우 pt1의 x 좌표와 y 좌표에 각각 2를 곱하여 pt4에는 (10, 20) 좌표가 저장됨
	
	Point::dot() 함수는 두 점의 내적을 계산하는 함수
	두 점의 내적은 x 좌표끼리 곱한 값에 y 좌표끼리 곱한 값을 더하여 계산
	그러므로 d1에는 5×10 + 10×30 = 350이 저장됨

	Point 객체 끼리 == 또는 != 연산자를 이용하여 두 점의 좌표가 서로 같은지 혹은 다른지를 검사할 수도 있음
	위 코드에서는 pt1과 pt2의 좌표가 서로 같지 않으므로 변수 b1에는 false가 저장됨
	*/


	/* 
	OpenCV에서 제공하는 대부분의 자료형 클래스는 C++ 표준 출력을 지원
	그러므로 std::cout과 << 연산자를 이용하여 Point_ 객체의 좌표를 쉽게 출력할 수 있음
	다음은 pt1과 pt2 변수에 저장된 좌표를 화면에 출력하는 코드 예제
	*/

	cout << "pt1: " << pt1 << endl;
	cout << "pt2: " << pt2 << endl;


	cout << endl << "///////////////////////////////////////////////////////" << endl << endl;
	/////////////////////////////////////////////////////// (3-2-1)

	cv::Size sz1, sz2(10, 20);		// sz1 = [0 × 0], sz2 = [10 × 20]
	sz1.width = 5, sz1.height = 10;	// sz1 = [5 × 10]

	/*
	위 코드에서 주석 부분은 연산에 의해 생성되는 Size_ 객체의 크기를 나타냄

	변수 sz1은 기본 생성자를 사용하여 생성하였으며, 
	이 경우 맴버 변수 sz1.width와 sz1.height는 0으로 초기화됨
	그러므로 기본 생성자로 생성된 변수 sz1은 0×0의 크기를 나타내고, 이는 유효하지 않은 크기 객체

	변수 sz2는 생성과 동시에 10×20의 크기를 나타냄

	위 코드의 두 번째 행에서는 sz1.width에 5를 대입하고, sz1.height에는 10을 대입함으로써 5×10의 크기를 나타내도록 변경
	*/


	/*
	Point 클래스와 마찬가지로 Size_ 클래스도 다양한 연산자에 대해 연산자 재정의가 되어 있음
	그러므로 다음과 같이 사칙 연산을 이용하여 크기를 조절할 수 있음
	*/

	// sz1 = [5 × 10], sz2 = [10 × 20]
	cv::Size sz3 = sz1 + sz2;	// sz3 = [15 × 30]
	cv::Size sz4 = sz1 * 2;		// sz4 = [10 × 20[
	int area1 = sz4.area();		// area1 = 200

	/*
	먼저 Size 객체 끼리 덧셈 연산을 하면 가로 크기와 세로 크기를 각각 더하여 새로운 크기 객체를 생성
	그러므로 sz3.width에는 5 + 10 = 15가 저장되고, sz3.height에는 10 + 20 = 30이 저장됨
	
	변수 sz4에는 sz1에 정수 2를 곱하여 생성하였으며, 이 경우 sz1.width와 sz1.height에 각각 2를 곱한 결과가 sz4에 저장됨
	그러므로 sz4의 크기 정보는 10×20이 됨

	Size::area() 맴버 함수는 사각형 크기에 해당하는 면적을 반환하며, 변수 area1에는 10 × 20=200이 저장됨
	*/


	/*
	Size_ 클래스도 C++ 표준 스트림 출력을 지원
	예를 들어 앞서 생성한 sz3와 sz4 객체의 정보를 화면에 출력하려면 다음과 같이 코드를 작성
	*/

	cout << "sz3: " << sz3 << endl;
	cout << "sz4: " << sz4 << endl;

	/*
	std::cout과 << 연산자를 이용하여 Size_ 객체를 출력하면 크기 정보가 [width×height] 형식으로 출력됨
	*/
 
	cout << endl << "///////////////////////////////////////////////////////" << endl << endl;
	/////////////////////////////////////////////////////// (3-3-1)

	cv::Rect rc1;					// rc1 = [0 × 0 from (0, 0)]
	cv::Rect rc2(10, 10, 60, 40);	// rc2 = [60 × 40 from (10, 10)]

	/*
	위 코드에서 주석 부분은 연산에 의해 생성되는 Rect_ 객체의 위치와 크기 정보를 나타냄
	즉, rc2는 (10, 10) 좌표부터 크기가 60 × 40인 사각형으로 나타냄

	변수 rc1은 기본 생성자를 사용하여 생성되었으며, 이 경우 모든 맴버 변수는 0으로 초기화됨
	변수 rc2는 네 개의 정수를 생성자 인자로 사용하였으며, 이 인자들은 차례대로 Rect_ 클래스의 맴버 변수 x, y, width, height 값으로 설정됨
	*/


	/*
	Rect_ 클래스는 Size_ 또는 Point_ 클래스 객체와의 산술 연산자 재정의가 되어 있음
	덧셈 연산자를 이용하여 Rect_ 객체와 Szie_ 객체를 서로 더하면 사각형의 가로와 세로 크기가 변경됨
	반면에 Rect_ 객체와 Point_ 객체를 서로 더하거나 빼면 사각형 위치가 변경됨
	*/

	// rc1 = [0 × 0 from (0, 0)], rc2 = [60 × 40 from (10, 10)]
	cv::Rect rc3 = rc1 + cv::Size(50, 40);	// rc3 = [50 × 40 from (0, 0)]
	cv::Rect rc4 = rc2 + cv::Point(10, 10);	// rc4 = [60 × 40 from (20, 20)]

	/*
	위 코드에서 rc1 객체는 모든 맴버 변수가 0으로 설정되어 있는 유효하지 않은 사각형
	변수 rc1에 Size(50, 40)을 더하면 rc1의 가로 크기가 각각 50과 40만큼 증가
	그러므로 rc3은 (0, 0) 좌표에서 시작하고, 가로 50, 세로 40인 사각형을 표현하게 됨

	변수 rc4는 rc2 객체에 Point(10, 10)을 덧셈 연산자를 이용하여 더하였으며, 이 경우 rc2 사각형의 위치가 (10, 10)만큼 이동
	rc2 사각형이 (10, 10)에서 시작하는 60 × 40 크기의 사각형이므로 rc4는 (20, 20)에서 시작하는 같은 크기의 사각형이 됨
	*/


	/*
	Rect_ 객체끼리 서로 &, | 연산자를 이용한 논리 연산을 수행할 수 있음
	두 개의 사각형 객체끼리 & 연산을 수행하면 두 사각형이 교차하는 사각형 영역을 반환
	반면에 두 사각형 객체끼리 | 연산을 수행하면 두 사각형을 모두 포함하는 최소 크기의 사각형을 반환
	*/

	// rc3 = [50 × 40 from (0, 0)], rc4 = [60 × 40 from (20, 20)]
	cv::Rect rc5 = rc3 & rc4;	// rc5 = [30 × 20 from (20, 20)]
	cv::Rect rc6 = rc3 | rc4;	// rc6 = [80 × 60 from (0, 0)]

	/*
	위 코드에서 rc3은 (0, 0) 좌표에서 시작하는 50 × 40 크기의 사각형이고,
	rc4는 (20, 20) 좌표에서 시작하는 60 × 40 크기의 사각형
	이 두 사각형에 대해 & 연산을 수행하면 사각형이 겹치는 영역이 반환
	그러므로 rc5는 (20, 20) 좌표에서 시작하는 30 × 20 크기의 사각형

	rc3와 rc4 두 사각형에 대해 | 연산을 수행하면 두 사각형을 모두 포함하는 최소 크기의 사각형이 반환
	즉, rc6은 (0, 0) 좌표에서 시작하는 80 × 60 크기의 사각형이 됨
	*/


	/*
	Rect_ 클래스도 C++ 표준 스트림 출력을 지원
	예를 들어 앞서 생성한 rc5와 rc6 객체 정보를 화면에 출력하려면 다음과 같이 코드를 작성
	*/

	cout << "rc5: " << rc5 << endl;
	cout << "rc6: " << rc6 << endl;

	/*
	std::cout과 << 연산자를 이용하여 Rect_ 객체를 출력하면 사각형 정보가 [width × height from (x, y)] 형식으로 출력됨
	*/

	cout << endl << "///////////////////////////////////////////////////////" << endl << endl;
	/////////////////////////////////////////////////////// (3-4)

	/*
	중심 좌표가 (40, 30), 크기는 40×20, 시계방향으로 30˚만큼 회전된 사각형 객체는 다음 코드를 이용하여 생성할 수 있음
	*/

	cv::RotatedRect rr1(cv::Point2f(40, 30), cv::Size2f(40, 20), 30.f);

	/*
	만약 회전된 사각형 객체의 네 꼭지점 좌표를 알고 싶다면 RotatedRect::points() 맴버 함수를 사용
	Rotated::points() 함수에는 크기가 4인 Point2f 자료형의 배열 이름을 전달
	*/

	cv::Point2f pts[4];
	rr1.points(pts);

	cout << "rr1.points() : " << pts[0] << " " << pts[1] << " " << pts[2] << " " << pts[3] << endl;

	/*
	위 코드를 실행하면 회전된 사각형의 네 꼭지점 좌표가 pts 배열에 저장됨 
	실제로 코드를 실행하면 
	pts[0] = (17.6795, 286603),
	pts[1] = (27.6795, 11.3397),
	pts[2] = (2.3205, 31.3397),
	pts[3] = (52.3205, 48.6603)
	형태로 좌표가 설정됨
	RotatedRect::points() 함수는 사각형의 좌측 하단 꼭지점부터 시계방향으로 꼭지점 좌표를 추출
	*/


	/*
	경우에 따라서는 회전된 사각형을 감싸는 최소 크기의 사각형 정보가 필요
	이처럼 특정 객체를 감싸는 최소 크기의 사각형을 바운딩 박스(bounding box)라고 함
	회전된 사각형의 바운딩 박스를 구하려면 RotatedRect::boundingRect() 맴버 함수를 사용
	*/

	cv::Rect br = rr1.boundingRect();
	cout << "br : " << br << endl;

	/*
	실제로 이 코드를 실행하여 구해지는 사각형 객체 br은 (17, 11)에 위치하고 크기가 47×39인 사각형으로 설정됨
	만약 바운딩 박스 사각형의 좌표를 실수 단위로 얻고 싶다면 RotatedRect::boundingRect2f() 함수를 사용해야 함
	*/

	cout << endl << "///////////////////////////////////////////////////////" << endl << endl;
	/////////////////////////////////////////////////////// (3-5)

	/*
	Range 클래스는 start부터 end까지의 정수 단위 범위를 표현
	이 때 start는 범위에 포함되고, end는 범위에 포함되지 않음
	예를 들어 다음 코드에서 r1은 0부터 9까지의 범위를 표현하고, 10은 포함하지 않음
	*/

	cv::Range r1(0, 10);

	cout << "r1 : " << r1 << endl;

	cout << endl << "///////////////////////////////////////////////////////" << endl << endl;
	/////////////////////////////////////////////////////// (3-6)

	/*
	String 타입의 문자열 객체는 C/C++ 언어에서 사용하는 이중 따옴표로 감싸진 문자열로부터 간단하게 만들 수 있음
	그리고 덧셈 연산자를 이용하여 여러 문자열을 이어서 하나의 문자열을 만들 수 있음
	다음 예제 코드를 실행하면 str3 변수에 "Hello World" 문자열이 저장됨
	*/

	String str1 = "Hello";
	String str2 = "world";
	String str3 = str1 + " " + str2; // str3 = "Hello world"

	cout << "str3 : " << str3 << endl;

	/*
	두 문자열 객체의 내용을 비교하기 위해서는 std::string::compare() 함수 또는 == 연산자 재정의를 사용할 수 있음
	예를 들어 다음은 두 문자열의 내용이 같은지 비교하는 예제 코드
	*/

	bool ret = (str2 == "WORLD");
	cout << "ret : " << ret << endl;

	/*
	str2 변수에는 소문자로 구성된 "world"가 저장되어 있음
	== 연산자는 대소문자를 구문하므로 str2와 "WORLD"를 비교할 경우 서로 다르다고 인식
	그러므로 ret 변수에는 false가 저장됨
	*/


	return 0;
}