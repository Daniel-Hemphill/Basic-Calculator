#include "CalculatorProcessor.h"

CalculatorProcessor::CalculatorProcessor()
{

}
CalculatorProcessor::~CalculatorProcessor()
{

}
wxString CalculatorProcessor::CalculateText(wxString textBox)
{
    wxStringTokenizer tokenizer(textBox, " ");
    wxString token = "";
    double result = 0.0; // Initialize the result

    std::vector<double> numbers;
    std::vector<wxString> functions;
    std::vector<wxString> operations;

    while (tokenizer.HasMoreTokens())
    {
        token = tokenizer.GetNextToken();
        double value;

        if (token.ToDouble(&value))
        {
            numbers.push_back(value);
        }
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
        {
            while (!operations.empty() && OperationOrdering(operations.back()) >= OperationOrdering(token))
            {
                Calculate(numbers, functions, operations);
            }
            operations.push_back(token);
        }
        if (token == "sin" || token == "cos" || token == "tan")
        {
            functions.push_back(token);
        }
    }

    while (!operations.empty() || !functions.empty())
    {
        Calculate(numbers, functions, operations);
    }

    if (!numbers.empty())
    {
        result = numbers.back();
    }

    wxString wxResult = wxString::FromDouble(result, 5);
    return wxResult;
}

int CalculatorProcessor::OperationOrdering(wxString op)
{
    if (op == "+" || op == "-")
    {
        return 1;
    }
    else if (op == "*" || op == "/" || op == "%")
    {
        return 2;
    }
    return 0;
}

void CalculatorProcessor::Calculate(std::vector<double>& numbers, std::vector<wxString>& functions, std::vector<wxString>& operations)
{
    double a = 0;
    double b = 0;
    double result = 0.0;
    wxString op = "";

    if (numbers.size() < 0)
    {
        a = numbers.back();
        numbers.pop_back();
        result = a;
    }
    else
    {
        b = numbers.back();
        numbers.pop_back();

        a = numbers.back();
        numbers.pop_back();

        op = operations.back();
        operations.pop_back();
    }

    switch (op.ToStdString()[0])
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        if (b == 0)
        {
            wxLogError("Division by zero error!");
            return;
        }
        result = a / b;
        break;
    case '%':
        result = fmod(a, b);
        break;
    }

    numbers.push_back(result);

    if (!functions.empty())
    {
        wxString func = functions.back();
        functions.pop_back();

        if (func == "sin")
        {
            result = std::sin((result * (3.14 / 180)));
        }
        if (func == "cos")
        {
            result = std::cos((result * (3.14 / 180)));
        }
        if (func == "tan")
        {
            result = std::tan((result * (3.14 / 180)));
        }

        numbers.back() = result;
    }
}