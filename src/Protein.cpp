#include <bits/stdc++.h>
#include "Protein.h"
#include "CodonsTable.h"

using namespace std;

Protein::Protein()
{
    //ctor
}
void Protein:: Print()
{
    cout << "Protein Sequence is : ";
    for(int i=0 ; i<strlen(seq) ; i++) cout << seq[i];
    cout << endl;
    cout<<"Protein type is : ";
    if(type==Hormon) cout<< "Hormon" <<endl;
    if(type==Enzyme) cout<< "Enzyme" <<endl;
    if(type==TF) cout<< "TF" <<endl;
    if(type==Cellular_Function) cout<< "Cellular_Function" <<endl;
    cout << endl;
}
Protein::Protein(char* p , Protein_Type type):Sequence(strlen(p))
{
    this->type=type;
    for(int i=0 ; i<strlen(seq) ; i++) seq[i] = p[i];
}

DNA* Protein::GetDNAStrandsEncodingMe(const DNA & bigDNA)
{
    int index = 0;
    /// Make an array of DNA to store the sequences
    DNA * Arr = new DNA[20];
    for(int i=0 ; i<20 ; i++)
    {
        Arr[i].seq= new char[strlen(seq)*3 + 1];
        Arr[i].seq[strlen(seq)*3] = '\0';
    }
    /// Array to store a subset of The BigDNA to Compare with the protein sequence
    char * Compare = new char [strlen(seq)*3 +1];
    Compare[strlen(seq)*3] = '\0';


    CodonsTable T;
    for(int i=0 ; i<=(strlen(bigDNA.seq)-strlen(seq)*3); i++)
    {   /// Take a subset from the bigDNA
        for(int j=0 ; j<strlen(seq)*3 ; j++)
        {
            Compare[j] = bigDNA.seq[i+j];
        }
        DNA D(Compare , tail);
        RNA R;
        R.seq = new char[strlen(D.seq)+1];
        R.seq[strlen(D.seq)] = '\0';
        for(int i=0 ; i<strlen(D.seq) ; i++)
        {
            if(D.seq[i] == 'T') R.seq[i] = 'U';
            else R.seq[i] = D.seq[i];
        }
        Protein P;
        P = R.ConvertToProtein(T);
        /* ------- */
        bool flag = true;
        for(int k=0 ; k<strlen(seq) ; k++)
        {
            if(P.seq[k] != seq[k]){flag = false ; break;}
        }
        if(flag == true)
        {
            for(int g=0 ; g<strlen(seq)*3 ; g++){
                    Arr[index].seq[g] = bigDNA.seq[g+i];
            }
            i+=((strlen(seq)*3)-1);
            index += 1;
        }
    }
    Arr[index].seq[0] = '~';
    return Arr;
}
void Protein::Print(DNA* D)
{
    for(int i=0 ; i<20 ; i++)
    {
        if(D[i].seq[0] == '~') break;
        cout << "Probability Sequence : ";
        for(int j=0 ; j<strlen(D[0].seq) ; j++)
            {
                cout << D[i].seq[j];
            }
            cout << endl;
    }
}
Protein::~Protein()
{
}
