"""
 Problem: 166. Fraction to Recurring Decimal
 Language: python3
 Runtime: 0 ms (100.00%)
 Memory: 18.2 MB (92.97%)
 Tags: Hash Table, Math, String
"""
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"
    
        res = []
        if (numerator < 0) ^ (denominator < 0):
            res.append("-")
        
        numerator, denominator = abs(numerator), abs(denominator)
        
        res.append(str(numerator // denominator))
        remainder = numerator % denominator
        if remainder == 0:
            return "".join(res)
        
        res.append(".")
        remainder_map = {}
        
        while remainder != 0:
            if remainder in remainder_map:
                idx = remainder_map[remainder]
                res.insert(idx, "(")
                res.append(")")
                break
            remainder_map[remainder] = len(res)
            
            remainder *= 10
            res.append(str(remainder // denominator))
            remainder %= denominator
        
        return "".join(res)