#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

/////////////////////////////////////////////////////// (4-13)

// ����ȭ��  FileStorage Ŭ���� ����(���� ������� �ʴ� ���� �ڵ�)
class FileStorage {
public:
	// FileStorage Ŭ���� ������ ����
	FileStorage();
	FileStorage(const String& filename, int flags, const String& encoding = String());

	// ������ ���� ���� �� ����ϴ� �ɹ� �Լ�
	virtual bool open(const String& filename, int flags, const String& encoding = String());
	virtual bool isOpened() const;
	virtual void release();

	// ���Ͽ��� �����͸� �о FileNode ��ü�� ��ȯ�ϱ� ���� [] ������ ������
	FileNode operator[](const char* nodename) const;
	// ...
};

// ���Ͽ� �����͸� ������ �� ����ϴ� << ������ ������
template<typename _Tp> static
::FileStorage& operator << (::FileStorage& fs, const _Tp& value);
static ::FileStorage& operator << (::FileStorage& fs, const String& str);
static ::FileStorage& operator << (::FileStorage& fs, const char& str);

// ���Ͽ��� �����͸� �о�� �� ����ϴ� >> ������ ������
//template<typename _Tp> static
//void operator >> (const FileNode& n, _Tp& value);
//template<typename _Tp> static
//void operator >> (const FileNode& n, std::vector<_Tp>& vec);

/////////////////////////////////////////////////////// (4-14)

// ������ ���� �̸����� ����� ���ڿ��� ���� ������ ����
// String filename = "mydata.xml";
// String filename = "mydata.yml";
String filename = "mydata.json";

void writeData() {
	// ���Ͽ� ������ ������ ���� ����
	String name = "Jane";
	int age = 10;
	Point pt1(100, 200);
	vector<int> scores = { 80, 90, 50 };
	Mat mat1 = (Mat_<float>(2, 2) << 1.0f, 1.5f, 2.0f, 3.2f);

	// FileStorage ��ü�� ���� ���� ����
	cv::FileStorage fs(filename, cv::FileStorage::WRITE);

	// FileStorage ��ü ���� ���� �� ó���� ���ܹ�
	if (!fs.isOpened()) {
		cerr << "File open failed!" << endl;
		return;
	}

	// << �����ڸ� �̿��Ͽ� �غ��� �����͸� ���Ͽ� ����
	fs << "name" << name;
	fs << "age" << age;
	fs << "point" << pt1;
	fs << "scores" << scores;
	fs << "data" << mat1;

	// ������ ������ ������ ������ ����
	fs.release();
 }

/////////////////////////////////////////////////////// (4-15)

void readData() {
	// ���Ͽ��� �о�� �����͸� ������ ���� ����
	String name;
	int age;
	Point pt1;
	vector<int> scores;
	Mat mat1;

	// FileStorage ��ü�� �б� ���� �����ؼ� filename �̸��� ����(mydata.json)�� �о�� ������ ����
	cv::FileStorage fs(filename, cv::FileStorage::READ);

	// ���� �ε� ���� �� ó���� ���ܹ�
	if (!fs.isOpened()) {
		cerr << "File open failed!" << endl;
		return;
	}

	// ���Ϸκ��� �����͸� ����� �о����� Ȯ���ϱ� ���Ͽ� ���� �����͸� �ܼ� â�� ���
	fs["name"] >> name;
	fs["age"] >> age;
	fs["point"] >> pt1;
	fs["scores"] >> scores;
	fs["data"] >> mat1;

	// ������ �бⰡ ������ ������ ����
	fs.release();

	cout << "name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "point: " << pt1 << endl;
	// std::vector ��ü�� ����� ���� ������ ����ϱ� ���� �ڵ��, 
	// �� vector<int> ������ scores ���ҵ�� ������ 1��¥�� ����� ������ �� �� ����� 1��¥�� ��ġ ����� �����Ͽ� ���
	cout << "scores: " << Mat(scores).t() << endl;
	cout << "data:\n" << mat1 << endl;
}

int main() {

	/////////////////////////////////////////////////////// (4-14)

	/*
	FileStorage Ŭ������ �̿��Ͽ� C/C++ �⺻ �ڷ���, STL ����, OpenCV �ڷ��� ���� JSON ���� �������� �����ϴ� �Լ�
	*/

	writeData();

	/*
	writeData() �Լ� ���� �� ���α׷� ���� ������ mydata.json ������ ������
	mydata.json ���Ͽ��� JSON ������ �̿��Ͽ� ������ �����Ͱ� ����Ǿ� ������, �� �����ʹ� �̸��� ���� �ݷ�(:)���� ���еǾ� ����
	���ڿ��� ������ �����ʹ� �ϳ��� �� ���·� ����Ǿ� �ְ�, Point �ڷ����� vector<int> ������ �����ʹ� [] ���ȣ�� �̿��� JSON �迭 ���·� �����
	Mat Ŭ���� �����ʹ� {} �߰�ȣ�� �̿��ϴ� JSON ��ü �������� �����

	������ ���� �̸��� mydata.json ��� mydata.xml �Ǵ� mydata.yml�� �����ϸ� ���� XML�� YAML ���Ŀ� �°� �����͸� ������
	FileStorage Ŭ������ ���� �پ��� ������ ������ ������ ���������� �����Ǵ� ���� Ȯ���� �� ������, 
	����� ������ ���� FileStorage Ŭ������ �̿��Ͽ� �ٽ� �о�� �� ����
	*/

	/////////////////////////////////////////////////////// (4-15)

	/*
	FileStorage Ŭ������ �̿��Ͽ� ���Ϸκ��� C/C++ �⺻ �ڷ���, STL ����, OpenCV �ڷ��� ���� �о���� �Լ�
	*/

	readData();

	/*
	mydata.json ������ ������ ���Ϸ� ����Ͽ� �ش� ������ ������ �о ȭ�鿡 ���
	*/

	return 0;
}