#include <iostream>
using namespace std;

int values[10];
int weight[10];
int capacity;
int size;

void getData()
{
    cout << "Enter No. of Items :\t";
    cin >> size;
    cout << "\nEnter the items";
    for (int i = 0; i < size; i++)
    {
        cout << "\nEnter item " << i + 1 << endl;
        cout << "Value :\t";
        cin >> values[i];
        cout << "weight : ";
        cin >> weight[i];
    }
    cout << "\nCapacity " << endl;
    cin >> capacity;
    cout << "___________________________________________________________________________________________________________";
}

void displayData()
{
    cout << "\nItems" << endl;
    cout << "Values\tweight" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << values[i] << "\t" << weight[i] << endl;
    }
    cout << "___________________________________________________________________________________________________________";
}

void knapsack_01()
{
    int knap[size + 1][capacity + 1];
    for (int i = 0; i < size + 1; i++)
    {
        for (int j = 0; j < capacity + 1; j++)
        {
            knap[i][j] = 0;
        }
    }

    for (int i = 1; i < size + 1; i++)
    {
        for (int j = 0; j < capacity + 1; j++)
        {
            if (weight[i - 1] <= j)
            {
                knap[i][j] = knap[i - 1][j] > knap[i - 1][j - weight[i - 1]] + values[i - 1] ? knap[i - 1][j] : knap[i - 1][j - weight[i - 1]] + values[i - 1];
            }
            else
            {
                knap[i][j] = knap[i - 1][j];
            }
        }
    }

    int result = knap[size][capacity];
    int count = 0;
    int cap = capacity;
    int selected_values[size][2];
    for (int i = size; i > 0; i--)
    {
        if (knap[i][cap] != knap[i - 1][cap])
        {
            selected_values[count][0] = values[i - 1];
            selected_values[count][1] = weight[i - 1];
            count++;
            cap -= weight[i - 1];
        }
    }


    cout << "\n\nKnap Values : \n";
    for (int i = 0; i < size + 1; i++)
    {
        for (int j = 0; j < capacity + 1; j++)
        {
            cout << knap[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "___________________________________________________________________________________________________________";
    cout << endl;

    cout << "Selected Items" << endl;
    cout << "Values\tweight" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << selected_values[i][0] << "\t" << selected_values[i][1] << endl;
    }
    cout << "___________________________________________________________________________________________________________";

    cout << "\n\nValue: \t" << knap[size][capacity] << endl;
    cout << "\n\n";
}

int main(int argc, char const *argv[])
{
    getData();
    displayData();
    knapsack_01();
    return 0;
}
