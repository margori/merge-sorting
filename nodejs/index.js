const split_list_in_halves = (full_list) => {
    const middle_index = full_list.length / 2;

    const left_list = full_list.slice(0, middle_index);
    const right_list = full_list.slice(middle_index, full_list.length);

    return [left_list, right_list]
}

const merge_sorted_lists = (left_list, right_list) => {
    let left_index = 0;
    let right_index = 0;
    const result_list = [];

    // compare elements and add minor
    while (left_index < left_list.length && right_index < right_list.length) {
        if (left_list[left_index] < right_list[right_index]) {
            result_list.push(left_list[left_index]);
            left_index += 1;
        } else {
            result_list.push(right_list[right_index])
            right_index += 1;
        }
    }
    // add remaining left elements
    while (left_index < left_list.length) {
        result_list.push(left_list[left_index]);
        left_index += 1;
    }
    // add remaining right elements
    while (right_index < right_list.length) {
        result_list.push(right_list[right_index]);
        right_index += 1;
    }

    return result_list;
}

const merge_sort = (current_list) => {
    if (current_list.length === 1) {
        return current_list
    }

    const [left_list, right_list] = split_list_in_halves(current_list);

    const sorted_left_list = merge_sort(left_list);
    const sorted_right_lest = merge_sort(right_list);

    return merge_sorted_lists(sorted_left_list, sorted_right_lest);
}

const create_random_list = (size) => {
    const result = [];

    for (let i = 0; i < size; i++) {
        result.push(Math.floor(Math.random() * size * 10));
    }

    return result;
}

console.log('Welcome to Merge Sorting by Margori\n');

const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

readline.question('Enter amount of elements to sort? ', (size) => {
    const original_list = create_random_list(size);
    console.log(`Original list [${original_list}]`);

    const sorted_list = merge_sort(original_list);
    console.log(`  Sorted list [${sorted_list}]`);

    readline.close();
});

