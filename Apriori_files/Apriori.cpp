#include "Apriori.h"

bool isCondition(int i, int c)
{
	switch (c)
	{
	case 0:
		if (i%2==0){ return true; }
		else{ return false; }
		break;
	case 1:
		if (i%2==1){ return true; }
		else{ return false; }
		break;
	case 2:
		if ((i/2)%2==0){ return true; }
		else{ return false; }
		break;
	case 3:
		if ((i / 2) % 2 == 1){ return true; }
		else{ return false; }
		break;
	case 4:
		if ((i / 4) % 2 == 0){ return true; }
		else{ return false; }
		break;
	case 5:
		if ((i / 4) % 2 == 0){ return true; }
		else{ return false; }
		break;
	case 6:
		if (i>=0 && i<=7){ return true; }
		else{ return false; }
		break;
	case 7:
		if (i >= 8 && i <= 15){ return true; }
		else{ return false; }
		break;
	case 8:
		if (i >= 16 && i <= 23){ return true; }
		else{ return false; }
		break;
	case 9:
		if (i >= 24 && i <= 31){ return true; }
		else{ return false; }
		break;
	default:
		return false;
		break;
	}
}

int genSupport(setNode* setStart, int data[])
{
	if (setStart==nullptr|| setStart->condition==NULL)
	{
		return 0;
	}
	
	
	int support = 0;
	bool cond = true;
	setNode* temp;
	setNode* t;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cond = true;
		temp = setStart;
		while (temp!= nullptr && temp->condition!=NULL&& cond)
		{
			if (cond)
			{cond = isCondition(i, temp->condition);}
			t = temp->next;
			temp = t;
		}
		
		if (cond) { support += data[i]; }
		cond = true;
	}
	return support; 
}

void insert_pNode(passNode* pNode, passNode* prev)
{
	pNode->next = prev->next;
	prev->next->prev = pNode;
	pNode->prev = prev;
	prev->next = pNode;
}
void remove_pNode(passNode* pNode)
{
	passNode* temp = pNode;
	temp->next->prev = pNode->prev;
	temp->prev->next = pNode->next;
	delete pNode;
}

bool testNewNode(passNode* currPNode, int c, int data[])
{
	passNode* copy = currPNode;
	setNode* newSetItem= new setNode;
	setNode* temp;
	newSetItem->condition = c;
	temp = copy->first_set_item;
	while (temp->next!=nullptr)
	{
		temp = temp->next;
	}
	temp->next = newSetItem;
	if (((float)genSupport(copy->first_set_item,data) / ALL_PEOPLE) < MIN_SUPPORT)
	{
		return false;
	}
	else{ return true; }


}

passNode* genNewNode( passNode* currPNode, int c, int data[])
{
	passNode* copy = currPNode;
	setNode* newSetItem = new setNode;
	setNode* temp;
	newSetItem->condition = c;
	temp = copy->first_set_item;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = newSetItem;
	copy->support = genSupport(copy->first_set_item, data);
	return copy;
	
}

