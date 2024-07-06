/*
    header file:
    - contiene le definizioni delle classi e i prototipi dei metodi
    - contiene le direttive:
        #ifndef persona_hpp
        #define persona_hpp
        -- programma --
        #endif /* persona_hpp */

/*
    Se si usano delle classi template nell'header file in esso si deve includere il file .cpp (prima di #endif) e non includere quest'ultimo nella compilazione (i metodi template sono risolti dal compilatore e non dal linker).
*/