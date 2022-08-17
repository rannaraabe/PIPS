/*
Difficulty: Hard;

Convert a non-negative integer num to its English words representation.

Constraints:
0 <= num <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std;

string digits[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string numberToWords(int num) {
    if(num == 0) return "Zero";
    string output = convertNum(num);
    
    return output.substr(1, output.size()-1);
}

string convertNum(int num){
    if(num >= 1000000000){
        return convertNum(num/1000000000) + " Billion" + convertNum(num%1000000000);
    } else if(num >= 1000000){
        return convertNum(num/1000000) + " Million" + convertNum(num%1000000);
    } else if(num >= 1000){
        return convertNum(num/1000) + " Thousand" + convertNum(num%1000);
    } else if(num >= 100){
        return convertNum(num/100) + " Hundred" + convertNum(num%100);
    } else if(num >= 20){
        return " " + tens[num/10] + convertNum(num%10);
    } else if(num >= 1){
        return " " + digits[num];
    }
    
    return "";
}