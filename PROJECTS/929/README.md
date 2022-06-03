# 929 Unique Email Addresses

<https://leetcode.cn/problems/unique-email-addresses/>

每个有效电子邮件地址都由一个本地名和一个域名组成，以 '@' 符号分隔。除小写字母之外，电子邮件地址还可以含有一个或多个 '.' 或 '+'。给你一个字符串数组 emails，我们会向每个 emails[i] 发送一封电子邮件。返回实际收到邮件的不同地址数目。

## 笔记

- 多重循环注意 i j k kk 等不要重复使用 或者就换有意义的名字
- size_t & usigned long 一定要转为int再做比较
- 我写的算法应该是有问题的 直接做hash应该会冲突吧？虽然我不知道会有多大的概率 但是能过所有的题解
- 注意其实没必要单独统计 domain_name 直接把一个email看成一个hash就可以了
- std可以不用那么多 `using std::vector;`这样子省一些

## References

- [CSDN | C++中string的用法](https://blog.csdn.net/qq_30534935/article/details/82227364)
