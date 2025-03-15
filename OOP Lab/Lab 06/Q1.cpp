#include <iostream>
#include <string>
using namespace std;

class Message
{
    string messageContent;

public:
    Message() : messageContent("") {}
    Message(string m) : messageContent(m) {}

    void setString(const string &s) { messageContent = s; }
    string toString() const { return messageContent; }
    string getString() const { return messageContent; }
};

class SMS : public Message
{
    string recipientContactNo;

public:
    SMS(string n, string m) : Message(m)
    {
        recipientContactNo = n;
    }

    void setContactNo(const string &number) { recipientContactNo = number; }
    string getContactNo() const { return recipientContactNo; }
    string toString() const
    {
        return "To: " + recipientContactNo + " | Message: " + Message::toString();
    }
};

class Email : public Message
{
    string sender;
    string receiver;
    string subject;

public:
    Email(string s, string r, string sub, string m) : Message(m)
    {
        sender = s;
        receiver = r;
        subject = sub;
    }

    void setSender(const string &s) { sender = s; }
    void setReceiver(const string &r) { receiver = r; }
    void setSubject(const string &sub) { subject = sub; }
    string getSender() const { return sender; }
    string getReceiver() const { return receiver; }
    string getSubject() const { return subject; }
    string toString() const
    {
        return "Sender: " + sender + " | Receiver: " + receiver + " | Subject: " + subject + " | Message: " + Message::toString();
    }
};

bool ContainsKeyword(const Message &messageObject, const string &keyword)
{
    string text = messageObject.toString();
    string word = "";

    for (int i = 0; i < text.length(); i++) {
        if (isspace(text[i]) || ispunct(text[i])) {
            if (word == keyword) {
                return true;
            }
            word = "";
        }
        else {
            word += text[i];
        }
    }
    return word == keyword;
}

string EncodeMessage(const string &text)
{
    string encodedText = text;
    for (int i = 0; i < encodedText.length(); i++)
    {
        if ((encodedText[i] >= 'A' && encodedText[i] < 'Z') || (encodedText[i] >= 'a' && encodedText[i] < 'z'))
        {
            encodedText[i] += 1;
        }
        else if (encodedText[i] == 'Z')
        {
            encodedText[i] = 'A';
        }
        else if (encodedText[i] == 'z')
        {
            encodedText[i] = 'a';
        }
    }
    return encodedText;
}

int main()
{
    Message msg("Ramadan Mubarak bro!");
    cout << "Message: " << msg.toString() << endl << endl;

    SMS sms("0333-3214569", "Hello, how are you?");
    cout << "SMS: " << endl << sms.toString() << endl << endl;

    Email email("ahmedrza@gmail.com", "karimfaisal@gmail.com", "Project Update", "Online meeting at 5 PM");
    cout << "Email: " << endl << email.toString() << endl << endl;

    cout << "Message contains 'Eid': " << (ContainsKeyword(msg, "Eid") ? "Yes" : "No") << endl;
    cout << "SMS contains 'how': " << (ContainsKeyword(sms, "how") ? "Yes" : "No") << endl;
    cout << "Email contains 'meeting': " << (ContainsKeyword(email, "Meeting") ? "Yes" : "No") << endl << endl;

    cout << "Encoded Message: " << EncodeMessage(msg.getString()) << endl;
    cout << "Encoded SMS: " << EncodeMessage(sms.getString()) << endl;
    cout << "Encoded Email: " << EncodeMessage(email.getString()) << endl;

    return 0;
}
