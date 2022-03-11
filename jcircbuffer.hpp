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
Implements a circular buffer class to add, retrieve, and readout elements
of a declared length.  Buffer will overwrite when filled.
used for reading data.
 */

#pragma once
#include <iostream>
#include <vector>

template <class T>
class jCircularBuffer {

private:
	std::vector<T> buff;  //buffer
	int head;
	int maxElementCount;
	int elementsInBuffer;

	//move write and read index pointers and adjust buffer size
	bool advanceWriteIndex(void){
		//advance buffer pointer up to total filled count and roll over
		//or advance buffer pointer if filled...
		head++;
		head%= maxElementCount; //if overflow return to 0
		elementsInBuffer++;
		if(elementsInBuffer > maxElementCount)  {
			advanceReadIndex();
			return false;
		}
		return true;
	}

	bool advanceReadIndex(void)  {
		if (elementsInBuffer==0)  {
			return false;
		}
		else
		{
			elementsInBuffer--;
			return true;
		}
	}

	int retrieveReadIndex(void)  {
		if((head-elementsInBuffer) <0)
			return head-elementsInBuffer+maxElementCount;
		else return (head-elementsInBuffer);
	}


public:

	void init(unsigned int bufsize)   {
		maxElementCount=bufsize;
		head=0;
		elementsInBuffer=0;
		buff=std::vector<T>(bufsize);
	}

	//extract one element from circular buffer
	bool consumeElement(T& out)  {
		out = buff[retrieveReadIndex()];
		return advanceReadIndex();
		
	}

	//returns the number of elements read, if not the requested amount
	int consumeElements(std::vector<T>& out, int n)  {
		out=std::vector<T>(n);
		T temp;
		for(int i=0;i<n;i++)  {
			if(!consumeElement(temp))  {
				return i;
			}
			else  {
				out[i]=temp;
			}
		}

		return n;

	}

	//add single element	
	bool writeElement(T element)  {
		//returns false if buffer overwriting, true if not.
		buff[head]=element;
		return advanceWriteIndex();
	}

	//write as many elements as we want even if it overflows
	int writeElements(std::vector<T>& elements, bool &overflow)  {

		for(int i=0;i<elements.size();i++)  {
			overflow = writeElement(elements[i]);
		}
		return elements.size();
	}

	//returns buffer fill state
	int elementCount(void)  {
		return elementsInBuffer;
	}

	//returns buffer size
	int bufferSize(void) {
		return maxElementCount;
	}

	//reads out buffer without consuming values
	std::vector<T> readOut(void) {
		unsigned int toRead=elementCount();
		unsigned int i=retrieveReadIndex();
		std::vector<T> output(toRead);
		int j=retrieveReadIndex();
		for(int i=0;i< toRead; i++)  
		{	
			output[i]=buff[j];
			j++;
			j=j%maxElementCount;
		}
		return output;
	}

};