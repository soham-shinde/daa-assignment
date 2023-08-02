#include <iostream>

using namespace std;

class Objects
{
public:
    int index;
    int profit;
    int weight;
    float ratio;

    Objects() {}

    void setData(int index, int profit, int weight)
    {
        this->index = index;
        this->profit = profit;
        this->weight = weight;
        this->ratio = (float)profit / weight;
    }
};

void getArray(Objects arr[], int size)
{
    cout << "Enter Data\n";
    int profit, weight;
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "\t";
        cout << "Enter Profit :- \t";
        cin >> profit;
        cout << "Enter Weight :- \t";
        cin >> weight;
        arr[i].setData(i + 1, profit, weight);
    }
}

void printArray(Objects arr[], int size)
{
    cout << "Profit\tWeight\tRatio\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i].profit << "\t" << arr[i].weight << "\t" << arr[i].ratio << "\n";
    }
    cout << endl;
}

int partition(Objects arr[], int low, int high)
{
    float pivot = arr[high].ratio;
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j].ratio > pivot)
        {
            Objects temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    Objects temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

void quickSort(Objects arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void knapsack(Objects arr[],int size,int sackWeight){
    int sack=0;
    Objects arrr1[7];
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].ratio == arr[i+1].ratio)
        {
            if(arr[i].weight<arr[i+1].weight){
                Objects temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp; 
            }
        }

        if((sack+arr[i].weight)<=sackWeight){
            sack+=arr[i].weight;
            arrr1[i] = arr[i];
            count++;
        }
        else{
            int remain = sackWeight - sack;
            
        }
    }
     cout<<sackWeight-sack<<"\n";
    printArray(arrr1,count);
    
}

int main(int argc, char const *argv[]){
    Objects arr[7];
    int size = 7;
    int sackWeight;
    getArray(arr, size);
    cout<<"\n Enter sack Capacity"<<endl;
    cin>>sackWeight;
    quickSort(arr, 0, size);

    printArray(arr, size);

    knapsack(arr,size,sackWeight);
    return 0;
}
    


