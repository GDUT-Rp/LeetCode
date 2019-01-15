package com.rp.leetcode

object LeetCode27 {
  def removeElement(nums: Array[Int], `val`: Int): Int = {
    var i: Int = 0
    for (j <- 0 until nums.length) {
      if (nums(j) != `val`) {
        nums(i) = nums(j)
        i += 1
      }
    }
    i
  }

  def removeElementBySwap(nums: Array[Int], `val`: Int): Int = {
    var i: Int = 0
    var n = nums.length
    while(i < n){
      if (nums(i) == `val`){
        nums(i) = nums(n - 1)
        n -= 1  //  reduce array size by one and check the place of i again
      }
      else{
        i += 1  //  check successfully and continue
      }
    }
    n
  }

  def main(args: Array[String]): Unit = {
    val nums = Array(1, 2, 2, 3, 4, 5, 4, 2)
    val nums2 = Array(1, 2, 2, 3, 4, 5, 4, 2)
    println(removeElement(nums, 2))
    println(removeElementBySwap(nums2, 2))
  }
}
