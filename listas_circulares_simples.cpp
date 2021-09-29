//Listas circulares simplemente enlazadas
//INTEGRANTES
//Bejar Roman Katherine Nikole
//Soto Begazo Juan Manuel
//Deza Cuela Miguel Angel

#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class Node
{
	public:
		T Data; 
		Node<T>* Next;
	public:
		Node(T d){
            Data = d;
            Next = nullptr;
        }
};

template <typename T>
class SimpleCircularList{
    private:
        Node<T>* Head;
        Node<T>* Last;
    public:
        SimpleCircularList(): Last{nullptr}, Head{nullptr}{}

        // agregar elementos al inicio de la lista
        void push_front(T d){   
            Node<T> *tmp = new Node<T> (d);
            tmp -> Next = nullptr;
            if (!Head) {
                Last = Head = tmp;
                Last -> Next = Head;
            }
            else {
                tmp -> Next = Head;
                Last -> Next = tmp;
                Head = tmp;
            }
        }

        // agregar elementos al final de la lista
        void push_back(T d){
            Node<T> *tmp = new Node<T> (d);
            tmp -> Next = nullptr;
            if (!Head) {
                tmp -> Next = tmp;
                Last = Head = tmp;
            }
            else {
                tmp -> Next = Head;
                Last -> Next = tmp;
                Last = tmp;
                Last -> Next = Head;  
            }
        }

        //agregar un elemento en una posicion
        void push_position(T d, int P) {
            if ((P < 1 || P > NumeroNodos()+1)){
                cout << "No existe esa posicion ";
            }

            if (P == 1) {
                push_front(d); return; 
            }

            if (P == NumeroNodos()+1) {
                push_front(d); return;
            }

            Node<T> *tmp = Head;
            for(int i = 2; i < P; i++)
                tmp = tmp -> Next;
            Node<T> *nuevo = new Node<T> (d);
            nuevo -> Next = tmp -> Next;
            tmp -> Next = nuevo;
        }
  
        //encontrar elemento
        bool find_iterative(T d){
            Node<T> * tmp = Last -> Next;
            while(tmp != Last) { 
                if( tmp -> Data == d) 
                    return true; 
                tmp = tmp -> Next;            
            } 
            if(tmp == Last) {
                if( tmp -> Data == d) 
                    return true; 
                return false;  
            }
            return false;      
        } 


        
        //Encontrar elemento de la lista de manera recursiva
        bool findRecursivo(Node<T> *tmp, T d){
            //if (tmp != Last) break;
            if (tmp -> Data == d)
                return true;
            if (tmp -> Data == Last -> Data)
                return true;
            return this -> findRecursivo(tmp -> Next, d);
        }      
        bool mostrarfindRecursivo(T d){
           return this->findRecursivo(this -> Last -> Next, d);
        }


        T max_iterative(){
            Node<T>* tmp = Head;
            int mayor = 0;
            while(tmp != Last){ 
                if(tmp -> Data > mayor){
                    mayor = tmp -> Data;
                }
                tmp = tmp -> Next;
            } 
            if(Last -> Data >= mayor){
                mayor = Last -> Data;
            }
            return mayor;
        }


        //Contar pares iterativa
        int count_iterative_even()
        {
            int counter {0};
            Node<T> *tmp = Last -> Next;
            while (tmp != Last ) {
                if (tmp -> Data % 2 == 0)
                    counter++;
                tmp = tmp -> Next;
            }
            if (tmp == Last) {
                if (tmp -> Data % 2 == 0)
                    counter++;
            }
            return counter;
        }


        //Contar pares recursiva
        /*int count_recursive_even(){
            Node<T>* tmp = Head;
            int counter = 0;
            if (!Head) return counter;
            if (Head -> Data % 2 == 0) counter++;
            return count_recursive_even(tmp->m_pSig, counter);
        }*/



        // impresion de la lista iterativa
        void print_iterative()
        {
            Node<T> *tmp = Last -> Next;
            if(Last == nullptr){
                cout << "Lista vacia: \n";
            }
            while (tmp != Last ){
                cout << tmp -> Data <<" -> ";
                tmp = tmp -> Next;
            }
            if(tmp == Last){
                cout << tmp -> Data <<"  ";
            }
        }


        //Numero de nodos
        int NumeroNodos(){
            int c {0};
            Node<T> *tmp = Head;
            if(!Head){
                cout << "Lista vacia: \n";
            }
            while (tmp != Last ){
                c++;
                tmp = tmp -> Next;
            }
            if(tmp == Last){
                c++;
            }
            return c;
        }

        // impresion de la lista recursiva
        void print_recursive(Node <T> * tmp) {
            if(tmp ->Next == nullptr){
                cout << tmp ->Data << " ->";
            }
            else if (Last -> Next == Head){ 
                return;
            }
            else
            {
                cout << tmp->Data << " -> ";
                print_recursive(tmp->Next);
            }
        }
        void PRINT_RECURSIVE() {
            Node<T> * tmp = Head;
            print_recursive(tmp);
        }
        

        void insert_Orden(T d){
            Node<T>* tmp = Head;
            for(;tmp ; tmp = tmp -> Next){
                if(tmp -> Data > d){
                    push_front(d);
                }
                else{
                    push_back(d);
                }
            }
        }

};

int main(){
    SimpleCircularList<int> a;
    string A = "D:\\ficheros\\listas.txt";
    a.push_front(26);
    a.push_front(267);
    a.push_front(19);
    a.push_front(61);
    a.push_back(12326);
    a.push_front(272);
    a.push_front(2874);
    cout << "Imprime la lista: " << endl;
    a.print_iterative(); 
    cout << endl;
    cout << endl;

    cout << "Agrega al final de la lista el 126: " << endl;
    a.push_back(126);
    a.print_iterative();
    cout << endl;

    cout << "\nEncuentra el elemento 19 ... " << endl;
    cout << a.find_iterative(19) << endl;

    cout << "\nEncuentra el elemento 14 ... " << endl;
    cout << a.find_iterative(14) << endl;

    //cout << endl;
    //cout << a.mostrarfindRecursivo(912) << endl;
    //cout << a.mostrarfindRecursivo(14) << endl;

    cout << endl;
    cout << "\nContar pares: " << endl;
    cout << a.count_iterative_even() << endl;

    cout << endl;
    cout << "Numero de nodos: " << endl;
    cout << a.NumeroNodos() << endl;

    //cout << "Maximo: " << endl;
    //a.max_iterative();
    //cout << endl;

    cout << "\nAgrega en la posicion 2: " << endl;
    a.push_position(3,2);
    a.print_iterative();
    cout << endl;
    cout << "\nAgrega en la posicion 5: " << endl;
    a.push_position(2341,5);
    a.print_iterative();
    cout << endl;
    cout << endl;
    cout << "El valor maximo es: " << a.max_iterative() << endl;
    
    cout << "insertar en orden el elemento: " << endl;
    a.insert_Orden(45);
    
    //SimpleCircularList <string> word;
    //string word;

    //ifstream input (A);
    //while(!input.eof()) {
    //    input >> word;
    //}
    //input.close();
    //word.print_iterative();
   
    return 0;
}