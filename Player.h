#pragma once
#include "Stop.h"
#include "Add.h"
#include "Play.h"
#include "Pause.h"
#include "Previous.h"
#include "Next.h"
#include "TimerManager.h"
#include "VolumeManager.h"
#include "ProgressManager.h"
#include "PlaylistManager.h"
#include "SavePlaylistManager.h"
#include "LoadPlaylistManager.h"
#include "IndexManager.h"

namespace SmirnovAlexeyCourseWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::IO;

	/// <summary>
	/// ������ ��� Player
	/// </summary>
	public ref class Player : public System::Windows::Forms::Form
	{
	public:
		Player(void)
		{
			InitializeComponent();
			currentVolume = 50; // ������������� ��������� �������� ���������
			paths = gcnew List<String^>(); // �������������� ������ �����

			savePlaylistManager = gcnew SavePlaylistManager(paths);
			loadPlaylistManager = gcnew LoadPlaylistManager(track_list, paths);
			loadPlaylistManager->Execute();  // �������� ��������� ��� �������

			InitializeToolTips(); // �������������� ���������


			stopHandler = gcnew Stop(player_for_tracks, progressBar1, label_track_start, label_message);
			playHandler = gcnew Play(player_for_tracks, track_list, paths, label_message);
			pauseHandler = gcnew Pause(player_for_tracks, label_message);
			previousHandler = gcnew Previous(track_list);
			nextHandler = gcnew Next(track_list);
			volumeManager = gcnew VolumeManager(player_for_tracks, trackBar1, label_volume);
			timerManager = gcnew TimerManager(player_for_tracks, progressBar1, label_track_start, label_track_end);
			progressManager = gcnew ProgressManager(player_for_tracks, progressBar1, label_track_start);
			addHandler = gcnew Add(track_list, paths, savePlaylistManager);
			playlistManager = gcnew PlaylistManager(track_list, paths, label_message, player_for_tracks, savePlaylistManager);

			indexManager = gcnew IndexManager(player_for_tracks, track_list, paths, label_message, timer1, trackBar1, label_volume);

			trackBar1->Scroll += gcnew System::EventHandler(this, &Player::trackBar1_Scroll);
			timer1->Tick += gcnew System::EventHandler(this, &Player::timer1_Tick);
			progressBar1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Player::progressBar1_MouseClick);
			track_list->SelectedIndexChanged += gcnew System::EventHandler(this, &Player::track_list_SelectedIndexChanged);
			track_list->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Player::track_list_KeyDown);
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
	private: AxWMPLib::AxWindowsMediaPlayer^ player_for_tracks;
	private: System::Windows::Forms::Label^ label_message;
	private: System::Windows::Forms::Button^ button_stop;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::ToolTip^ toolTip; // ��������� ToolTip

	private:
		int currentVolume; // ���������� ��� �������� �������� ������ ���������
		List<String^>^ paths; // ���������� List ������ �������

		Stop^ stopHandler;
		Play^ playHandler;
		Pause^ pauseHandler;
		Previous^ previousHandler;
		Next^ nextHandler;
		VolumeManager^ volumeManager;
		TimerManager^ timerManager;
		ProgressManager^ progressManager;
		IndexManager^ indexManager;
		Add^ addHandler;
		PlaylistManager^ playlistManager;
		SavePlaylistManager^ savePlaylistManager;
		LoadPlaylistManager^ loadPlaylistManager;

	private: System::Windows::Forms::Timer^ timer1;
		   array<String^>^ files;

	private: void InitializeToolTips() {
		toolTip = gcnew System::Windows::Forms::ToolTip();

		toolTip->AutoPopDelay = 5000; // ��������� ����� ����� 5 ������
		toolTip->InitialDelay = 2000; // ��������� �������� ����� 2 �������

		// ������������� ��������� ��� ������
		toolTip->SetToolTip(this->button_play, "�������������");
		toolTip->SetToolTip(this->button_pause, "�����");
		toolTip->SetToolTip(this->button_stop, "����");
		toolTip->SetToolTip(this->button_next, "��������� ����");
		toolTip->SetToolTip(this->button_previous, "���������� ����");
		toolTip->SetToolTip(this->button_add, "�������� ����");
		toolTip->SetToolTip(this->trackBar1, "�������� ���������");
		toolTip->SetToolTip(this->track_list, "�������� ���� ��� ��������������� \n��� �������� ����� �������� � ������� �� ������� Delete");
		toolTip->SetToolTip(this->progressBar1, "�������� ����� ��������������� �����");
	}

