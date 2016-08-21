#pragma once
#include "Cipher.h"
#include "Message.h"
class RSACipher:
	public Cipher
{
public:
	Message doCipher(Message*);
	RSACipher(int e, int n);
	~RSACipher();
private:
	int e, n;
	int powMod(int b, int e, int mod);
	RSACipher();
};

