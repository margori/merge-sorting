#include <iostream>
#include <vector>

using namespace std;

vector<int> create_random_list(int size)
{
  vector<int> result;
  srand(time(0));

  for (int i = 0; i < size; i++)
  {
    result.push_back(rand() % (size * 10));
  }

  return result;
}

vector<vector<int>> split_list_in_halves(vector<int> list)
{
  vector<int> left(list.begin(), list.begin() + list.size() / 2);
  vector<int> right(list.begin() + list.size() / 2, list.end());

  vector<vector<int>> result;
  result.push_back(left);
  result.push_back(right);
  return result;
}

vector<int> mergeSortedLists(vector<int> leftList, vector<int> rightList)
{
  int leftindex = 0;
  int rightIndex = 0;
  vector<int> resultList;

  // compare elements and add minor
  while (leftindex < leftList.size() && rightIndex < rightList.size())
  {
    if (leftList.at(leftindex) < rightList.at(rightIndex))
    {
      resultList.push_back(leftList.at(leftindex));
      leftindex++;
    }
    else
    {
      resultList.push_back(rightList.at(rightIndex));
      rightIndex++;
    }
  }
  // add remaining left elements
  while (leftindex < leftList.size())
  {
    resultList.push_back(leftList.at(leftindex));
    leftindex++;
  }

  // add remaining right elements
  while (rightIndex < rightList.size())
  {
    resultList.push_back(rightList.at(rightIndex));
    rightIndex++;
  }

  return resultList;
}

vector<int> merge_sort(vector<int> currentList)
{
  if (currentList.size() == 1)
  {
    return currentList;
  }

  vector<vector<int>> halves = split_list_in_halves(currentList);
  vector<int> leftList = halves.at(0);
  vector<int> right_list = halves.at(1);

  vector<int> sortedLeftList = merge_sort(leftList);
  vector<int> sortedRightLest = merge_sort(right_list);

  return mergeSortedLists(sortedLeftList, sortedRightLest);
}

void print(vector<int> list)
{
  cout << "[";
  for (int i = 0; i < list.size() - 1; i++)
  {
    cout << list.at(i) << ", ";
  }
  cout << list.back() << "]";
}

int main()
{
  cout << "Welcome to Merge Sorting by Margori" << endl
       << endl;
  cout << "Enter amount of elements to sort:" << endl;

  int size = 0;
  cin >> size;

  vector<int> originalList = create_random_list(size);
  cout << "Original list ";
  print(originalList);
  cout << endl;

  vector<int> sortedList = merge_sort(originalList);
  cout << "  Sorted list ";
  print(sortedList);
  cout << endl;

  cout << endl;
}