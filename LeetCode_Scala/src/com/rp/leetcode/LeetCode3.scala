package com.rp.leetcode

import scala.util.control.Breaks._

class LeetCode3 {
  def lengthOfLongestSubstring(s: String): Int =
    s.zipWithIndex.foldLeft((0, -1, Map[Char, Int]())) { case ((len, start_pos, map), (char, i)) =>
      val last_pos = map.getOrElse(char, -1)
      if (last_pos >= start_pos) (len max (i - last_pos), last_pos, map + (char -> i))
      else (len max (i - start_pos), start_pos, map + (char -> i))
    }._1

  def normal(s: String): Int = {
    var map = new scala.collection.mutable.HashMap[Char, Int]()
    var max = 0
    for (i <- s.indices) {
      val c = s.charAt(i)
      if (map.contains(c)) {
        if (max < map.size) {
          max = map.size
        }
        val index = map(c)
        map = map.filter(t => t._2 > index)
      }
      map.put(c, i)
    }
    if (max < map.size) {
      max = map.size
    }
    return max
  }

  def faster(s: String): Int = {
    s.foldLeft((new StringBuilder(""),0)){
      case ((b,i),c) =>
        if (!b.contains(c)){
          b.append(c)
        }
        else {
          b.delete(0,b.indexOf(c)+1)
          b.append(c)
        }
        if (b.length>i)
          (b,b.length)
        else
          (b,i)
    }._2
  }

  def fastest(s: String): Int = {
    var maxSub = Array(0, 0)
    var sub = Array(0, 0)
    var i: Int = 0
    var stopIndex: Int = 0
    for(j <- i + 1 to s.length - 1){
      var flag: Boolean = true
      breakable{
        for(k <- i to j-1){
          stopIndex = k
          if(s.charAt(k) == s.charAt(j)){
            flag = false
            break
          }
        }
      }

      if(flag)
        sub(1) = j
      else{
        i = stopIndex + 1
        sub(0) = i
        sub(1) = j
      }

      if(sub(1) - sub(0) > maxSub(1) - maxSub(0)){
        maxSub(0) = sub(0)
        maxSub(1) = sub(1)
      }
    }

    if(s.equals(""))
      0
    else
      maxSub(1) - maxSub(0) + 1
  }
}
