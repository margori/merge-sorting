import random


def split_list_in_halves(full_list):
    middle_index = len(full_list) // 2

    left_list = full_list[:middle_index]
    right_list = full_list[middle_index:]

    return left_list, right_list


def merge_sorted_lists(left_list, right_list):
    left_index = 0
    right_index = 0
    result_list = []

    # compare elements and add minor
    while left_index < len(left_list) and right_index < len(right_list):
        if left_list[left_index] < right_list[right_index]:
            result_list.append( left_list[left_index])
            left_index += 1
        else:
            result_list.append( right_list[right_index])
            right_index += 1

    # add remaining left elements
    while left_index < len(left_list):
        result_list.append(left_list[left_index])
        left_index += 1

    # add remaining right elements
    while right_index < len(right_list):
        result_list.append(right_list[right_index])
        right_index += 1

    return result_list


def merge_sort(current_list):
    if len(current_list) == 1:
        return current_list

    left_list, right_list = split_list_in_halves(current_list)

    sorted_left_list = merge_sort(left_list)
    sorted_right_lest = merge_sort(right_list)

    return merge_sorted_lists(sorted_left_list, sorted_right_lest)


if __name__ == '__main__':
    print('Welcome to Merge Sorting by Margori\n')

    size = int(input("Enter amount of elements to sort: "))

    original_list = [random.randint(0, size * 10) for i in range(0, size)]
    print(f'Original list {original_list}')

    sorted_list = merge_sort(original_list)
    print(f'  Sorted list {sorted_list}')
