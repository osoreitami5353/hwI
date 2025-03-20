#include <iostream>
#include <memory>

using namespace std;

// Definición del nodo
struct Node {
    int data;
    shared_ptr<Node> next; // Se usa shared_ptr porque la lista enlazada necesita compartir la propiedad de los nodos entre funciones
};

// Función para crear un nuevo nodo
shared_ptr<Node> create_node(int value) {
    return make_shared<Node>(Node{value, nullptr}); // Se usa make_shared para mejorar la eficiencia de la asignación de memoria
}

// Función para insertar un nodo al frente de la lista
void push_front(shared_ptr<Node>& head, int value) {
    shared_ptr<Node> new_node = create_node(value);
    new_node->next = head;
    head = new_node;
    cout << "Nodo insertado en el principio de la lista correctamente." << endl;
}

// Función para insertar un nodo al final de la lista
void push_back(shared_ptr<Node>& head, int value) {
    shared_ptr<Node> new_node = create_node(value);
    if (!head) {
        head = new_node;
        cout << "Nodo insertado en el final de la lista correctamente." << endl;
        return;
    }
    shared_ptr<Node> temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new_node;
    cout << "Nodo insertado en el final de la lista correctamente." << endl;
}

// Función para insertar un nodo en una posición específica
void insert(shared_ptr<Node>& head, int value, int position) {
    shared_ptr<Node> new_node = create_node(value);
    if (position <= 0 || !head) {
        push_front(head, value);
        return;
    }
    shared_ptr<Node> temp = head;
    int index = 0;
    while (temp->next && index < position - 1) {
        temp = temp->next;
        index++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    cout << "Nodo insertado correctamente en la posición solicitada." << endl;
}

// Función para eliminar un nodo en una posición específica
void erase(shared_ptr<Node>& head, int position) {
    if (!head) return;
    if (position <= 0) {
        head = head->next;
        cout << "Nodo eliminado correctamente." << endl;
        return;
    }
    shared_ptr<Node> temp = head;
    shared_ptr<Node> prev = nullptr;
    int index = 0;
    while (temp->next && index < position) {
        prev = temp;
        temp = temp->next;
        index++;
    }
    if (prev) {
        prev->next = temp->next;
    }
    cout << "Nodo de la posición solicitada eliminado correctamente." << endl;
}

// Función para imprimir la lista enlazada
void print_list(shared_ptr<Node> head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n" << endl;
}

int main() {
    shared_ptr<Node> head = nullptr;
    
    // Prueba de la función create_node()
    shared_ptr<Node> test_node = create_node(99);

    push_front(head, 10);
    print_list(head);

    push_front(head, 20);
    print_list(head);

    push_back(head, 30);
    print_list(head);

    insert(head, 25, 1);
    print_list(head);

    insert(head, 40, 10);
    print_list(head);
    
    erase(head, 2);
    print_list(head);

    erase(head, 10);
    print_list(head);
    
    return 0;
}