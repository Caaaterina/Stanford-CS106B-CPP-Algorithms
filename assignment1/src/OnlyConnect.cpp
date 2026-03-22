/* File: OnlyConnect.cpp
 *
 * 实现说明：
 * 我使用递归处理字符串。每一层递归先处理去掉首字符后的子串，
 * 再判断当前字符：如果不是字母或是元音就丢弃；否则将其转为大写并拼接到结果前面。
 * 其中 y/Y 按辅音处理，不会被删除。
 *
 * 给 section leader 的谜题：
 * Consonant string: MTRX
 * Hint: 1999 sci-fi movie
 */
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
#include <cctype>
using namespace std;

string onlyConnectize(string phrase) {
    /* TODO: The next few lines just exist to make sure you don't get compiler warning messages
      * when this function isn't implemented. Delete these lines, then implement this function.
      */
    if (phrase == ""){
        return "";
    }

    char ch = phrase[0];
    string rest = onlyConnectize(phrase.substr(1));

    char lower = tolower(ch);
    bool isVowel = (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u');

    if (isVowel || !isalpha(ch)){
        return rest;
    }else{
        return string(1, toupper(ch)) + rest;
    }
}






/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

STUDENT_TEST("keeps y as consonant"){
    EXPECT_EQUAL(onlyConnectize("yYaeiou"), "YY");
    EXPECT_EQUAL(onlyConnectize("rhythm"), "RHYTHM");
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
  * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
  * general rules of testing:
  *
  *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
  *
  *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
  *       for cases that aren't just variations of one another.
  *
  *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
  *       actually enter, but which are still perfectly legal.
  *
  * Happy testing!
  */






