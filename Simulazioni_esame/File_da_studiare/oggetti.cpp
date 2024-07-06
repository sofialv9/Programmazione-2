// i metodi get sono sempre const
// es. string getTitolo() const {return titolo;}

// nelle classi con attributi allocati dinamicamente questi devono essere allocati nel costruttore e deallocati nel distruttore

// classe polimorfica = contiene attributi virtual

// classe alias = usa lo stesso costruttore della classe base
// es. using Torneo::Torneo;

// costruttore di copia = inizializza un oggetto a partire da un oggetto della stessa classe
// es. Book(const Book& book) : author{ "Copied " + book.author }, title{ "Copied " + book.title} {}

// Si può fare solo upcast (cast di un elemento di una classe derivata ad un elemento dela classe base), non downcast (viceversa)

// metodo virtuale puro (= metodo privo di implementazione)
// es. virtual string getLabel() const = 0;

// classe astratta = ha almeno un metodo virtuale puro - NON si può istanziare un OGGETTO di una classe astratta

// inserire uno switch in un do...while permette di continuare a prendere input dall'utente finché non inserisce un numero valido

// Ereditarietà virtuale: se ci sono più classi base (ereditarietà multipla) da cui si deriva uno stesso stato quest'ultimo viene derivato una sola volta (si eredità quello della classe base originaria)