string genRules(passNode* A, int data[])
{
	stringstream rules;
	int maximal_support;
	subsetNode* maximal_set = new subsetNode;
	setNode* test= new setNode;
	setNode* temp1 = new setNode;
	setNode* temp2 = new setNode;
	temp1 = A->first_set_item;
	temp2 = maximal_set->start;
	
	int count = 0;
	while (temp1!=nullptr)
	{
		temp2->next = temp1->next;
		temp1 = temp1->next;
		temp2 = temp2->next;
		count++;
	}
	maximal_support = genSupport(maximal_set->start, data);
	int* maximal_conditions = new int[count];
	temp1 = maximal_set->start;
	for (int i = 0; i < count; i++)
	{
		maximal_conditions[i] = temp1->condition;
		temp1 = temp1->next;
	}
	
	test->condition = maximal_conditions[0];
	temp1 = test;
	for (int j = 0; j < 14; j++)
	{
		switch (j)
		{
		case 0:
			temp1->condition = maximal_conditions[0];
			if (testRule(maximal_support, genSupport(test, data), test))
			{
				rules << genRule(maximal_support, genSupport(test, data ), test, maximal_set->start) << endl;
			}
			break;
		case 1:
			temp1->condition = maximal_conditions[1];
			if (testRule(maximal_support, genSupport(test, data), test))
			{
				rules << genRule(maximal_support, genSupport(test, data), test, maximal_set->start) << endl;
			}
			break;
		case 2:
			temp1->condition = maximal_conditions[2];
			if (testRule(maximal_support, genSupport(test, data), test))
			{
				rules << genRule(maximal_support, genSupport(test, data), test, maximal_set->start) << endl;
			}
			break;
		case 3:
			temp1->condition = maximal_conditions[3];
			if (testRule(maximal_support, genSupport(test, data), test))
			{
				rules << genRule(maximal_support, genSupport(test, data), test, maximal_set->start) << endl;
			}
			break;
		case 4:
			temp1->condition = maximal_conditions[0];
			temp1 = temp1->next;
			temp1->condition = maximal_conditions[1];
			if (testRule(maximal_support, genSupport(test, data), test))
			{
				rules << genRule(maximal_support, genSupport(test, data), test, maximal_set->start) << endl;
			}
			break;
		case 5:
			temp1->condition = maximal_conditions[2];
			if (testRule(maximal_support, genSupport(test, data), test))
			{
				rules << genRule(maximal_support, genSupport(test, data), test, maximal_set->start) << endl;
			}
			break;
		case 6:
			temp1->condition = maximal_conditions[3];
			if (testRule(maximal_support, genSupport(test, data), test))
			{
				rules << genRule(maximal_support, genSupport(test, data), test, maximal_set->start) << endl;
			}
			break;
		case 7:
			temp1 = test; 
			temp1->condition = maximal_conditions[1];
			temp1 = temp1->next;
			temp1->condition = maximal_conditions[2];
			if (testRule(maximal_support, genSupport(test, data), test))
			{
				rules << genRule(maximal_support, genSupport(test, data), test, maximal_set->start) << endl;
			}
			break;
		case 8:
			temp1->condition = maximal_conditions[3];
			if (testRule(maximal_support, genSupport(test, data), test))
			{
				rules << genRule(maximal_support, genSupport(test, data), test, maximal_set->start) << endl;
			}
			break;
		case 9:
			temp1 = test;
			temp1->condition = maximal_conditions[2];
			temp1 = temp1->next;
			temp1->condition = maximal_conditions[3];
			if (testRule(maximal_support, genSupport(test, data), test))
			{
				rules << genRule(maximal_support, genSupport(test, data), test, maximal_set->start) << endl;
			}
			break;
		case 10:
			temp1 = test;
			temp1->condition = maximal_conditions[0];
			temp1 = temp1->next;
			temp1->condition = maximal_conditions[1];
			temp1 = temp1->next;
			temp1->condition = maximal_conditions[2];
			if (testRule(maximal_support, genSupport(test, data), test))
			{
				rules << genRule(maximal_support, genSupport(test, data), test, maximal_set->start) << endl;
			}
			break;
		case 11:
			temp1 = temp1->next;
			temp1->condition = maximal_conditions[3];
			if (testRule(maximal_support, genSupport(test, data), test))
			{
				rules << genRule(maximal_support, genSupport(test, data), test, maximal_set->start) << endl;
			}
			break;
		case 12:
			temp1 = test;
			temp1 = temp1->next;
			temp1->condition = maximal_conditions[2];
			if (testRule(maximal_support, genSupport(test, data), test))
			{
				rules << genRule(maximal_support, genSupport(test, data), test, maximal_set->start) << endl;
			}
			break;
		case 13:
			temp1 = test;
			temp1->condition = maximal_conditions[1];
			temp1 = temp1->next;
			temp1->condition = maximal_conditions[2];
			temp1 = temp1->next;
			temp1->condition = maximal_conditions[3];
			if (testRule(maximal_support, genSupport(test, data), test))
			{
				rules << genRule(maximal_support, genSupport(test, data), test, maximal_set->start) << endl;
			}
			break;
		default:
			break;
		}
	}
	return rules.str();
}

