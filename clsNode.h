// ============================================================================
//  Linked List Node Library
//  Author       : Sohail Zoraibi
//  Created On   : 07/05/2025
//  Description  :
//      This header file defines the Node class and provides a suite of static
//      utility methods for working with singly linked lists, including
//      insertion, deletion, search, and printing operations.
// 
//      The implementation follows principles of defensive programming,
//      ensuring safe memory management and handling of edge cases.
// ============================================================================

#pragma once
#include <iostream>

using namespace std;


class Node
{
public:
	string FirstName;
	string LastName;
	int Grade;
	Node* Next;

	Node();
	Node(string FirstName, string LastName, int Grade, Node* Next)
	{
		this->FirstName = FirstName;
		this->LastName = LastName;
		this->Grade = Grade;
		this->Next = Next;
	}

	static void InsertInBeginning(Node* &Head, Node* ToAddNode)
	{
		ToAddNode->Next = Head;
		Head = ToAddNode;
	}

	static void InsertInBeginning(Node* &Head, string FirstName, string LastName, int Grade)
	{
		Node::InsertInBeginning(Head,  new Node(FirstName,LastName, Grade, nullptr));
	}

	static Node* Find(Node* head, string FirstName)
	{
		while (head != nullptr)
		{
			if (head->FirstName == FirstName)
			{
				return head;
			}
			head = head->Next;
		}
		return nullptr;
	}

	static void PrintNodes(Node* head)
	{
		while (head != nullptr)
		{
			cout << "FirstName: " << head->FirstName << endl;
			cout << "LastName : " << head->LastName << endl;
			cout << "Grade    : " << head->Grade << endl;
			cout << "\n\n";
			head = head->Next;
		}
	}

	static void PrintNode(Node* CurrentNode)
	{
		cout << "FirstName: " << CurrentNode->FirstName << endl;
		cout << "LastName : " << CurrentNode->LastName << endl;
		cout << "Grade    : " << CurrentNode->Grade << endl;
		cout << "\n\n";
	}

	static void InsertAfter(Node* head, string TargetName, Node* ToInsertNode)
	{
		Node* TargetNode = Node::Find(head, TargetName);
		if (TargetNode == nullptr) return;

		ToInsertNode->Next = TargetNode->Next;
		TargetNode->Next = ToInsertNode;
	}

	static void InsertAfter(Node* head, string TargetName, string FirstName, string Lastname, int Grade)
	{
		InsertAfter(head, TargetName, new Node(FirstName, Lastname, Grade, nullptr));
	}

	static void InsertBefore(Node* &head, string TargetName, Node* ToInsertNode)
	{
		if (head == nullptr) return;

		if (head->FirstName == TargetName)
		{
			ToInsertNode->Next = head;
			head = ToInsertNode;
			return;
		}

		Node* CurrentNode = head;
		Node* PreviousNode = nullptr;
		while (CurrentNode != nullptr)
		{
			if (CurrentNode->FirstName == TargetName)
			{
				break;
			}
			PreviousNode = CurrentNode;
			CurrentNode = CurrentNode->Next;
		}

		if (CurrentNode == nullptr) return;


		ToInsertNode->Next = CurrentNode;
		if (PreviousNode != nullptr)
			PreviousNode->Next = ToInsertNode;
	}

	static void InsertAtEnd(Node*& head, Node* ToInsertNode)
	{
		if (head == nullptr)
		{
			head = ToInsertNode;
			return;
		}

		Node* Current = head;
		
		while (Current->Next != nullptr)
		{
			Current = Current->Next;
		}

		Current->Next = ToInsertNode;
	}

	static void InsertAtEnd(Node*& head, string FirstName, string LastName, int Grade)
	{
		InsertAtEnd(head, new Node(FirstName, LastName, Grade, nullptr));
	}

	static void InsertBefore(Node* head, string TargetName, string FirstName, string Lastname, int Grade)
	{
		InsertBefore(head, TargetName, new Node(FirstName, Lastname, Grade, nullptr));
	}

	static void DeleteNode(Node* &head, string TargetName)
	{
		Node* Current = head;
		Node* PreviousNode = nullptr;

		if (head == nullptr) return;

		if (Current->FirstName == TargetName)
		{
			head = head->Next;
			delete Current;
			return;
		}

		while (Current != nullptr && Current->FirstName != TargetName)
		{
			PreviousNode = Current;
			Current = Current->Next;
		}

		if (Current == nullptr) return;

		if (PreviousNode != nullptr)
		{
			PreviousNode->Next = Current->Next;
		}
		delete Current;
	}

	static void DeleteFirstNode(Node*& head)
	{
		if (head == nullptr) return;

		Node* Current = head;

		head = Current->Next;
		delete Current;
	}

	static void DeleteLastNode(Node*& head)
	{
		if (head == nullptr) return;

		Node* Current = head;
		if (head->Next == nullptr)
		{
			head = nullptr;
			delete Current;
			return;
		}

		Node* PreviousNode = nullptr;

		while (Current->Next != nullptr)
		{
			PreviousNode = Current;
			Current = Current->Next;
		}

		if (PreviousNode != nullptr)
		{
			PreviousNode->Next = nullptr;
		}
		delete Current;
	}
};