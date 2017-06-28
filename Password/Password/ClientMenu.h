#pragma once
#include "ClientBorrowBook.h"
#include "ClientReturnBook.h"
#include "BorrowedBooksLog.h"
namespace Password {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ClientMenu
	/// </summary>
	public ref class ClientMenu : public System::Windows::Forms::Form
	{
	public:
		ClientMenu(void)
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
		~ClientMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(60, 26);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(148, 38);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Borrow Book";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ClientMenu::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(60, 81);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(148, 38);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Return Book";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ClientMenu::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(60, 139);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(148, 38);
			this->button3->TabIndex = 2;
			this->button3->Text = L"See Borrowed Books";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ClientMenu::button3_Click);
			// 
			// ClientMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 201);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"ClientMenu";
			this->Text = L"Client Menu";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 ClientBorrowBook^ obj=gcnew ClientBorrowBook();
				 obj->Show();
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 ClientReturnBook^ obj=gcnew ClientReturnBook();
				 obj->Show();
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 BorrowedBooksLog^ obj=gcnew BorrowedBooksLog();
				 obj->Show();
			 }
	};
}
