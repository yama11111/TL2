#include "TextureConverter.h"
#include <windows.h>

using YGame::TextureConverter;

void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath)
{
	// ファイル読み込み
	LoadWICTextureFromFile(filePath);

	// 書き出し(DDS)
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	// ファイルパス変換
	std::wstring wFilePath = ConvertMultiByteStringToWideString(filePath);


}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString)
{
	std::wstring result;

	// 文字数
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	// 文字数分のバッファを用意
	result.resize(static_cast<size_t>(filePathBufferSize));

	// 変換
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &result[0], filePathBufferSize);

	return result;
}
