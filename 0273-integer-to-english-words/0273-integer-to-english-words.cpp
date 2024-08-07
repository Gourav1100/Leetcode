string ONES[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string TENS[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string POWERS[] = {"Hundred", "Thousand", "Million", "Billion"};
string TEENS[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return convert(num).substr(1);
    }
    string convert(int num) {
        if (num >= 1000000000) return convert(num / 1000000000) + " Billion" + convert(num % 1000000000);
        if (num >= 1000000) return convert(num / 1000000) + " Million" + convert(num % 1000000);
        if (num >= 1000) return convert(num / 1000) + " Thousand" + convert(num % 1000);
        if (num >= 100) return convert(num / 100) + " Hundred" + convert(num % 100);
        if (num >= 20) return " " + TENS[num / 10] + convert(num % 10);
        if (num >= 10) return " " + TEENS[num - 10];
        if (num > 0) return " " + ONES[num];
        return "";
    }
};