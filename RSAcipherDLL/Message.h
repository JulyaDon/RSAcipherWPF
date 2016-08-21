#pragma once
class Message
{
private:
	int length;
	char* message; //��������� �� ������ � ����������
	Message(); //����������� �� ���������. ��������� ��� ������������ ����� ��������� � ������ private.
	void setMessage(char* message); //����� ������ ���������
public:
	char* getMessage() const; //����� ��������� ���������
	unsigned char* getUMessage() const;
	int getLength() const;
	Message(char* message); //�����������. ��������� ������ ���������.
	Message(unsigned char* message);
	Message(const Message &); //����������� �����������
	~Message();
	Message operator=(Message message);
};


