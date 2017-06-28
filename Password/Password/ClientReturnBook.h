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
	/// Summary for ClientReturnBook
	/// </summary>
	public ref class ClientReturnBook : public System::Windows::Forms::Form
	{
	public:
		ClientReturnBook(void)
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
		~ClientReturnBook()
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(80, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter Book ID: ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(98, 21);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(163, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(70, 89);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(144, 34);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Return Book";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ClientReturnBook::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(98, 47);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(163, 20);
			this->textBox2->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Enter Username: ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(95, 130);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 5;
			// 
			// ClientReturnBook
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 152);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"ClientReturnBook";
			this->Text = L"Client Return Book";
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
				 cmd->CommandText="select * from borrowbooks where username='"+textBox2->Text+"' AND bookid='"+textBox1->Text+"'";
				 dr=cmd->ExecuteReader();
				 if(dr->Read())
				 {
				 dr->Close();
				 cmd->CommandText="delete from BorrowBooks where bookid='"+textBox1->Text+"' and username='"+textBox2->Text+"'";
				 cmd->ExecuteNonQuery();
				 String^ a;
				 a="User "+""+textBox2->Text+""+" returned "+""+textBox1->Text+""+".";
				 cmd->CommandText="insert into logbook values('"+a+"')";
				 cmd->ExecuteNonQuery();
				 cmd->CommandText="update book set bookquan=bookquan+1 where bookid='"+textBox1->Text+"'";
				 cmd->ExecuteNonQuery();
				 this->Close();
				 }
				 else
				 {
					 label3->Text="Not available";
				 }
			 }
	};
}
