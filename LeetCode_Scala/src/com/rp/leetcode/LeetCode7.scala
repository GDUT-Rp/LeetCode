package com.rp.leetcode

object LeetCode7 {
  def reverse(x: Int): Int = {
    var str = x.toString()
    if (x < 0) {
      str = str.substring(1)
      str = str.reverse
      if (-1 * str.toLong < Int.MinValue) {
        return 0
      }
      return -1 * str.toInt
    }
    str = str.reverse
    if (str.toLong > Int.MaxValue)
      0
    else
      str.toInt
  }

  def easy(x: Int): Int = {
    var ans: Long = 0
    var yu: Int = 0
    var temp: Int = x
    while (temp != 0) {
      yu = temp % 10
      temp /= 10
      if (ans > Integer.MAX_VALUE / 10 || ans < Integer.MIN_VALUE / 10)
        return 0
      ans = ans * 10 + yu
    }
    ans.toInt
  }

  def fastest(x: Int): Int = {
    if (x == 0) x
    else{
      try{
        val absX = Math.abs(x)
        x / absX * absX.toString.reverse.toInt
      }catch {
        case _: Throwable => 0
      }
    }
  }

  def main(args: Array[String]): Unit = {
    val arr = Array(123, -123, 120, 10, 969, 898, 0, 1534236469)
    for (i <- 0 to (arr.length - 1)) {
      println(reverse(arr(i)))
      println(easy(arr(i)))
      println(fastest(arr(i)))
    }
  }
}
