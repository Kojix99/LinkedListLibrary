#include <iostream>
#include "clsNode.h"

using namespace std;


int main(){
	Node* FirstNode = new Node("Sohail", "Zoraibi", 20, nullptr);
	Node* SecondNode = new Node("Rayane", "Zoraibi", 13, nullptr); 
	Node* ThirdNode = new Node("Mouad", "Sodore", 18, nullptr);
	Node* FourthNode = new Node("Walid", "Khayati", 15, nullptr);

	FirstNode->Next = SecondNode; 
	SecondNode->Next = ThirdNode;
	ThirdNode->Next = FourthNode;
	
	Node* head = FirstNode;

	Node* NewNode = new Node("Jocker", "Sohail", 2999, nullptr);
	Node::InsertBefore(head, "Mouad", NewNode);
	Node::InsertAtEnd(head, new Node("Safae", "o7esso", 19, nullptr));

	Node::DeleteLastNode(head);
	Node::PrintNodes(head);
}
