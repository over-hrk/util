#pragma once
#include <cstdint>

class BitwiseReader
{
private:
	int m_iBitCounter;
	uint8_t *m_pBuffer;
	int readOneBit();

public:
	BitwiseReader();
	~BitwiseReader();
	void setBuffer(void* buf);
	int readBits(int size);
};

