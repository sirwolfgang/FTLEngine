//===============================================================
// File:	File.h
// Purpose: To Handle File IO
//===============================================================
#pragma once
#include <fstream>
#include "../DataTypes.h"

namespace Platform
{
	class File
	{
	public:
		enum EOpen
		{
			EOPEN_APPEND,
			EOPEN_TRUNCATE,
		};

		enum EData
		{
			EDATA_ASCII,
			EDATA_BINARY,
		};

		enum EPermissions
		{
			EPERMISSION_READ		= 1,
			EPERMISSION_WRITE		= 2,
			EPERMISSION_READ_WRITE	= 3,
		};

		enum EPositions
		{
			EPOSITION_BEGIN,
			EPOSITION_CURRENT,
			EPOSITION_END,
		};

	private:
		EOpen			m_eOpen;
		EData			m_eData;
		EPermissions	m_ePermissions;

		utf8			m_szFilename[FILENAME_MAX];
		std::fstream	m_file;

		File();
	public:
		File(const utf8 _szFilename[], EOpen _eOpen, EData _eData, EPermissions _ePermissons);
		virtual ~File();

		void Read(memsize_u _nSize, void* _pData);
		void Write(memsize_u _nSize, void* _pData);

		void Commit();

		void MoveHead(EPositions _ePosition, memsize_s _nOffset = NULL);
		void MoveHead(memsize_s _nOffset, EPositions _ePosition = EPOSITION_CURRENT);

		memsize_s GetHeadPosition();
		memsize_s GetFileSize();
	};
}