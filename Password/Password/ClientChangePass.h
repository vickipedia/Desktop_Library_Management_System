#pragma once

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
	/// Summary for ClientChangePass
	/// </summary>
	public ref class ClientChangePass : public System::Windows::Forms::Form
	{
	public:
		ClientChangePass(void)
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
		~ClientChangePass()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter Username:";
			this->label1->Click += gcnew System::EventHandler(this, &ClientChangePass::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(115, 17);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(141, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(69, 77);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(139, 42);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Register";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ClientChangePass::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(115, 48);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(141, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->UseSystemPasswordChar = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Enter Password: ";
			// 
			// ClientChangePass
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(285, 146);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"ClientChangePass";
			this->Text = L"Client New User";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 SqlConnection^ temp=gcnew SqlConnection("Data Source=VICKY-PC\\SQLSERVER;Initial Catalog=logindb;Integrated Security=True");
				 SqlCommand^ cmd=gcnew SqlCommand();
				 SqlDataReader^ dr;
				 cmd->Connection=temp;
				 temp->Open();
				 cmd->CommandText="insert into logintb2 (username,password) values('"+textBox1->Text+"' , '"+textBox2->Text+"')";
				 cmd->ExecuteNonQuery();
				 String^ a;
				 a="User "+""+textBox1->Text+""+" created new account.";
				 cmd->CommandText="insert into logbook values('"+a+"')";
				 cmd->ExecuteNonQuery();
				 temp->Close();
				 this->Close();
			 }
};
}
