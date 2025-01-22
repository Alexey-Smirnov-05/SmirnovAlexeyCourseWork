#pragma once
#include <Windows.h> // ��������� include ��� Windows
using namespace System::Windows::Forms;
using namespace AxWMPLib;
using namespace System::Collections::Generic;
using namespace System; // ��������� using namespace System;
using namespace System::IO;  // ����� ��� ������ � �������

#include "SavePlaylistManager.h"  // ���������� ������������ ����

ref class Add {
private:
	ListBox^ trackList;
	List<String^>^ paths;
	SavePlaylistManager^ savePlaylistManager;  // ��������� �������� ����������

public:
	Add(ListBox^ list, List<String^>^ p, SavePlaylistManager^ saveMgr) {
		trackList = list;
		paths = p;
		savePlaylistManager = saveMgr;  // ��������� ������ �� ������ ����������
	}

    void Execute()
    {
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		ofd->Multiselect = true;
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			array<String^>^ files = ofd->SafeFileNames; // ��������� ���������� ��� ������
			array<String^>^ newPaths = ofd->FileNames; // ��������� ���������� ��� �����

			List<String^>^ invalidFiles = gcnew List<String^>(); // ������ ��� ������������ ������

			for (int x = 0; x < files->Length; x++)
			{
				// ��������� ���������� �����
				String^ extension = Path::GetExtension(newPaths[x]);
				if (extension == ".mp3" || extension == ".wma" || extension == ".wav" ||
					extension == ".m4a" || extension == ".aac" ||
					extension == ".mp4" || extension == ".wmv" ||
					extension == ".avi" || extension == ".mov") {
					trackList->Items->Add(files[x]);
					paths->Add(newPaths[x]); // ��������� ����� ���� � ������
				}
				else {
					invalidFiles->Add(files[x]); // ��������� ������������ ���� � ������
				}
			}
			
			// ��������� �������� ����� ���������� ������
			savePlaylistManager->Execute();  // �������� ����������

			// ���� ���� ������������ �����, ������� ���������
			if (invalidFiles->Count > 0) {
				String^ message = "��������� ����� ���� ��������� ��-�� ������������� ����������:\n";
				for each (String ^ invalidFile in invalidFiles) {
					message += invalidFile + "\n";
				}
				MessageBox::Show(message, "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
    }
};
