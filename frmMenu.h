#pragma once
#include "frmAlumnos.h"
#include "frmCurso.h"

namespace PROYECTOPRACTICO2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class frmMenu : public System::Windows::Forms::Form
	{
	public:
		frmMenu(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnAlumnos;
	private: System::Windows::Forms::Button^ BTN_Curso;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnAlumnos = (gcnew System::Windows::Forms::Button());
			this->BTN_Curso = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnAlumnos
			// 
			this->btnAlumnos->Location = System::Drawing::Point(13, 13);
			this->btnAlumnos->Margin = System::Windows::Forms::Padding(4);
			this->btnAlumnos->Name = L"btnAlumnos";
			this->btnAlumnos->Size = System::Drawing::Size(481, 68);
			this->btnAlumnos->TabIndex = 0;
			this->btnAlumnos->Text = L"Alumnos";
			this->btnAlumnos->UseVisualStyleBackColor = true;
			this->btnAlumnos->Click += gcnew System::EventHandler(this, &frmMenu::btnAlumnos_Click);
			// 
			// BTN_Curso
			// 
			this->BTN_Curso->Location = System::Drawing::Point(13, 89);
			this->BTN_Curso->Margin = System::Windows::Forms::Padding(4);
			this->BTN_Curso->Name = L"BTN_Curso";
			this->BTN_Curso->Size = System::Drawing::Size(481, 68);
			this->BTN_Curso->TabIndex = 1;
			this->BTN_Curso->Text = L"Curso";
			this->BTN_Curso->UseVisualStyleBackColor = true;
			this->BTN_Curso->Click += gcnew System::EventHandler(this, &frmMenu::BTN_Curso_Click);
			// 
			// frmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(507, 363);
			this->Controls->Add(this->BTN_Curso);
			this->Controls->Add(this->btnAlumnos);
			this->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"frmMenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &frmMenu::frmMenu_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnAlumnos_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmAlumnos^ frm = gcnew frmAlumnos();
		frm->ShowDialog();
	}
	private: System::Void frmMenu_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void BTN_Curso_Click(System::Object^ sender, System::EventArgs^ e) {

		frmCurso^ frm = gcnew frmCurso();
		frm->ShowDialog();
	}		   
	};
}
