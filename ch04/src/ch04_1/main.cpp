#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/////////////////////////////////////////////////////// (4-1)

// �Ʒ� �ڵ�� ���ÿ� ���� �ڵ��, ������ ������� ����

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

/////////////////////////////////////////////////////// (4-3)

void video_in() {

	// stopwatch.avi ������ �ҷ��ͼ� cap ��ü�� ����
	cv::VideoCapture cap("stopwatch.avi");

	// ���� �ε� ���� �� ������ ���� ó�� �ڵ�
	if (!cap.isOpened()) {
		cerr << "Video open failed!" << endl;
		return;
	}

	// ���� �������� ���� ũ��� ���� ũ��, ��ü ������ �� ���
	cout << "Frame width: " << cvRound(cap.get(cv::CAP_PROP_FRAME_WIDTH));
	cout << "Frame height: " << cvRound(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
	cout << "Frame count:" << cvRound(cap.get(cv::CAP_PROP_FRAME_COUNT));

	// ���� ������ �ʴ� ������ ��(FPS) ���� �޾� �ͼ� ���
	double fps = cap.get(cv::CAP_PROP_FPS);
	cout << "FPS: " << fps << endl;

	// FPS �����κ��� �� ������ ������ �ð� ���� delay(�и��� ����)�� ���
	int delay = cvRound(1000 / fps);

	cv::Mat frame, inversed;
	while (true) {
		// ī�޶� ��ġ�κ��� �� �������� �޾� �ͼ� frame ������ ����
		cap >> frame;
		// ���� �ش� ������ ������ ��� ������ while ������ ��������
		if (frame.empty()) {
			break;
		}

		// ���� �������� �����Ͽ� inversed ������ ����
		inversed = ~frame;

		// frame�� inversed�� ����� ���� ������ ȭ�鿡 ���
		imshow("frame", frame);
		imshow("inversed", inversed);

		// delay �ð���ŭ Ű �Է��� ��ٸ���, ���� EscŰ�� ������ while ���� �ݺ��� ����
		if (waitKey(delay) == 27) // ESC key
			break;
	}

	destroyAllWindows();
}

/////////////////////////////////////////////////////// (4-4)

// �Ʒ� �ڵ�� ���ÿ� ���� �ڵ��, ������ ������� ����

// ����ȭ�� VideoWriter Ŭ���� ����
class VideoWriter {
public:
	// VideoWriter Ŭ������ �����ڿ� �Ҹ���
	VideoWriter();
	VideoWriter(const String& filename, int fourcc, double fps, Size frameSize, bool isColor = true);

	virtual ~VideoWriter();

	// ������ ������ ���ų� �ݴ� �۾��� �����ϴ� ��� �Լ�
	virtual bool open(const String& filename, int fourcc, double fps, Size frameSize, bool isColor = true);
	virtual bool isOpened() const;
	virtual void release();

	// ������ ���Ͽ� �������� �߰��ϴ� ����� ��� �Լ�
	virtual VideoWriter& operator << (const Mat& image);

	// ���� ���� ������ ���Ϸκ��� ������ �������ų� �����ϴ� ����� ����ϴ� �Լ�
	virtual void write(const Mat& image);
	virtual bool set(int propId, double value);
	
	// VideoWriter::fourcc() ��� �Լ��� fourcc �ڵ带 �����ϴ� ���� ��� �Լ�
	static int fourcc(char c1, char c2, char c3, char c4);

	// ...
};

/////////////////////////////////////////////////////// (4-5)

void camera_in_video_out() {

	// �ý��� �⺻ ī�޶� ���
	cv::VideoCapture cap(0);

	// ī�޶� �ε� ���� �� ������ ����ó�� �ڵ�
	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return;
	}

	// ī�޶� �������� ����, ���� ũ��, ī�޶��� FPS ���� �޾ƿ�
	int w = cvRound(cap.get(cv::CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
	double fps = cap.get(cv::CAP_PROP_FPS);

	// DivX MPEG-4 �ڵ��� �ش��ϴ� fourcc �ڵ带 ����
	int fourcc = cv::VideoWriter::fourcc('D', 'I', 'V', 'X');
	// FPS �����κ��� �� ������ ������ �ð� ������ �и��� ������ ���
	int delay = cvRound(1000 / fps);

	// ������ ������ ������ ����. ������ ������ �̸��� output.avi
	cv::VideoWriter outputVideo("output.avi", fourcc, fps, cv::Size(w, h));

	// ������ ���� ������ ���� �߻� �� ������ ����ó�� �ڵ�
	if (!outputVideo.isOpened()) {
		cout << "File open failed!" << endl;
		return;
	}

	cv::Mat frame, inversed;

	while (true) {
		// ī�޶�κ��� �� �������� �޾ƿ� frame�� ����
		cap >> frame;
		// �������� �޾ƿ��� ���� empty ���¶�� �ݺ��� ����
		if (frame.empty())
			break;

		// ī�޶� �������� �����Ͽ� inversed�� ����
		inversed = ~frame;
		// ������ ī�޶� ������ ���� inversed�� ��� ������ �߰�
		outputVideo << inversed;

		// ���� �����Ӱ� ������ �������� ���� â�� ���
		cv::imshow("frame", frame);
		cv::imshow("inversed", inversed);

		// Esc�� �������� �ݺ��� ����
		if (waitKey(delay) == 27)
			break;
	}

	destroyAllWindows();
}

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

	/////////////////////////////////////////////////////// (4-3)

	/*
	���� ������ �ҷ��� ���� ������� ������ �������� ����ϴ� �Լ�
	*/

	video_in();

	/*
	���������� ����Ǹ� stopwatch.avi ������ ���Ϸ� ���� �� �������� �޾ƿͼ� ���� �����Ӱ� ������ �������� ���� ȭ�鿡 ��Ÿ��

	�ܼ� â���� �������� ���� ũ��� ���� ũ��, ��ü ������ ��, FPS ���� ���

	��ü �������� ��� ��µǸ� video_in() �Լ��� �ڵ����� ����
	*/

	/////////////////////////////////////////////////////// (4-5)

	/*
	��ǻ�Ϳ� ����� ī�޶�κ��� �������� �Է¹ް�, �ش� �������� ������ ������ �̿��Ͽ� ������ ������ �����ϴ� �Լ�
	*/

	camera_in_video_out();

	/*
	���������� �����ϸ� ȭ�鿡 frame�� inversed �̸��� ���� â�� ��Ÿ����, ���� ī�޶� �Է� �����Ӱ� ������ ������ ������ ���
	����ڰ� Ű������ Esc Ű�� ������ â�� ������鼭 �Լ��� �����

	�Լ��� ����� �� Windows ���� Ž���⸦ �̿��Ͽ� ���α׷� ���� ������ �̵��ϸ� output.avi ������ ������ ���� Ȯ���� �� ����
	�ش� ������ DivX �ڵ��� ����Ͽ� ����� ������ �����̸�, �Ϲ����� ������ ��� ���α׷����� ����� �� ����
	*/

	return 0;
}