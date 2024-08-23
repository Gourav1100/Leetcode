/**
 * @param {string} expression
 * @return {string}
 */

function gcd(a, b) {
  if (b === 0) {
    return a;
  }
  return gcd(b, a % b);
}

function lcm(a, b) {
  return (a * b) / gcd(a, b);
}

var fractionAddition = function(expression) {
    expressions = expression.replaceAll("+", " + ").replaceAll("-", " - ").split(" ")
    result = {
        numerator: 0,
        denominator: 1,
        operation: undefined
    }
    const steps = expressions.map((e) => {
        const nums = e.split("/");
        return nums.length == 2 ? {
            numerator: JSON.parse(nums.at(0)),
            denominator: JSON.parse(nums.at(1)),
            operation: undefined
        } : {
            numerator: undefined,
            denominator: undefined,
            operation: e
        }
    })
    steps.forEach(step => {
        if (step.operation) {
            result.operation = step.operation;
        } else {
            if (result.operation) {
                const _lcm = lcm(result.denominator, step.denominator);
                step.numerator = (_lcm / step.denominator) * step.numerator;
                result.numerator = (_lcm / result.denominator) * result.numerator;
                result.numerator += (result.operation == "+" ? 1 : -1) * step.numerator;
                result.denominator = _lcm;
            } else {
                result.numerator = step.numerator || 0;
                result.denominator = step.denominator || 1;
            }
        }
    })
    const _gcd = gcd(Math.abs(result.numerator), Math.abs(result.denominator));
    return `${result.numerator / _gcd}/${result.denominator / _gcd}`
};