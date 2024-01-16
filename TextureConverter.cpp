#include "TextureConverter.h"
#include <windows.h>

using YGame::TextureConverter;
using namespace DirectX;

void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath)
{
	// ファイル読み込み
	TextureData data = LoadWICTextureFromFile(filePath);

	// 書き出し (DDS)
	SaveDDSTextureToFile(data);
}

TextureConverter::TextureData TextureConverter::LoadWICTextureFromFile(
	const std::string& filePath)
{
	TextureData data;

	// ファイルパス変換
	std::wstring wFilePath = ConvertMultiByteStringToWideString(filePath);

	// 読み込み (WIC)
	HRESULT hr = LoadFromWICFile(
		wFilePath.c_str(), WIC_FLAGS_NONE, 
		&data.metadata, data.scratchImg);
	assert(SUCCEEDED(hr));

	// ファイルパス分解
	SeparateFilePath(filePath, data.directoryPath, data.fileName, data.fileExt);

	return data;
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

void TextureConverter::SeparateFilePath(
	const std::string& filePath, 
	std::string& directoryPath, 
	std::string& fileName, 
	std::string& fileExt)
{
	size_t pos1 = 0;
	std::string exceptExt;

	// '.' があるなら
	pos1 = filePath.rfind('.');
	if (pos1 != std::string::npos)
	{
		// '.' より後ろを抜き出す (ext)
		fileExt = filePath.substr(pos1 + 1, filePath.size() - pos1 - 1);
		exceptExt = filePath.substr(0, pos1);
	}
	else
	{
		fileExt = "";
		exceptExt = filePath;
	}

	// '\\' があるなら
	pos1 = exceptExt.rfind('\\');
	if (pos1 != std::string::npos)
	{
		// '\\' より前を抜き出す (directory)
		directoryPath = exceptExt.substr(0, pos1 + 1);
		
		// '\\' より後ろを抜き出す (fileName)
		fileName = exceptExt.substr(pos1 + 1, exceptExt.size() - pos1 - 1);
		
		return;
	}

	// '/' があるなら
	pos1 = exceptExt.rfind('/');
	if (pos1 != std::string::npos)
	{
		// '/' より前を抜き出す (directory)
		directoryPath = exceptExt.substr(0, pos1 + 1);

		// '/' より後ろを抜き出す (fileName)
		fileName = exceptExt.substr(pos1 + 1, exceptExt.size() - pos1 - 1);

		return;
	}

	directoryPath = "";
	fileName = exceptExt;
}

void TextureConverter::SaveDDSTextureToFile(const TextureData& texData)
{
	DirectX::TexMetadata metadata = texData.metadata;
	metadata.format = MakeSRGB(metadata.format);

	std::wstring filePath = 
		ConvertMultiByteStringToWideString(
			texData.directoryPath + texData.fileName + ".dds");

	HRESULT hr = SaveToDDSFile(
		texData.scratchImg.GetImages(), texData.scratchImg.GetImageCount(),
		metadata, DDS_FLAGS_NONE, filePath.c_str());
	assert(SUCCEEDED(hr));
}

