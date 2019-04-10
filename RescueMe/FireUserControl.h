#pragma once

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include "Utils.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

// Global objects
__declspec(selectany)  cv::dnn::Net mobileNetSSD = cv::dnn::readNetFromCaffe(
	"./models/MobileNetSSD/MobileNetSSD_deploy.prototxt", 
	"./models/MobileNetSSD/MobileNetSSD_deploy.caffemodel");

namespace RescueMe {

	/// <summary>
	/// Summary for FireUserControl
	/// </summary>
	public ref class FireUserControl : public System::Windows::Forms::UserControl
	{
	private:
		cv::VideoCapture* capture;
		float threshold;
		int classID;

	public:

		FireUserControl(void)
		{
			InitializeComponent();
			threshold = 0.2;
			classID = 0;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FireUserControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  sourceGroupBox;
	private: System::Windows::Forms::ComboBox^  sourceComboBox;
	private: System::Windows::Forms::Button^  startButton;
	private: System::Windows::Forms::GroupBox^  settingGroupBox;
	private: System::Windows::Forms::Label^  thresholdLabel;
	private: System::Windows::Forms::NumericUpDown^  thresholdNumericUpDown;



	private: System::Windows::Forms::GroupBox^  videoGroupBox;
	private: System::Windows::Forms::PictureBox^  framePictureBox;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::ComponentModel::IContainer^  components;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
/// <summary>
/// Required method for Designer support - do not modify
/// the contents of this method with the code editor.
/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->sourceGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->sourceComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->settingGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->thresholdLabel = (gcnew System::Windows::Forms::Label());
			this->thresholdNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->videoGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->framePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->sourceGroupBox->SuspendLayout();
			this->settingGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->thresholdNumericUpDown))->BeginInit();
			this->videoGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->framePictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// sourceGroupBox
			// 
			this->sourceGroupBox->Controls->Add(this->startButton);
			this->sourceGroupBox->Controls->Add(this->sourceComboBox);
			this->sourceGroupBox->Location = System::Drawing::Point(147, 3);
			this->sourceGroupBox->Name = L"sourceGroupBox";
			this->sourceGroupBox->Size = System::Drawing::Size(510, 45);
			this->sourceGroupBox->TabIndex = 0;
			this->sourceGroupBox->TabStop = false;
			this->sourceGroupBox->Text = L"Source";
			// 
			// startButton
			// 
			this->startButton->BackColor = System::Drawing::Color::MediumSeaGreen;
			this->startButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->startButton->ForeColor = System::Drawing::Color::White;
			this->startButton->Location = System::Drawing::Point(412, 15);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(89, 23);
			this->startButton->TabIndex = 1;
			this->startButton->Text = L"Start";
			this->startButton->UseVisualStyleBackColor = false;
			this->startButton->Click += gcnew System::EventHandler(this, &FireUserControl::startButton_Click);
			// 
			// sourceComboBox
			// 
			this->sourceComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->sourceComboBox->FormattingEnabled = true;
			this->sourceComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Video File", L"Webcam" });
			this->sourceComboBox->Location = System::Drawing::Point(11, 17);
			this->sourceComboBox->Name = L"sourceComboBox";
			this->sourceComboBox->Size = System::Drawing::Size(368, 21);
			this->sourceComboBox->TabIndex = 0;
			// 
			// settingGroupBox
			// 
			this->settingGroupBox->Controls->Add(this->thresholdLabel);
			this->settingGroupBox->Controls->Add(this->thresholdNumericUpDown);
			this->settingGroupBox->Location = System::Drawing::Point(3, 3);
			this->settingGroupBox->Name = L"settingGroupBox";
			this->settingGroupBox->Size = System::Drawing::Size(138, 45);
			this->settingGroupBox->TabIndex = 1;
			this->settingGroupBox->TabStop = false;
			this->settingGroupBox->Text = L"Settings";
			// 
			// thresholdLabel
			// 
			this->thresholdLabel->AutoSize = true;
			this->thresholdLabel->Location = System::Drawing::Point(6, 20);
			this->thresholdLabel->Name = L"thresholdLabel";
			this->thresholdLabel->Size = System::Drawing::Size(54, 13);
			this->thresholdLabel->TabIndex = 3;
			this->thresholdLabel->Text = L"Threshold";
			// 
			// thresholdNumericUpDown
			// 
			this->thresholdNumericUpDown->DecimalPlaces = 1;
			this->thresholdNumericUpDown->Location = System::Drawing::Point(72, 17);
			this->thresholdNumericUpDown->Name = L"thresholdNumericUpDown";
			this->thresholdNumericUpDown->Size = System::Drawing::Size(60, 20);
			this->thresholdNumericUpDown->TabIndex = 2;
			this->thresholdNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 65536 });
			this->thresholdNumericUpDown->ValueChanged += gcnew System::EventHandler(this, &FireUserControl::thresholdNumericUpDown_ValueChanged);
			// 
			// videoGroupBox
			// 
			this->videoGroupBox->Controls->Add(this->framePictureBox);
			this->videoGroupBox->Location = System::Drawing::Point(3, 54);
			this->videoGroupBox->Name = L"videoGroupBox";
			this->videoGroupBox->Size = System::Drawing::Size(654, 365);
			this->videoGroupBox->TabIndex = 2;
			this->videoGroupBox->TabStop = false;
			this->videoGroupBox->Text = L"Video";
			// 
			// framePictureBox
			// 
			this->framePictureBox->BackColor = System::Drawing::Color::LightGray;
			this->framePictureBox->Location = System::Drawing::Point(6, 18);
			this->framePictureBox->Name = L"framePictureBox";
			this->framePictureBox->Size = System::Drawing::Size(640, 340);
			this->framePictureBox->TabIndex = 0;
			this->framePictureBox->TabStop = false;
			// 
			// timer
			// 
			this->timer->Interval = 20;
			this->timer->Tick += gcnew System::EventHandler(this, &FireUserControl::timer_Tick);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"Open Video";
			// 
			// FireUserControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Controls->Add(this->videoGroupBox);
			this->Controls->Add(this->settingGroupBox);
			this->Controls->Add(this->sourceGroupBox);
			this->Name = L"FireUserControl";
			this->Size = System::Drawing::Size(660, 423);
			this->sourceGroupBox->ResumeLayout(false);
			this->settingGroupBox->ResumeLayout(false);
			this->settingGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->thresholdNumericUpDown))->EndInit();
			this->videoGroupBox->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->framePictureBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void startButton_Click(System::Object^  sender, System::EventArgs^  e) {

		if (this->startButton->Text == "Start")
		{
			if (this->sourceComboBox->Text == "Video File")
			{
				this->openFileDialog->Filter = "All Videos Files |*.dat; *.wmv; *.3g2; *.3gp; *.3gp2; *.3gpp; *.amv; *.asf;  *.avi; *.bin; *.cue; *.divx; *.dv; *.flv; *.gxf; *.iso; *.m1v; *.m2v; *.m2t; *.m2ts; *.m4v; " +
					" *.mkv; *.mov; *.mp2; *.mp2v; *.mp4; *.mp4v; *.mpa; *.mpe; *.mpeg; *.mpeg1; *.mpeg2; *.mpeg4; *.mpg; *.mpv2; *.mts; *.nsv; *.nuv; *.ogg; *.ogm; *.ogv; *.ogx; *.ps; *.rec; *.rm; *.rmvb; *.tod; *.ts; *.tts; *.vob; *.vro; *.webm";
				this->openFileDialog->FilterIndex = 2;
				this->openFileDialog->RestoreDirectory = true;
				this->openFileDialog->FileName = "";

				if (this->openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					char *fileName = (char*)Marshal::StringToHGlobalAnsi(openFileDialog->FileName).ToPointer();

					capture = new cv::VideoCapture(fileName);

					if (!capture->isOpened())
					{
						MessageBox::Show("Video Capture failed", "Error", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
					}// check if we succeeded
					else
					{
						start_video_processing();
					}
				}
			}
			else if (this->sourceComboBox->Text == "Webcam")
			{
				capture = new cv::VideoCapture(0);

				if (!capture->isOpened())
				{
					MessageBox::Show("Video Capture failed", "Error", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				}// check if we succeeded
				else
				{
					start_video_processing();
				}

			}

		}
		else if (this->startButton->Text == "Stop")
		{
			stop_video_processing();
		}
	}
	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {

		cv::Mat frame;
		capture->read(frame);

		if (!frame.empty())
		{
			cv::Mat resizedFrame = frame.clone();
			cv::resize(frame, resizedFrame, cv::Size(300, 300));

			cv::Mat inputBlob = cv::dnn::blobFromImage(resizedFrame, 0.007843, cv::Size(300, 300), cv::Scalar(127.5, 127.5, 127.5), false, false);

			mobileNetSSD.setInput(inputBlob);
			cv::Mat detection = mobileNetSSD.forward();

			cv::Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

			for (int i = 0; i < detectionMat.rows; i++)
			{
				float confidence = detectionMat.at<float>(i, 2);
				int classId = static_cast<int>(detectionMat.at<float>(i, 1));

				if (confidence > this->threshold && classId == this->classID)
				{
					int cols = frame.cols;
					int rows = frame.rows;

					int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * cols);
					int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * rows);
					int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * cols);
					int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * rows);

					float heightFactor = frame.rows / 300.0;
					float widthFactor = frame.cols / 300.0;

					cv::rectangle(frame, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(0, 255, 0), 1);
				}
			}

			Utils::Mat2PictureBox(frame, this->framePictureBox);

		}
		else
		{
			stop_video_processing();
		}

	}

	private: void start_video_processing() {
		this->timer->Start();
		this->startButton->Text = "Stop";
		this->startButton->BackColor = Color::PaleVioletRed;
	}

	private: void stop_video_processing() {
		capture->release();
		this->timer->Stop();
		this->startButton->Text = "Start";
		this->startButton->BackColor = Color::MediumSeaGreen;
	}
	private: System::Void thresholdNumericUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		this->threshold = Convert::ToDouble(this->thresholdNumericUpDown->Value);
	}
	};
}
