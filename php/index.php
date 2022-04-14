<?php

function create_random_list($size): array {
    $result = [];

    for ($i = 0; $i < $size; $i++) {
        $result[] = rand(0, $size * 10);
    }

    return $result;
}

function split_list_in_halves($list): array {
    $left_side = array_slice($list, 0, intdiv(count($list), 2));
    $right_side = array_slice($list, intdiv(count($list), 2), count($list) - 1);
    return [$left_side, $right_side];
}

function merge_sorted_lists($left_list, $right_list): array {
    $left_index = 0;
    $right_index = 0;
    $result_list = [];

    # compare elements and add minor
    while ($left_index < count($left_list) && $right_index < count($right_list)) {
        if ($left_list[$left_index] < $right_list[$right_index]) {
            $result_list[] = $left_list[$left_index];
            $left_index += 1;
        } else {
            $result_list[] = $right_list[$right_index];
            $right_index += 1;
        }
    }
    # add remaining left elements
    while ($left_index < count($left_list)) {
        $result_list[] = $left_list[$left_index];
        $left_index += 1;
    }

    # add remaining right elements
    while ($right_index < count($right_list)) {
        $result_list[] = $right_list[$right_index];
        $right_index += 1;
    }

    return $result_list;
}

function merge_sort($current_list) {
    if (count($current_list) == 1) {
        return $current_list;
    }

    list($left_list, $right_list) = split_list_in_halves($current_list);

    $sorted_left_list = merge_sort($left_list);
    $sorted_right_lest = merge_sort($right_list);

    return merge_sorted_lists($sorted_left_list, $sorted_right_lest);
}

print("Welcome to Merge Sorting by Margori\n\n");

$size = readline("Enter amount of elements to sort: ");

$original_list = create_random_list($size);
printf("Original list [%s]\n", implode(', ', $original_list));

$sorted_list = merge_sort($original_list);
printf("  Sorted list [%s]\n", implode(', ', $sorted_list));
