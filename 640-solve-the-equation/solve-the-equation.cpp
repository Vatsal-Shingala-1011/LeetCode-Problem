class Solution {
public:
    string solveEquation(string eq) {
        int x_coeff = 0, num = 0;  // Coefficients for x and the constant term
        int sign = 1;  // Current sign: 1 for positive, -1 for negative
        int side = 1;  // Current side: 1 for left side, -1 for right side

        int n = eq.size();
        for (int i = 0; i < n; ) {
            if (eq[i] == '=') {
                side = -1;  // Switch to right side
                sign = 1;  // Reset the sign
                i++;
            } else if (eq[i] == '+') {
                sign = 1;  // Positive sign
                i++;
            } else if (eq[i] == '-') {
                sign = -1;  // Negative sign
                i++;
            } else {
                int start = i;
                while (i < n && isdigit(eq[i])) i++;
                int number = (i > start) ? stoi(eq.substr(start, i - start)) : 1;
                if (i < n && eq[i] == 'x') {
                    x_coeff += sign * side * number;
                    i++;
                } else {
                    num += sign * side * number;
                }
            }
        }

        if (x_coeff == 0) {
            if (num == 0) return "Infinite solutions";
            else return "No solution";
        }

        int solution = -num / x_coeff;
        return "x=" + to_string(solution);
    }
};
