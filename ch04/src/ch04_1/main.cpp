#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// �Ʒ� �ڵ�� ���ÿ� ���� �ڵ��, ������ ������� ����

/////////////////////////////////////////////////////// (4-1)

// ����ȭ�� VideoCapture Ŭ���� ����
class VideoCapture {
public:
	// VideoCapture Ŭ������ �����ڿ� �Ҹ���
	VideoCapture();
	VideoCapture(const String& filename, int apiPreference = CAP_ANY);
	VideoCapture(int index, int apiPreference = CAP_ANY);
	virtual ~VideoCapture();

	// ������ ���� �Ǵ� ī�޶� ��ġ�� ���ų� �ݴ� �۾��� ���õ� ��� �Լ�
	virtual bool open(const String& filename, int apiPreference = CAP_ANY);
	virtual bool open(int index, int apiPreference = CAP_ANY);
	virtual bool isOpened() const;
	virtual void release();

	// ������ ���� �Ǵ� ī�޶� ��ġ�κ��� �� �������� �޾� ���� ����� ��� �Լ�
	virtual bool grab();
	virtual bool retrieve(OutputArray image, int flag = 0);
	virtual VideoCapture& operator >> (Mat& image);
	virtual bool read(OutputArray image);

	// ���� ���� �ִ� ������ ���� �Ǵ� ī�޶� ��ġ�κ��� ������ �������ų� �����ϴ� ����� ����ϴ� ��� �Լ�
	virtual bool set(int propId, double value);
	virtual double get(int propId) const;

	// ...
};

/////////////////////////////////////////////////////// (4-2)

void camera_in() {

	// VideoCapture ��ü�� �����ϰ�, ��ǻ�Ϳ� ����� �⺻ ī�޶� ����ϵ��� ����
	cv::VideoCapture cap(0);

	// ī�޶� ��ġ�� ���������� ������ �ʾҴٸ� ���� �޽����� ����ϰ� �Լ��� ����
	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return;
	}

	// ī�޶� �Ӽ� �߿��� ������ ���� ũ��� ���� ũ�⸦ �ܼ� â�� ���
	cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;

	// Mat Ÿ���� ���� frame�� inversed�� ����
	cv::Mat frame, inversed;
	while (true) {
		// ī�޶� ��ġ�κ��� �� �������� �޾ƿͼ� frame ������ ����
		cap >> frame;
		// ���� ������ ������ ��� �ִٸ� while ������ ��������
		if (frame.empty())
			break;

		// ���� �������� �����Ͽ� inversed ������ ����
		inversed = ~frame;

		// frame�� inversed�� ����� ���� ������ ȭ�鿡 ���
		cv::imshow("frame", frame);
		cv::imshow("inversed", inversed);

		// ����ڷκ��� 10ms �ð� ���� Ű���� �Է��� ���
		// ���� Ű���� �Է��� �ְ�, �ش� Ű ���� 27(Esc)�̸� while ������ ��������
		if (waitKey(10) == 27) // ESC key
			break;
	}

	// ��� â�� ����
	destroyAllWindows();
}
/*
camera_in() �Լ� ���� �� cap ������ �Ҹ�Ǹ鼭 �ڵ����� ī�޶� ��ġ�� �ݱ� ������ 
������� cap.release(); �Լ� ȣ�� ���� ����
*/

int main() {

	/////////////////////////////////////////////////////// (4-2)

	/*
	��ǻ���� �⺻ ī�޶� ��ġ�� ����Ͽ� �̹����� ����ϴ� �Լ�
	*/

	camera_in();

	/*
	���������� ����Ǹ� ī�޶�κ��� �� �������� �޾ƿͼ� ���� �����Ӱ� ������ �������� ���� ȭ�鿡 ��Ÿ��

	�ܼ� â���� �ش� �������� ���� ũ��� ���� ũ�⸦ �ȼ� ������ ���

	Ű������ Esc Ű�� ������ ī�޶� ������ �����ϰ� ��� â�� ����

	���� ��ǻ�Ϳ� ī�޶� ����� ����Ǿ� ���� �ʰų� �ٸ� ���α׷��� ī�޶� ����ϰ� �ִ� ���¶�� 
	"Camera open failed!" ���ڿ��� ����ϰ� �Լ��� �����
	*/

	return 0;
}