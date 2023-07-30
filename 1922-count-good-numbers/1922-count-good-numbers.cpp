class Solution {
public:
    int mod = 1e9+7;  // The modulo for large numbers

    // Function to calculate the power under modulo using fast power algorithm
    long long power(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {   // Continue until exp is 0
            if (exp & 1)    // If exp is odd, multiply the result with base
                result = result * base % mod;
            base = base * base % mod; // Square the base
            exp >>= 1;  // Divide exp by 2 (same as exp = exp / 2)
        }
        return result; // Return the result under modulo
    }

    int countGoodNumbers(long long n) {
        // Calculate the power for even digits (5 possibilities)
        long long evens = power(5, (n + 1) / 2);
        // Calculate the power for odd digits (4 possibilities)
        long long odds = power(4, n / 2);
        // Return the result as multiplication of both under modulo
        return (evens * odds) % mod;
    }
};
