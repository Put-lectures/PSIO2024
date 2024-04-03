#include <fstream>
#include <iostream>
using namespace std;
struct sNode
{
    string word_;
    int counter_ = 1;
    sNode *l_ = nullptr;
    sNode *r_ = nullptr;
};

sNode *add_new(string word)
{
    sNode *el = new sNode;
    el->word_ = word;
    return el;
}
void add_element(sNode *node, string word)
{
    {
        if (node->word_ == word) {
            node->counter_++;
            return;
        } else if (node->word_ < word) {
            if (node->l_ == nullptr)
                node->l_ = add_new(word);
            else {
                add_element(node->l_, word);
            }

        } else {
            if (node->r_ == nullptr)
                node->r_ = add_new(word);
            else {
                add_element(node->r_, word);
            }
        }
    }
}
int main()
{
    fstream file("/home/piotr/Downloads/gpl-3.0.txt", ios::in);
    sNode *root = nullptr;
    if (file.is_open()) {
        string word;
        while (!file.eof()) {
            file >> word;
            if (root == nullptr) {
                root = add_new(word);
            } else {
                add_element(root, word);
            }
        }
    }
    return 0;
}
