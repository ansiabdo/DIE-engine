#ifndef SCRIPTELF_H
#define SCRIPTELF_H

#include "scriptgeneric.h"
//#include "scriptbinary.h"
#include "../elffile.h"
//#include "dialogoptions.h"

class scriptELF : public scriptGeneric
{
    Q_OBJECT
public:
    explicit scriptELF(QObject *parent = 0);
    void setData(ELFFile *elffile);

    
public slots:
    QString getGeneralOptions();

    unsigned short getElfHeader_type();
    unsigned short getElfHeader_machine();
    unsigned int getElfHeader_version();
    unsigned int getElfHeader_entry();
    unsigned long long getElfHeader_entry64();
    unsigned int getElfHeader_phoff();
    unsigned long long getElfHeader_phoff64();
    unsigned int getElfHeader_shoff();
    unsigned long long getElfHeader_shoff64();
    unsigned int getElfHeader_flags();
    unsigned short getElfHeader_ehsize();
    unsigned short getElfHeader_phentsize();
    unsigned short getElfHeader_phnum();
    unsigned short getElfHeader_shentsize();
    unsigned short getElfHeader_shnum();
    unsigned short getElfHeader_shstrndx();

    bool compareEP(QString sSignature,unsigned int nOffset=0);
//    bool compareEPn(QString sSignature,unsigned int nOffset);
//    bool compareHeader(QString sSignature);
    bool compare(QString sSignature,unsigned int nOffset=0);
    QString getFileDirectory();
    QString getFileBaseName();
    QString getFileSuffix();
    QString getFileCompleteSuffix();
    unsigned int getSize();
    QString getString(unsigned int nOffset,unsigned int nSize=50);
    unsigned int readDword(unsigned int nOffset);
    unsigned short readWord(unsigned int nOffset);
    unsigned char readByte(unsigned int nOffset);
    int findByte(unsigned int nOffset, unsigned int nSize, unsigned char cValue);
    int findWord(unsigned int nOffset, unsigned int nSize, unsigned short sValue);
    int findDword(unsigned int nOffset, unsigned int nSize, unsigned int nValue);
    int findString(unsigned int nOffset, unsigned int nSize, QString sValue);
    int findSignature(unsigned int nOffset, unsigned int nSize, QString sSignature);
    bool isSignaturePresent(unsigned int nOffset, unsigned int nSize, QString sSignature);

//    bool compareReg(QString sSignature,unsigned int nOffset);

    bool isSectionNamePresent(QString sSectionName);
    bool isStringInTablePresent(QString sSectionName, QString sString);

    float calculateEntropy(unsigned int nOffset, unsigned int nSize);
    QString getSignature(unsigned int nOffset,unsigned int nSize);
    QString calculateMD5(unsigned int nOffset, unsigned int nSize);

    unsigned int getSectionFileOffset(int nSection);
    unsigned int getSectionFileSize(int nSection);
    int getSectionNumber(QString sSectionName);

    long long RVAToOffset(unsigned long long nRVA);
    long long VAToOffset(unsigned long long nVA);
    long long OffsetToVA(unsigned long long nOffset);
    long long OffsetToRVA(unsigned long long nOffset);

    unsigned int getProgramFileOffset(int nProgram);
    unsigned int getProgramFileSize(int nProgram);

    unsigned int getOverlaySize();
    unsigned int getOverlayOffset();
    bool isOverlayPresent();


    int getNumberOfSections();
    int getNumberOfPrograms();

    QString getSectionName(int nSection);


    bool compareOverlay(QString sSignature,unsigned int nOffset=0);

    long long getEntryPointOffset();
private:
    ELFFile *elffile;
};

#endif // SCRIPTELF_H
