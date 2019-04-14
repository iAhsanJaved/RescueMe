#pragma once
#include <opencv2/core.hpp>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::Collections;

ref class Utils
{
public:
	Utils();
	static void Mat2PictureBox(cv::Mat frame, System::Windows::Forms::PictureBox^ pictureBox);
	static String^ PictureBoxToBase64(System::Windows::Forms::PictureBox^ pictureBox);
};

