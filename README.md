# embeddedfun<br>
Tinkering with code for use with embedded systems<br>
## jcircularbuffer.hpp<br>
This class file implements a templated circular buffer class of arbitrary size and data type.  It's useful for handling of streaming data coming in from embedded devices for processing data above and beyond what is available with driver-based buffers (eg UARTs, BT devices, IP based devices, or hardware sensors).
Methods:
##### init(buffersize)<br>
##### bool consumeElement(out) : extracts an element and notifies if buffer is empty<br>
##### int consumeElements(vector out, int n) : extracts n elements into an output vector and returns n when the entire amount can be extracted, or x<n based on remaining buffer availability.<br>
##### bool writeElement(element) : adds element to vector and notifies if circular buffer is being overrun, data gets overwritten.<br>
##### int writeElements(vector in) : adds as many elements as possible up until a full buffer, and returns the number of elements added.<br>
##### int elementsCount() : returns # of elements in buffer.<br>                                                                                                                                                
##### int bufferSize() : returns size of buffer.<br>
##### vector readOut() : nondestructively returns a linear vector containing the buffer from start to finish.<br>                                                                                                                                                 
                                                                                                                                                    
