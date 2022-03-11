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


int main(void) {
	bool overflow;
	static constexpr unsigned int buffsize=10;
	jCircularBuffer<int> myBuff = jCircularBuffer<int>();
	myBuff.init(buffsize);
	for(int i=0;i<15;i++)  {
		myBuff.writeElement(i);
	}
	std::cout << "element count " << myBuff.elementCount() << "\n";
	std::vector<int> output = myBuff.readOut();
	for(std::vector<int>::iterator it=output.begin(); it !=output.end();++it)  {
		std::cout << *it << " ";
	}
	std::cout << "\n";
	std::cout << "output: ";
	for(int i=0; i<buffsize+20;i++)
	{
		int temp;
		if(myBuff.consumeElement(temp))
			std::cout << temp << " ";
		else std::cout << " empty ";
	}
	std::cout << "\n";



	for(int i=15;i<25;i++)  {
		myBuff.writeElement(i);
	}
	std::cout << "element count " << myBuff.elementCount() << "\n";
	output = myBuff.readOut();
	for(std::vector<int>::iterator it=output.begin(); it !=output.end();++it)  {
		std::cout << *it << " ";
	}
	std::cout << "\n";
	std::cout << "output: ";
	for(int i=0; i<buffsize+20;i++)
	{
		int temp;
		if(myBuff.consumeElement(temp))
			std::cout << temp << " ";
		else std::cout << " empty ";
	}
	std::cout << "\n";


	for(int i=25;i<40;i++)  {
		myBuff.writeElement(i);
	}
	std::cout << "element count " << myBuff.elementCount() << "\n";
	output = myBuff.readOut();
	for(std::vector<int>::iterator it=output.begin(); it !=output.end();++it)  {
		std::cout << *it << " ";
	}
	std::cout << "\n";

	std::cout << " read multiple: req 4: actual: " << myBuff.consumeElements(output, 4) << "\n";
		for(std::vector<int>::iterator it=output.begin(); it !=output.end();++it)  {
		std::cout << *it << " ";
	}
	std::cout << "\n";

	std::cout << " read multiple: req 16: actual: " << myBuff.consumeElements(output, 16) << "\n";
		for(std::vector<int>::iterator it=output.begin(); it !=output.end();++it)  {
		std::cout << *it << " ";
	}
	std::cout << "\n";

	std::cout << " read multiple: req 16: actual: " << myBuff.consumeElements(output, 16) << "\n";
		for(std::vector<int>::iterator it=output.begin(); it !=output.end();++it)  {
		std::cout << *it << " ";
	}
	std::cout << "\n";




	std::cout << "circular buffer size after consuming: " << myBuff.bufferSize() << "\n";

	std::cout << "current element count after consuming: " << myBuff.elementCount() << "\n";




	std:: cout << "adding 4 more\n";

	for(int i=40;i<44;i++)  {
		myBuff.writeElement(i);
	}

	std::cout << "circular buffer size: " << myBuff.bufferSize() << "\n";

	std::cout << "current element count: " << myBuff.elementCount() << "\n";

	std::cout << "readout of filled buffer before loading tests:\n";
	std::vector<int> output4 = myBuff.readOut();
	for(std::vector<int>::iterator it=output4.begin(); it !=output4.end();++it)  {
		std::cout << *it << " ";
	}
	std::cout << "\n";

	std::cout << "loading another 4 which should be successful: " << myBuff.writeElements(output4, overflow) << "\n";


	std::cout << "circular buffer size: " << myBuff.bufferSize() << "\n";

	std::cout << "current element count after adding 4 more: " << myBuff.elementCount() << "\n";

	std::cout << "readout of filled buffer again\n";
	std::vector<int> output5 = myBuff.readOut();
	for(std::vector<int>::iterator it=output5.begin(); it !=output5.end();++it)  {
		std::cout << *it << " ";
	}

	std::cout << "current element count after readout should be 8  " << myBuff.elementCount() << "\n";
	std::cout << "loading another 8 which should only allow 2 for total of 10 with 2 loaded: " << myBuff.writeElements(output5,overflow) << "\n";
	std::cout << "current element count after load should be 10  " << myBuff.elementCount() << "\n";



	std::cout << " consumed multiple: req 16: actual: " << myBuff.consumeElements(output, 16) << "\n";
	for(std::vector<int>::iterator it=output.begin(); it !=output.end();++it)  {
		std::cout << *it << " ";
	}
	std::cout << "\n";

	std::cout << "circular buffer size after consuming: " << myBuff.bufferSize() << "\n";
	std::cout << "current element count after consuming: " << myBuff.elementCount() << "\n";
	std::cout << "loading another 16 which should only allow 10 for total of 10 with 10 loaded: " << myBuff.writeElements(output,overflow) << "\n";
	std::cout << "current element count after load should be 10  " << myBuff.elementCount() << "\n";
	std::cout << "\n";

	std::cout << "readout of final filled buffer again\n";
	std::vector<int> output6 = myBuff.readOut();
	for(std::vector<int>::iterator it=output6.begin(); it !=output6.end();++it)  {
		std::cout << *it << " ";
	}
	std::cout << "\n";




	return 0;
}