#ifndef CIRCULAR_LINKED_LIST
#define CIRCULAR_LINKED_LIST

template < typename T >
class NodeC {
    public:
    T data;
	NodeC < T > * next ;
    NodeC();
    NodeC(T data);
} ;

template < typename T >
class Circular_Linked_List
{
    public:
    NodeC<T>* head = nullptr;
    Circular_Linked_List();
    ~Circular_Linked_List();
    void insertElement( T element );  
    bool isEmpty( );
    
};

#endif
