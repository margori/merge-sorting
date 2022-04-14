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

vector<int> merge_sorted_lists(vector<int> left_list, vector<int> right_list)
{
  int left_index = 0;
  int right_index = 0;
  vector<int> result_list;

  // compare elements and add minor
  while (left_index < left_list.size() && right_index < right_list.size())
  {
    if (left_list.at(left_index) < right_list.at(right_index))
    {
      result_list.push_back(left_list.at(left_index));
      left_index++;
    }
    else
    {
      result_list.push_back(right_list.at(right_index));
      right_index++;
    }
  }
  // add remaining left elements
  while (left_index < left_list.size())
  {
    result_list.push_back(left_list.at(left_index));
    left_index++;
  }

  // add remaining right elements
  while (right_index < right_list.size())
  {
    result_list.push_back(right_list.at(right_index));
    right_index++;
  }

  return result_list;
}

vector<int> merge_sort(vector<int> current_list)
{
  if (current_list.size() == 1)
  {
    return current_list;
  }

  vector<vector<int>> halves = split_list_in_halves(current_list);
  vector<int> left_list = halves.at(0);
  vector<int> right_list = halves.at(1);

  vector<int> sortedleft_list = merge_sort(left_list);
  vector<int> sortedRightLest = merge_sort(right_list);

  return merge_sorted_lists(sortedleft_list, sortedRightLest);
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

  vector<int> original_list = create_random_list(size);
  cout << "Original list ";
  print(original_list);
  cout << endl;

  vector<int> sorted_list = merge_sort(original_list);
  cout << "  Sorted list ";
  print(sorted_list);
  cout << endl;

  cout << endl;
}