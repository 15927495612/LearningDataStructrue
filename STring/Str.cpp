/*
ADT 串(string)
Data 
    串中的元素仅由一个字符组成，相邻的元素具有前驱与后继的关系
Operation
    StrAssign(T,*chars);生成一个其值等于字符串常量chars的串T
    StrCopy(T,s);串s存在，将串s复制得串T
    ClearString(s);串s存在，将串清空
    StringEmpty(s);若串s为空，返回true，否则返回false
    StrLength(s);返回串S的元素个数，也即串的长度
    StrCompare(S,T);若S>T，返回值为true，否则返回false
    Concat(T,s1.s2);用T返回s1与s2联结而成的新串
    SubString(Sub,S,pos,len);串S存在，1<=pos<=StrLength(s),且0<=len<=StrLength(S)-pos+1,用sub返回串S的第pos个字符起长度为len的子串
    Index(S,T,pos);串S和T存在，T是非空串，1<=pos<=StrLength(S)。若主串S中存在和串T值相同的子串，则返回他在主串中第pos个字符之后第一次出现的位置，否则返回零
    Replace(S,T,V);串S，T和V存在，T是非空串，用V替换主串S中出现的所有与T相等的不重叠的子串
    StrIsert(S,pos,T);串S和T存在，1<=Strlength(S)-len+1.从喜欢S的第pos个字符之前插入串T
    StrDelete(S,pos,len);串S存在，1<=pos<=Strlength(s)-len+1.从串S中删除第pos个字符起长度为len的子串

*/
#include <string>
/*      朴素模式匹配     */
int Index( s,String f,int pos)
{
    

}