#include <bits/stdc++.h>
#include "RNA.h"
#include "DNA.h"
#include "Protein.h"
#include "CodonsTable.h"

using namespace std;

class DNA;

RNA::RNA()
{
    type = mRNA;
}

RNA::RNA(char * seq, RNA_Type atype):Sequence(strlen(seq))
{
    /// translate the the char array to the parent class
    for(int i=0 ; i< strlen(seq) ; i++) this-> seq[i] = seq[i];
    type = atype;
}
void RNA::Print()
{
    cout << "RNA Sequence is : ";
    for (int i=0 ; i<strlen(seq) ; i++) cout << seq[i];
    cout << endl;
    cout<<"RNA type is : ";
    if(type==mRNA) cout<< "mRNA" <<endl;
    if(type==pre_mRNA) cout<< "pre_mRNA" <<endl;
    if(type==mRNA_exon) cout<< "mRNA_exon" <<endl;
    if(type==mRNA_intron) cout<< "mRNA_intron" <<endl;
    cout << endl;
}
DNA RNA::ConvertToDNA()
{
    DNA d;
    d.seq = new char [(strlen(seq))+1];  /// Object to store the new DNA sequence
    d.seq[strlen(seq)] = '\0';
    for (int i = 0 ; i<strlen(seq) ; i++){
        if(seq[i]=='U') d.seq[i] = 'T';
        else d.seq[i] = seq[i];
    }
    return d;
}
Protein RNA::ConvertToProtein(const CodonsTable & table)
{
    int index = 0;
    Protein p;
    p.seq = new char[(strlen(seq)/3)+1];     ///Allocate a new array by size/3 as every protein is equal to 3 char of RNA
    p.seq[(strlen(seq)/3)] = '\0';
    for (int i=0 ; i<(strlen(seq)) ; i+=3)    /// Check every 3 char is equal an amino acid or not by the codons table
    {
        for(int j=0 ; j<64 ; j++)
        {
            if(seq[i]==table.codons[j].value[0] && seq[i+1]==table.codons[j].value[1] && seq[i+2]==table.codons[j].value[2]){
                p.seq[index] = table.codons[j].AminoAcid;
                index++;
            }
        }
    }
    return p;
}
RNA::~RNA(){}
