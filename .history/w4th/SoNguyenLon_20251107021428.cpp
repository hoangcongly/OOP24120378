#include "SoNguyenLon.h"

Node* SoNguyenLon:: CreateNode(const int& value)
{
    Node* node= new Node();
    node->info=value;
    node->pNext=nullptr;
    return node;

}