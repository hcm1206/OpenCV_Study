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

/////////////////////////////////////////////////////// (3-7)

void MatOp1() {

	// ��� �ִ� ����� �����ϴ� Mat �⺻ ������ 
	cv::Mat img1;	// empty matrix

	// �޸� ������ �Ҵ��Ͽ� ����� �����ϴ� Mat ������
	cv::Mat img2(480, 640, CV_8UC1);			// unsigned char, 1-channel
	cv::Mat img3(480, 640, CV_8UC3);			// unsigned char, 3-channels
	cv::Mat img4(Size(640, 480), CV_8UC3);		// Size(width, height)

	// �޸� ������ �Ҵ��ϰ� �ʱ�ȭ�� ���� ����� ����� �����ϴ� Mat ������
	cv::Mat img5(480, 640, CV_8UC1, cv::Scalar(128));			// initial values, 128
	cv::Mat img6(480, 640, CV_8UC3, cv::Scalar(0, 0, 255));		// initial values, red

	// �޸� ������ �Ҵ��ϰ� Ư�� ������ �ʱ�ȭ�� ����� �����ϴ� Mat ���� �Լ�
	cv::Mat mat1 = cv::Mat::zeros(3, 3, CV_32SC1);		// 0's matrix
	cv::Mat mat2 = cv::Mat::ones(3, 3, CV_32FC1);		// 1's matrix
	cv::Mat mat3 = cv::Mat::eye(3, 3, CV_32FC1);		// identify matrix

	// �̹� ������ �ܺ� �޸� ���� �̿��Ͽ� ����� �����ϴ� Mat ������
	float data[] = { 1, 2, 3, 4, 5, 6 };
	cv::Mat mat4(2, 3, CV_32FC1, data);

	// C++ �ʱ�ȭ ����Ʈ(initializer list) ������ �̿��Ͽ� ��� �� �ʱ�ȭ
	cv::Mat mat5 = (cv::Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);
	cv::Mat mat6 = cv::Mat_<uchar>({ 2, 3 }, { 1, 2, 3, 4, 5, 6 });

	// ���� Mat ��ü�� ���ο� ����� �����ϴ� Mat::create() �޼ҵ�
	mat4.create(256, 256, CV_8UC3); // uchar, 3-channels
	mat5.create(4, 4, CV_32FC1); // float, 1-channel

	// = ������ ������ �� Mat ��ü �޼ҵ带 �̿��Ͽ� ��� ��ü ���� ���� �Ѳ����� ����
	mat4 = cv::Scalar(255, 0, 0); 
	mat5.setTo(1.f);
}

/////////////////////////////////////////////////////// (3-8)

void MatOp2() {
	// dog.bmp ������ ������ �ҷ��ͼ� img1�� ����
	cv::Mat img1 = imread("dog.bmp");

	// ���� �����ڿ� ���� �����ڸ� �̿��Ͽ� img1�� ���纻 ���� img2, img3�� ����(���� ����)
	cv::Mat img2 = img1;
	cv::Mat img3;
	img3 = img1;

	// Mat::clone()�� Mat::copyTo() �Լ��� �̿��Ͽ� img1�� ���纻 ���� img4, img5�� ���� (���� ����)
	cv::Mat img4 = img1.clone();
	cv::Mat img5;
	img1.copyTo(img5);

	// img1 ������ ��� �ȼ��� Scalar(0, 255, 255)�� �ش��ϴ� ��������� ����
	img1.setTo(Scalar(0, 255, 255)); // yellow

	// img1~img5 ������ ��� �� â���� ���
	cv::imshow("img1", img1);
	cv::imshow("img2", img2);
	cv::imshow("img3", img3);
	cv::imshow("img4", img4);
	cv::imshow("img5", img5);

	cv::waitKey();
	cv::destroyAllWindows();
}

/////////////////////////////////////////////////////// (3-9)

void MatOp3() {
	// cat.bmp ����� ������ �ҷ��ͼ� img1�� ����
	cv::Mat img1 = cv::imread("cat.bmp");

	// ������ �ҷ����µ� �����Ͽ� img1 ����� ����ִٸ� ���� �޽��� ��� �� ����
	if (img1.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	// img1 ����� ������ Ư�� �簢�� ���� ROI�� �����Ͽ� img2�� ���� (���� ����)
	cv::Mat img2 = img1(Rect(220, 120, 340, 240));
	// img1 ����� ������ Ư�� �簢�� ���� ROI�� ���� �� �ش� ���� ��� �����Ͽ� ���ο� �޸𸮸� �Ҵ��Ͽ� img3�� ���� (���� ����)
	cv::Mat img3 = img1(Rect(220, 120, 340, 240)).clone();

	// img2 ������ ���� ����
	img2 = ~img2;

	// img1, img2, img3 ������ ��� �� â���� ���
	cv::imshow("img1", img1);
	cv::imshow("img2", img2);
	cv::imshow("img3", img3);

	cv::waitKey();
	cv::destroyAllWindows();
}

int main() {

	/////////////////////////////////////////////////////// (3-7)

	/*
	�Ʒ� �Լ��� Mat ��� ���� �� �� �ʱ�ȭ�� �����ϰ� ��Ÿ �ƹ��� ������ ���� ����
	*/ 
	MatOp1(); 

	/////////////////////////////////////////////////////// (3-8)

	/*
	�Ʒ� �Լ��� �پ��� ���� ����� �̿��Ͽ� img1�� ����� ������ ������ ���ο� ���� img2, img3, img4, img5�� ���� ����
	�׸��� img1 ������ ��� �ȼ� ���� ������� �ش��ϴ� Scalar(0, 255, 255)�� ������ ��, ������ ������ ȭ�鿡 ���
	*/

	MatOp2();

	/*
	img1 ���� ��������� �����Ͽ����� img1, img2, img3 ������ ��� ��������� �ٲ�
	img2�� img3 ������ img1�� �ȼ� �����͸� �����ϱ� ������ ��Ÿ�� ���
	�ݸ鿡 img4�� img5�� ���� ���縦 �����Ͽ��� ������ ������ ������ �״�� ����
	*/

	/////////////////////////////////////////////////////// (3-9)

	/*
	�Ʒ� �Լ��� img1�� ����� ����� ������ �κ� ���� ������ �����Ͽ� ���ο� ���� img2, img3�� ���� ����
	�׸��� img2 ������ ���� ���� ��, ������ ������ ȭ�鿡 ���
	*/

	MatOp3();

	return 0;
}
