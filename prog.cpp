#include <iostream>
#include "test.h"
struct nod
{
    int liczba;
    nod *lewy, *prawy;
    nod (int n) : liczba(n), lewy(nullptr), prawy(nullptr) {}
    ~nod () = default;
};
class BST
{
    public:
    nod *korzen;
    void insert (int n)
    {
        if (!korzen)
        {
            nod *temp = new nod(n);
            korzen = temp;
        }
        else
        {
            nod *temp = korzen;
            nod *temp2 = nullptr;
            bool side = false;
            while (temp)
            {
                temp2 = temp;
                if (temp->liczba < n)
                {
                    temp = temp->prawy;
                    side = true;
                }
                else
                {
                    temp = temp->lewy;
                    side = false;
                }
            }
            temp = new nod(n);
            if (side)
            {
                temp2->prawy = temp;
            } else
            {
                temp2->lewy = temp;
            }
        }
    }
    void deletenod (int n)
    {
        if (!korzen)
        {
            std::cout << "Tree is empty" << std::endl;
        }
        else
        {
            nod *temp = korzen;
            nod *temp2 = nullptr;
            bool side = false;
            while (temp)
            {
                if (temp->liczba != n)
                {
                    temp2 = temp;
                    if (temp->liczba > n)
                    {
                        temp = temp->lewy;
                        side = true;
                    }
                    else
                    {
                        temp = temp->prawy;
                        side = false;
                    }
                }
                else
                {
                    if (!temp->lewy && !temp->prawy)
                    {
                        if (!side)
                        {
                            temp2->lewy = NULL;
                        } else
                        {
                            temp2->prawy = NULL;
                        }
                        break;
                    }
                    else if (!temp->prawy && temp->lewy)
                    {
                        if (!side)
                        {
                            temp2->lewy = temp->lewy;
                        }
                        else
                        {
                            temp2->prawy = temp->lewy;
                        }
                        break;
                    }
                    else if (!temp->lewy && temp->prawy)
                    {
                        if (!side)
                        {
                            temp2->lewy = temp->prawy;
                        }
                        else
                        {
                            temp2->prawy = temp->prawy;
                        }
                        break;
                    }
                    else
                    {
                        int key = findSmallestnod(temp);
                        deletenod(key);
                        temp->liczba = key;
                        break;
                    }
                }
            }
            if (!temp)
            {
                std::cout << "Key -> " << n << " not found" << std::endl;
            }
            else
            {
                temp = nullptr;
            }
        }
    }
    bool contains(int n)
    {
        nod *temp = korzen;
        while (temp->liczba != n)
        {
            if (temp->liczba > n)
            {
                temp = temp->lewy;
            }
            else
            {
                temp = temp->prawy;
            }
            if (temp == NULL)
            {
                return false;
            }
        }
        return true;
    }
    void sizeCount(nod* korzen, int &sum) const
    {
        if (korzen!=NULL)
        {
              ++sum;
              sizeCount(korzen->lewy, sum);
              sizeCount(korzen->prawy, sum);
        }
    }
    int size() const
    {
        int sum=0;
        if (this->korzen!=NULL)
        {
              ++sum;
              sizeCount(korzen->lewy, sum);
              sizeCount(korzen->prawy, sum);
        }
        return sum;
    }
    int findSmallestnod(nod *korzen)
    {
        nod *temp = korzen->prawy;

        while (temp && temp->lewy != NULL)
        {
            temp= temp->lewy;
        }
        return temp->liczba;
    }
    void display(nod* ptr, int poziom)
    {
        if (ptr)
        {
            display(ptr->prawy, poziom + 1);
            printf("\n");
            if (ptr == korzen)
            std::cout << "Korzen drzewa BST -> ";
            for (int i = 0; i < poziom && ptr != korzen; i++)
                std::cout << "      ";
            std::cout << ptr->liczba << std::endl;
            display(ptr->lewy, poziom + 1);
        }
    }
};
int main()
{
    unit_test();
}
