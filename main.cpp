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
	// コマンドライン引数指定なし
	if(argc < NumArgument)
	{
		// 使い方を表示
		YGame::TextureConverter::OutputUsage();
		return 0;
	}

	// COMライブラリ初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	// オプションの数
	int numOptions = argc - NumArgument;
	// オプションの配列 (ダブルポインタ)
	char** options = argv + NumArgument;

	YGame::TextureConverter converter;

	// テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath], numOptions, options);

	// COMライブラリ終了
	CoUninitialize();

	//system("pause");

	return 0;
}