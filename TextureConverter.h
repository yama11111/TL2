#pragma once
#include <string>

namespace YGame
{
	class TextureConverter
	{

	public:

		/// <summary>
		/// WIC → DDS変換
		/// </summary>
		/// <param name="filePath"> : ファイルパス</param>
		void ConvertTextureWICToDDS(const std::string& filePath);

	private:

		/// <summary>
		/// テクスチャファイル読み込み
		/// </summary>
		/// <param name="filePath"> : ファイルパス</param>
		void LoadWICTextureFromFile(const std::string& filePath);

		/// <summary>
		/// マルチバイト文字列 → ワイド文字列 変換
		/// </summary>
		/// <param name="mString"> : マルチバイト文字列</param>
		/// <returns>ワイド文字列</returns>
		static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

	};
}
