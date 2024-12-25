#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 아래 코드는 예시용 스텁 코드로, 실제로 사용하지 않음

/////////////////////////////////////////////////////// (4-1)

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

	return 0;
}