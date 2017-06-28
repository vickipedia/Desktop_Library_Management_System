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

	/// <summary>
	/// Summary for DeleteBook
	/// </summary>
	public ref class DeleteBook : public System::Windows::Forms::Form
	{
	public:
		DeleteBook(void)
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
		~DeleteBook()
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
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter Book ID:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(111, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(138, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(81, 64);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(113, 25);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Delete";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &DeleteBook::button1_Click);
			// 
			// DeleteBook
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 107);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"DeleteBook";
			this->Text = L"Delete Book";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 SqlConnection^ temp=gcnew SqlConnection("Data Source=VICKY-PC\\SQLSERVER;Initial Catalog=logindb;Integrated Security=True");
				 SqlCommand^ cmd=gcnew SqlCommand();
				 cmd->Connection=temp;
				 temp->Open();
				 cmd->CommandText="delete from book where bookid='"+textBox1->Text+"'";
				 cmd->ExecuteNonQuery();
				 String^ a;
				 a="Book "+""+textBox1->Text+""+" deleted.";
				 cmd->CommandText="insert into logbook values('"+a+"')";
				 cmd->ExecuteNonQuery();
				 this->Hide();
			 }
	};
}
