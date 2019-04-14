#pragma once

#include "Node.h"
#include "MainForm.h"

namespace RescueMe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// Summary for AuthForm
	/// </summary>
	public ref class AuthForm : public System::Windows::Forms::Form
	{
	private:
		Node^ node;
	public:
		AuthForm(void)
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
		~AuthForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  headPanel;
	private: System::Windows::Forms::PictureBox^  logoPictureBox;
	private: System::Windows::Forms::TextBox^  nodeIDTextBox;
	private: System::Windows::Forms::TextBox^  nodeKeyTextBox;
	private: System::Windows::Forms::Button^  authButton;
	private: System::Windows::Forms::Button^  closeButton;
	private: System::Windows::Forms::PictureBox^  iconIDPictureBox;
	private: System::Windows::Forms::PictureBox^  iconKeyPictureBox;
	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AuthForm::typeid));
			this->headPanel = (gcnew System::Windows::Forms::Panel());
			this->logoPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->nodeIDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->nodeKeyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->authButton = (gcnew System::Windows::Forms::Button());
			this->closeButton = (gcnew System::Windows::Forms::Button());
			this->iconIDPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->iconKeyPictureBox = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logoPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->iconIDPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->iconKeyPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// headPanel
			// 
			this->headPanel->BackColor = System::Drawing::Color::DimGray;
			this->headPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->headPanel->Location = System::Drawing::Point(0, 0);
			this->headPanel->Name = L"headPanel";
			this->headPanel->Size = System::Drawing::Size(360, 11);
			this->headPanel->TabIndex = 0;
			// 
			// logoPictureBox
			// 
			this->logoPictureBox->BackColor = System::Drawing::Color::Transparent;
			this->logoPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logoPictureBox.Image")));
			this->logoPictureBox->Location = System::Drawing::Point(100, 64);
			this->logoPictureBox->Name = L"logoPictureBox";
			this->logoPictureBox->Size = System::Drawing::Size(162, 50);
			this->logoPictureBox->TabIndex = 1;
			this->logoPictureBox->TabStop = false;
			// 
			// nodeIDTextBox
			// 
			this->nodeIDTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->nodeIDTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nodeIDTextBox->Location = System::Drawing::Point(100, 148);
			this->nodeIDTextBox->Multiline = true;
			this->nodeIDTextBox->Name = L"nodeIDTextBox";
			this->nodeIDTextBox->Size = System::Drawing::Size(180, 24);
			this->nodeIDTextBox->TabIndex = 2;
			this->nodeIDTextBox->Text = L"Node ID";
			// 
			// nodeKeyTextBox
			// 
			this->nodeKeyTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->nodeKeyTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nodeKeyTextBox->Location = System::Drawing::Point(100, 186);
			this->nodeKeyTextBox->Multiline = true;
			this->nodeKeyTextBox->Name = L"nodeKeyTextBox";
			this->nodeKeyTextBox->Size = System::Drawing::Size(180, 24);
			this->nodeKeyTextBox->TabIndex = 3;
			this->nodeKeyTextBox->Text = L"Node Key";
			// 
			// authButton
			// 
			this->authButton->BackColor = System::Drawing::Color::MediumSeaGreen;
			this->authButton->FlatAppearance->BorderSize = 0;
			this->authButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->authButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->authButton->Location = System::Drawing::Point(124, 235);
			this->authButton->Name = L"authButton";
			this->authButton->Size = System::Drawing::Size(125, 26);
			this->authButton->TabIndex = 4;
			this->authButton->Text = L"Auth";
			this->authButton->UseVisualStyleBackColor = false;
			this->authButton->Click += gcnew System::EventHandler(this, &AuthForm::authButton_Click);
			// 
			// closeButton
			// 
			this->closeButton->BackColor = System::Drawing::Color::DimGray;
			this->closeButton->FlatAppearance->BorderSize = 0;
			this->closeButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Red;
			this->closeButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->closeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->closeButton->Location = System::Drawing::Point(345, 0);
			this->closeButton->Name = L"closeButton";
			this->closeButton->Size = System::Drawing::Size(15, 21);
			this->closeButton->TabIndex = 0;
			this->closeButton->Text = L"X";
			this->closeButton->UseVisualStyleBackColor = false;
			this->closeButton->Click += gcnew System::EventHandler(this, &AuthForm::closeButton_Click);
			// 
			// iconIDPictureBox
			// 
			this->iconIDPictureBox->BackColor = System::Drawing::Color::Transparent;
			this->iconIDPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"iconIDPictureBox.Image")));
			this->iconIDPictureBox->Location = System::Drawing::Point(70, 148);
			this->iconIDPictureBox->Name = L"iconIDPictureBox";
			this->iconIDPictureBox->Size = System::Drawing::Size(24, 24);
			this->iconIDPictureBox->TabIndex = 5;
			this->iconIDPictureBox->TabStop = false;
			// 
			// iconKeyPictureBox
			// 
			this->iconKeyPictureBox->BackColor = System::Drawing::Color::Transparent;
			this->iconKeyPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"iconKeyPictureBox.Image")));
			this->iconKeyPictureBox->Location = System::Drawing::Point(70, 186);
			this->iconKeyPictureBox->Name = L"iconKeyPictureBox";
			this->iconKeyPictureBox->Size = System::Drawing::Size(24, 24);
			this->iconKeyPictureBox->TabIndex = 6;
			this->iconKeyPictureBox->TabStop = false;
			// 
			// AuthForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(360, 317);
			this->Controls->Add(this->iconKeyPictureBox);
			this->Controls->Add(this->iconIDPictureBox);
			this->Controls->Add(this->closeButton);
			this->Controls->Add(this->authButton);
			this->Controls->Add(this->nodeKeyTextBox);
			this->Controls->Add(this->nodeIDTextBox);
			this->Controls->Add(this->logoPictureBox);
			this->Controls->Add(this->headPanel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AuthForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AuthForm";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &AuthForm::AuthForm_Paint);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logoPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->iconIDPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->iconKeyPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AuthForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		LinearGradientBrush^ lgh = gcnew LinearGradientBrush(this->ClientRectangle,
			Color::PaleVioletRed, Color::Red, LinearGradientMode::Vertical);
		Graphics^ g = e->Graphics;
		g->FillRectangle(lgh, this->ClientRectangle);
	}
	private: System::Void authButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->node->id = nodeIDTextBox->Text;
		this->node->key = nodeKeyTextBox->Text;

		if (this->node->verify())
		{
			RescueMe::MainForm^ form = gcnew RescueMe::MainForm();
			form->node = this->node;
			form->Show();
			this->Hide();
		}
		else
		{
			MessageBox::Show("Node id and key are invalid.", "Node Error", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}

	}
	private: System::Void closeButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
};
}
