#pragma once
#include "Message.h"
class Cipher
{
private:
	Message sentence;
public:
	bool InputMessage(Message message);
	virtual Message doCipher(Message*) = 0;
	bool SendMessage(Message ciphered);
	Cipher(void);
	~Cipher(void);
protected:
	Message getSentence();
};

