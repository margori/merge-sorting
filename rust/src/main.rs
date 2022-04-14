use std::io;

extern crate rand;

use rand::thread_rng;
use rand::Rng;

fn main() {
  println!("Welcome to Merge Sorting by Margori");

  println!("Enter amount of elements to sort:");

  let mut size_string = String::new();

  io::stdin()
    .read_line(&mut size_string)
    .expect("Fail to read input");

  let size: u32 = size_string.trim().parse().expect("Not a number");

  let original_list = create_random_list(size);
  println!("Original list {:?}", original_list);

  let sorted_list = merge_sort(original_list);
  println!("  Sorted list {:?}", sorted_list);
}

fn create_random_list(size: u32) -> Vec<u32> {
  let mut rng = thread_rng();
  let mut result: Vec<u32> = Vec::new();

  for _number in 1..size {
    result.push(rng.gen_range(0, size * 10));
  }

  result
}

fn merge_sort(current_list: Vec<u32>) -> Vec<u32> {
  if current_list.len() == 1 {
    return current_list;
  }

  let halves = split_list_in_halves(current_list);

  let sorted_left_list = merge_sort(halves.0);
  let sorted_right_list = merge_sort(halves.1);

  merge_sorted_lists(sorted_left_list, sorted_right_list)
}

fn split_list_in_halves(list: Vec<u32>) -> (Vec<u32>, Vec<u32>) {
  let middle = list.len() / 2;
  (list[0..middle].to_vec(), list[middle..].to_vec())
}

fn merge_sorted_lists(left_list: Vec<u32>, right_list: Vec<u32>) -> Vec<u32> {
  let mut left_index = 0;
  let mut right_index = 0;
  let mut result_list: Vec<u32> = Vec::new();

  // compare elements and add minor
  while left_index < left_list.len() && right_index < right_list.len() {
    if left_list[left_index] < right_list[right_index] {
      result_list.push(left_list[left_index]);
      left_index += 1;
    } else {
      result_list.push(right_list[right_index]);
      right_index += 1;
    }
  }

  // add remaining left elements
  while left_index < left_list.len() {
    result_list.push(left_list[left_index]);
    left_index += 1;
  }

  // add remaining right elements
  while right_index < right_list.len() {
    result_list.push(right_list[right_index]);
    right_index += 1;
  }

  result_list
}
