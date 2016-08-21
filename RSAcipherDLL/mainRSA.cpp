#include "RSACipher.h"
#include "Message.h"
#include <iostream>
#include <conio.h>

using namespace std;

int getE(int p, int q, int n) {
	int f, e;
	f = (p - 1)*(q - 1);

	for (e = 3; e < n; e++) {
		if (f%e == 0) {
			continue;
		}

		for (int i = 2; i < e; i++) {
			if (e%i == 0) {
				if (f%i == 0) {
					break;
				}
			}
		}
		break;
	}
	return e;
}

int getD(int p, int q, int e) {
	int f, d;
	f = (p - 1)*(q - 1);
	for (d = 1; (d * e) % f != 1; d++);
	return d;
}

extern "C" __declspec(dllexport) char* mainRSA(char* sentence, int p, int q)
{
	int n = 0;

	n = p * q;

	int e = getE(p, q, n);
	int d = getD(p, q, e);
	/*RSACipher cipher(&channel, e, n);
	cipher.InputMessage(Message(sentence));
	cout << cipher.doCipher().getUMessage() << endl;*/


	Cipher* myCipher = 0;

	int length = 0;
	for (int i = 0; i < 201; i++) {
		if (*(sentence + i) != 0) length++;
		else break;
	}
	char* newSentence = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		newSentence[i] = sentence[i];
	}
	newSentence[length] = '\0';
	myCipher = new RSACipher(e, n);
	Message myMessage(newSentence);
	
	Message ciphered = myCipher->doCipher(&myMessage);
	for (int i = 0; i < ciphered.getLength(); i++)
	{
		newSentence[i] = ciphered.getMessage()[i];
	}
	return newSentence;
	

	_getch();
	return 0;
}