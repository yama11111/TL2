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
	assert(NumArgument <= argc);

	// COM���C�u����������
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	YGame::TextureConverter converter;

	// �e�N�X�`���ϊ�
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	// COM���C�u�����I��
	CoUninitialize();

	system("pause");

	return 0;
}