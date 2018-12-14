#ifndef PROTEIN_H
#define PROTEIN_H
#include "Sequence.h"
#include "CodonsTable.h"
#include "RNA.h"
#include "DNA.h"

class DNA;
class RNA;

enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
  	private:
        Protein_Type type;
        CodonsTable table;
      public:
 	 	/// constructors and destructor
 	 	Protein();
 	 	Protein(char * p,Protein_Type type);
 	 	~Protein();
 	 	void Print(DNA* D);
 	 	void Print();
 	 	/// return an array of DNA sequences that can possibly
        /// generate that protein sequence
        DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA);

};


#endif // PROTEIN_H
