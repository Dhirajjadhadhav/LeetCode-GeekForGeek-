<h2>
  <div class="flex items-start gap-2">
    <div class="text-title-large font-semibold text-text-primary dark:text-text-primary">
      <a 
        class="no-underline hover:text-blue-s dark:hover:text-dark-blue-s truncate cursor-text whitespace-normal hover:!text-[inherit]" 
        href="https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/" 
        target="_blank" 
        rel="noopener noreferrer"
      >
        2529. Maximum Count of Positive Integer and Negative Integer
      </a>
      <div class="text-body ml-2 inline-flex items-center gap-2 py-1">
        <div class="inline-flex items-center space-x-2"></div>
      </div>
    </div>
  </div>
</h2>


<div><div class="elfjS" data-track-load="description_content"><p>Given an array <code>nums</code> sorted in <strong>non-decreasing</strong> order, return <em>the maximum between the number of positive integers and the number of negative integers.</em></p>

<ul>
	<li>In other words, if the number of positive integers in <code>nums</code> is <code>pos</code> and the number of negative integers is <code>neg</code>, then return the maximum of <code>pos</code> and <code>neg</code>.</li>
</ul>

<p><strong>Note</strong> that <code>0</code> is neither positive nor negative.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [-2,-1,-1,1,2,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 3 positive integers and 3 negative integers. The maximum count among them is 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [-3,-2,-1,0,0,1,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 2 positive integers and 3 negative integers. The maximum count among them is 3.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [5,20,66,1314]
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 positive integers and 0 negative integers. The maximum count among them is 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2000</code></li>
	<li><code>-2000 &lt;= nums[i] &lt;= 2000</code></li>
	<li><code>nums</code> is sorted in a <strong>non-decreasing order</strong>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Can you solve the problem in <code>O(log(n))</code> time complexity?</p>
</div></div>