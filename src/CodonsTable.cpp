#include "CodonsTable.h"
#include <iostream>
#include <fstream>


using namespace std;

CodonsTable::CodonsTable()
{
    LoadCodonsFromFile("codons.txt");
}

void CodonsTable :: LoadCodonsFromFile(string codonsFileName)
{
    ifstream read(codonsFileName.c_str());
    string code;
    char p;
    for(int i=0;i<64;++i)
    {
        read>>code;
        read>>p;
        for(int j=0;j<3;++j)
        {
            codons[i].value[j]=code[j];
        }
        codons[i].value[3]='\0';
        if(p == '-') codons[i].AminoAcid = '\0';
        else codons[i].AminoAcid=p;

    }
}
void CodonsTable::Print(){}
Codon CodonsTable:: getAminoAcid(char * value)
{
    for(int i=0; i<64; i++)
    {
        if((value[0] == codons[i].value[0]) && (value[1] == codons[i].value[1]) && (value[2] == codons[i].value[2]))
        {
            return codons[i];
        }
    }
    cout << "Not Found" << endl;
}
void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{
    for(int i=0; i<3; i++)
    {
        codons[index].value[i] = value[i];
    }
    codons[index].value[3] = '\0';
    codons[index].AminoAcid = AminoAcid;
}
bool CodonsTable::isValid(char a)
{
    for(int j=0; j<64; j++)
    {
        if(a == codons[j].AminoAcid)
        {
            return true;
        }
    }
    return false;
}
CodonsTable::~CodonsTable()
{
}