#pragma region 
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
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
			   this->player_for_tracks = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			   this->label_message = (gcnew System::Windows::Forms::Label());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->groupBox1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->player_for_tracks))->BeginInit();
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
			   this->label_volume->BackColor = System::Drawing::Color::Transparent;
			   this->label_volume->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label_volume->ForeColor = System::Drawing::Color::White;
			   this->label_volume->Location = System::Drawing::Point(523, 79);
			   this->label_volume->Name = L"label_volume";
			   this->label_volume->Size = System::Drawing::Size(30, 17);
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
			   this->button_stop->Click += gcnew System::EventHandler(this, &Player::button_stop_Click);
			   // 
			   // track_list
			   // 
			   this->track_list->BackColor = System::Drawing::Color::Gray;
			   this->track_list->ForeColor = System::Drawing::Color::White;
			   this->track_list->FormattingEnabled = true;
			   this->track_list->ItemHeight = 20;
			   this->track_list->Location = System::Drawing::Point(6, 62);
			   this->track_list->Name = L"track_list";
			   this->track_list->Size = System::Drawing::Size(480, 124);
			   this->track_list->TabIndex = 5;
			   this->track_list->SelectedIndexChanged += gcnew System::EventHandler(this, &Player::track_list_SelectedIndexChanged);
			   this->track_list->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Player::track_list_KeyDown);
			   // 
			   // trackBar1
			   // 
			   this->trackBar1->Location = System::Drawing::Point(489, 26);
			   this->trackBar1->Maximum = 100;
			   this->trackBar1->Name = L"trackBar1";
			   this->trackBar1->Orientation = System::Windows::Forms::Orientation::Vertical;
			   this->trackBar1->Size = System::Drawing::Size(56, 125);
			   this->trackBar1->TabIndex = 6;
			   this->trackBar1->Scroll += gcnew System::EventHandler(this, &Player::trackBar1_Scroll);
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
			   this->button_add->Click += gcnew System::EventHandler(this, &Player::button_add_Click);
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
			   this->button_next->Click += gcnew System::EventHandler(this, &Player::button_next_Click);
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
			   this->button_pause->Click += gcnew System::EventHandler(this, &Player::button_pause_Click);
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
			   this->button_play->Click += gcnew System::EventHandler(this, &Player::button_play_Click);
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
			   this->button_previous->Click += gcnew System::EventHandler(this, &Player::button_previous_Click);
			   // 
			   // progressBar1
			   // 
			   this->progressBar1->Location = System::Drawing::Point(83, 314);
			   this->progressBar1->Name = L"progressBar1";
			   this->progressBar1->Size = System::Drawing::Size(426, 13);
			   this->progressBar1->TabIndex = 3;
			   this->progressBar1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Player::progressBar1_MouseClick);
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
			   // player_for_tracks
			   // 
			   this->player_for_tracks->Enabled = true;
			   this->player_for_tracks->Location = System::Drawing::Point(8, 9);
			   this->player_for_tracks->Name = L"player_for_tracks";
			   this->player_for_tracks->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"player_for_tracks.OcxState")));
			   this->player_for_tracks->Size = System::Drawing::Size(427, 241);
			   this->player_for_tracks->TabIndex = 9;
			   // 
			   // label_message
			   // 
			   this->label_message->AutoSize = true;
			   this->label_message->BackColor = System::Drawing::Color::Transparent;
			   this->label_message->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label_message->ForeColor = System::Drawing::Color::White;
			   this->label_message->Location = System::Drawing::Point(11, 12);
			   this->label_message->Name = L"label_message";
			   this->label_message->Size = System::Drawing::Size(112, 20);
			   this->label_message->TabIndex = 2;
			   this->label_message->Text = L"MediaPlayer";
			   // 
			   // timer1
			   // 
			   this->timer1->Tick += gcnew System::EventHandler(this, &Player::timer1_Tick);
			   // 
			   // Player
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::Black;
			   this->ClientSize = System::Drawing::Size(594, 503);
			   this->Controls->Add(this->label_message);
			   this->Controls->Add(this->player_for_tracks);
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
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->player_for_tracks))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e) {
		addHandler->Execute();
	}

	private: System::Void track_list_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		indexManager->Execute(volumeManager->GetCurrentVolume());  // �������� ����������� ���������
	}
	
	private: System::Void button_play_Click(System::Object^ sender, System::EventArgs^ e) {
		playHandler->Execute();
	}

	private: System::Void button_pause_Click(System::Object^ sender, System::EventArgs^ e) {
		pauseHandler->Execute();
	}

	private: System::Void button_stop_Click(System::Object^ sender, System::EventArgs^ e) {
		stopHandler->Execute();
	}

	private: System::Void button_previous_Click(System::Object^ sender, System::EventArgs^ e) {
		previousHandler->Execute();
	}

	private: System::Void button_next_Click(System::Object^ sender, System::EventArgs^ e) {
		nextHandler->Execute();
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		timerManager->Execute();
	}

	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
		volumeManager->Execute();  // ��������� ����� ���������
	}

	private: System::Void progressBar1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		progressManager->Execute(e);  // ��������� ������� � ����� ������� ����������
	}

	private: System::Void track_list_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		playlistManager->Execute(e);
	}
	};
}