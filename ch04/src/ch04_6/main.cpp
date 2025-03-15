#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

/////////////////////////////////////////////////////// (4-13)

// 간략화한  FileStorage 클래스 정의(실제 사용하지 않는 스텁 코드)
class FileStorage {
public:
	// FileStorage 클래스 생성자 정의
	FileStorage();
	FileStorage(const String& filename, int flags, const String& encoding = String());

	// 파일을 열고 닫을 대 사용하는 맴버 함수
	virtual bool open(const String& filename, int flags, const String& encoding = String());
	virtual bool isOpened() const;
	virtual void release();

	// 파일에서 데이터를 읽어서 FileNode 객체를 반환하기 위한 [] 연산자 재정의
	FileNode operator[](const char* nodename) const;
	// ...
};

// 파일에 데이터를 저장할 때 사용하는 << 연산자 재정의
template<typename _Tp> static
::FileStorage& operator << (::FileStorage& fs, const _Tp& value);
static ::FileStorage& operator << (::FileStorage& fs, const String& str);
static ::FileStorage& operator << (::FileStorage& fs, const char& str);

// 파일에서 데이터를 읽어올 때 사용하는 >> 연산자 재정의
//template<typename _Tp> static
//void operator >> (const FileNode& n, _Tp& value);
//template<typename _Tp> static
//void operator >> (const FileNode& n, std::vector<_Tp>& vec);

/////////////////////////////////////////////////////// (4-14)

// 데이터 파일 이름으로 사용할 문자열을 전역 변수로 선언
// String filename = "mydata.xml";
// String filename = "mydata.yml";
String filename = "mydata.json";

void writeData() {
	// 파일에 저장할 데이터 변수 선언
	String name = "Jane";
	int age = 10;
	Point pt1(100, 200);
	vector<int> scores = { 80, 90, 50 };
	Mat mat1 = (Mat_<float>(2, 2) << 1.0f, 1.5f, 2.0f, 3.2f);

	// FileStorage 객체를 쓰기 모드로 생성
	cv::FileStorage fs(filename, cv::FileStorage::WRITE);

	// FileStorage 객체 생성 실패 시 처리할 예외문
	if (!fs.isOpened()) {
		cerr << "File open failed!" << endl;
		return;
	}

	// << 연산자를 이용하여 준비한 데이터를 파일에 저장
	fs << "name" << name;
	fs << "age" << age;
	fs << "point" << pt1;
	fs << "scores" << scores;
	fs << "data" << mat1;

	// 데이터 저장이 끝나면 파일을 닫음
	fs.release();
 }

/////////////////////////////////////////////////////// (4-15)

void readData() {
	// 파일에서 읽어올 데이터를 저장할 변수 선언
	String name;
	int age;
	Point pt1;
	vector<int> scores;
	Mat mat1;

	// FileStorage 객체를 읽기 모드로 생성해서 filename 이름의 파일(mydata.json)을 읽어와 내용을 저장
	cv::FileStorage fs(filename, cv::FileStorage::READ);

	// 파일 로드 실패 시 처리할 예외문
	if (!fs.isOpened()) {
		cerr << "File open failed!" << endl;
		return;
	}

	// 파일로부터 데이터를 제대로 읽었는지 확인하기 위하여 읽은 데이터를 콘솔 창에 출력
	fs["name"] >> name;
	fs["age"] >> age;
	fs["point"] >> pt1;
	fs["scores"] >> scores;
	fs["data"] >> mat1;

	// 데이터 읽기가 끝나면 파일을 닫음
	fs.release();

	cout << "name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "point: " << pt1 << endl;
	// std::vector 객체에 저장된 값을 간단히 출력하기 위한 코드로, 
	// 이 vector<int> 형식의 scores 원소들로 구성된 1열짜리 행렬을 생성한 후 그 행렬의 1행짜리 전치 행렬을 생성하여 출력
	cout << "scores: " << Mat(scores).t() << endl;
	cout << "data:\n" << mat1 << endl;
}

int main() {

	/////////////////////////////////////////////////////// (4-14)

	/*
	FileStorage 클래스를 이용하여 C/C++ 기본 자료형, STL 벡터, OpenCV 자료형 등을 JSON 파일 형식으로 저장하는 함수
	*/

	writeData();

	/*
	writeData() 함수 실행 시 프로그램 실행 폴더에 mydata.json 파일이 생성됨
	mydata.json 파일에는 JSON 문법을 이용하여 각각의 데이터가 저장되어 있으며, 각 데이터는 이름과 값이 콜론(:)으로 구분되어 있음
	문자열과 정수형 데이터는 하나의 값 형태로 저장되어 있고, Point 자료형과 vector<int> 형식의 데이터는 [] 대괄호를 이용한 JSON 배열 형태로 저장됨
	Mat 클래스 데이터는 {} 중괄호를 이용하는 JSON 객체 형식으로 저장됨

	저장할 파일 이름을 mydata.json 대신 mydata.xml 또는 mydata.yml로 지정하면 각각 XML과 YAML 형식에 맞게 데이터를 저장함
	FileStorage 클래스에 의해 다양한 형식의 데이터 파일이 정상적으로 생성되는 것을 확인할 수 있으며, 
	저장된 파일은 추후 FileStorage 클래스를 이용하여 다시 읽어올 수 있음
	*/

	/////////////////////////////////////////////////////// (4-15)

	/*
	FileStorage 클래스를 이용하여 파일로부터 C/C++ 기본 자료형, STL 벡터, OpenCV 자료형 등을 읽어오는 함수
	*/

	readData();

	/*
	mydata.json 파일을 데이터 파일로 사용하여 해당 파일의 내용을 읽어서 화면에 출력
	*/

	return 0;
}