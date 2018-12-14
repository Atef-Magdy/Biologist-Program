#include <bits/stdc++.h>
#include "DNA.h"

using namespace std;

DNA::DNA()
{
    type=promoter;
}

DNA::DNA(char * seq, DNA_Type atype):Sequence(strlen(seq))
{
    /// translate the the char array to the parent class
    for(int i=0 ; i< strlen(seq) ; i++) this-> seq[i] = seq[i];
    type = atype;
}
void DNA::setStart(int S){startIndex = S;}
void DNA::setEnd(int E){endIndex = E;}

RNA DNA::ConvertToRNA()
{
    RNA r;
    r.seq = new char [(endIndex - startIndex +1)+1]; /// Object to store the new RNA sequence
    r.seq[(endIndex - startIndex +1)]='\0';

    for (int i = startIndex-1 ; i < endIndex ; i++){
            if(complementary_strand->seq[i]=='T') r.seq[i] = 'U';  /// Convert To RNA from the Complementary Strand
            else r.seq[i] = complementary_strand->seq[i];
    }
    return r;
}
void DNA::Print()
{
    cout << "DNA Sequence is : ";
    for (int i=0 ; i<strlen(seq) ; i++) cout << seq[i];
    cout << endl;
    cout<<"DNA type is : ";
    if(this->type==promoter) cout<< "promoter" <<endl;
    if(this->type==motif) cout<< "motif" <<endl;
    if(this->type==tail) cout<< "tail" <<endl;
    if(this->type==noncoding) cout<< "noncoding" <<endl;
    cout << endl;
}
void DNA::BuildComplementaryStrand()
{
    complementary_strand = new DNA;
    complementary_strand->seq= new char[strlen(seq)+1];   /// Allocate the Complementary Strand by the size of the first strand
    complementary_strand->seq[strlen(seq)] = '\0';
    for (int i=0 ; i<strlen(seq) ; i++)
    {
        if     (seq[i]=='A') complementary_strand->seq[i] = 'T';
        else if(seq[i]=='T') complementary_strand->seq[i] = 'A';
        else if(seq[i]=='G') complementary_strand->seq[i] = 'C';
        else if(seq[i]=='C') complementary_strand->seq[i] = 'G';
    }
    for(int i=0;i<strlen(seq)/2;++i)                          ///* Reversing the complementary strand to be used to process RNA
    {
        char temp= complementary_strand->seq[i];
        complementary_strand->seq[i]=complementary_strand->seq[strlen(seq)-1-i];
        complementary_strand->seq[strlen(seq)-1-i]=temp;
    }
}
void DNA::getComp()  /// Function To Show the complementary strand
{
    cout << "Complementary Strand is : ";
    for(int i=0 ; i<strlen(complementary_strand->seq) ; i++) cout << complementary_strand->seq[i];
    cout << endl;
}
DNA::~DNA(){}
