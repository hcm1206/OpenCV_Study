#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

/*
Mat 행렬의 원소 값을 출력하는 기능을 하는 함수
함수의 인자로 전달받는 타입이 InputArray
*/

void printMat(InputArray _mat) {
	// InputArray 타입의 _mat 객체로부터 Mat 객체 mat을 생성
	Mat mat = _mat.getMat();
	// C++ 표준 출력 스트림으로 mat 행렬을 출력
	cout << mat << endl;
}

int main() {
	
	// data1 배열 값을 갖는 2×3 행렬 mat1을 생성
	uchar data1[] = { 1, 2, 3, 4, 5, 6 };
	Mat mat1(2, 3, CV_8U, data1);
	// printMat() 함수에 Mat 클래스 객체를 전달하여 원소 값을 출력
	printMat(mat1);

	// 세 개의 실수로 이루어진 vec1 벡터를 생성
	vector<float> vec1 = { 1.2f, 3.4f, -2.1f };
	// printMat() 함수에 vector<float> 객체를 전달하여 원소 값을 출력
	printMat(vec1);

	/*
	위 예제 코드에서 printMat() 함수를 두 번 호출
	한 번은 Mat 객체를 전달하고 다음에는 vector<float> 객체를 전달
	printMat() 함수는 두 가지 경우에 대해 모두 getMat() 함수를 통해 Mat 객체를 생성하고, 이를 std::cout과 << 연산자를 통해 화면에 출력
	*/

	return 0;
}