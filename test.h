#include <cassert>
void unit_test() {

    BST tree;

    tree.insert(4);
    tree.insert(43);
    tree.insert(18);
    tree.insert(5);
    tree.insert(8);
    tree.insert(56);
    tree.insert(10);
    tree.insert(14);
    tree.insert(56);
    tree.insert(9);
    assert(tree.size() == 10);
    tree.insert(42);
    assert(tree.contains(3) == false);
    assert(tree.contains(56) == true);
    assert(tree.size() == 11);
    tree.insert(34);
    tree.insert(72);
    tree.insert(26);

    tree.deleteNode(8);
    assert(tree.root->right->data == 9);
    tree.deleteNode(10);
    assert(tree.root->right->right->data == 14);

    //usuwany roota
    tree.deleteNode(4);
    assert(tree.root->data == 5);

    //usuwamy element ktorego nie ma w drzewie
    assert(tree.size() == 11);
    tree.deleteNode(88);
    assert(tree.size() == 11);

    //kontrolne reczne rysowanie drzewa
    tree.display(tree.korzen, 1);

    std::cout << "testy zdane!";
}