bool testRule(int A, int B, setNode* test)
{
	if ((float)(A/B) < MIN_CONFIDENCE)
	{return true;}
	else{ return false; }
}
string genRule(int A, int B, setNode* test, setNode* m_set)
{
	stringstream rule;
	setNode* temp = test;
	setNode* temp2 = m_set;
	bool found;
	rule << condition_names[temp->condition];
	while (temp!=nullptr)
	{
		temp = temp->next;
		rule << "and " << condition_names[temp->condition];
	}
	rule << " proves ";
	temp = test;
	while (temp2!=nullptr)
	{
		found = false;
		while (temp!=nullptr)
		{
			if ((temp->condition==temp2->condition))
			{
				found = true;
			}
			temp = temp->next;
		}
		if (!found)
		{
			rule << condition_names[temp->condition] << " ";
		}
		temp2 = temp2->next;
	}
	rule << "with confidence of " << (float)(A / B);
	
	return rule.str();
}


void Apriori(int data[])
{
	passNode* head= new passNode;
	passNode* currentPass;
	passNode* temp1;
	passNode* temp2;
	setNode* currentSetItem = new setNode;
	setNode* setTemp;
	int i, j, k, pass = 1;
	int conditions = CONDITIONS, dropped = 0, fails = 0;//;
	temp1= head;

	for ( i = 0; i < CONDITIONS; i++)
	{
		currentSetItem->condition = i;
		temp1->first_set_item = currentSetItem;
		temp1->support = genSupport(temp1->first_set_item, data);
		currentPass = temp1;
		temp1 = new passNode;
		currentPass->next = temp1;
		temp1->prev = currentPass;
	}
	temp2 = head;

	while (temp2 != nullptr)
	{
		if (((float)(temp2->support)/ALL_PEOPLE) < MIN_SUPPORT)
		{
			dropped_conditions[temp2->first_set_item->condition] = true;
			conditions--;
			remove_pNode(temp2);
		}
		else{ temp2 = temp2->next; }
	}



	while (pass<4)
	{
	temp1 = head;
	currentPass = head;
	dropped = 0;
	for ( k = 0; k < CONDITIONS; k++)
	{
		dropped_conditions[k] = 0;

	}
	while (temp1 != nullptr)
	{
		
		for ( j = 0; j < CONDITIONS; j++)
		{
			if (!dropped_conditions[j])
			{
				if (testNewNode(temp1, j, data))
				{
					insert_pNode(genNewNode(temp1, j, data), currentPass);
					currentPass= currentPass->next;			
				}
				else{ fails++; }
				
			}
		}
		setTemp = temp1->first_set_item;
		while (setTemp!=nullptr)
		{
			failed_conditions[setTemp->condition] += fails;
			setTemp = setTemp->next;
		}
		fails = 0;
		currentPass = currentPass->next;
		if (temp1== head)
		{
			head = temp1->next;
			
			remove_pNode(temp1);
			temp1 = currentPass;
		}
		else
		{ 
			remove_pNode(temp1);
			temp1 = currentPass; 
		}
		for ( k = 0; k < CONDITIONS; k++)
		{
			if (failed_conditions[k]>= (conditions*pass))
			{
				dropped_conditions[k] = true;
				dropped++;
			}
		}
		conditions -= dropped;
	}
	pass++;
	}
	temp1 = head;
	while (temp1!=nullptr)
	{
		cout << genRules(temp1, data) << endl;
		temp1 = temp1->next;
	}






}




