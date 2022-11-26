## Uva 156

一道`map`容器的基础例题

题目要求输出满足以下条件的单词：**不能通过字母重排得出与其他输入单词相同的单词**，在判断该条件时不区分大小写，如输入`POst`、`oSpt`，这两个单词都可通过字母重排得到另一个单词，所以这两个单词**不可被输出**

根据题意，很容易想到，通过将每个输入的单词中的字母按**统一的方式排序**，然后存放在`map`中，重复得到相同的`key`会使得对应的`value`自增，以此就可判断了

按照这个思路，可以按照字典序排序字母来实现统一的排序，排序单个字符串可以用到`sort()`函数，由于题目中输入的单词是包含大小写的，所以我们需要一个把所有字母都小写化，这里我是根据`ASCII`码自己手写了一个转换，紫书中用的是`cctype`头文件中的`tolower()`函数，不过结果是一样的，代码如下：
```c++
string transf(const string &s) {
    string str = s;
    for (auto &i : str) {
        if (i <= 90) i += 32;
    }
    sort(str.begin(), str.end());
    return str;
}
```

`map`容器在本题中的运用就是一个`pair`数组，单纯用来记录一个特定的字母序列出现的个数，在书中也明确提到`map`更像是一个“关联数组“

### 时间复杂度

- `sort()`函数时间复杂度为`O(nlogn)`
- `map`（底层实现就是红黑树）的所有操作时间复杂度均为`O(logn)`

结合主要代码是嵌套在一个大循环里的
```c++
 while(cin >> t) { // O(n)
        if (t == "#") break;
        string tmp = transf(t);

        // O(logn)
        if (!dict.count(tmp)) dict[tmp] = 0;
        else dict[tmp]++;

        words.emplace_back(t);
    }
```

**所以总时间复杂度是`O(nlogn)`**