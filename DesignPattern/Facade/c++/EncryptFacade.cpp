#include <iostream>
#include <string>


using std::endl;
using std::cout;
using std::string;


namespace FacadeSample
{

class FileReader
{
public:
    FileReader()
    {
        cout << "创建FileReader" << endl;
    }

    ~FileReader()
    {
        cout << "FileReader bye" << endl;
    }

    string Read(string fileNameSrc)
    {
        return "要加密的字符";
    }

};

class FileWriter
{
public:
    FileWriter()
    {
        cout << "创建FileWriter" << endl;
    }

    ~FileWriter()
    {
        cout << "FileWriter bye" << endl;

    }

    void Write(string encryptedText, string fileNameDes)
    {
        cout << " 写入密文：" << encryptedText << endl;
    }
};

class CipherMachine
{
public:
    CipherMachine()
    {
        cout << "创建CipherMachine" << endl;
    }
    ~CipherMachine()
    {
        cout << "CipherMachine bye" << endl;
    }

    string Encrypt(string painText)
    {
        return "我是加密后的文字2333";
    }
};

class EncryptFacadeInterfase
{
public:
    virtual void FileEncrypt(string fileNameSrc, string fileNameDes) = 0;
    virtual ~EncryptFacadeInterfase() {};
};

class EncryptFacade:public EncryptFacadeInterfase
{
public:
    EncryptFacade()
    {
        cout << "创建EncryptFacade" << endl;
    }

    ~EncryptFacade()
    {
        cout << "EncryptFacade bye" << endl;
    }

    void FileEncrypt(string fileNameSrc, string fileNameDes)
    {
        string plainText = mReader.Read(fileNameSrc);
        string result = mCipher.Encrypt(plainText);
        mWriter.Write(result, fileNameDes);
    }

private:
    FileReader mReader;
    FileWriter mWriter;
    CipherMachine mCipher;
};

}; // namespace FacadeSample

int main()
{
    FacadeSample::EncryptFacadeInterfase *ef = new FacadeSample::EncryptFacade();
    ef->FileEncrypt("zheli", "nali");
    delete ef;
    return 0;
}