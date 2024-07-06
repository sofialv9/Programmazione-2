#include "periodical.h"

// classe derivata da Periodical in cui l'unica differenza è che la frequenza è settata a 7
class Weekly : public Periodical
{
  public:
	  Weekly(string author, string title) : Periodical(author, title, 7) {}	  

};