#pragma once
#include "MyForm12.h"
namespace Password {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::Sql;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		
	   
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button1;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(74, 156);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Enter your login details";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// textBox2
			// 
			this->textBox1->Location = System::Drawing::Point(95, 25);
			this->textBox1->MaxLength = 20;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(162, 20);
			this->textBox1->TabIndex = 5;
			this->textBox2->Location = System::Drawing::Point(95, 58);
			this->textBox2->MaxLength = 20;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(162, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->UseSystemPasswordChar = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(27, 61);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Password : ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(27, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Username : ";
			// 
			// textBox1
			// 
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(55, 105);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(148, 35);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(283, 185);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 SqlConnection^ temp=gcnew SqlConnection("Data Source=VICKY-PC\\SQLSERVER;Initial Catalog=logindb;Integrated Security=True");
				 SqlCommand^ cmd=gcnew SqlCommand();
				 SqlDataReader^ dr;
				 cmd->Connection=temp;
				 temp->Open();
				 cmd->CommandText="select * from logintb where password='"+textBox2->Text+"' AND username='"+textBox1->Text+"'";
				 dr=cmd->ExecuteReader();
				 if(dr->Read())
				 {
				    this->Hide();
					MyForm12^ f2 = gcnew MyForm12();
					f2->Show();

				 }
				 else
				 {
					label1->Text="Access Denied";
					label1->ForeColor=System::Drawing::Color::Red;
				 }
				 temp->Close();
		 }
};
}
