
def merge_sorted_lists(left_list, right_list)
  left_index = 0
  right_index = 0
  result_list = []

  # compare elements and add minor
  while left_index < left_list.length && right_index < right_list.length
    if left_list[left_index] < right_list[right_index]
      result_list.append( left_list[left_index])
      left_index += 1
    else
      result_list.append( right_list[right_index])
      right_index += 1
    end
  end

  # add remaining left elements
  while left_index < left_list.length
    result_list.append(left_list[left_index])
    left_index += 1
  end

  # add remaining right elements
  while right_index < right_list.length
    result_list.append(right_list[right_index])
    right_index += 1
  end

  result_list
end

def merge_sort(current_list)
  return current_list if current_list.length == 1

  middle_index = current_list.length / 2

  left_list = current_list.slice(0, middle_index)
  right_list = current_list.slice(middle_index, current_list.length)

  sorted_left_list = merge_sort(left_list)
  sorted_right_lest = merge_sort(right_list)

  merge_sorted_lists(sorted_left_list, sorted_right_lest)
end

def createRandomList(size)
  result = []

  (1..size).each { |_i|
    result.append(rand(size * 10))
  }

  result
end


puts("Welcome to Merge Sorting by Margori\n\n")

print('Enter amount of elements to sort? ')
size = gets.to_i

puts "\n"

original_list = createRandomList(size)
puts("Original list #{original_list.inspect}")

sorted_list = merge_sort(original_list)
puts("  Sorted list #{sorted_list.inspect}")
