#include <bits/stdc++.h>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"
#include "CodonsTable.h"

using namespace std;

bool check_DNA(string a);       ///* Function to check validation of DNA sequence.
bool check_RNA(string a);       ///* Function to check validation of RNA sequence.
bool check_Protein(string a);   ///* Function to check validation of Protein sequence.
string lower_case(string a);    ///* Convert string to lowercase letters, used in entering sequences types

int main()
{
    DNA D;
    RNA R;
    Protein P;
    CodonsTable T;
    int choice;
    bool loop = true;
    cout << "Ahlan Ya User Ya Hpipy." << endl;           ///* User interface
    cout << "What Do You want to do?" << endl;
    while(loop == true)
    {
        cout << "\n1-Enter DNA Sequence" <<endl;
        cout << "2-Enter RNA Sequence" <<endl;
        cout << "3-Enter Protein Sequence" <<endl;
        cout << "4-Align Two Sequence" <<endl;
        cout << "5-Exit" <<endl << endl;
        cout << "Enter The Choice : ";
        cin >> choice;
        cout << endl;
        /// First Choice
        if(choice == 1)
        {
            int first;
            string Seq;
            l:
            cout << "Enter Sequence : ";
            cin >> Seq;
            try
            {
                bool valid=check_DNA(Seq);                ///* checking if the sequence is valid i.e(contains 'A','C','G' and 'T' only)
                if(valid==0) throw 1;
            }
            catch (int x)
            {
                cout<<"Invalid DNA sequence!, press 1 to re-enter DNA sequence! : "; ///* if not valid throws and exception
                int z;
                cin>>z;
                if(z==1) goto l;
            }
            cout << endl;
            char* Array = new char[Seq.size()+1];        ///* assigning character array to sequence
            Array[Seq.size()] = '\0';
            for(int i=0 ; i<Seq.size() ; i++) Array[i] = Seq[i];
            map <string , DNA_Type > types;             ///* map with key string(user input) and enum type(value)
            types.insert(make_pair("promoter",promoter));
            types.insert(make_pair("tail",tail));
            types.insert(make_pair("motif",motif));
            types.insert(make_pair("noncoding",noncoding));
            string t;
            n:
            cout<<"Enter DNA type : ";
            cin>>t;
            cout << endl;
            try
            {                                          ///* throws an exception if the type is not valid
            if(lower_case(t)!="promoter" && lower_case(t)!="tail" && lower_case(t)!="motif" && lower_case(t)!="noncoding")
                throw 1;
            }
            catch(int x)
            {
                cout<<"Invalid DNA type, press 1 to re-enter type : ";
                int z;
                cin>>z;
                if(z==1) goto n;
            }
            DNA D(Array,types[t]);
            cout << "1-Convert To complementary Strand" << endl;
            cout << "2-Convert to RNA" << endl;
            cout << "3-Convert to Protein" << endl << endl;
            cout << "Enter Your Choice : ";
            cin >> first;
            cout << endl;
            if(first == 1)
            {
                D.BuildComplementaryStrand();
                D.getComp();
            }
            else if(first == 2)
            {
                int Start , End;
                cout << "Enter the Start Index of Converting : ";
                cin >> Start;
                cout << "Enter the End Index of Converting : ";
                cin >> End;
                cout << endl << endl;
                if(Start == -1 || End == -1 || Start < 0 || End > strlen(Array)){D.setStart(1); D.setEnd(strlen(Array));}
                else { D.setStart(1); D.setEnd(5);}
                D.BuildComplementaryStrand();
                R = D.ConvertToRNA();
                R.Print();
            }
            else if(first == 3)
            {
                D.BuildComplementaryStrand();
                D.setStart(1);
                D.setEnd(strlen(Array));
                R = D.ConvertToRNA();
                P = R.ConvertToProtein(T);
                P.Print();
            }
        }
        /// Second Choice
        else if(choice == 2)
        {
            int second;
            string Seq;
            k:
            cout << "Enter Sequence : ";
            cin >> Seq;
            try
            {
                bool valid=check_RNA(Seq);          ///* throws an exception if the RNA sequence is valid
                if(valid==0) throw 1;
            }
            catch(int x)
            {                                       ///* Asking user to re-enter Sequence
                cout<<"Invalid RNA sequence, Press 1 to re-enter RNA sequence : ";
                int z;
                cin>>z;
                if(z==1) goto k;
            }
            cout << endl;
            char* Array = new char[Seq.size()+1];    ///* assigning Array (char pointer) to sequence
            Array[Seq.size()] = '\0';
            for(int i=0 ; i<Seq.size() ; i++) Array[i] = Seq[i];
            map <string , RNA_Type > types;
            types.insert(make_pair("mrna",mRNA));            ///* map with key string (typer input by user) and enum values with types
            types.insert(make_pair("pre_mrna",pre_mRNA));
            types.insert(make_pair("mrna_exon",mRNA_exon));
            types.insert(make_pair("mrna_intron",mRNA_intron));
            string t;
            m:
            cout<<"Enter RNA type : ";
            cin>>t;
            cout << endl;
            try
            {                                                ///* throw exception is type is not valid
            if(lower_case(t)!="mrna" && lower_case(t)!="pre_mrna" && lower_case(t)!="mrna_exon" && lower_case(t)!="mrna_intron")
                throw 1;
            }
            catch(int x)
            {
                cout<<"Invalid DNA type, press 1 to re-enter type : ";
                int z;
                cin>>z;
                if(z==1) goto m;
            }
            RNA R(Array ,types[lower_case(t)]);
            DNA D;
            cout << "1-Convert To DNA" << endl;
            cout << "2-Convert To Protein" << endl << endl;
            cout << "Enter Your Choice : ";
            cin >> second;
            cout << endl;
            if(second == 1)
            {
                D = R.ConvertToDNA();
                D.Print();
            }
            else if(second == 2)
            {
                P = R.ConvertToProtein(T);
                P.Print();
            }
        }
        ///Third Choice
        else if (choice == 3)
        {
            int third;
            string Seq;
            h:
            cout << "Enter Sequence : ";
            cin >> Seq;
            try
            {                                          ///* throws exception if Protein sequence is not valid
                bool valid=check_Protein(Seq);
                if(valid==0) throw 1;
            }
            catch(int x)
            {
                cout<<"Invalid Protein Sequence, Press 1 to re-enter sequence : ";
                int z;
                cin>>z;
                if(z==1)
                {
                    goto  h;
                }
            }
            cout << endl;
            char* Array = new char[Seq.size()+1];
            Array[Seq.size()] = '\0';
            for(int i=0 ; i<Seq.size() ; i++) Array[i] = Seq[i];
            map <string , Protein_Type > types;                  ///* map with key strings(types entered by user) and enum values with protein types
            types.insert(make_pair("hormone",Hormon));
            types.insert(make_pair("enzyme",Enzyme));
            types.insert(make_pair("tf",TF));
            types.insert(make_pair("cellular_function",Cellular_Function));
            string t;
            b:
            cout<<"Enter Protein type : ";
            cin>>t;
            cout << endl;
            try
            {                                                    ///* throws an exception if protein type is not valid
            if(lower_case(t)!="hormon" && lower_case(t)!="enzyme" && lower_case(t)!="tf" && lower_case(t)!="cellular_function")
                throw 1;
            }
            catch(int x)
            {
                cout<<"Invalid Protein type, press 1 to re-enter type : ";
                int z;
                cin>>z;
                if(z==1) goto b;
            }
            Protein P(Array , types[lower_case(t)]);
            P.Print();
            cout << "1-Convert to DNA" << endl << endl;
            cout << "Enter Your Choice : ";
            cin >> third;
            cout << endl;
            if(third)
            {
                Protein ob;
                char BigDNA[] =
                {'A','A','A','G','A','A','G','T','T','T','G','A','A','G','T','T','T','A','A','A','A','A','G','C','C','C','C','T',
                'C','C','G','A','T','T','C','A','T','C','A','A','G','C','C','C','A','T','T','T','T','C','A','A','C','G','T','G','C',
                'A','C','\0'};
                DNA bigDNA(BigDNA , promoter);
                ob.Print(P.GetDNAStrandsEncodingMe(bigDNA));
            }
        }
        else if(choice == 4)
        {
            string Seq1 , Seq2;
            /// Take Sequence one and put it in DNA as template
            g:
            cout << "Enter Sequence 1 : ";
            cin >> Seq1;
            try
            {
                bool valid=check_DNA(Seq1);
                if(valid==0) throw 1;
            }
            catch(int x)
            {
                cout<<"Invalid DNA Sequence(1), press 1 to re-enter Sequence(1) : ";
                int z;
                cin>>z;
                if(z==1)
                    goto g;
            }
            cout << endl;
            char* Array1 = new char[Seq1.size()+1];
            Array1[Seq1.size()] = '\0';
            for(int i=0 ; i<Seq1.size() ; i++) Array1[i] = Seq1[i];

            /// Take Sequence two and put it in DNA as template
            f:
            cout << "Enter Sequence 2 : ";
            cin >> Seq2;
            try
            {
                bool valid=check_DNA(Seq2);
                if(valid==0) throw 1;
            }
            catch(int x)
            {
                cout<<"Invalid DNA Sequence(2), press 1 to re-enter Sequence(2) : ";
                int z;
                cin>>z;
                if(z==1)
                    goto f;
            }
            cout << endl;
            char* Array2 = new char[Seq2.size()+1];
            Array2[Seq2.size()] = '\0';
            for(int i=0 ; i<Seq2.size() ; i++) Array2[i] = Seq2[i];

            /// Save them in DNA sequence as template
            Sequence * d1 = new DNA(Array1 , promoter);
            Sequence * d2 = new DNA(Array2 , promoter);

            char* result = Align(d1 , d2);
            cout << "Common Characters : ";
            for(int i=0 ; i<strlen(result) ; i++) cout << result[i];
            cout << endl;
        }
        else if (choice == 5) loop = false;
    }
    return 0;
}

