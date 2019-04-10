#pragma once
#include <opencv2/core.hpp>

using namespace System::Windows::Forms;

ref class Utils
{
public:
	Utils();
	static void Mat2PictureBox(cv::Mat frame, System::Windows::Forms::PictureBox^ pictureBox);
};

