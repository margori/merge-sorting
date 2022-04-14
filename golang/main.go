package main

import (
	"fmt"
	"math/rand"
)

func splitListInHalves(fullList []int) ([]int, []int) {
	var middleIndex = len(fullList) / 2

	var leftList = fullList[:middleIndex]
	var rightList = fullList[middleIndex:]

	return leftList, rightList
}

func mergeSortedLists(leftList []int, rightList []int) []int {
	var leftIndex = 0
	var rightIndex = 0
	var resultList []int

	// compare elements and add minor
	for leftIndex < len(leftList) && rightIndex < len(rightList) {
		if leftList[leftIndex] < rightList[rightIndex] {
			resultList = append(resultList, leftList[leftIndex])
			leftIndex += 1
		} else {
			resultList = append(resultList, rightList[rightIndex])
			rightIndex += 1
		}
	}

	// add remaining left elements
	for leftIndex < len(leftList) {
		resultList = append(resultList, leftList[leftIndex])
		leftIndex += 1
	}
	// add remaining right elements
	for rightIndex < len(rightList) {
		resultList = append(resultList, rightList[rightIndex])
		rightIndex += 1
	}
	return resultList
}

func mergeSort(currentList []int) []int {
	if len(currentList) == 1 {
		return currentList
	}

	var leftList, rightList = splitListInHalves(currentList)

	var sortedLeftList = mergeSort(leftList)
	var sortedRightLest = mergeSort(rightList)

	return mergeSortedLists(sortedLeftList, sortedRightLest)
}
func createRandomList(size int) []int {
	var result []int
	var i int
	for i = 0; i < size; i++ {
		result = append(result, rand.Intn(size*2))
	}
	return result
}

func main() {
	fmt.Print("Welcome to Merge Sorting by Margori\n\n")

	fmt.Print("Enter amount of elements to sort: ")
	var size int
	_, err := fmt.Scanln(&size)
	if err != nil {
		return
	}

	var originalList = createRandomList(size)
	fmt.Printf("Original list: %v\n", originalList)

	var sortedList = mergeSort(originalList)
	fmt.Printf("  Sorted list: %v\n", sortedList)
}
