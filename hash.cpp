
#include "hash.h"

HashMap::HashMap(int size) 
{
   this->size = size;         
   table = new Entry*[size];            
   for (int i = 0; i < size; i++)                  
   table[i] = NULL;
}
HashMap::~HashMap() 
{
  for (int i = 0; i < size; i++)                  
   if (table[i] != NULL)                        
        delete table[i];            
	delete[] table;      

}

unsigned long HashMap::hash(string str)
 {
       const char* cstr = str.c_str();
	unsigned long hash = 5381; 
	int c; 
	while (c = *cstr++)
		hash = hash * 33 + c;
	return hash;

 }

void HashMap:: put(Entry *e)
{ 
 	string key = e->getKey();       
	int index = hash(key) % size;            
	int startIndex = index;            
	while (table[index] != NULL && table[index]->getKey() != key && table[index]->getKey() != "empty") {          
		index = (index + 1) % size;
		if(index == startIndex) throw Overflow();
	}
	table[index] = e;

}
Entry* HashMap::get(string key)
{
 int index = hash(key) % size;           
	int startIndex = index;            
	while (table[index] != NULL && table[index]->getKey() != key) {                  
		index = (index + 1) % size;                  
		if(index == startIndex)	return NULL;            
	}            
	return table[index];

}

Entry* HashMap:: remove(string key)
{
  int index = hash(key) % size;           
	int startIndex = index;            
	while (table[index] != NULL && table[index]->getKey() != key) {                  
		index = (index + 1) % size;                  
		if(index == startIndex)	return NULL;            
	}            
	Entry *e = table[index];
	delete e;
	table[index] = new Entry("empty", 0, 0);
	return e; 

}



