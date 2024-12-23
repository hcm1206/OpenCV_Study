#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

/*
Mat ����� ���� ���� ����ϴ� ����� �ϴ� �Լ�
�Լ��� ���ڷ� ���޹޴� Ÿ���� InputArray
*/

void printMat(InputArray _mat) {
	// InputArray Ÿ���� _mat ��ü�κ��� Mat ��ü mat�� ����
	Mat mat = _mat.getMat();
	// C++ ǥ�� ��� ��Ʈ������ mat ����� ���
	cout << mat << endl;
}

int main() {
	
	// data1 �迭 ���� ���� 2��3 ��� mat1�� ����
	uchar data1[] = { 1, 2, 3, 4, 5, 6 };
	Mat mat1(2, 3, CV_8U, data1);
	// printMat() �Լ��� Mat Ŭ���� ��ü�� �����Ͽ� ���� ���� ���
	printMat(mat1);

	// �� ���� �Ǽ��� �̷���� vec1 ���͸� ����
	vector<float> vec1 = { 1.2f, 3.4f, -2.1f };
	// printMat() �Լ��� vector<float> ��ü�� �����Ͽ� ���� ���� ���
	printMat(vec1);

	/*
	�� ���� �ڵ忡�� printMat() �Լ��� �� �� ȣ��
	�� ���� Mat ��ü�� �����ϰ� �������� vector<float> ��ü�� ����
	printMat() �Լ��� �� ���� ��쿡 ���� ��� getMat() �Լ��� ���� Mat ��ü�� �����ϰ�, �̸� std::cout�� << �����ڸ� ���� ȭ�鿡 ���
	*/

	return 0;
}