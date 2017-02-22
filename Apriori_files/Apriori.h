/*Author: Robert Gentile
Class:CSI-281-05
Assignment: Assignment 1
Assigned:8/31/15
Due:9/7/15

Purpose: Demonstrate understanding of past concepts 

I certify that this is entirely my own work, except when I have given fully-documented references 
to the work of others. I understand the definition and consequences of plagiarism and acknowledge 
that the assessor of this assignment may for the purpose of this assessing this assignment:
Reproduce this and provide a copy to another academic staff; and or 
communicate a copy of this assignment to a plagiarism checking service 
(which may then retain a copy of this assignment on its database for the purpose of plagiarism checking) 
*/
/*Author: Robert Gentile
Class:CSI-281-05
Assignment: Final
Assigned:11/30/15
Due:12/9/15

Purpose: Apriori

I certify that this is entirely my own work, except when I have given fully-documented references
to the work of others. I understand the definition and consequences of plagiarism and acknowledge
that the assessor of this assignment may for the purpose of this assessing this assignment:
Reproduce this and provide a copy to another academic staff; and or
communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for the purpose of plagiarism checking)
*/


#ifndef APRIORI_H
#define APRIORI_H

#include <string>
#include <sstream>
#include <iostream>
#include <cmath>

using namespace std;

const int MAX_SIZE = 32;
const float MIN_SUPPORT = 0.2f;
const float MIN_CONFIDENCE = 0.7f;
const float CONDITIONS = 10;
const float ALL_PEOPLE = 2200;

enum conditions
{
	lived, died, female, male, child, adult, 
	crew, third, second, first
};

static int failed_conditions[10];
static string condition_names[10] = { "survived", "died", "female", "male", "child", "adult", "crew", "third", "second", "first" };
static bool dropped_conditions[10];



struct setNode {
	setNode* next;
	int condition;
};

struct passNode {
	passNode* next;
	passNode* prev;
	setNode* first_set_item;
	int support;
};

struct subsetNode {
	subsetNode* next;
	setNode* start;
};


void insert_pNode(passNode* pNode, passNode* prev);
void remove_pNode(passNode* pNode);

bool isCondition(int i ,int c);
int genSupport(setNode* setStart, int data[]);
string genRules(passNode* A, int data[]);
bool testRule(int A, int B, setNode* test);
string genRule(int A, int B, setNode* test, setNode* m_set);
passNode* genNewNode(passNode* currPNode, int c, int data[]);
bool testNewNode(passNode* currPNode, int c, int data[]);
void Apriori(int data[]);








#endif