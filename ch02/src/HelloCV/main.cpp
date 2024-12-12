/*
OpenCV���� ����ϴ� �پ��� Ŭ������ �Լ��� ����Ǿ� �ִ� opencv.hpp ��� ������ ����
opencv.hpp ������ OpenCV ��� ������ �� �ִ� ���� ��ġ���� opencv2��� �̸��� ���� ���� �ȿ� �ֱ� ������
#include "opencv2/opencv.cpp" ���·� �ڵ带 �Է��ؾ� ��
*/
#include "opencv2/opencv.hpp"

// C++ ǥ�� ����� ���� iostream ��� ���� ����
#include <iostream>


int main() {
	/*
	C++ ǥ�� ������� OpenCV ���̺귯���� ������ ����ϴ� �ڵ�
	�ҽ� �ڵ忡�� ���� CV_VERSION�� ��ǻ�Ϳ� ��ġ�Ǿ� �ִ� OpenCV ���̺귯���� ���� ������ ���ڿ� ���·� ������ ��ũ��
	���� �ǽ� ȯ�濡�� OpenCV 4.10.0 ������ ����ϱ� ������ CV_VERSION���� "4.0.0" ���ڿ��� ����Ǿ� ����
	*/
	std::cout << "Hello OpenCV " << CV_VERSION << std::endl;

	return 0;
}