/*
MIT License

Copyright (c) 2021 Eyebotix,LLC (Josh Karch)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Description: 
Test code for the circular buffer tester class.
 */

#include "jcircbuffer.hpp"

// quick compile:
//g++ jcircbuffertester2.cpp -std=c++11 -o ./buffertest
int main(void) {
	bool overflow;
	static constexpr unsigned int buffsize=25;
	jCircularBuffer<int> myBuff = jCircularBuffer<int>();
	myBuff.init(buffsize);
	std::vector<int> rxbuf(buffsize);
	std::vector<int> rxbuf2(2 * buffsize);
	

	
	std::vector<int> b1({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29});
	std::vector<int> b2({42});
	std::vector<int> b3({55,9000});

	myBuff.writeElements(b1, overflow); 
	std::vector<int> output = myBuff.readOut();
	for(std::vector<int>::iterator it=output.begin(); it !=output.end();++it)  {
		std::cout << *it << " ";
	}
	std::cout << "\n";


	std::cout << " consumed multiple: req 25: actual: " << myBuff.consumeElements(rxbuf, buffsize) << "\n";
	for(std::vector<int>::iterator it=rxbuf.begin(); it !=rxbuf.end();++it)  {
		std::cout << *it << " ";
	}
	std::cout << "\n";




	myBuff.writeElements(b3, overflow); 
	myBuff.writeElements(b1, overflow); 
	myBuff.writeElements(b2, overflow); 
	myBuff.writeElements(b3, overflow); 
	myBuff.writeElements(b3, overflow);
	myBuff.writeElements(b3, overflow);
	myBuff.writeElements(b3, overflow);
	myBuff.writeElements(b3, overflow);
	myBuff.writeElements(b3, overflow);

	output = myBuff.readOut();
	std::cout << "readout:\n";
	for(std::vector<int>::iterator it=output.begin(); it !=output.end();++it)  {
		std::cout << *it << " ";
	}
	std::cout << "\n";

	std::cout << " consumed multiple: req 25: actual: " << myBuff.consumeElements(rxbuf2, buffsize*2) << "\n";
	for(std::vector<int>::iterator it=rxbuf2.begin(); it !=rxbuf2.end();++it)  {
		std::cout << *it << " ";
	}
	std::cout << "\n";


	myBuff.writeElements(b2, overflow);
	myBuff.writeElements(b3, overflow);
	output = myBuff.readOut();
	for(std::vector<int>::iterator it=output.begin(); it !=output.end();++it)  {
		std::cout << *it << " ";
	}
	std::cout << "\n";
	std::cout << " consumed multiple: req 25: actual: " << myBuff.consumeElements(rxbuf2, buffsize*2) << "\n";
	for(std::vector<int>::iterator it=rxbuf2.begin(); it !=rxbuf2.end();++it)  {
		std::cout << *it << " ";
	}
	std::cout << "\n";





	return 0;
}