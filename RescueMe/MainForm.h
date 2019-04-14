#pragma once

#include "FallUserControl.h"
#include "FireUserControl.h"
#include "AccidentUserControl.h"
#include "Node.h"

namespace RescueMe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		Node^ node;

		MainForm(void)
		{
			InitializeComponent();
			node = gcnew Node();

			//
			//TODO: Add the constructor code here
			//
		}



	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  sidebarPanel;
	private: System::Windows::Forms::Panel^  headerPanel;
	private: System::Windows::Forms::Button^  fallNavBtn;
	private: System::Windows::Forms::Button^  accidentNavButton;
	private: System::Windows::Forms::Button^  fireNavButton;
	private: System::Windows::Forms::Label^  headingLabel;
	private: System::Windows::Forms::Panel^  mainPanel;
	private: System::Windows::Forms::Button^  closeButton;
	private: System::Windows::Forms::PictureBox^  logoPictureBox;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->sidebarPanel = (gcnew System::Windows::Forms::Panel());
			this->logoPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->accidentNavButton = (gcnew System::Windows::Forms::Button());
			this->fireNavButton = (gcnew System::Windows::Forms::Button());
			this->fallNavBtn = (gcnew System::Windows::Forms::Button());
			this->headerPanel = (gcnew System::Windows::Forms::Panel());
			this->headingLabel = (gcnew System::Windows::Forms::Label());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->closeButton = (gcnew System::Windows::Forms::Button());
			this->sidebarPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logoPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// sidebarPanel
			// 
			this->sidebarPanel->BackColor = System::Drawing::Color::Gray;
			this->sidebarPanel->Controls->Add(this->logoPictureBox);
			this->sidebarPanel->Controls->Add(this->accidentNavButton);
			this->sidebarPanel->Controls->Add(this->fireNavButton);
			this->sidebarPanel->Controls->Add(this->fallNavBtn);
			this->sidebarPanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->sidebarPanel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sidebarPanel->Location = System::Drawing::Point(0, 0);
			this->sidebarPanel->Name = L"sidebarPanel";
			this->sidebarPanel->Size = System::Drawing::Size(187, 512);
			this->sidebarPanel->TabIndex = 0;
			this->sidebarPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::sidebarPanel_Paint);
			// 
			// logoPictureBox
			// 
			this->logoPictureBox->BackColor = System::Drawing::Color::Transparent;
			this->logoPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logoPictureBox.Image")));
			this->logoPictureBox->Location = System::Drawing::Point(12, 23);
			this->logoPictureBox->Name = L"logoPictureBox";
			this->logoPictureBox->Size = System::Drawing::Size(162, 50);
			this->logoPictureBox->TabIndex = 3;
			this->logoPictureBox->TabStop = false;
			// 
			// accidentNavButton
			// 
			this->accidentNavButton->BackColor = System::Drawing::Color::Transparent;
			this->accidentNavButton->FlatAppearance->BorderSize = 0;
			this->accidentNavButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->accidentNavButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DarkGray;
			this->accidentNavButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->accidentNavButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->accidentNavButton->ForeColor = System::Drawing::Color::White;
			this->accidentNavButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"accidentNavButton.Image")));
			this->accidentNavButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->accidentNavButton->Location = System::Drawing::Point(0, 239);
			this->accidentNavButton->Name = L"accidentNavButton";
			this->accidentNavButton->Padding = System::Windows::Forms::Padding(6, 0, 0, 0);
			this->accidentNavButton->Size = System::Drawing::Size(187, 45);
			this->accidentNavButton->TabIndex = 2;
			this->accidentNavButton->Text = L"  Accident Detection";
			this->accidentNavButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->accidentNavButton->UseVisualStyleBackColor = false;
			this->accidentNavButton->Click += gcnew System::EventHandler(this, &MainForm::accidentNavButton_Click);
			// 
			// fireNavButton
			// 
			this->fireNavButton->BackColor = System::Drawing::Color::Transparent;
			this->fireNavButton->FlatAppearance->BorderSize = 0;
			this->fireNavButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->fireNavButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DarkGray;
			this->fireNavButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->fireNavButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fireNavButton->ForeColor = System::Drawing::Color::White;
			this->fireNavButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fireNavButton.Image")));
			this->fireNavButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->fireNavButton->Location = System::Drawing::Point(0, 188);
			this->fireNavButton->Name = L"fireNavButton";
			this->fireNavButton->Padding = System::Windows::Forms::Padding(6, 0, 0, 0);
			this->fireNavButton->Size = System::Drawing::Size(187, 45);
			this->fireNavButton->TabIndex = 1;
			this->fireNavButton->Text = L"  Fire Detection";
			this->fireNavButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->fireNavButton->UseVisualStyleBackColor = false;
			this->fireNavButton->Click += gcnew System::EventHandler(this, &MainForm::fireNavButton_Click);
			// 
			// fallNavBtn
			// 
			this->fallNavBtn->BackColor = System::Drawing::Color::Transparent;
			this->fallNavBtn->FlatAppearance->BorderSize = 0;
			this->fallNavBtn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->fallNavBtn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DarkGray;
			this->fallNavBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->fallNavBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fallNavBtn->ForeColor = System::Drawing::Color::White;
			this->fallNavBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fallNavBtn.Image")));
			this->fallNavBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->fallNavBtn->Location = System::Drawing::Point(0, 137);
			this->fallNavBtn->Name = L"fallNavBtn";
			this->fallNavBtn->Padding = System::Windows::Forms::Padding(6, 0, 0, 0);
			this->fallNavBtn->Size = System::Drawing::Size(187, 45);
			this->fallNavBtn->TabIndex = 0;
			this->fallNavBtn->Text = L"  Fall Detection";
			this->fallNavBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->fallNavBtn->UseVisualStyleBackColor = false;
			this->fallNavBtn->Click += gcnew System::EventHandler(this, &MainForm::fallNavBtn_Click);
			// 
			// headerPanel
			// 
			this->headerPanel->BackColor = System::Drawing::Color::DimGray;
			this->headerPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->headerPanel->ForeColor = System::Drawing::Color::White;
			this->headerPanel->Location = System::Drawing::Point(187, 0);
			this->headerPanel->Name = L"headerPanel";
			this->headerPanel->Size = System::Drawing::Size(706, 11);
			this->headerPanel->TabIndex = 1;
			// 
			// headingLabel
			// 
			this->headingLabel->AutoSize = true;
			this->headingLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->headingLabel->ForeColor = System::Drawing::Color::Black;
			this->headingLabel->Location = System::Drawing::Point(206, 34);
			this->headingLabel->Name = L"headingLabel";
			this->headingLabel->Size = System::Drawing::Size(68, 21);
			this->headingLabel->TabIndex = 2;
			this->headingLabel->Text = L"Heading";
			// 
			// mainPanel
			// 
			this->mainPanel->BackColor = System::Drawing::Color::White;
			this->mainPanel->ForeColor = System::Drawing::SystemColors::ControlText;
			this->mainPanel->Location = System::Drawing::Point(210, 70);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(660, 430);
			this->mainPanel->TabIndex = 3;
			// 
			// closeButton
			// 
			this->closeButton->BackColor = System::Drawing::Color::DimGray;
			this->closeButton->FlatAppearance->BorderSize = 0;
			this->closeButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Red;
			this->closeButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->closeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->closeButton->Location = System::Drawing::Point(878, 0);
			this->closeButton->Name = L"closeButton";
			this->closeButton->Size = System::Drawing::Size(15, 21);
			this->closeButton->TabIndex = 0;
			this->closeButton->Text = L"X";
			this->closeButton->UseVisualStyleBackColor = false;
			this->closeButton->Click += gcnew System::EventHandler(this, &MainForm::closeButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(893, 512);
			this->Controls->Add(this->closeButton);
			this->Controls->Add(this->mainPanel);
			this->Controls->Add(this->headingLabel);
			this->Controls->Add(this->headerPanel);
			this->Controls->Add(this->sidebarPanel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RescueMe";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->sidebarPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logoPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void sidebarPanel_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		LinearGradientBrush^ lgh = gcnew LinearGradientBrush(this->sidebarPanel->ClientRectangle,
			Color::PaleVioletRed, Color::Red, LinearGradientMode::Vertical);
		Graphics^ g = e->Graphics;
		g->FillRectangle(lgh, this->sidebarPanel->ClientRectangle);
	}
	
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
		// Load FallUserControl
		this->mainPanel->Controls->Clear();
		FallUserControl^ uc = gcnew FallUserControl();
		uc->emergencyAlert->node = this->node;
		this->mainPanel->Controls->Add(uc);
		this->mainPanel->Show();
		// Change Nav Buttons BackColor
		this->fallNavBtn->BackColor = Color::DarkGray;
		this->fireNavButton->BackColor = Color::Transparent;
		this->accidentNavButton->BackColor = Color::Transparent;
		// Change Heading
		this->headingLabel->Text = "FALL DETECTION";
	}
	private: System::Void fallNavBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->mainPanel->Controls->Clear();
		FallUserControl^ uc = gcnew FallUserControl();
		uc->emergencyAlert->node = this->node;
		this->mainPanel->Controls->Add(uc);
		this->mainPanel->Show();
		// Change Nav Buttons BackColor
		this->fallNavBtn->BackColor = Color::DarkGray;
		this->fireNavButton->BackColor = Color::Transparent;
		this->accidentNavButton->BackColor = Color::Transparent;
		// Change Heading
		this->headingLabel->Text = "FALL DETECTION";
	}
	private: System::Void fireNavButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->mainPanel->Controls->Clear();
		FireUserControl^ uc = gcnew FireUserControl();
		this->mainPanel->Controls->Add(uc);
		this->mainPanel->Show();
		// Change Nav Button BackColor
		this->fallNavBtn->BackColor = Color::Transparent;
		this->fireNavButton->BackColor = Color::DarkGray;
		this->accidentNavButton->BackColor = Color::Transparent;
		// Change Heading
		this->headingLabel->Text = "FIRE DETECTION";
	}
	private: System::Void accidentNavButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->mainPanel->Controls->Clear();
		AccidentUserControl^ uc = gcnew AccidentUserControl();
		this->mainPanel->Controls->Add(uc);
		this->mainPanel->Show();
		// Change Nav Button BackColor
		this->fallNavBtn->BackColor = Color::Transparent;
		this->fireNavButton->BackColor = Color::Transparent;
		this->accidentNavButton->BackColor = Color::DarkGray;
		// Change Heading
		this->headingLabel->Text = "ACCIDENT DETECTION";
	}
	private: System::Void closeButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
};
}
