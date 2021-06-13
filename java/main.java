import java.util.Random;
import java.util.Scanner;
import java.util.Arrays;

class MergeSorting {

    private static int[] create_random_list(int size) {
        int[] result = new int[size];
        Random r = new Random();

        for (int i = 0; i < size; i++) {
            result[i] = r.nextInt(size * 10);
        }

        return result;
    }

    private static int[][] splitListInHalves(int[] list) {
        int[] leftSide = Arrays.copyOfRange(list, 0, list.length / 2);
        int[] rightSide = Arrays.copyOfRange(list, list.length / 2, list.length);

        int[][] result = {leftSide, rightSide};
        return result;
    }

    private static int[] mergeSortedLists(int[] leftList, int[] rightList) {
        int leftindex = 0;
        int rightIndex = 0;
        int resultIndex = 0;
        int[] resultList = new int[leftList.length + rightList.length];

        // compare elements and add minor
        while (leftindex < leftList.length && rightIndex < rightList.length) {
            if (leftList[leftindex] < rightList[rightIndex]) {
                resultList[resultIndex] = leftList[leftindex];
                leftindex++;
            } else {
                resultList[resultIndex] =rightList[rightIndex];
                rightIndex++;
            }
            resultIndex++;
        }
        // add remaining left elements
        while (leftindex < leftList.length) {
            resultList[resultIndex] =leftList[leftindex];
            leftindex++;
            resultIndex++;
        }

        // add remaining right elements
        while (rightIndex < rightList.length) {
            resultList[resultIndex] =rightList[rightIndex];
            rightIndex++;
            resultIndex++;
        }

        return resultList;
    }

    private static int[] mergeSort(int[] currentList) {
        if (currentList.length == 1) {
            return currentList;
        }

        int[][] halves = splitListInHalves(currentList);
        int[] leftList = halves[0];
        int[] right_list = halves[1];

        int[] sortedLeftList = mergeSort(leftList);
        int[] sortedRightLest = mergeSort(right_list);

        return mergeSortedLists(sortedLeftList, sortedRightLest);
    }

    public static void main(String[] args) {
        System.out.println("Welcome to Merge Sorting by Margori\n\n");
        System.out.print("Enter amount of elements to sort? ");

        Scanner in = new Scanner(System.in);
        int size = in.nextInt();

        int[] originalList = create_random_list(size);
        System.out.print("Original list ");
        System.out.println(Arrays.toString(originalList));

        int[] sortedList = mergeSort(originalList);
        System.out.print("  Sorted list ");
        System.out.println(Arrays.toString(sortedList));
    }
}
