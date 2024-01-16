#pragma once
#include <string>
#include <DirectXTex.h>

namespace YGame
{
	class TextureConverter
	{

	public:

		/// <summary>
		/// WIC → DDS変換
		/// </summary>
		/// <param name="filePath"> : ファイルパス</param>
		static void ConvertTextureWICToDDS(const std::string& filePath);

	private:

		/// <summary>
		/// テクスチャデータ構造体
		/// </summary>
		struct TextureData
		{
			// 画像データ
			DirectX::TexMetadata metadata{};
			DirectX::ScratchImage scratchImg{};
			
			// ファイルパス
			std::string directoryPath;
			std::string fileName;
			std::string fileExt;
		};
	
	private:

		/// <summary>
		/// テクスチャファイル読み込み
		/// </summary>
		/// <param name="filePath"> : ファイルパス</param>
		static TextureData LoadWICTextureFromFile(const std::string& filePath);

		/// <summary>
		/// マルチバイト文字列 → ワイド文字列 変換
		/// </summary>
		/// <param name="mString"> : マルチバイト文字列</param>
		/// <returns>ワイド文字列</returns>
		static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

		/// <summary>
		/// ファイルパス分解
		/// </summary>
		/// <param name="filePath"> : ファイルパス</param>
		/// <param name="directoryPath"> : 受け取り用 ディレクトリパス</param>
		/// <param name="fileName"> : 受け取り用 ファイル名</param>
		/// <param name="fileExt"> : 受け取り用 ファイル拡張子</param>
		static void SeparateFilePath(
			const std::string& filePath,
			std::string& directoryPath,
			std::string& fileName,
			std::string& fileExt);

		/// <summary>
		/// DDSテクスチャとしてファイル書き出し
		/// </summary>
		/// <param name="texData"> : 画像データ</param>
		static void SaveDDSTextureToFile(const TextureData& texData);

	};
}
