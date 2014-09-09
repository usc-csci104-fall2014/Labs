#include <iostream>
#include <string>

using namespace std;

// taken from http://stackoverflow.com/questions/3381614/c-convert-string-to-hexadecimal-and-vice-versa
std::string string_to_hex(const string & input)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = input.length();

    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}

// recursive function to reverse a string
// you should start your debugging here with a breakpoint
string ReverseText(string & msg, int start = 0, int end = -1)
{
	if (end  ==  -1) end = msg.length() - 1;  // init case
	if (end < start) return msg;             // base case
	else
	{
		char hold  = msg[start];
		msg[start] = msg[end];
		msg[end]   = hold;
		return ReverseText(msg, start++, end--);
	}
}

// A simple loop-based decode function for string
string DecodeText(string & msg)
{
	size_t len = msg.length();
	for(size_t i = 0; i < len; ++i) msg[i] = msg[i] ^ 0x02;
	return msg;
}

// decodes a secret message
int main()
{	
	string secret = "novj,vgpagq]12`cn-q`cn-623kaqa|-wfg,aqw,daq/uuu--8rvvj";
	cout << "secret:  " << secret << endl;
	string rev = ReverseText(secret);
	cout << "Reverse: " << rev << endl;
	string msg = DecodeText(secret);
	cout << "Message: " << msg << endl;
	// cout << "Message: " << string_to_hex(msg) << endl;
	return 0;
}
