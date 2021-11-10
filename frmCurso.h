#pragma once
#include "frmAlumnos.h"
#include "Lista.h"
#include "Alumno.h"

namespace PROYECTOPRACTICO2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmCurso
	/// </summary>
	public ref class frmCurso : public System::Windows::Forms::Form
	{
		Lista<Alumno*>* alumnosCursos;
	public:
		frmCurso(void)
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
		~frmCurso()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btn_BuscarCurso;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ListBox^ lbxDocentes;
	private: System::Windows::Forms::ListBox^ lbxAlumnos;


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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_BuscarCurso = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->lbxDocentes = (gcnew System::Windows::Forms::ListBox());
			this->lbxAlumnos = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(22, 68);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(337, 32);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(16, 27);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Curso";
			// 
			// btn_BuscarCurso
			// 
			this->btn_BuscarCurso->Location = System::Drawing::Point(249, 27);
			this->btn_BuscarCurso->Margin = System::Windows::Forms::Padding(4);
			this->btn_BuscarCurso->Name = L"btn_BuscarCurso";
			this->btn_BuscarCurso->Size = System::Drawing::Size(112, 33);
			this->btn_BuscarCurso->TabIndex = 4;
			this->btn_BuscarCurso->Text = L"Buscar";
			this->btn_BuscarCurso->UseVisualStyleBackColor = true;
			this->btn_BuscarCurso->Click += gcnew System::EventHandler(this, &frmCurso::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(18, 114);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 23);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Docentes";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold));
			this->label3->Location = System::Drawing::Point(18, 296);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(95, 23);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Alumnos";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(22, 493);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 33);
			this->button2->TabIndex = 7;
			this->button2->Text = L"A-Z";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(249, 494);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(112, 33);
			this->button3->TabIndex = 8;
			this->button3->Text = L"P/Nota";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// lbxDocentes
			// 
			this->lbxDocentes->FormattingEnabled = true;
			this->lbxDocentes->ItemHeight = 23;
			this->lbxDocentes->Location = System::Drawing::Point(22, 157);
			this->lbxDocentes->Name = L"lbxDocentes";
			this->lbxDocentes->Size = System::Drawing::Size(337, 119);
			this->lbxDocentes->TabIndex = 23;
			// 
			// lbxAlumnos
			// 
			this->lbxAlumnos->FormattingEnabled = true;
			this->lbxAlumnos->ItemHeight = 23;
			this->lbxAlumnos->Location = System::Drawing::Point(22, 336);
			this->lbxAlumnos->Name = L"lbxAlumnos";
			this->lbxAlumnos->Size = System::Drawing::Size(337, 119);
			this->lbxAlumnos->TabIndex = 24;
			// 
			// frmCurso
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(389, 540);
			this->Controls->Add(this->lbxAlumnos);
			this->Controls->Add(this->lbxDocentes);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btn_BuscarCurso);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"frmCurso";
			this->Text = L"frmCurso";
			this->Load += gcnew System::EventHandler(this, &frmCurso::frmCurso_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmCurso_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	
	
	
}
};
}
