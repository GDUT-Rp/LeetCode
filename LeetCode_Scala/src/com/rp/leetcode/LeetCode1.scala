package com.rp.leetcode

object LeetCode1 {
  def twoSum(nums: Array[Int], target: Int): Array[Int] = {
    val m = nums.zipWithIndex.groupBy(_._1)
    nums.zipWithIndex.withFilter(pair => {
      val diff = target - pair._1
      m.contains(diff) && m(diff).exists(_._2 != pair._2)
    }).map(_._2)
  }

  def fastest(nums: Array[Int], target: Int): Array[Int] = {
    var map = scala.collection.immutable.Map[Int, Int]()
    for (i <- 0 to nums.length) {
      if (map.contains(target - nums(i))) {
        return Array(map(target - nums(i)), i)
      } else map += (nums(i) -> i)
    }
    Array(0, 0)
  }

  def main(args: Array[String]): Unit = {
    val numbers = Array(2, 11, 15, 7)
    val target = 9
    val fast = fastest(numbers, target)
    for (i <- 0 to (fast.length - 1))
      println(fast(i))
  }
}

