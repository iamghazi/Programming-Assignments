//package practiceQuestions;

/*
Page 667
Problem 14.11
(Implement iterative variation of merge sort,
 merge adjacent regions at a time)
 */
import java.util.Scanner;

/**
 * @author Prasoon Jain
 *
 */
public class MergeSortVariation {

  //method returns true if the number is power of two
  /**
   * @param number
   * @return
   */
  private static boolean isPowerofTwo(int number) {
    if ((number & (number - 1)) == 0)
      return true;
    return false;
  }

  //method to compare elements of adjacent regions and merge them
  /**
   * @param givenArray
   * @param sizeofadjacentRegion
   * @param leftRegionStartpoint
   * @param rightRegionStartPoint
   */
  private static void compareAndMergeAdjacentRegions(int givenArray[],
      int sizeofadjacentRegion, int leftRegionStartpoint,
      int rightRegionStartPoint) {

    int temporaryArray[] = new int[2 * sizeofadjacentRegion];		
    int tempArrayIndex = 0;
    int leftRegionIndex = leftRegionStartpoint;
    int rightRegionIndex = rightRegionStartPoint;
    int leftRegionEndPoint = leftRegionStartpoint
        + sizeofadjacentRegion;
    int rightRegionEndPoint=rightRegionStartPoint
        + sizeofadjacentRegion;

    // comparing and merging the left and right regions elements
    while(leftRegionIndex < leftRegionEndPoint
        && rightRegionIndex < rightRegionEndPoint) {

      if (givenArray[leftRegionIndex] <= givenArray[rightRegionIndex]) {
        temporaryArray[tempArrayIndex] = givenArray[leftRegionIndex];
        leftRegionIndex++;
      } else if(givenArray[rightRegionIndex] <givenArray[leftRegionIndex]){
        temporaryArray[tempArrayIndex] = givenArray[rightRegionIndex];
        rightRegionIndex++;
      }
      tempArrayIndex++;
    }

    // If some elements are left in any of the the two arrays.
    while (leftRegionIndex < leftRegionEndPoint) {
      temporaryArray[tempArrayIndex] = givenArray[leftRegionIndex];
      leftRegionIndex++;
      tempArrayIndex++;
    }
    while (rightRegionIndex < rightRegionEndPoint) {
      temporaryArray[tempArrayIndex] = givenArray[rightRegionIndex];
      rightRegionIndex++;
      tempArrayIndex++;
    }

    for (int arrayIndex = 0; arrayIndex <
        2*sizeofadjacentRegion; arrayIndex++) {
      givenArray[leftRegionStartpoint] = temporaryArray[arrayIndex];
      leftRegionStartpoint++;
    }
  }

  /**
   * @param array
   * @param arraySize
   */
  private static void printArray(int array[],int arraySize) {
    for(int index= 0; index< arraySize; index++) {
      System.out.print(array[index]+" ");
    }
    System.out.println("");
  }


  /**
   * @param args
   */
  public static void main(String[] args) {

    Scanner scan = new Scanner(System.in);
    System.out.println("Enter the size of the array : ");
    final int sizeOfArray = scan.nextInt();

    // Checking id the input is valid or not
    if (!isPowerofTwo(sizeOfArray)) {
      System.out.println("Length of array is not the power of 2");
    } else {
      //taking user input of Array elements
      System.out.println("Enter array elements : ");
      int givenArray[] = new int[sizeOfArray];
      for (int arrayIndex = 0; arrayIndex < sizeOfArray; arrayIndex++) {
        givenArray[arrayIndex] = scan.nextInt();
      }

      //size of adjacent regions increases by the power of two
      for (int sizeOfAdjacentRegion = 1; sizeOfAdjacentRegion <sizeOfArray;
          sizeOfAdjacentRegion *= 2) {

        System.out.println("Merging all the adjacent regions Of size : "
            + sizeOfAdjacentRegion);

        //next left region start point is given by previous index +
        // twice the size of current region i.e. (left+right) Regions 
        for (int leftRegionStartPoint = 0; leftRegionStartPoint <sizeOfArray;
            leftRegionStartPoint += 2*sizeOfAdjacentRegion) {

          int rightRegionStartPoint =leftRegionStartPoint +sizeOfAdjacentRegion;

          // merging the adjacent regions 
          compareAndMergeAdjacentRegions(givenArray,
              sizeOfAdjacentRegion, leftRegionStartPoint,
              rightRegionStartPoint);
        }

        //printing given array in intermediate steps  
        printArray(givenArray, sizeOfArray);
      }

      //printing final sorted array
      System.out.println("Final Sorted Array : ");
      printArray(givenArray, sizeOfArray);
    }
    scan.close();
  }
}
