#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <cassert>
#include "TextureConverter.h"

enum Argument
{
	kApplicationPath,	 // �A�v���P�[�V�����p�X
	kFilePath,			 // �t�@�C���p�X

	NumArgument,
};

int main(int argc, char* argv[])
{
	// �R�}���h���C�������w��Ȃ�
	if(argc < NumArgument)
	{
		// �g������\��
		YGame::TextureConverter::OutputUsage();
		return 0;
	}

	// COM���C�u����������
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	// �I�v�V�����̐�
	int numOptions = argc - NumArgument;
	// �I�v�V�����̔z�� (�_�u���|�C���^)
	char** options = argv + NumArgument;

	YGame::TextureConverter converter;

	// �e�N�X�`���ϊ�
	converter.ConvertTextureWICToDDS(argv[kFilePath], numOptions, options);

	// COM���C�u�����I��
	CoUninitialize();

	//system("pause");

	return 0;
}