bool check_DNA(string a)
{
    for(int i=0;i<a.size();++i)
    {
        if(a[i]!='A' && a[i]!='C' && a[i]!='G' && a[i]!='T') ///* The only letters allowed in DNA
            return false;                                    ///* Returning False if an invalid letter is found!
    }
    return true;
}
bool check_RNA(string a)
{
    for(int i=0;i<a.size();++i)
    {
        if(a[i]!='U' && a[i]!='C' && a[i]!='G' && a[i]!='A') ///* The allowed letters in RNA
            return false;                                    ///* Return false if an invalid letter is found
    }
    return true;
}
bool check_Protein(string a)
{
    for(int i=0;i<a.size();++i)
    {
        if(a[i]!='K' && a[i]!='T' && a[i]!='N' && a[i]!='R' && a[i]!='S' && a[i]!='I' && a[i]!='M' && a[i]!='Q'
           && a[i]!='H' && a[i]!='P' && a[i]!='L' && a[i]!='E' && a[i]!='D' && a[i]!='A' && a[i]!='G' && a[i]!='V'
           && a[i]!='Y' && a[i]!='C' && a[i]!='W' && a[i]!='F')
            return false;
    }
    return true;
}
string lower_case(string a)
{
    for(int i=0;i<a.size();++i)
    {
        if(isalpha(a[i]) && isupper(a[i]))
        {
            a[i]=tolower(a[i]);
        }
        else
        {
            a[i]=a[i];
        }
    }
    return a;
}
