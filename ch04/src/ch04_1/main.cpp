#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/////////////////////////////////////////////////////// (4-1)

// 아래 코드는 예시용 스텁 코드로, 실제로 사용하지 않음

// 간략화한 VideoCapture 클래스 정의
class VideoCapture {
public:
	// VideoCapture 클래스의 생성자와 소멸자
	VideoCapture();
	VideoCapture(const String& filename, int apiPreference = CAP_ANY);
	VideoCapture(int index, int apiPreference = CAP_ANY);
	virtual ~VideoCapture();

	// 동영상 파일 또는 카메라 장치를 열거나 닫는 작업과 관련된 멤버 함수
	virtual bool open(const String& filename, int apiPreference = CAP_ANY);
	virtual bool open(int index, int apiPreference = CAP_ANY);
	virtual bool isOpened() const;
	virtual void release();

	// 동영상 파일 또는 카메라 장치로부터 한 프레임을 받아 오는 기능의 멤버 함수
	virtual bool grab();
	virtual bool retrieve(OutputArray image, int flag = 0);
	virtual VideoCapture& operator >> (Mat& image);
	virtual bool read(OutputArray image);

	// 현재 열려 있는 동영상 파일 또는 카메라 장치로부터 정보를 가져오거나 설정하는 기능을 담당하는 멤버 함수
	virtual bool set(int propId, double value);
	virtual double get(int propId) const;

	// ...
};

/////////////////////////////////////////////////////// (4-2)

void camera_in() {

	// VideoCapture 객체를 생성하고, 컴퓨터에 연결된 기본 카메라를 사용하도록 설정
	cv::VideoCapture cap(0);

	// 카메라 장치가 성공적으로 열리지 않았다면 에러 메시지를 출력하고 함수를 종료
	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return;
	}

	// 카메라 속성 중에서 프레임 가로 크기와 세로 크기를 콘솔 창에 출력
	cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;

	// Mat 타입의 변수 frame과 inversed를 선언
	cv::Mat frame, inversed;
	while (true) {
		// 카메라 장치로부터 한 프레임을 받아와서 frame 변수에 저장
		cap >> frame;
		// 만약 프레임 영상이 비어 있다면 while 루프를 빠져나감
		if (frame.empty())
			break;

		// 현재 프레임을 반전하여 inversed 변수에 저장
		inversed = ~frame;

		// frame과 inversed에 저장된 정지 영상을 화면에 출력
		cv::imshow("frame", frame);
		cv::imshow("inversed", inversed);

		// 사용자로부터 10ms 시간 동안 키보드 입력을 대기
		// 만약 키보드 입력이 있고, 해당 키 값이 27(Esc)이면 while 루프를 빠져나감
		if (waitKey(10) == 27) // ESC key
			break;
	}

	// 모든 창을 닫음
	destroyAllWindows();
}
/*
camera_in() 함수 종료 시 cap 변수가 소멸되면서 자동으로 카메라 장치를 닫기 때문에 
명시적인 cap.release(); 함수 호출 생략 가능
*/

/////////////////////////////////////////////////////// (4-3)

