#pragma once
#include "ClientMenu.h";
#include "ClientChangePass.h";
namespace Password {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::Sql;
	using namespace System::Data::SqlClient;
	using namespace System::Data::SqlTypes;
	/// <summary>
	/// Summary for ClientInterface
	/// </summary>
	public ref class ClientInterface : public System::Windows::Forms::Form
	{
	public:
		ClientInterface(void)
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
		~ClientInterface()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label3;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Username: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Password: ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(91, 32);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(156, 20);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(91, 67);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(156, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->UseSystemPasswordChar = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(60, 117);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(156, 31);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ClientInterface::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(60, 167);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(156, 32);
			this->button2->TabIndex = 5;
			this->button2->Text = L"New Account Creation";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ClientInterface::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(98, 207);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 6;
			// 
			// ClientInterface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 229);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"ClientInterface";
			this->Text = L"Client Interface";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 SqlConnection^ temp=gcnew SqlConnection("Data Source=VICKY-PC\\SQLSERVER;Initial Catalog=logindb;Integrated Security=True");
				 SqlCommand^ cmd=gcnew SqlCommand();
				 SqlDataReader^ dr;
				 cmd->Connection=temp;
				 temp->Open();
				 cmd->CommandText="select * from logintb2 where password='"+textBox2->Text+"' AND username='"+textBox1->Text+"'";
				 dr=cmd->ExecuteReader();
				 if(dr->Read())
				 {
				    this->Hide();
					ClientMenu^ f2 = gcnew ClientMenu();
					f2->Show();

				 }
				 else
				 {
					label3->Text="Access Denied";
					label3->ForeColor=System::Drawing::Color::Red;
				 }
				 temp->Close();
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			        this->Hide();
					ClientChangePass^ f2 = gcnew ClientChangePass();
					f2->Show();

		 }
};
}
