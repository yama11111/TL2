#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <cassert>
#include "TextureConverter.h"

enum Argument
{
	kApplicationPath,	 // アプリケーションパス
	kFilePath,			 // ファイルパス

	NumArgument,
};

int main(int argc, char* argv[])
{
	assert(NumArgument <= argc);

	// COMライブラリ初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	YGame::TextureConverter converter;

	// テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	// COMライブラリ終了
	CoUninitialize();

	system("pause");

	return 0;
}