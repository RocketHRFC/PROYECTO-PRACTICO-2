#pragma once
#include <msclr\marshal_cppstd.h>
#include "Lista.h"
#include "Alumno.h"
#include "CsvReader.h"
//#include "Herramientas.h"
namespace PROYECTOPRACTICO2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class frmAlumnos : public System::Windows::Forms::Form
	{
		//#include "Herramientas.h"

		Lista<Alumno*>* alumnos;
	private: System::Windows::Forms::Button^ btnBorrar;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::ListBox^ lbxBorrarAlumnos;
	private: System::Windows::Forms::Button^ btnCrearEliminarCurso;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::ComboBox^ cbxModificarAlumnos;
	private: System::Windows::Forms::Button^ btnModificarEliminarCurso;
	private: System::Windows::Forms::Button^ btnModificar;



	private: System::Windows::Forms::Button^ btnModificarAgregarCurso;
	private: System::Windows::Forms::ListBox^ lbxModificarCursos;


	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::NumericUpDown^ nudModificarNota;

	private: System::Windows::Forms::TextBox^ txtModificarCurso;

	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::NumericUpDown^ nudModificarIngreso;
	private: System::Windows::Forms::ComboBox^ cbxModificarModalidad;


	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ txtModificarFacultad;

	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::TextBox^ txtModificarDPI;

	private: System::Windows::Forms::TextBox^ txtModificarApellidos;

	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::TextBox^ txtModificarNombres;

	private: System::Windows::Forms::Label^ label20;


		   Lista<Curso*>* cursos;
		   Alumno* alumnoModificar = nullptr;
	public:

		std::string StdString(System::String^ text)
		{
			return msclr::interop::marshal_as<std::string>(text);
		}

		System::String^ VisualString(std::string text)
		{
			return gcnew System::String(text.c_str());
		}

		frmAlumnos(void)
		{
			InitializeComponent();
			alumnos = new Lista<Alumno*>;
			cursos = new Lista<Curso*>;
			LeerCSV();
			LlenarDatosAlumnos();
		}
		void LeerCSV()
		{
			CsvReader* CSV = new CsvReader("data/estudiantes.csv");
			while (CSV->ReadLine())
			{
				Alumno* alumno = new Alumno();
				CSV->Read(alumno->Apellidos);
				CSV->Read(alumno->Nombres);
				std::string ingreso;
				CSV->Read(ingreso);
				alumno->Ingreso = std::stoi(ingreso);
				CSV->Read(alumno->DPI);
				CSV->Read(alumno->Facultad);
				CSV->Read(alumno->Modalida);

				std::string str_curso;
				while (CSV->Read(str_curso))
				{
					String^ CURSO = VisualString(str_curso);

					Curso* curso = new Curso();
					curso->Nombre = StdString(CURSO->Split('-')[0]);
					curso->Nota = std::stof(StdString(CURSO->Split('-')[1]));

					alumno->Cursos->Insertar(curso);
				}

				alumnos->Insertar(alumno);

				
			}
		}
		void LlenarDatosAlumnos()
		{
			lbxDatosAlumnos->Items->Clear();
			for (int i = 0; i < alumnos->cantidad; i++)
			{
				Alumno* alumno = alumnos->Obtener(i);
				std::string texto = alumno->Apellidos + " " + alumno->Nombres + " " + alumno->DPI;
				lbxDatosAlumnos->Items->Add(VisualString(texto));
			}

			lbxBorrarAlumnos->Items->Clear();
			for (int i = 0; i < alumnos->cantidad; i++)
			{
				Alumno* alumno = alumnos->Obtener(i);
				std::string texto = alumno->Apellidos + " " + alumno->Nombres + " " + alumno->DPI;
				lbxBorrarAlumnos->Items->Add(VisualString(texto));
			}

			cbxModificarAlumnos->Items->Clear();
			for (int i = 0; i < alumnos->cantidad; i++)
			{
				Alumno* alumno = alumnos->Obtener(i);
				std::string texto = alumno->Apellidos + " " + alumno->Nombres + " " + alumno->DPI;
				cbxModificarAlumnos->Items->Add(VisualString(texto));
			}

			lbxCrearCursos->Items->Clear();
			for (int i = 0; i < cursos->cantidad; i++)
			{
				Curso* curso = cursos->Obtener(i);
				std::string texto = curso->Nombre + " " + StdString(curso->Nota.ToString());
				lbxCrearCursos->Items->Add(VisualString(texto));
			}
			if (alumnoModificar != nullptr)
			{
				lbxModificarCursos->Items->Clear();
				for (int i = 0; i < alumnoModificar->Cursos->cantidad; i++)
				{
					Curso* curso = alumnoModificar->Cursos->Obtener(i);
					std::string texto = curso->Nombre + " " + StdString(curso->Nota.ToString());
					lbxModificarCursos->Items->Add(VisualString(texto));

				}
			}
		}

	protected:
		~frmAlumnos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtCrearFacultad;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtCrearDPI;
	private: System::Windows::Forms::TextBox^ txtCrearApellidos;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtCrearNombres;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::TextBox^ txtCrearCurso;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::NumericUpDown^ nupCrearIngreso;
	private: System::Windows::Forms::ComboBox^ cbxCrearModalidad;
	private: System::Windows::Forms::Button^ btnCrearRegistrar;
private: System::Windows::Forms::Button^ btnCrearAgregarCurso;

	private: System::Windows::Forms::ListBox^ lbxCrearCursos;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::NumericUpDown^ nudCrearNota;

	private: System::Windows::Forms::ListBox^ lbxDatosAlumnos;
	private: System::Windows::Forms::Button^ btnDatosGuardar;
	private: System::Windows::Forms::Button^ btnDatosAbrir;
	private: System::Windows::Forms::Label^ label10;
	private: System::ComponentModel::Container ^components;

	#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->btnDatosGuardar = (gcnew System::Windows::Forms::Button());
			this->btnDatosAbrir = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->lbxDatosAlumnos = (gcnew System::Windows::Forms::ListBox());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->btnCrearEliminarCurso = (gcnew System::Windows::Forms::Button());
			this->btnCrearRegistrar = (gcnew System::Windows::Forms::Button());
			this->btnCrearAgregarCurso = (gcnew System::Windows::Forms::Button());
			this->lbxCrearCursos = (gcnew System::Windows::Forms::ListBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->nudCrearNota = (gcnew System::Windows::Forms::NumericUpDown());
			this->txtCrearCurso = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->nupCrearIngreso = (gcnew System::Windows::Forms::NumericUpDown());
			this->cbxCrearModalidad = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtCrearFacultad = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtCrearDPI = (gcnew System::Windows::Forms::TextBox());
			this->txtCrearApellidos = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtCrearNombres = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->cbxModificarAlumnos = (gcnew System::Windows::Forms::ComboBox());
			this->btnModificarEliminarCurso = (gcnew System::Windows::Forms::Button());
			this->btnModificar = (gcnew System::Windows::Forms::Button());
			this->btnModificarAgregarCurso = (gcnew System::Windows::Forms::Button());
			this->lbxModificarCursos = (gcnew System::Windows::Forms::ListBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->nudModificarNota = (gcnew System::Windows::Forms::NumericUpDown());
			this->txtModificarCurso = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->nudModificarIngreso = (gcnew System::Windows::Forms::NumericUpDown());
			this->cbxModificarModalidad = (gcnew System::Windows::Forms::ComboBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->txtModificarFacultad = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->txtModificarDPI = (gcnew System::Windows::Forms::TextBox());
			this->txtModificarApellidos = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->txtModificarNombres = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->btnBorrar = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->lbxBorrarAlumnos = (gcnew System::Windows::Forms::ListBox());
			this->tabControl1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudCrearNota))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nupCrearIngreso))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudModificarNota))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudModificarIngreso))->BeginInit();
			this->tabPage4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(445, 650);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->btnDatosGuardar);
			this->tabPage2->Controls->Add(this->btnDatosAbrir);
			this->tabPage2->Controls->Add(this->label10);
			this->tabPage2->Controls->Add(this->lbxDatosAlumnos);
			this->tabPage2->Location = System::Drawing::Point(4, 32);
			this->tabPage2->Margin = System::Windows::Forms::Padding(4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(4);
			this->tabPage2->Size = System::Drawing::Size(437, 614);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Datos";
			this->tabPage2->UseVisualStyleBackColor = true;
			this->tabPage2->Click += gcnew System::EventHandler(this, &frmAlumnos::tabPage2_Click);
			// 
			// btnDatosGuardar
			// 
			this->btnDatosGuardar->Location = System::Drawing::Point(219, 553);
			this->btnDatosGuardar->Name = L"btnDatosGuardar";
			this->btnDatosGuardar->Size = System::Drawing::Size(183, 40);
			this->btnDatosGuardar->TabIndex = 22;
			this->btnDatosGuardar->Text = L"Guardar CSV";
			this->btnDatosGuardar->UseVisualStyleBackColor = true;
			// 
			// btnDatosAbrir
			// 
			this->btnDatosAbrir->Location = System::Drawing::Point(30, 553);
			this->btnDatosAbrir->Name = L"btnDatosAbrir";
			this->btnDatosAbrir->Size = System::Drawing::Size(183, 40);
			this->btnDatosAbrir->TabIndex = 21;
			this->btnDatosAbrir->Text = L"Abrir CSV";
			this->btnDatosAbrir->UseVisualStyleBackColor = true;
			this->btnDatosAbrir->Click += gcnew System::EventHandler(this, &frmAlumnos::btnDatosAbrir_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(14, 16);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(95, 23);
			this->label10->TabIndex = 20;
			this->label10->Text = L"Alumnos";
			// 
			// lbxDatosAlumnos
			// 
			this->lbxDatosAlumnos->FormattingEnabled = true;
			this->lbxDatosAlumnos->ItemHeight = 23;
			this->lbxDatosAlumnos->Location = System::Drawing::Point(14, 42);
			this->lbxDatosAlumnos->Name = L"lbxDatosAlumnos";
			this->lbxDatosAlumnos->Size = System::Drawing::Size(410, 487);
			this->lbxDatosAlumnos->TabIndex = 19;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->btnCrearEliminarCurso);
			this->tabPage1->Controls->Add(this->btnCrearRegistrar);
			this->tabPage1->Controls->Add(this->btnCrearAgregarCurso);
			this->tabPage1->Controls->Add(this->lbxCrearCursos);
			this->tabPage1->Controls->Add(this->label9);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->nudCrearNota);
			this->tabPage1->Controls->Add(this->txtCrearCurso);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->nupCrearIngreso);
			this->tabPage1->Controls->Add(this->cbxCrearModalidad);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->txtCrearFacultad);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->txtCrearDPI);
			this->tabPage1->Controls->Add(this->txtCrearApellidos);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->txtCrearNombres);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Location = System::Drawing::Point(4, 32);
			this->tabPage1->Margin = System::Windows::Forms::Padding(4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(4);
			this->tabPage1->Size = System::Drawing::Size(437, 614);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Crear";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// btnCrearEliminarCurso
			// 
			this->btnCrearEliminarCurso->Location = System::Drawing::Point(278, 507);
			this->btnCrearEliminarCurso->Name = L"btnCrearEliminarCurso";
			this->btnCrearEliminarCurso->Size = System::Drawing::Size(151, 32);
			this->btnCrearEliminarCurso->TabIndex = 21;
			this->btnCrearEliminarCurso->Text = L"Eliminar";
			this->btnCrearEliminarCurso->UseVisualStyleBackColor = true;
			this->btnCrearEliminarCurso->Click += gcnew System::EventHandler(this, &frmAlumnos::btnCrearEliminarCurso_Click);
			// 
			// btnCrearRegistrar
			// 
			this->btnCrearRegistrar->Location = System::Drawing::Point(65, 564);
			this->btnCrearRegistrar->Name = L"btnCrearRegistrar";
			this->btnCrearRegistrar->Size = System::Drawing::Size(298, 32);
			this->btnCrearRegistrar->TabIndex = 20;
			this->btnCrearRegistrar->Text = L"Registrar";
			this->btnCrearRegistrar->UseVisualStyleBackColor = true;
			this->btnCrearRegistrar->Click += gcnew System::EventHandler(this, &frmAlumnos::btnCrearRegistrar_Click);
			// 
			// btnCrearAgregarCurso
			// 
			this->btnCrearAgregarCurso->Location = System::Drawing::Point(278, 367);
			this->btnCrearAgregarCurso->Name = L"btnCrearAgregarCurso";
			this->btnCrearAgregarCurso->Size = System::Drawing::Size(151, 32);
			this->btnCrearAgregarCurso->TabIndex = 19;
			this->btnCrearAgregarCurso->Text = L"Agregar";
			this->btnCrearAgregarCurso->UseVisualStyleBackColor = true;
			this->btnCrearAgregarCurso->Click += gcnew System::EventHandler(this, &frmAlumnos::btnCrearAgregarCurso_Click);
			// 
			// lbxCrearCursos
			// 
			this->lbxCrearCursos->FormattingEnabled = true;
			this->lbxCrearCursos->ItemHeight = 23;
			this->lbxCrearCursos->Location = System::Drawing::Point(12, 405);
			this->lbxCrearCursos->Name = L"lbxCrearCursos";
			this->lbxCrearCursos->Size = System::Drawing::Size(417, 96);
			this->lbxCrearCursos->TabIndex = 18;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(8, 369);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(63, 23);
			this->label9->TabIndex = 17;
			this->label9->Text = L"Nota:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(8, 332);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(95, 23);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Nombre:";
			// 
			// nudCrearNota
			// 
			this->nudCrearNota->DecimalPlaces = 2;
			this->nudCrearNota->Location = System::Drawing::Point(136, 367);
			this->nudCrearNota->Name = L"nudCrearNota";
			this->nudCrearNota->Size = System::Drawing::Size(136, 32);
			this->nudCrearNota->TabIndex = 15;
			// 
			// txtCrearCurso
			// 
			this->txtCrearCurso->Location = System::Drawing::Point(136, 329);
			this->txtCrearCurso->Name = L"txtCrearCurso";
			this->txtCrearCurso->Size = System::Drawing::Size(293, 32);
			this->txtCrearCurso->TabIndex = 14;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(8, 292);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(81, 23);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Cursos:";
			// 
			// nupCrearIngreso
			// 
			this->nupCrearIngreso->Location = System::Drawing::Point(136, 157);
			this->nupCrearIngreso->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2045, 0, 0, 0 });
			this->nupCrearIngreso->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1980, 0, 0, 0 });
			this->nupCrearIngreso->Name = L"nupCrearIngreso";
			this->nupCrearIngreso->Size = System::Drawing::Size(293, 32);
			this->nupCrearIngreso->TabIndex = 12;
			this->nupCrearIngreso->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1980, 0, 0, 0 });
			// 
			// cbxCrearModalidad
			// 
			this->cbxCrearModalidad->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbxCrearModalidad->FormattingEnabled = true;
			this->cbxCrearModalidad->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Doctorado", L"Pregrado", L"Postgrado" });
			this->cbxCrearModalidad->Location = System::Drawing::Point(136, 232);
			this->cbxCrearModalidad->Name = L"cbxCrearModalidad";
			this->cbxCrearModalidad->Size = System::Drawing::Size(293, 31);
			this->cbxCrearModalidad->TabIndex = 11;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(8, 235);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(122, 23);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Modalidad:";
			// 
			// txtCrearFacultad
			// 
			this->txtCrearFacultad->Location = System::Drawing::Point(136, 194);
			this->txtCrearFacultad->Name = L"txtCrearFacultad";
			this->txtCrearFacultad->Size = System::Drawing::Size(293, 32);
			this->txtCrearFacultad->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(8, 197);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(101, 23);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Facultad:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(8, 159);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(88, 23);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Ingreso:";
			// 
			// txtCrearDPI
			// 
			this->txtCrearDPI->Location = System::Drawing::Point(136, 92);
			this->txtCrearDPI->Name = L"txtCrearDPI";
			this->txtCrearDPI->Size = System::Drawing::Size(293, 32);
			this->txtCrearDPI->TabIndex = 5;
			// 
			// txtCrearApellidos
			// 
			this->txtCrearApellidos->Location = System::Drawing::Point(136, 54);
			this->txtCrearApellidos->Name = L"txtCrearApellidos";
			this->txtCrearApellidos->Size = System::Drawing::Size(293, 32);
			this->txtCrearApellidos->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 95);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 23);
			this->label3->TabIndex = 3;
			this->label3->Text = L"DPI:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 23);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Apellidos:";
			// 
			// txtCrearNombres
			// 
			this->txtCrearNombres->Location = System::Drawing::Point(136, 16);
			this->txtCrearNombres->Name = L"txtCrearNombres";
			this->txtCrearNombres->Size = System::Drawing::Size(293, 32);
			this->txtCrearNombres->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombres:";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label21);
			this->tabPage3->Controls->Add(this->cbxModificarAlumnos);
			this->tabPage3->Controls->Add(this->btnModificarEliminarCurso);
			this->tabPage3->Controls->Add(this->btnModificar);
			this->tabPage3->Controls->Add(this->btnModificarAgregarCurso);
			this->tabPage3->Controls->Add(this->lbxModificarCursos);
			this->tabPage3->Controls->Add(this->label12);
			this->tabPage3->Controls->Add(this->label13);
			this->tabPage3->Controls->Add(this->nudModificarNota);
			this->tabPage3->Controls->Add(this->txtModificarCurso);
			this->tabPage3->Controls->Add(this->label14);
			this->tabPage3->Controls->Add(this->nudModificarIngreso);
			this->tabPage3->Controls->Add(this->cbxModificarModalidad);
			this->tabPage3->Controls->Add(this->label15);
			this->tabPage3->Controls->Add(this->txtModificarFacultad);
			this->tabPage3->Controls->Add(this->label16);
			this->tabPage3->Controls->Add(this->label17);
			this->tabPage3->Controls->Add(this->txtModificarDPI);
			this->tabPage3->Controls->Add(this->txtModificarApellidos);
			this->tabPage3->Controls->Add(this->label18);
			this->tabPage3->Controls->Add(this->label19);
			this->tabPage3->Controls->Add(this->txtModificarNombres);
			this->tabPage3->Controls->Add(this->label20);
			this->tabPage3->Location = System::Drawing::Point(4, 32);
			this->tabPage3->Margin = System::Windows::Forms::Padding(4);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(4);
			this->tabPage3->Size = System::Drawing::Size(437, 614);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Modificar";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(8, 12);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(101, 23);
			this->label21->TabIndex = 44;
			this->label21->Text = L"Alumnos:";
			// 
			// cbxModificarAlumnos
			// 
			this->cbxModificarAlumnos->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbxModificarAlumnos->FormattingEnabled = true;
			this->cbxModificarAlumnos->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Doctorado", L"Pregrado", L"Postgrado" });
			this->cbxModificarAlumnos->Location = System::Drawing::Point(136, 9);
			this->cbxModificarAlumnos->Name = L"cbxModificarAlumnos";
			this->cbxModificarAlumnos->Size = System::Drawing::Size(293, 31);
			this->cbxModificarAlumnos->TabIndex = 43;
			this->cbxModificarAlumnos->SelectedIndexChanged += gcnew System::EventHandler(this, &frmAlumnos::cbxModificarAlumnos_SelectedIndexChanged);
			// 
			// btnModificarEliminarCurso
			// 
			this->btnModificarEliminarCurso->Location = System::Drawing::Point(278, 523);
			this->btnModificarEliminarCurso->Name = L"btnModificarEliminarCurso";
			this->btnModificarEliminarCurso->Size = System::Drawing::Size(151, 32);
			this->btnModificarEliminarCurso->TabIndex = 42;
			this->btnModificarEliminarCurso->Text = L"Eliminar";
			this->btnModificarEliminarCurso->UseVisualStyleBackColor = true;
			this->btnModificarEliminarCurso->Click += gcnew System::EventHandler(this, &frmAlumnos::btnModificarEliminarCurso_Click);
			// 
			// btnModificar
			// 
			this->btnModificar->Location = System::Drawing::Point(65, 565);
			this->btnModificar->Name = L"btnModificar";
			this->btnModificar->Size = System::Drawing::Size(298, 32);
			this->btnModificar->TabIndex = 41;
			this->btnModificar->Text = L"Modificar";
			this->btnModificar->UseVisualStyleBackColor = true;
			this->btnModificar->Click += gcnew System::EventHandler(this, &frmAlumnos::btnModificar_Click);
			// 
			// btnModificarAgregarCurso
			// 
			this->btnModificarAgregarCurso->Location = System::Drawing::Point(278, 383);
			this->btnModificarAgregarCurso->Name = L"btnModificarAgregarCurso";
			this->btnModificarAgregarCurso->Size = System::Drawing::Size(151, 32);
			this->btnModificarAgregarCurso->TabIndex = 40;
			this->btnModificarAgregarCurso->Text = L"Agregar";
			this->btnModificarAgregarCurso->UseVisualStyleBackColor = true;
			this->btnModificarAgregarCurso->Click += gcnew System::EventHandler(this, &frmAlumnos::btnModificarAgregarCurso_Click);
			// 
			// lbxModificarCursos
			// 
			this->lbxModificarCursos->FormattingEnabled = true;
			this->lbxModificarCursos->ItemHeight = 23;
			this->lbxModificarCursos->Location = System::Drawing::Point(12, 421);
			this->lbxModificarCursos->Name = L"lbxModificarCursos";
			this->lbxModificarCursos->Size = System::Drawing::Size(417, 96);
			this->lbxModificarCursos->TabIndex = 39;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(8, 385);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(63, 23);
			this->label12->TabIndex = 38;
			this->label12->Text = L"Nota:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(8, 348);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(95, 23);
			this->label13->TabIndex = 37;
			this->label13->Text = L"Nombre:";
			// 
			// nudModificarNota
			// 
			this->nudModificarNota->DecimalPlaces = 2;
			this->nudModificarNota->Location = System::Drawing::Point(136, 383);
			this->nudModificarNota->Name = L"nudModificarNota";
			this->nudModificarNota->Size = System::Drawing::Size(136, 32);
			this->nudModificarNota->TabIndex = 36;
			// 
			// txtModificarCurso
			// 
			this->txtModificarCurso->Location = System::Drawing::Point(136, 345);
			this->txtModificarCurso->Name = L"txtModificarCurso";
			this->txtModificarCurso->Size = System::Drawing::Size(293, 32);
			this->txtModificarCurso->TabIndex = 35;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(8, 313);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(81, 23);
			this->label14->TabIndex = 34;
			this->label14->Text = L"Cursos:";
			// 
			// nudModificarIngreso
			// 
			this->nudModificarIngreso->Location = System::Drawing::Point(136, 187);
			this->nudModificarIngreso->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2045, 0, 0, 0 });
			this->nudModificarIngreso->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1980, 0, 0, 0 });
			this->nudModificarIngreso->Name = L"nudModificarIngreso";
			this->nudModificarIngreso->Size = System::Drawing::Size(293, 32);
			this->nudModificarIngreso->TabIndex = 33;
			this->nudModificarIngreso->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1980, 0, 0, 0 });
			// 
			// cbxModificarModalidad
			// 
			this->cbxModificarModalidad->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbxModificarModalidad->FormattingEnabled = true;
			this->cbxModificarModalidad->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Doctorado", L"Pregrado", L"Postgrado" });
			this->cbxModificarModalidad->Location = System::Drawing::Point(136, 262);
			this->cbxModificarModalidad->Name = L"cbxModificarModalidad";
			this->cbxModificarModalidad->Size = System::Drawing::Size(293, 31);
			this->cbxModificarModalidad->TabIndex = 32;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(8, 265);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(122, 23);
			this->label15->TabIndex = 31;
			this->label15->Text = L"Modalidad:";
			// 
			// txtModificarFacultad
			// 
			this->txtModificarFacultad->Location = System::Drawing::Point(136, 224);
			this->txtModificarFacultad->Name = L"txtModificarFacultad";
			this->txtModificarFacultad->Size = System::Drawing::Size(293, 32);
			this->txtModificarFacultad->TabIndex = 30;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(8, 227);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(101, 23);
			this->label16->TabIndex = 29;
			this->label16->Text = L"Facultad:";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(8, 189);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(88, 23);
			this->label17->TabIndex = 28;
			this->label17->Text = L"Ingreso:";
			// 
			// txtModificarDPI
			// 
			this->txtModificarDPI->Location = System::Drawing::Point(136, 134);
			this->txtModificarDPI->Name = L"txtModificarDPI";
			this->txtModificarDPI->Size = System::Drawing::Size(293, 32);
			this->txtModificarDPI->TabIndex = 27;
			// 
			// txtModificarApellidos
			// 
			this->txtModificarApellidos->Location = System::Drawing::Point(136, 96);
			this->txtModificarApellidos->Name = L"txtModificarApellidos";
			this->txtModificarApellidos->Size = System::Drawing::Size(293, 32);
			this->txtModificarApellidos->TabIndex = 26;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(8, 137);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(47, 23);
			this->label18->TabIndex = 25;
			this->label18->Text = L"DPI:";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(8, 99);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(107, 23);
			this->label19->TabIndex = 24;
			this->label19->Text = L"Apellidos:";
			// 
			// txtModificarNombres
			// 
			this->txtModificarNombres->Location = System::Drawing::Point(136, 58);
			this->txtModificarNombres->Name = L"txtModificarNombres";
			this->txtModificarNombres->Size = System::Drawing::Size(293, 32);
			this->txtModificarNombres->TabIndex = 23;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(8, 61);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(104, 23);
			this->label20->TabIndex = 22;
			this->label20->Text = L"Nombres:";
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->btnBorrar);
			this->tabPage4->Controls->Add(this->label11);
			this->tabPage4->Controls->Add(this->lbxBorrarAlumnos);
			this->tabPage4->Location = System::Drawing::Point(4, 32);
			this->tabPage4->Margin = System::Windows::Forms::Padding(4);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(4);
			this->tabPage4->Size = System::Drawing::Size(437, 614);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Borrar";
			this->tabPage4->UseVisualStyleBackColor = true;
			this->tabPage4->Click += gcnew System::EventHandler(this, &frmAlumnos::tabPage4_Click);
			// 
			// btnBorrar
			// 
			this->btnBorrar->Location = System::Drawing::Point(127, 551);
			this->btnBorrar->Name = L"btnBorrar";
			this->btnBorrar->Size = System::Drawing::Size(183, 40);
			this->btnBorrar->TabIndex = 24;
			this->btnBorrar->Text = L"Borrar";
			this->btnBorrar->UseVisualStyleBackColor = true;
			this->btnBorrar->Click += gcnew System::EventHandler(this, &frmAlumnos::btnBorrar_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(13, 19);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(95, 23);
			this->label11->TabIndex = 23;
			this->label11->Text = L"Alumnos";
			// 
			// lbxBorrarAlumnos
			// 
			this->lbxBorrarAlumnos->FormattingEnabled = true;
			this->lbxBorrarAlumnos->ItemHeight = 23;
			this->lbxBorrarAlumnos->Location = System::Drawing::Point(13, 45);
			this->lbxBorrarAlumnos->Name = L"lbxBorrarAlumnos";
			this->lbxBorrarAlumnos->Size = System::Drawing::Size(410, 487);
			this->lbxBorrarAlumnos->TabIndex = 22;
			// 
			// frmAlumnos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(445, 650);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"frmAlumnos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Alumnos";
			this->tabControl1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudCrearNota))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nupCrearIngreso))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudModificarNota))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudModificarIngreso))->EndInit();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnCrearRegistrar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Alumno* alumno = new Alumno();
		alumno->Nombres = StdString(txtCrearNombres->Text);
		alumno->Apellidos = StdString(txtCrearApellidos->Text);
		alumno->DPI = StdString(txtCrearDPI->Text);

		alumno->Ingreso = (int)nupCrearIngreso->Value;
		alumno->Facultad = StdString(txtCrearFacultad->Text);
		alumno->Modalida = StdString(cbxCrearModalidad->Text);

		alumno->Cursos = cursos;

		alumnos->Insertar(alumno);

		txtCrearNombres->Clear();
		txtCrearApellidos->Clear();
		txtCrearDPI->Clear();
		txtCrearFacultad->Clear();
		cbxCrearModalidad->SelectedIndex = -1;
		nupCrearIngreso->Value = 1980;
		cursos = new Lista<Curso*>;

		LlenarDatosAlumnos();
	}
	private: System::Void btnCrearAgregarCurso_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Curso* curso = new Curso();
		curso->Nombre = StdString(txtCrearCurso->Text);
		curso->Nota = (float)nudCrearNota->Value;

		txtCrearCurso->Clear();
		nudCrearNota->Value = 0;

		cursos->Insertar(curso);
		LlenarDatosAlumnos();
	}
	private: System::Void btnBorrar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (lbxBorrarAlumnos->SelectedIndex != -1)
		{
			alumnos->Extraer(lbxBorrarAlumnos->SelectedIndex);
			LlenarDatosAlumnos();
		}
	}

	private: System::Void btnCrearEliminarCurso_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (lbxCrearCursos->SelectedIndex != -1)
		{
			cursos->Extraer(lbxCrearCursos->SelectedIndex);
			LlenarDatosAlumnos();
		}
	}
	private: System::Void cbxModificarAlumnos_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (cbxModificarAlumnos->SelectedIndex != -1)
		{
			Alumno* alumno = alumnos->Obtener(cbxModificarAlumnos->SelectedIndex);
			txtModificarNombres->Text = VisualString(alumno->Nombres);
			txtModificarApellidos->Text = VisualString(alumno->Apellidos);
			txtModificarDPI->Text = VisualString(alumno->DPI);

			nudModificarIngreso->Value = alumno->Ingreso;
			txtModificarFacultad->Text = VisualString(alumno->Facultad);
			cbxModificarModalidad->Text = VisualString(alumno->Modalida);

			alumnoModificar = alumno;
			LlenarDatosAlumnos();
		}
		else
		{
			txtModificarNombres->Clear();
			txtModificarApellidos->Clear();
			txtModificarDPI->Clear();

			nudModificarIngreso->Value = 1980;
			txtModificarFacultad->Clear();
			cbxModificarModalidad->SelectedIndex = -1;

			alumnoModificar = nullptr;
		}
	}
	private: System::Void btnModificarAgregarCurso_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (alumnoModificar != nullptr)
		{
			Curso* curso = new Curso();
			curso->Nombre = StdString(txtCrearCurso->Text);
			curso->Nota = (float)nudCrearNota->Value;

			txtCrearCurso->Clear();
			nudCrearNota->Value = 0;

			alumnoModificar->Cursos->Insertar(curso);
			LlenarDatosAlumnos();
		}
	}
	private: System::Void btnModificarEliminarCurso_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (alumnoModificar != nullptr)
		{
			if (lbxModificarCursos->SelectedIndex != -1)
			{
				alumnoModificar->Cursos->Extraer(lbxModificarCursos->SelectedIndex);
				LlenarDatosAlumnos();
			}
		}
	}
	private: System::Void btnModificar_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (alumnoModificar != nullptr)
		{
			alumnoModificar->Nombres = StdString(txtModificarNombres->Text);
			alumnoModificar->Apellidos = StdString(txtModificarApellidos->Text);
			alumnoModificar->DPI = StdString(txtModificarDPI->Text);

			alumnoModificar->Ingreso = (int)nudModificarIngreso->Value;
			alumnoModificar->Facultad = StdString(txtModificarFacultad->Text);
			alumnoModificar->Modalida = StdString(cbxModificarModalidad->Text);
			LlenarDatosAlumnos();
		}
	}
private: System::Void btnDatosAbrir_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tabPage2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tabPage4_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
