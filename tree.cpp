#include <iostream>
using namespace std;

int tabs = 0;

struct Branch
{
    char Data;
    Branch *LeftBranch;
    Branch *RightBranch; 
};


void Add(char aData, Branch *&aBranch)
{
    if (!aBranch)
    {
        aBranch = new Branch;
        aBranch->Data = aData;
        aBranch->LeftBranch = 0;
        aBranch->RightBranch = 0;
        return;
    }
    else if (aBranch->Data > aData)
    {
        Add(aData, aBranch->LeftBranch);
    }
    else
    {
        Add(aData, aBranch->RightBranch);
    };
}

void print(Branch *aBranch)
{
    if (!aBranch) return;
    tabs++;

    print(aBranch->LeftBranch);

    for (int i = 0; i < tabs; i++) cout << " ";
    cout << aBranch->Data << endl;

    print(aBranch->RightBranch);

    tabs--;
    return;
}

Branch* FindMinNode(Branch* aBranch)
{
    Branch* current = aBranch;
    while (current->LeftBranch != NULL)
    {
        current = current->LeftBranch;
    }
    return current;
}

Branch* RemoveNode(char aData, Branch* aBranch)
{
    if (aBranch == NULL) return aBranch;

    if (aData < aBranch->Data)
    {
        aBranch->LeftBranch = RemoveNode(aData, aBranch->LeftBranch);
    }
    else if (aData > aBranch->Data)
    {
        aBranch->RightBranch = RemoveNode(aData, aBranch->RightBranch);
    }
    else
    {
        if (aBranch->LeftBranch == NULL)
        {
            Branch* temp = aBranch->RightBranch;
            delete aBranch;
            return temp;
        }
        else if (aBranch->RightBranch == NULL)
        {
            Branch* temp = aBranch->LeftBranch;
            delete aBranch;
            return temp;
        }

        Branch* temp = FindMinNode(aBranch->RightBranch);
        aBranch->Data = temp->Data;
        aBranch->RightBranch = RemoveNode(temp->Data, aBranch->RightBranch);
    }
    return aBranch;
}

void FreeTree(Branch *aBranch)
{
    if (!aBranch) return;
    FreeTree(aBranch->LeftBranch);
    FreeTree(aBranch->RightBranch);
    delete aBranch;
    return;
}


int main()
{
    Branch *Root = 0;
    char s[] = "18452789";

    for (int i = 0; s[i]; i++)
    {
        Add(s[i], Root);
    }

    print(Root);
    Root = RemoveNode('7', Root); // Удаляем узел с данными '7'
    cout << "After removal:" << endl;
    print(Root);
    FreeTree(Root);

    cin.get();
    return 0;
}
