//===============================================================
// File:	File.cpp
// Purpose: To Handle File IO
//===============================================================
#include "File.h"
using namespace Platform;

//---------------------------------------------------------------
File::File() 
	: m_eOpen(EOPEN_APPEND), m_eData(EDATA_BINARY), m_ePermissions(EPERMISSION_READ_WRITE)
{
	memset(m_szFilename, 0, sizeof(utf8) * FILENAME_MAX);
}

//---------------------------------------------------------------
File::File(const utf8 _szFilename[], EOpen _eOpen, EData _eData, EPermissions _ePermissons)
	: m_eOpen(_eOpen), m_eData(_eData), m_ePermissions(_ePermissons)
{
	strcpy_s(m_szFilename, sizeof(utf8) * FILENAME_MAX, _szFilename);
}

//---------------------------------------------------------------
File::~File()
{
	if(m_file.is_open())
		Close();
}

//---------------------------------------------------------------
void File::Open()
{
	std::ios_base::openmode Mode = NULL;
	Mode |= (m_eOpen == EOPEN_APPEND)				? std::ios_base::app	: NULL;
	Mode |= (m_eOpen == EOPEN_TRUNCATE)				? std::ios_base::trunc	: NULL;
	Mode |= (m_eData == EDATA_BINARY)				? std::ios_base::binary	: NULL;
	Mode |= (m_ePermissions & EPERMISSION_READ)		? std::ios_base::in		: NULL;
	Mode |= (m_ePermissions & EPERMISSION_WRITE)	? std::ios_base::out	: NULL;

	m_file = std::fstream(m_szFilename, Mode);
}

//---------------------------------------------------------------
void File::Close()
{
	m_file.close();
	m_file = std::fstream();
}

//---------------------------------------------------------------
void File::Read(memsize_u _nSize, void* _pData)
{
	if(m_file.is_open())
		m_file.read((char*)_pData, _nSize);
}

//---------------------------------------------------------------
void File::Write(memsize_u _nSize, void* _pData)
{
	if(m_file.is_open())
		m_file.write((char*)_pData, _nSize);
}

//---------------------------------------------------------------
void File::MoveReadHead(EPositions _ePosition, memsize_s _nOffset)
{
	m_file.seekg(_nOffset, (_ePosition == EPOSITION_BEGIN) ? std::ios_base::beg : ((_ePosition == EPOSITION_END) ? std::ios_base::end : std::ios_base::cur));
}

//---------------------------------------------------------------
void File::MoveReadHead(memsize_s _nOffset, EPositions _ePosition)
{
	MoveReadHead(_ePosition, _nOffset);
}

//---------------------------------------------------------------
void File::MoveWriteHead(EPositions _ePosition, memsize_s _nOffset)
{
	m_file.seekp(_nOffset, (_ePosition == EPOSITION_BEGIN) ? std::ios_base::beg : ((_ePosition == EPOSITION_END) ? std::ios_base::end : std::ios_base::cur));
}

//---------------------------------------------------------------
void File::MoveWriteHead(memsize_s _nOffset, EPositions _ePosition)
{
	MoveWriteHead(_ePosition, _nOffset);
}

//---------------------------------------------------------------
void File::MoveReadToWrite()
{
	MoveReadHead(GetWriteHead(), EPOSITION_BEGIN);
}

//---------------------------------------------------------------
void File::MoveWriteToRead()
{
	MoveWriteHead(GetReadHead(), EPOSITION_BEGIN);
}

//---------------------------------------------------------------
memsize_u File::GetReadHead()
{
	return m_file.tellg();
}

//---------------------------------------------------------------
memsize_u File::GetWriteHead()
{
	return m_file.tellp();
}

//---------------------------------------------------------------
memsize_u File::GetFileSize()
{
	// Cache Current Read Position
	memsize_u Cache = GetReadHead();
	memsize_u Size	= NULL;

	MoveReadHead(EPOSITION_END);
	Size = GetReadHead();
	MoveReadHead(EPOSITION_BEGIN, Cache);

	return Size;
}