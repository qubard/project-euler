#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class BigInt {
    using carry_t = uint8_t;
    using digit_t = uint8_t;
    using container = std::vector<digit_t>;

    friend std::ostream& operator<<(std::ostream& os, const BigInt& num) {
        return os << num.to_str();
    }
    
    friend size_t sum_digits(BigInt&);
    public:
        BigInt() {}
        BigInt(const BigInt& num) : values(num.values) {}
        BigInt(BigInt&& num) : values(std::move(num.values)) {}
        BigInt(size_t i) {
            while(i) {
                values.push_back(i % 10);
                i /= 10;
            }
        }
        BigInt(container c) : values(c) {}
        BigInt(std::string str) {
            values = container(str.rbegin(), str.rend());
            std::transform(values.begin(), values.end(), values.begin(), [](auto val){ return val - '0'; });
        }

        BigInt operator+(const BigInt& num) const {
            return *this + std::move(num);
        }
        
        BigInt& operator=(const BigInt& num) {
            this->values = num.values;
            return *this;
        }

        BigInt operator+(const BigInt&& num) const {
            if(num.values.size() > values.size()) 
                return num + *this;
            BigInt result;
            carry_t carry = 0;
            for(auto itr = values.begin(); itr != values.end(); itr++) {
                auto index = itr - values.begin();
                digit_t dig = index >= num.values.size() ? 0 : num.values[index];
                digit_t val = carry + dig + *itr;
                result.values.push_back(val % 10);
                carry = (val % 10) != val;
            }
            if(carry) result.values.push_back(carry);
            return result;
        }
        
        BigInt operator*(BigInt& num) {
            return *this * std::move(num); 
        }
        
        BigInt operator*(const BigInt&& num) const {
            if(num.values.size() > values.size()) 
                return num + *this;
            BigInt result;
            size_t i = 0;
            for(auto& dig: num.values) { // loop over the lower multiplication value
                BigInt temp; // multiply v against every digit and add the result in temp
                carry_t carry = 0;
                for(; i > 0; i--) temp.values.push_back(0); // add leading zeros to temp
                for(auto itr = values.begin(); itr != values.end(); itr++) {
                   digit_t val = carry + dig * (*itr);
                   temp.values.push_back(val % 10);
                   carry = val / 10;
                }
                if(carry) temp.values.push_back(carry);
                result = result + temp;
                i++;
            }
            return result;  
        }

        bool operator==(const BigInt&& num) const {
            return values == num.values;
        }

        std::string to_str() const {
            std::string ret;
            for(auto itr = values.rbegin(); itr != values.rend(); itr++) ret += *itr + '0';
            return ret;
        }
    private:
        container values;
};

size_t sum_digits(BigInt& num) {
    return std::accumulate(num.values.begin(), num.values.end(), (size_t)0);
}

int main() {
    BigInt solution("1");
    for(size_t i = 2; i < 100; i++) solution = solution * BigInt(i);
    std::cout << "Solution is " << sum_digits(solution) << std::endl;
    return 0;
}