void video_in() {

	// stopwatch.avi 파일을 불러와서 cap 객체를 생성
	cv::VideoCapture cap("stopwatch.avi");

	// 비디오 로드 실패 시 수행할 예외 처리 코드
	if (!cap.isOpened()) {
		cerr << "Video open failed!" << endl;
		return;
	}

	// 비디오 프레임의 가로 크기와 세로 크기, 전체 프레임 수 출력
	cout << "Frame width: " << cvRound(cap.get(cv::CAP_PROP_FRAME_WIDTH));
	cout << "Frame height: " << cvRound(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
	cout << "Frame count:" << cvRound(cap.get(cv::CAP_PROP_FRAME_COUNT));

	// 비디오 파일의 초당 프레임 수(FPS) 값을 받아 와서 출력
	double fps = cap.get(cv::CAP_PROP_FPS);
	cout << "FPS: " << fps << endl;

	// FPS 값으로부터 각 프레임 사이의 시간 간격 delay(밀리초 단위)를 계산
	int delay = cvRound(1000 / fps);

	cv::Mat frame, inversed;
	while (true) {
		// 카메라 장치로부터 한 프레임을 받아 와서 frame 변수에 저장
		cap >> frame;
		// 만약 해당 프레임 영상이 비어 있으면 while 루프를 빠져나감
		if (frame.empty()) {
			break;
		}

		// 현재 프레임을 반전하여 inversed 변수에 저장
		inversed = ~frame;

		// frame과 inversed에 저장된 정지 영상을 화면에 출력
		imshow("frame", frame);
		imshow("inversed", inversed);

		// delay 시간만큼 키 입력을 기다리고, 만약 Esc키가 눌리면 while 무한 반복문 종료
		if (waitKey(delay) == 27) // ESC key
			break;
	}

	destroyAllWindows();
}

/////////////////////////////////////////////////////// (4-4)

// 아래 코드는 예시용 스텁 코드로, 실제로 사용하지 않음

// 간략화한 VideoWriter 클래스 정의
class VideoWriter {
public:
	// VideoWriter 클래스의 생성자와 소멸자
	VideoWriter();
	VideoWriter(const String& filename, int fourcc, double fps, Size frameSize, bool isColor = true);

	virtual ~VideoWriter();

	// 동영상 파일을 열거나 닫는 작업르 수행하는 멤버 함수
	virtual bool open(const String& filename, int fourcc, double fps, Size frameSize, bool isColor = true);
	virtual bool isOpened() const;
	virtual void release();

	// 동영상 파일에 프레임을 추가하는 기능의 멤버 함수
	virtual VideoWriter& operator << (const Mat& image);

	// 현재 열린 동영상 파일로부터 정보를 가져오거나 설정하는 기능을 담당하는 함수
	virtual void write(const Mat& image);
	virtual bool set(int propId, double value);
	
	// VideoWriter::fourcc() 멤버 함수는 fourcc 코드를 생성하는 정적 멤버 함수
	static int fourcc(char c1, char c2, char c3, char c4);

	// ...
};

/////////////////////////////////////////////////////// (4-5)

void camera_in_video_out() {

	// 시스템 기본 카메라 사용
	cv::VideoCapture cap(0);

	// 카메라 로드 실패 시 수행할 예외처리 코드
	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return;
	}

	// 카메라 프레임의 가로, 세로 크기, 카메라의 FPS 값을 받아옴
	int w = cvRound(cap.get(cv::CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
	double fps = cap.get(cv::CAP_PROP_FPS);

	// DivX MPEG-4 코덱에 해당하는 fourcc 코드를 생성
	int fourcc = cv::VideoWriter::fourcc('D', 'I', 'V', 'X');
	// FPS 값으로부터 매 프레임 사이의 시간 간격을 밀리초 단위로 계산
	int delay = cvRound(1000 / fps);

	// 저장할 동영상 파일을 생성. 동영상 파일의 이름은 output.avi
	cv::VideoWriter outputVideo("output.avi", fourcc, fps, cv::Size(w, h));

	// 동영상 파일 생성에 문제 발생 시 수행할 예외처리 코드
	if (!outputVideo.isOpened()) {
		cout << "File open failed!" << endl;
		return;
	}

	cv::Mat frame, inversed;

	while (true) {
		// 카메라로부터 한 프레임을 받아와 frame에 저장
		cap >> frame;
		// 프레임을 받아오지 못해 empty 상태라면 반복문 종료
		if (frame.empty())
			break;

		// 카메라 프레임을 반전하여 inversed에 저장
		inversed = ~frame;
		// 반전된 카메라 프레임 영상 inversed를 출력 동영상에 추가
		outputVideo << inversed;

		// 원본 프레임과 반전된 프레임을 각각 창에 출력
		cv::imshow("frame", frame);
		cv::imshow("inversed", inversed);

		// Esc가 눌려지면 반복문 종료
		if (waitKey(delay) == 27)
			break;
	}

	destroyAllWindows();
}

int main() {

	/////////////////////////////////////////////////////// (4-2)

	/*
	컴퓨터의 기본 카메라 장치를 사용하여 이미지를 출력하는 함수
	*/

	camera_in();

	/*
	정상적으로 실행되면 카메라로부터 매 프레임을 받아와서 원본 프레임과 반전된 프레임을 각각 화면에 나타냄

	콘솔 창에는 해당 프레임의 가로 크기와 세로 크기를 픽셀 단위로 출력

	키보드의 Esc 키를 누르면 카메라 동작을 종료하고 모든 창을 닫음

	만약 컴퓨터에 카메라가 제대로 연결되어 있지 않거나 다른 프로그램이 카메라를 사용하고 있는 상태라면 
	"Camera open failed!" 문자열을 출력하고 함수가 종료됨
	*/

	/////////////////////////////////////////////////////// (4-3)

	/*
	비디오 파일을 불러와 원본 동영상과 색반전 동영상을 재생하는 함수
	*/

	video_in();

	/*
	정상적으로 실행되면 stopwatch.avi 동영상 파일로 부터 매 프레임을 받아와서 원본 프레임과 반전된 프레임을 각각 화면에 나타냄

	콘솔 창에는 프레임의 가로 크기와 세로 크기, 전체 프레임 수, FPS 값이 출력

	전체 프레임이 모두 출력되면 video_in() 함수는 자동으로 종료
	*/

	/////////////////////////////////////////////////////// (4-5)

	/*
	컴퓨터에 연결된 카메라로부터 프레임을 입력받고, 해당 프레임을 반전한 영상을 이용하여 동영상 파일을 생성하는 함수
	*/

	camera_in_video_out();

	/*
	정상적으로 실행하면 화면에 frame과 inversed 이름을 가진 창이 나타나고, 각각 카메라 입력 프레임과 반전된 프레임 영상을 출력
	사용자가 키보드의 Esc 키를 누르면 창이 사라지면서 함수가 종료됨

	함수가 종료된 후 Windows 파일 탐색기를 이용하여 프로그램 실행 폴더로 이동하면 output.avi 파일이 생성된 것을 확인할 수 있음
	해당 파일은 DivX 코덱을 사용하여 저장된 동영상 파일이며, 일반적인 동영상 재생 프로그램에서 재생할 수 있음
	*/

	return 0;
}