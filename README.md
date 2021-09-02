# embeddedfun
Tinkering with code for use with embedded systems
##jcircularbuffer.hpp
This class file implements a templated circular buffer class of arbitrary size and data type.  It's useful for handling of streaming data coming in from embedded devices for processing data above and beyond what is available with driver-based buffers (eg UARTs, BT devices, IP based devices, or hardware sensors).
Methods:
###init(buffersize)
###bool consumeElement(out) : extracts an element and notifies if buffer is empty
###int consumeElements(vector out, int n) : extracts n elements into an output vector and returns n when the entire amount can be extracted, or x<n based on remaining buffer availability.
###bool writeElement(element) : adds element to vector and notifies if circular buffer is being overrun, data gets overwritten.
###int writeElements(vector in) : adds as many elements as possible up until a full buffer, and returns the number of elements added.
###int elementsCount() : returns # of elements in buffer                                                                                                                                                    
###int bufferSize() : returns size of buffer
###vector readOut() : nondestructively returns a linear vector containing the buffer from start to finish.                                                                                                                                                    
                                                                                                                                                    
