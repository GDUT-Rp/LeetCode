package com.rp.leetcode

import scala.collection.mutable

object LeetCode13 {
  def romanToInt(s: String): Int = {
    var ans = 0
    val map = new mutable.HashMap[Char, Int]()
    map.put('I', 1)
    map.put('V', 5)
    map.put('X', 10)
    map.put('L', 50)
    map.put('C', 100)
    map.put('D', 500)
    map.put('M', 1000)
    for (i <- 0 to (s.length - 2)) {
      if (map(s.charAt(i + 1)) > map(s.charAt(i))) {
        ans -= map(s.charAt(i))
      }
      else {
        ans += map(s.charAt(i))
      }
    }
    ans + map(s.charAt(s.length - 1))
  }
  val m = Map('I' -> 1, 'V' -> 5, 'X' -> 10, 'L' -> 50, 'C' -> 100, 'D' -> 500, 'M' -> 1000)
  def romanToIntImproved(s: String): Int = {
    (s zip s.tail).foldLeft(0) {
      case ((sum, (ch1, ch2))) =>
        if (m(ch1) < m(ch2))
          sum - m(ch1)
        else
          sum + m(ch1)
    } + m(s.last)
  }

  def main(args: Array[String]): Unit = {
    val samples = Array("III", "IV", "IX", "LVIII", "MCMXCIV")
    for(i <- 0 to (samples.length - 1)){
      println(romanToInt(samples(i)))
    }
  }
}
