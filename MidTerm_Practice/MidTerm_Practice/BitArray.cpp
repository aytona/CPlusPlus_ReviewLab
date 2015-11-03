#include "Main.h"

void BitArrayTest()
{
	BitArray bitArray(16);
	std::cout << "Bit 2 = " << bitArray[2] << std::endl;
	std::cout << "Bit 3 = " << bitArray[3] << std::endl;
	std::cout << "Bit 14 = " << bitArray[14] << std::endl;
	bitArray.SetBit(2);
	bitArray.SetBit(14);
	std::cout << "SetBit: " << std::endl;
	std::cout << "Bit 2 = " << bitArray[2] << std::endl;
	std::cout << "Bit 3 = " << bitArray[3] << std::endl;
	std::cout << "Bit 14 = " << bitArray[14] << std::endl;
	bitArray.SetAllBits();
	std::cout << "SetAllBits: " << std::endl;
	std::cout << "Bit 2 = " << bitArray[2] << std::endl;
	std::cout << "Bit 3 = " << bitArray[3] << std::endl;
	std::cout << "Bit 14 = " << bitArray[14] << std::endl;
	bitArray.ClearAllBits();
	std::cout << "ClearAllBits: " << std::endl;
	std::cout << "Bit 2 = " << bitArray[2] << std::endl;
	std::cout << "Bit 3 = " << bitArray[3] << std::endl;
	std::cout << "Bit 14 = " << bitArray[14] << std::endl;
}