#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

// �Ʒ� �ڵ�� ���ÿ� ���� �ڵ��, ������ ������� ����

/////////////////////////////////////////////////////// (3-6)

class Mat {
public:

	// Mat Ŭ������ �پ��� �����ڿ� �Ҹ���
	Mat();
	Mat(int rows, int cols, int type);
	Mat(Size size, int type);
	Mat(int rows, int cols, int type, const Scalar& s);
	Mat(const Mat& m);
	~Mat();

	// Mat ũ������ �ɹ� �Լ�. Mat Ŭ������ �ɹ� �Լ����� ������ ������ �Լ��� ���� �ɹ� �Լ��� ���Ե�
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

	// Mat Ŭ������ �ֿ� �ɹ� ����
	int dims;
	int rows, cols;
	uchar* data;
	MatSize size;
	
	// ������ �Ϻ� �ڵ� ����
	// ...
};

/*
Mat::dims �ɹ� ������ Mat ����� ������ ��Ÿ����,
����� ���� 2���� ����� ��� Mat::dims ���� 2

Mat::rows�� Mat::cols �ɹ� ������ 2���� ����� ũ�⸦ ��Ÿ��
Mat::rows�� ����� �� ������ ��Ÿ����, Mat::cols�� �� ������ ��Ÿ��

���� Mat ��ü�� ���� ������ ����Ǿ� �ִ� �����
Mat::rows�� ������ ���� �ȼ� ũ���̰�, Mat::cols�� ������ ���� �ȼ� ũ��

Mat::rows�� Mat::cols �ɹ� ������ Mat ��ü�� 2���� ����� ��쿡�� �ǹ� �ִ� ���� ������, 
3���� �̻��� ��Ŀ����� -1�� �����
3���� �̻� ����� ũ�� ������ Mat::size �ɹ� ������ �̿��Ͽ� ������ �� ����

Mat::data�� ����� ���� �����Ͱ� ����Ǿ� �ִ� �޸� ������ ����Ű�� �������� �ɹ� ����
���� ��Ŀ� �ƹ��͵� ����Ǿ� ���� ���� ���¶�� Mat::data�� 0(NULL) ���� ����

Mat Ŭ������ ��� �ɹ� ������ public ���� �����ڷ� ����Ǿ� �־ Ŭ���� �ܺο��� ���� ������ �� ����
*/

int main() {

	return 0;
}
