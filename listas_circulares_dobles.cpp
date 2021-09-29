//Listas circulares doblemente enlazadas
//INTEGRANTES
//Bejar Roman Katherine Nikole
//Soto Begazo Juan Manuel
//Deza Cuela Miguel Angel

#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class Node
{
	public:
		Node<T>* Next;
		Node<T>* Previous;
		T Data; 
	public:
		Node(T _Data){
            Data = _Data;
            Next = nullptr;
            Previous = nullptr;
        }	

        void ShowInfo() {
            cout << this->Data << " -> ";
}
};


template <class T>
class DoubleCircularList
{
    private:
        Node<T>* First;
        Node<T>* Last;
	public:
        
        DoubleCircularList() {
            First = nullptr;
            Last = nullptr;
        }
 
        bool IsEmpty() {
            return First == nullptr;
        }
     
        void InsertLast(T data) { 
            Node<T>* aux = new Node<T>(data);
            if (IsEmpty()) {
                First = aux;
                First-> Next = aux ;
                First->Previous = aux;
                Last = First;
            }
            else {
                Last->Next = aux;
                aux-> Next = First;
                aux->Previous = Last;
                Last = aux;
            }
            Last->Next = First; 
        }

        
        void InsertBegin(T data) {
            Node<T>* aux = new Node<T>(data);
            if (IsEmpty()) {
                First = aux;
                First->Next = aux;
                First->Previous = aux;
                Last = First;
            }
            else {
                First-> Previous = aux;
                aux->Next = First;
                aux->Previous = Last;
                First = aux;
            }
            Last->Next = First;
        }

        
        void InsertInOrder(T data) {
            if (IsEmpty())
                InsertBegin(data);
            else {
                Node<T>* aux = new Node<T>(data);
                if (aux->Data <= First->Data)
                    InsertBegin(data);
                else if (aux->Data >= Last->Data)
                    InsertLast(data);
                else {
                    Node<T>* p = First;
                    Node<T>* q = First;
                    do {
                        q = p;
                        p = p->Next;

                    } while (p->Data < aux->Data);
                    q->Next = aux;
                    p->Previous = aux;
                    aux->Next = p;
                    aux->Previous = q;
                }
            }
        }

        //agregar un elemento en una posicion
        void InsertByPosition(T d, int P) {
            if ((P < 1 || P > Quantity()+1)){
                cout << "No existe esa posicion ";
            }

            if (P == 1) {
                InsertBegin(d); return; 
            }

            if (P == Quantity()+1) {
                InsertLast(d); return;
            }

            Node<T> *tmp = First;
            for(int i = 2; i < P; i++)
                tmp = tmp -> Next;
            Node<T> *nuevo = new Node<T> (d);
            nuevo -> Next = tmp -> Next;
            tmp -> Next = nuevo;
        }


        
        int Remove(T data) {
            int Found = 1;
            if (!IsEmpty()) {
                Node<T>* aux = First;

                do {
                    if (aux->Data == data) {
                        Node<T>* delete_node = aux;

                        if (First->Next == First){
                            First = nullptr;
                            Last = First;
                            delete First;
                            return 0;
                        }

                        if (aux == First) {
                            First = First->Next;
                            First->Previous = Last;
                            Last->Next = First;
                        }
                        else if (aux == Last) {
                            Last = Last->Previous;
                            First->Previous = Last;
                            Last->Next = First;
                        }
                        else {
                            aux->Previous->Next = aux->Next;
                            aux->Next->Previous = aux->Previous;
                        }
                        Found = 0;
                        aux = aux->Next;
                        delete delete_node;
                        continue;
                    }
                    aux = aux->Next;
                    if (aux == First) break;
                } while (true);
            }
        }
        
        int Quantity() {
            if (!IsEmpty()) {
                int i = 0;
                Node<T>* aux = First;
                while (true) {
                    ++i;
                    aux = aux-> Next;
                    if (aux == First)
                        return i;
                }
            }
            return 0;
        }
       
        void Show() {
            if (!IsEmpty()) {
                Node<T>* aux = First;
                while (true) {
                    aux -> ShowInfo();
                    aux = aux -> Next;
                    if (aux == First)
                        break;
                }
            }
        }

       
        T Get(int pos) {
            if (!IsEmpty() && pos < Quantity()) {
                Node<T>* aux = First;
                Node<T>* aux2 = Last;
                int i = 0;
                int j = Quantity() - 1;
                while (j >= i) {
                    if (i == pos)
                        return aux -> Data;
                    if (j == pos)
                        return aux2 -> Data;
                    aux = aux -> Next;
                    aux2 = aux2->Previous;
                    ++i;
                    --j;
                    if (aux == First || aux2 == Last)
                        break;
                }
            }
            return nullptr;
        }


        //Contar pares iterativa
        T CountEven()
        {
            T counter {0};
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


        bool find(T data) {
        Node<T>* tmp = First;
        Node<T>* tmp2 = Last;
        while(tmp != tmp2 && tmp && tmp2) {
            if (tmp->Data == data) return true;
            if (tmp2->Data == data) return true;
            tmp = tmp->Next;
            tmp2 = tmp->Previous;
        }
        return false;
        }

        /* 
        T findMax() {
            Node<T>* tmp = First;
            T maximo = 0;
            while (tmp != Last) {
                if (tmp->Data >= maximo){ 
                    maximo = tmp->Data;
                    tmp = tmp->Next;
                }
            }
            if (Last->Data >= maximo){ 
                maximo = Last->Data;
                return maximo;
            }
        }
        */

     
};


int main(){
    DoubleCircularList<int> list;
	string A = "D:\\ficheros\\listas.txt";
    list.InsertBegin(4);
    list.InsertInOrder(15);
    list.InsertInOrder(36);
    list.InsertInOrder(21);
    list.InsertInOrder(20);
    list.InsertInOrder(19);
    list.InsertInOrder(20);
    list.InsertInOrder(15);
    cout << list.Quantity() << endl; // Imprime cantidad
    list.Show();
    cout << "\n=========================================" << endl;
    list.Remove(15);
    cout << "\nBorro el 15.8" << endl;
    list.Show();
    cout << "\n==============================================" << endl;
    cout << "\nAhora borros los 20.7" << endl;
    list.Remove(28);
    list.Show();
    cout << "\n=========================================" << endl;
    list.InsertLast(37);
    list.InsertLast(52);
    list.Show();
    //cout << "funcion find: " << endl;
    cout << "\nEncontrar el 4....  "<< list.find(4) << endl;
    cout << "Encontrar el 476....  "<< list.find(476) << endl;

    cout << "\nAgrega en la posicion 5: " << endl;
    list.InsertByPosition(2341 ,5);
    list.Show();
    cout << endl << endl;


    cout << endl;
    cout << "\nContar pares: " << endl;
    cout << list.CountEven() << endl;

    //cout << "Maximo: " << list.findMax() << endl; 


	//DoubleCircularList <string> word;
    //string word;

    //ifstream input (A);
    //while(!input.eof()) {
    //    input >> word;
    //}
    //input.close();
    //word.print_iterative();
    

    return 0;
}