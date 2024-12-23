#include <iostream>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

// �Ʒ� �ڵ�� ���ÿ� ���� �ڵ��, ������ ������� ����

/////////////////////////////////////////////////////// (3-14)

// ���� ũ���� ����� ǥ���ϴ� Matx Ŭ���� ����. ��� ���Ҵ� val ��� ���� �迭�� ����
template<typename _Tp, int m, int n> class Matx {
public:
	// ...
	_Tp val[m * n]; // <matrix elements
};

// ���� ũ���� ���͸� ǥ���ϴ� Vec Ŭ���� ����. Vec Ŭ������ Matx Ŭ������ ��ӹ޾� ���������, cn���� ���Ҹ� ���� val �迭�� ��� ������ ����
template<typename _Tp, int cn> class Vec : public Matx<_Tp, cn, 1> {
public:
	// ...
	/*! element access */
	// Vec Ŭ������ ��� ���� �迭 val�� ������ �� �ִ� [] ������ ������
	_Tp& operator[](int i);
};

// C++ ǥ�� ��� ��Ʈ���� �̿��Ͽ� ���� ���Ҹ� ����ϴ� ������ ������
template<typename _Tp, int n> static inline
std::ostream& operator<< (std::ostream& out, const ::Vec<_Tp, n>& vec);


/////////////////////////////////////////////////////// (3-15)

// ����ȭ�� Scalar_�� Scalar Ŭ���� ����

template<typename _Tp> class Scalar_ : public Vec<_Tp, 4> {
public:
	// Scalar_ Ŭ���� ������
	Scalar_();
	Scalar_(_Tp v0);
	Scalar_(_Tp v0, _Tp v1, _Tp v2 = 0, _Tp v3 = 0);

	// Scalar::all() ��� �Լ��� �� ���� val �迭 ���� ��� v0���� ������ Scalar_ ��ü�� ��ȯ
	static Scalar_<_Tp> all(_Tp v0);

	// ...
};

// double �ڷ����� ����ϴ� Scalar_ Ŭ������ ���� Scalar��� �̸����� ������
typedef ::Scalar_<double> Scalar;

/*
�� ::Scalar_ Ŭ������ Vec Ŭ������ ��ӹ޾�����, �� ���� ���Ҹ� ������ �ִ� ���ø� Ŭ����
Scalar_ Ŭ������ ���ø� Ŭ�����̱� ������ �پ��� �ڷ����� 
*/


/////////////////////////////////////////////////////// (3-16)

void ScalarOp() {
	// 128 ���� �ϳ��� �̿��Ͽ� Scalar Ŭ���� Ÿ���� ���� gray�� �ʱ�ȭ
	// gray ��ü�� val ��� �������� [128, 0, 0, 0] ���� �����
	cv::Scalar gray = 128;
	cout << "gray: " << gray << endl;
	/*
	�� ��� gray ������ ������ �ִ� �� ���� double�� ���� �߿��� ù ��° ���Ҹ� 128�� �����ǰ�, ������ �� ���� ���Ҵ� 0���� �ʱ�ȭ��
	6���� yellow ������ �� ���� double�� ���� �� ó�� �� ���Ұ� ���ʴ�� 0, 255, 255�� �����ǰ�, ������ �� ��° ���Ҵ� 0���� �ʱ�ȭ��
	*/

	// yellow ��ü���� ������� ǥ���ϴ� [0, 255, 255, 0] ���� �����
	cv::Scalar yellow(0, 255, 255);
	cout << "yellow: " << yellow << endl;

	// yellow ������ Mat Ŭ���� �������� �� ��° ���ڷ� �����Ͽ�, ��������� �ʱ�ȭ�� 256��256 ũ���� �÷� ���� img1�� ����
	cv::Mat img1(256, 256, CV_8UC3, yellow);

	// yellow ��ü�� ����� ���� �����ϱ� ���� [] ������ ������ ���
	for (int i = 0; i < 4; i++)
		cout << yellow[i] << endl;
	/*
	Scalar Ŭ������ ����� ������ ���ҿ� �����ϱ� ���� ��� ���� val �迭�� ���� �����ص� ������ ������ [] ������ �����Ǹ� ���
	yellow ������ 0��° ���� ���� �����Ϸ��� yellow.val[0]�̶�� �Է��ص� ������ yellow[0] �ڵ带 �� ���� ���
	*/
}

int main() {
	
	/*
	�Ʒ� �Լ��� Scalar ��ü�� �����ϰ� 
	Mat ��� ��ü�� ������ �����ϴ� ���� �ڵ�� 
	Scalar ��ü�� ���ҵ��� [] ������ �����Ǹ� �̿��� ��ȸ �� ����ϴ� ���� �ڵ带 ����
	*/

	ScalarOp();

	return 0;
}