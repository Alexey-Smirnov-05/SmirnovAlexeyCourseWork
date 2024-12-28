#pragma once

namespace SmirnovAlexeyCourseWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Player
	/// </summary>
	public ref class Player : public System::Windows::Forms::Form
	{
	public:
		Player(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Player()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button_add;
	private: System::Windows::Forms::Button^ button_next;
	private: System::Windows::Forms::Button^ button_pause;
	private: System::Windows::Forms::Button^ button_play;
	private: System::Windows::Forms::Button^ button_previous;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::ListBox^ track_list;

	private: System::Windows::Forms::Label^ label_volume;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ label_track_start;
	private: System::Windows::Forms::Label^ label_track_end;
	private: AxWMPLib::AxWindowsMediaPlayer^ axWindowsMediaPlayer1;
	private: System::Windows::Forms::Label^ label_message;
	private: System::Windows::Forms::Button^ button_stop;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Player::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label_volume = (gcnew System::Windows::Forms::Label());
			this->button_stop = (gcnew System::Windows::Forms::Button());
			this->track_list = (gcnew System::Windows::Forms::ListBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->button_next = (gcnew System::Windows::Forms::Button());
			this->button_pause = (gcnew System::Windows::Forms::Button());
			this->button_play = (gcnew System::Windows::Forms::Button());
			this->button_previous = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label_track_start = (gcnew System::Windows::Forms::Label());
			this->label_track_end = (gcnew System::Windows::Forms::Label());
			this->axWindowsMediaPlayer1 = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			this->label_message = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Black;
			this->groupBox1->Controls->Add(this->label_volume);
			this->groupBox1->Controls->Add(this->button_stop);
			this->groupBox1->Controls->Add(this->track_list);
			this->groupBox1->Controls->Add(this->trackBar1);
			this->groupBox1->Controls->Add(this->button_add);
			this->groupBox1->Controls->Add(this->button_next);
			this->groupBox1->Controls->Add(this->button_pause);
			this->groupBox1->Controls->Add(this->button_play);
			this->groupBox1->Controls->Add(this->button_previous);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(12, 333);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(569, 158);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"����������";
			// 
			// label_volume
			// 
			this->label_volume->AutoSize = true;
			this->label_volume->BackColor = System::Drawing::Color::Black;
			this->label_volume->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_volume->ForeColor = System::Drawing::Color::White;
			this->label_volume->Location = System::Drawing::Point(528, 74);
			this->label_volume->Name = L"label_volume";
			this->label_volume->Size = System::Drawing::Size(35, 20);
			this->label_volume->TabIndex = 3;
			this->label_volume->Text = L"0%";
			// 
			// button_stop
			// 
			this->button_stop->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_stop->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_stop.Image")));
			this->button_stop->Location = System::Drawing::Point(330, 21);
			this->button_stop->Name = L"button_stop";
			this->button_stop->Size = System::Drawing::Size(75, 35);
			this->button_stop->TabIndex = 6;
			this->button_stop->UseVisualStyleBackColor = true;
			// 
			// track_list
			// 
			this->track_list->BackColor = System::Drawing::Color::Gray;
			this->track_list->ForeColor = System::Drawing::Color::White;
			this->track_list->FormattingEnabled = true;
			this->track_list->ItemHeight = 20;
			this->track_list->Location = System::Drawing::Point(6, 62);
			this->track_list->Name = L"track_list";
			this->track_list->Size = System::Drawing::Size(480, 84);
			this->track_list->TabIndex = 5;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(492, 21);
			this->trackBar1->Maximum = 100;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBar1->Size = System::Drawing::Size(56, 125);
			this->trackBar1->TabIndex = 6;
			// 
			// button_add
			// 
			this->button_add->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_add->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_add.Image")));
			this->button_add->Location = System::Drawing::Point(411, 21);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(75, 35);
			this->button_add->TabIndex = 4;
			this->button_add->UseVisualStyleBackColor = true;
			// 
			// button_next
			// 
			this->button_next->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_next->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_next.Image")));
			this->button_next->Location = System::Drawing::Point(249, 21);
			this->button_next->Name = L"button_next";
			this->button_next->Size = System::Drawing::Size(75, 35);
			this->button_next->TabIndex = 3;
			this->button_next->UseVisualStyleBackColor = true;
			// 
			// button_pause
			// 
			this->button_pause->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_pause->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_pause->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_pause.Image")));
			this->button_pause->Location = System::Drawing::Point(168, 21);
			this->button_pause->Name = L"button_pause";
			this->button_pause->Size = System::Drawing::Size(75, 35);
			this->button_pause->TabIndex = 2;
			this->button_pause->UseVisualStyleBackColor = true;
			// 
			// button_play
			// 
			this->button_play->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_play->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_play.Image")));
			this->button_play->Location = System::Drawing::Point(87, 21);
			this->button_play->Name = L"button_play";
			this->button_play->Size = System::Drawing::Size(75, 35);
			this->button_play->TabIndex = 1;
			this->button_play->UseVisualStyleBackColor = true;
			// 
			// button_previous
			// 
			this->button_previous->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_previous->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_previous.Image")));
			this->button_previous->Location = System::Drawing::Point(6, 21);
			this->button_previous->Name = L"button_previous";
			this->button_previous->Size = System::Drawing::Size(75, 35);
			this->button_previous->TabIndex = 0;
			this->button_previous->UseVisualStyleBackColor = true;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(83, 314);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(426, 13);
			this->progressBar1->TabIndex = 3;
			// 
			// label_track_start
			// 
			this->label_track_start->AutoSize = true;
			this->label_track_start->BackColor = System::Drawing::Color::Black;
			this->label_track_start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_track_start->ForeColor = System::Drawing::Color::White;
			this->label_track_start->Location = System::Drawing::Point(12, 310);
			this->label_track_start->Name = L"label_track_start";
			this->label_track_start->Size = System::Drawing::Size(55, 20);
			this->label_track_start->TabIndex = 7;
			this->label_track_start->Text = L"00:00";
			// 
			// label_track_end
			// 
			this->label_track_end->AutoSize = true;
			this->label_track_end->BackColor = System::Drawing::Color::Black;
			this->label_track_end->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_track_end->ForeColor = System::Drawing::Color::White;
			this->label_track_end->Location = System::Drawing::Point(515, 310);
			this->label_track_end->Name = L"label_track_end";
			this->label_track_end->Size = System::Drawing::Size(55, 20);
			this->label_track_end->TabIndex = 8;
			this->label_track_end->Text = L"00:00";
			// 
			// axWindowsMediaPlayer1
			// 
			this->axWindowsMediaPlayer1->Enabled = true;
			this->axWindowsMediaPlayer1->Location = System::Drawing::Point(8, 9);
			this->axWindowsMediaPlayer1->Name = L"axWindowsMediaPlayer1";
			this->axWindowsMediaPlayer1->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"axWindowsMediaPlayer1.OcxState")));
			this->axWindowsMediaPlayer1->Size = System::Drawing::Size(427, 241);
			this->axWindowsMediaPlayer1->TabIndex = 9;
			// 
			// label_message
			// 
			this->label_message->AutoSize = true;
			this->label_message->BackColor = System::Drawing::Color::Black;
			this->label_message->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_message->ForeColor = System::Drawing::Color::White;
			this->label_message->Location = System::Drawing::Point(11, 12);
			this->label_message->Name = L"label_message";
			this->label_message->Size = System::Drawing::Size(112, 20);
			this->label_message->TabIndex = 2;
			this->label_message->Text = L"MediaPlayer";
			// 
			// Player
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DimGray;
			this->ClientSize = System::Drawing::Size(594, 503);
			this->Controls->Add(this->label_message);
			this->Controls->Add(this->axWindowsMediaPlayer1);
			this->Controls->Add(this->label_track_start);
			this->Controls->Add(this->label_track_end);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Player";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MediaPlayer";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
