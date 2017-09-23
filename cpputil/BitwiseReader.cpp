#include "BitwiseReader.h"


int BitwiseReader::readOneBit()
{
	const auto iByteCnt = m_iBitCounter >> 3;		  // m_iBitCounter / 8
	const auto iBitCnt = m_iBitCounter & 0b00000111;  // m_iBitCounter % 8

	int value = m_pBuffer[iByteCnt] & (1 << iBitCnt);

	m_iBitCounter++;

	return value >> iBitCnt;
}

BitwiseReader::BitwiseReader()
	: m_iBitCounter(0)
	, m_pBuffer(nullptr)
{
}


BitwiseReader::~BitwiseReader()
{
	m_iBitCounter = 0;
	m_pBuffer = nullptr;
}

void BitwiseReader::setBuffer(void * buf)
{
	m_pBuffer = static_cast<uint8_t*>(buf);
	m_iBitCounter = 0;
}

int BitwiseReader::readBits(int size)
{
	int value = 0;

	for (int i = 0; i < size; i++)
	{
		int bin = readOneBit();
		value |= (bin << i);
	}

	return value;
}
