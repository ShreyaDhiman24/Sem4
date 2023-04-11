int main()
{
    CircularDoublyLinkedList list;

    // Insert some nodes at the start
    list.insertAtStart(10);
    list.printList();

    list.insertAtStart(20);
    list.printList();

    list.insertAtStart(30);
    list.printList();

    // Insert some nodes at the end
    list.insertAtEnd(40);
    list.printList();

    list.insertAtEnd(50);
    list.printList();

    list.insertAtEnd(60);
    list.printList();

    // Insert some nodes at the specified positions
    list.insertAtPosition(6, 2);
    list.printList();

    list.insertAtPosition(55, 6);
    list.printList();

    list.insertAtPosition(3, 5);
    list.printList();

    // Delete a node from start
    list.deleteAtStart();
    list.printList();

    // Delete a node from end
    list.deleteFromEnd();
    list.printList();

    // Delete a node at position 3
    list.deleteAtPosition(3);

    // Print the list after deletion
    list.printList();
    return 0;
}