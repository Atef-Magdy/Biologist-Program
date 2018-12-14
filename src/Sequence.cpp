#include "Sequence.h"
#include <iostream>

using namespace std;

Sequence::Sequence(){}

Sequence::Sequence(int length)
{
    /// Allocate a new position by take the length from the array which from the DNA or RNA or Protein contractors
    seq = new char [length+1];
    seq[length] = '\0';
}

char* Align(Sequence * s1, Sequence * s2)
{
    int m = strlen(s1->seq);
    int n = strlen(s2->seq);
    int L[m+1][n+1];
    int i, j;
    /// Looping To get the number of the common Longest string
    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
            L[i][j] = 0;

       else if (s1->seq[i-1] == s2->seq[j-1])
        {
            L[i][j] = L[i-1][j-1] + 1;
        }
       else
            L[i][j] = max(L[i-1][j], L[i][j-1]);
        }

   }
   /// Looping to get the common characters
    int Size=L[strlen(s1->seq)][strlen(s2->seq)];
    char* ResultString = new char[Size +1];       /// array to save the common characters
    ResultString[Size]='\0';

    int k=strlen(s1->seq),g=strlen(s2->seq);     /// To loop from the end to get the matching char

    while(k>0 && g>0){
            if(s1->seq[k-1]==s2->seq[g-1]){
                ResultString[Size-1]=s1->seq[k-1];
                k--;
                g--;
                Size--;
            }
            else if(L[k-1][g]>L[k][g-1]){
                k--;

            }
            else
                g--;
    }
    cout << "number of Longest Common Characters : " << L[m][n] << endl;
    delete[] L;
    return ResultString;
}
Sequence::~Sequence(){}
